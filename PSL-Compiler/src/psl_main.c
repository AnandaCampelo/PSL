#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "psl_llvm.h"

// Modificar a função main para usar uma abordagem mais robusta
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s arquivo.psl\n", argv[0]);
        return 1;
    }
    
    const char* filename = argv[1];
    printf("Processando arquivo com LLVM: %s\n", filename);
    
    // Preparar arquivo de saída para o markdown
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "%s.md", filename);
    FILE* output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Erro: Não foi possível criar arquivo de saída %s\n", output_filename);
        return 1;
    }
    
    // Redirecionar stdout para o arquivo para capturar o markdown durante o parsing
    int original_stdout = dup(STDOUT_FILENO);
    if (original_stdout == -1 || dup2(fileno(output_file), STDOUT_FILENO) == -1) {
        fprintf(stderr, "Erro ao redirecionar stdout\n");
        fclose(output_file);
        return 1;
    }
    
    // Inicializar o contexto do compilador
    PSLCompilerContext* ctx = psl_compiler_init("psl_module");
    if (!ctx) {
        // Restaurar stdout antes de imprimir mensagens de erro
        fflush(stdout);
        dup2(original_stdout, STDOUT_FILENO);
        close(original_stdout);
        fclose(output_file);
        
        fprintf(stderr, "Erro inicializando o compilador LLVM.\n");
        return 1;
    }
    
    // Analisar e compilar o arquivo PSL
    if (parse_psl_file(filename, ctx) != 0) {
        // Restaurar stdout antes de imprimir mensagens de erro
        fflush(stdout);
        dup2(original_stdout, STDOUT_FILENO);
        close(original_stdout);
        fclose(output_file);
        
        fprintf(stderr, "Erro analisando o arquivo %s.\n", filename);
        psl_compiler_cleanup(ctx);
        return 1;
    }
    
	// Restaurar stdout para exibir mensagens normais
	fflush(stdout);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	fclose(output_file);

	printf("Markdown gerado com sucesso em: %s\n", output_filename);

	// Finalizar o módulo LLVM (sem executar o código)
	printf("Finalizando o módulo LLVM...\n");
	psl_run_module(ctx);  // Agora esta chamada não afetará o arquivo MD

	// Limpar o contexto
	psl_compiler_cleanup(ctx);
    
    printf("Execução concluída com sucesso!\n");
    return 0;
}