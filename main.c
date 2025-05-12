#include <stdio.h>

int yyparse(void);

int main() {
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("\n");


    int result = yyparse();

    printf("\n");
    printf("--------------------------------------------------\n");

    if (result == 0) {
        printf("\nPrograma PSL processado com sucesso!\n");
    } else {
        printf("Falha ao interpretar o programa PSL.\n");
    }

    return result;
}