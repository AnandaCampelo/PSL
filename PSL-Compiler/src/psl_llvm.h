#ifndef PSL_LLVM_H
#define PSL_LLVM_H

#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Transforms/Scalar.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para manter o contexto do compilador
typedef struct {
    LLVMContextRef context;
    LLVMModuleRef module;
    LLVMBuilderRef builder;
    LLVMExecutionEngineRef engine;
    
    // Tabela de variáveis
    char** var_names;
    LLVMValueRef* var_values;
    int var_count;
    
    // Função atual
    LLVMValueRef current_function;
    
    // Blocos de controle para condicionais
    LLVMBasicBlockRef entry_block;
    LLVMBasicBlockRef then_block;
    LLVMBasicBlockRef else_block;
    LLVMBasicBlockRef merge_block;
    
    // Função de impressão
    LLVMValueRef print_function;
} PSLCompilerContext;

// Inicialização do contexto do compilador
PSLCompilerContext* psl_compiler_init(const char* module_name);

// Finalização do contexto do compilador
void psl_compiler_cleanup(PSLCompilerContext* ctx);

// Gerar código para blocos básicos do PSL
void psl_gen_titulo(PSLCompilerContext* ctx, const char* text);
void psl_gen_subtitulo(PSLCompilerContext* ctx, const char* text);
void psl_gen_paragrafo(PSLCompilerContext* ctx, const char* text);
void psl_gen_lista(PSLCompilerContext* ctx, const char* item);
void psl_gen_enumerar(PSLCompilerContext* ctx, const char* item, int num);
void psl_gen_tarefas(PSLCompilerContext* ctx, const char* text, int completed);
void psl_gen_codigo(PSLCompilerContext* ctx, const char* lang, const char* code);
void psl_gen_imagem(PSLCompilerContext* ctx, const char* alt, const char* src);
void psl_gen_link(PSLCompilerContext* ctx, const char* text, const char* url);
void psl_gen_nota(PSLCompilerContext* ctx, const char* text);
void psl_gen_divisor(PSLCompilerContext* ctx);

// Gerador de código para estruturas de controle
void psl_gen_if_start(PSLCompilerContext* ctx, const char* var, int op, const char* value);
void psl_gen_if_then(PSLCompilerContext* ctx);
void psl_gen_if_else(PSLCompilerContext* ctx);
void psl_gen_if_end(PSLCompilerContext* ctx);

void psl_gen_loop_start(PSLCompilerContext* ctx, int count);
void psl_gen_loop_body(PSLCompilerContext* ctx);
void psl_gen_loop_end(PSLCompilerContext* ctx);

// Funções para manipulação de variáveis
void psl_set_variable(PSLCompilerContext* ctx, const char* name, const char* value);
const char* psl_get_variable(PSLCompilerContext* ctx, const char* name);

// Funções para execução
void psl_run_module(PSLCompilerContext* ctx);
void psl_write_bitcode(PSLCompilerContext* ctx, const char* filename);

// Função para processamento de arquivos PSL com geração de LLVM
int parse_psl_file(const char* filename, void* ctx);

#endif // PSL_LLVM_H