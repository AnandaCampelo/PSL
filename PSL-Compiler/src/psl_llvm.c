#include "psl_llvm.h"

// Função para imprimir texto (será usada para gerar markdown)
static LLVMValueRef create_print_function(PSLCompilerContext* ctx) {
    // Declare a função externa para printf
    LLVMTypeRef printf_arg_types[] = { LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef printf_type = LLVMFunctionType(LLVMInt32Type(), printf_arg_types, 1, 1);
    LLVMValueRef printf_func = LLVMAddFunction(ctx->module, "printf", printf_type);
    
    // Crie uma função para print específico do Markdown
    LLVMTypeRef print_arg_types[] = { LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef print_type = LLVMFunctionType(LLVMInt32Type(), print_arg_types, 1, 0);
    LLVMValueRef print_func = LLVMAddFunction(ctx->module, "print_markdown", print_type);
    
    // Implementar a função print_markdown
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(print_func, "entry");
    LLVMPositionBuilderAtEnd(ctx->builder, entry);
    
    LLVMValueRef text = LLVMGetParam(print_func, 0);
    LLVMValueRef printf_args[] = { text };
    LLVMValueRef call_result = LLVMBuildCall2(ctx->builder, printf_type, printf_func, printf_args, 1, "printf_call");
    
    // Retornar o resultado do printf
    LLVMBuildRet(ctx->builder, call_result);
    
    return print_func;
}

// Função auxiliar para chamar print_markdown de forma consistente
static LLVMValueRef build_print_call(PSLCompilerContext* ctx, LLVMValueRef text_ptr) {
    if (!ctx || !text_ptr) return NULL;
    
    LLVMValueRef print_func = LLVMGetNamedFunction(ctx->module, "print_markdown");
    if (!print_func) {
        fprintf(stderr, "Erro: função print_markdown não encontrada\n");
        return NULL;
    }
    
    // Criar os argumentos para a chamada
    LLVMValueRef args[] = { text_ptr };
    
    // Construir uma estrutura de tipo estática para a chamada
    static LLVMTypeRef param_types[1] = { NULL };
    if (!param_types[0]) {
        param_types[0] = LLVMPointerType(LLVMInt8Type(), 0);
    }
    
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), param_types, 1, 0);
    
    // Chamar a função com o tipo correto
    return LLVMBuildCall2(ctx->builder, func_type, print_func, args, 1, "print_call");
}

PSLCompilerContext* psl_compiler_init(const char* module_name) {
    PSLCompilerContext* ctx = (PSLCompilerContext*)malloc(sizeof(PSLCompilerContext));
    if (!ctx) return NULL;
    
    // Inicializar LLVM
    LLVMInitializeCore(LLVMGetGlobalPassRegistry());
    LLVMLinkInMCJIT();
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    
    // Criar o contexto LLVM
    ctx->context = LLVMContextCreate();
    ctx->module = LLVMModuleCreateWithNameInContext(module_name, ctx->context);
    ctx->builder = LLVMCreateBuilderInContext(ctx->context);
    
    // Criar engine de execução
    char* error = NULL;
    LLVMCreateExecutionEngineForModule(&ctx->engine, ctx->module, &error);
    if (error) {
        fprintf(stderr, "Erro criando engine de execução: %s\n", error);
        LLVMDisposeMessage(error);
        psl_compiler_cleanup(ctx);
        return NULL;
    }
    
    // Inicializar tabela de variáveis
    ctx->var_names = NULL;
    ctx->var_values = NULL;
    ctx->var_count = 0;
    
    // Criar função main
    LLVMTypeRef main_type = LLVMFunctionType(LLVMInt32Type(), NULL, 0, 0);
    ctx->current_function = LLVMAddFunction(ctx->module, "main", main_type);
    ctx->entry_block = LLVMAppendBasicBlock(ctx->current_function, "entry");
    LLVMPositionBuilderAtEnd(ctx->builder, ctx->entry_block);
    
    // Criar função de impressão
    create_print_function(ctx);
    
    return ctx;
}

void psl_compiler_cleanup(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Liberar tabela de variáveis
    for (int i = 0; i < ctx->var_count; i++) {
        free(ctx->var_names[i]);
    }
    free(ctx->var_names);
    free(ctx->var_values);
    
    // Liberar recursos LLVM
    LLVMDisposeBuilder(ctx->builder);
    LLVMDisposeExecutionEngine(ctx->engine);
    LLVMContextDispose(ctx->context);
    
    free(ctx);
}

