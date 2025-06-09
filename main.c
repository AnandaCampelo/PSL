#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
int yyparse(void);
extern int yylineno;

// Instead of defining yydebug here, just declare it as extern
extern int yydebug;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo.psl>\n", argv[0]);
        return 1;
    }
    
    // Disable parser debugging for cleaner output
    yydebug = 0;
    
    yyin = fopen(argv[1], "r");
    if (!yyin) { 
        perror("Erro ao abrir arquivo"); 
        return 1; 
    }
    
    fprintf(stderr, "Processando arquivo: %s\n", argv[1]);
    
    int result = yyparse();
    if (result != 0) {
        fprintf(stderr, "Erro ao processar o arquivo PSL (código %d).\n", result);
    } else {
        fprintf(stderr, "Arquivo processado com sucesso.\n");
    }
    
    fclose(yyin);
    return result;
}