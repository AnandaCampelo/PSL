#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// LLVM removido // Update the include path

extern FILE *yyin;
extern int yyparse(void);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s arquivo.psl\n", argv[0]);
        return 1;
    }

    printf("Processando arquivo: %s\n", argv[1]);

    // Abrir o arquivo de entrada
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // Configurar o yyin para ler do arquivo
    yyin = input_file;

    // Analisar o arquivo
    int result = yyparse();

    // Fechar o arquivo
    fclose(input_file);

    if (result != 0) {
        fprintf(stderr, "Erro ao processar o arquivo PSL (código %d).\n", result);
        return 1;
    }

    return 0;
}