void psl_gen_titulo(PSLCompilerContext* ctx, const char* text) {
    if (!ctx || !text) return;
    
    // Criar string literal para o formato de título Markdown
    char* format = (char*)malloc(strlen(text) + 10);
    sprintf(format, "# %s\n\n", text);
    
    // Criar string global para o texto do título
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "titulo");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_subtitulo(PSLCompilerContext* ctx, const char* text) {
    if (!ctx || !text) return;
    
    char* format = (char*)malloc(strlen(text) + 10);
    sprintf(format, "## %s\n\n", text);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "subtitulo");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_paragrafo(PSLCompilerContext* ctx, const char* text) {
    if (!ctx || !text) return;
    
    char* format = (char*)malloc(strlen(text) + 10);
    sprintf(format, "%s\n\n", text);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "paragrafo");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_divisor(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, "---\n\n", "divisor");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
}

void psl_gen_imagem(PSLCompilerContext* ctx, const char* alt, const char* src) {
    if (!ctx || !alt || !src) return;
    
    char* format = (char*)malloc(strlen(alt) + strlen(src) + 10);
    sprintf(format, "![%s](%s)\n\n", alt, src);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "imagem");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_link(PSLCompilerContext* ctx, const char* text, const char* url) {
    if (!ctx || !text || !url) return;
    
    char* format = (char*)malloc(strlen(text) + strlen(url) + 10);
    sprintf(format, "[%s](%s)\n\n", text, url);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "link");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_lista(PSLCompilerContext* ctx, const char* item) {
    if (!ctx || !item) return;
    
    char* format = (char*)malloc(strlen(item) + 10);
    sprintf(format, "- %s\n", item);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "lista_item");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_enumerar(PSLCompilerContext* ctx, const char* item, int num) {
    if (!ctx || !item) return;
    
    char* format = (char*)malloc(strlen(item) + 20);
    sprintf(format, "%d. %s\n", num, item);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "enum_item");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_tarefas(PSLCompilerContext* ctx, const char* text, int completed) {
    if (!ctx || !text) return;
    
    char* format = (char*)malloc(strlen(text) + 20);
    if (completed) {
        sprintf(format, "- [x] %s\n", text);
    } else {
        sprintf(format, "- [ ] %s\n", text);
    }
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "tarefa");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_codigo(PSLCompilerContext* ctx, const char* lang, const char* code) {
    if (!ctx || !lang || !code) return;
    
    char* format = (char*)malloc(strlen(lang) + strlen(code) + 20);
    sprintf(format, "```%s\n%s\n```\n\n", lang, code);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "codigo");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

void psl_gen_nota(PSLCompilerContext* ctx, const char* text) {
    if (!ctx || !text) return;
    
    char* format = (char*)malloc(strlen(text) + 20);
    sprintf(format, "> *Note:* %s\n\n", text);
    
    LLVMValueRef global_str = LLVMBuildGlobalStringPtr(ctx->builder, format, "nota");
    
    // Chamar a função de impressão
    build_print_call(ctx, global_str);
    
    free(format);
}

// Implementação das funções de controle de fluxo if
void psl_gen_if_start(PSLCompilerContext* ctx, const char* var, int op, const char* value) {
    if (!ctx) return;
    
    // Em uma implementação real, aqui você geraria código LLVM para a 
    // condição do if, comparando a variável com o valor usando o operador
    printf("Gerando início de bloco if para variável %s com valor %s\n", var, value);
    
    // Aqui criamos os blocos básicos para o if/then/else
    ctx->then_block = LLVMAppendBasicBlock(ctx->current_function, "then");
    ctx->else_block = LLVMAppendBasicBlock(ctx->current_function, "else");
    ctx->merge_block = LLVMAppendBasicBlock(ctx->current_function, "ifcont");
    
    // Para simplificar, vamos apenas criar uma condição fixa (sempre verdadeira)
    LLVMValueRef condition = LLVMConstInt(LLVMInt1Type(), 1, 0);
    
    // Criar o branch condicional
    LLVMBuildCondBr(ctx->builder, condition, ctx->then_block, ctx->else_block);
}

void psl_gen_if_then(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Posicionar o builder no bloco 'then'
    LLVMPositionBuilderAtEnd(ctx->builder, ctx->then_block);
    
    printf("Gerando código para o bloco then\n");
}

void psl_gen_if_else(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Adicionar salto do final do bloco 'then' para o bloco de merge
    LLVMBuildBr(ctx->builder, ctx->merge_block);
    
    // Posicionar o builder no bloco 'else'
    LLVMPositionBuilderAtEnd(ctx->builder, ctx->else_block);
    
    printf("Gerando código para o bloco else\n");
}

void psl_gen_if_end(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Adicionar salto do final do bloco 'else' para o bloco de merge
    LLVMBuildBr(ctx->builder, ctx->merge_block);
    
    // Posicionar o builder no bloco de merge para código subsequente
    LLVMPositionBuilderAtEnd(ctx->builder, ctx->merge_block);
    
    printf("Finalizando bloco if\n");
}

// Implementação das funções de loop
void psl_gen_loop_start(PSLCompilerContext* ctx, int count) {
    if (!ctx) return;
    
    printf("Iniciando loop com %d iterações\n", count);
    
    // Criar blocos básicos para o loop
    LLVMBasicBlockRef loop = LLVMAppendBasicBlock(ctx->current_function, "loop");
    LLVMBasicBlockRef after = LLVMAppendBasicBlock(ctx->current_function, "afterloop");
    
    // Criar variável de controle do loop (índice i)
    LLVMValueRef i = LLVMBuildAlloca(ctx->builder, LLVMInt32Type(), "i");
    LLVMBuildStore(ctx->builder, LLVMConstInt(LLVMInt32Type(), 0, 0), i);
    
    // Saltar para o bloco do loop
    LLVMBuildBr(ctx->builder, loop);
    
    // Posicionar o builder no início do bloco do loop
    LLVMPositionBuilderAtEnd(ctx->builder, loop);
    
    // Carregar valor atual de i
    LLVMValueRef current_i = LLVMBuildLoad2(ctx->builder, LLVMInt32Type(), i, "i_val");
    
    // Comparar com o número de iterações
    LLVMValueRef count_val = LLVMConstInt(LLVMInt32Type(), count, 0);
    LLVMValueRef cond = LLVMBuildICmp(ctx->builder, LLVMIntSLT, current_i, count_val, "loopcond");
    
    // Criar branch condicional
    LLVMBuildCondBr(ctx->builder, cond, loop, after);
    
    // Guarda os blocos para uso posterior
    ctx->entry_block = loop;
    ctx->merge_block = after;
}

void psl_gen_loop_body(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Aqui você posicionaria o builder no local correto do loop para adicionar
    // o código do corpo do loop
    printf("Gerando corpo do loop\n");
}

void psl_gen_loop_end(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Incrementar o contador do loop
    // Em uma implementação real, aqui você faria:
    // 1. Carregar o valor atual da variável i
    // 2. Incrementar o valor
    // 3. Armazenar o valor incrementado
    // 4. Voltar para o teste do loop
    
    // Saltar de volta para o teste do loop
    LLVMBuildBr(ctx->builder, ctx->entry_block);
    
    // Posicionar o builder após o loop para código subsequente
    LLVMPositionBuilderAtEnd(ctx->builder, ctx->merge_block);
    
    printf("Finalizando loop\n");
}

void psl_run_module(PSLCompilerContext* ctx) {
    if (!ctx) return;
    
    // Finalizar a função main com return 0
    LLVMBuildRet(ctx->builder, LLVMConstInt(LLVMInt32Type(), 0, 0));
    
    // Verificar o módulo - em modo silencioso
    char* error = NULL;
    int status = LLVMVerifyModule(ctx->module, LLVMReturnStatusAction, &error);
    if (status != 0) {
        fprintf(stderr, "Aviso: Problemas no módulo LLVM, mas continuando...\n");
        if (error) LLVMDisposeMessage(error);
        
        // Não imprimir para stdout, apenas para stderr
        fprintf(stderr, "Módulo LLVM criado mas não executado devido a problemas de verificação.\n");
        return;
    }
    
    // Só chegamos aqui se o módulo não tiver problemas
    fprintf(stderr, "--- Executando código LLVM ---\n");
    
    // Executar o código com tratamento de erro
    LLVMGenericValueRef exec_args[] = {};
    LLVMGenericValueRef exec_result = NULL;
    
    // Tentar executar, mas não abortar se falhar
    exec_result = LLVMRunFunction(ctx->engine, ctx->current_function, 0, exec_args);
    
    if (exec_result) {
        int result = LLVMGenericValueToInt(exec_result, 0);
        fprintf(stderr, "Código executado com código de saída: %d\n", result);
        LLVMDisposeGenericValue(exec_result);
    } else {
        fprintf(stderr, "Aviso: Não foi possível executar o código LLVM gerado.\n");
    }
    
    fprintf(stderr, "--- Fim da execução do código LLVM ---\n");
}