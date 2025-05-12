%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // para system()
#include <stdbool.h>

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}

// Variáveis
typedef enum { T_INT, T_STRING } VarType;

typedef struct {
    char* name;
    VarType type;
    union {
        int intValue;
        char* strValue;
    } value;
} Variable;

#define MAX_VARS 100
Variable vars[MAX_VARS];
int var_count = 0;
char* current_user = NULL;

// Funções auxiliares
int find_var(const char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) return i;
    }
    return -1;
}

void set_var(const char* name, VarType type, void* value) {
    int i = find_var(name);
    if (i == -1 && var_count < MAX_VARS) {
        vars[var_count].name = strdup(name);
        vars[var_count].type = type;
        if (type == T_INT)
            vars[var_count].value.intValue = *(int*)value;
        else
            vars[var_count].value.strValue = strdup((char*)value);
        var_count++;
    } else if (i != -1) {
        if (type == T_INT)
            vars[i].value.intValue = *(int*)value;
        else {
            free(vars[i].value.strValue);
            vars[i].value.strValue = strdup((char*)value);
        }
    }
}

void print_var(const char* name) {
    int i = find_var(name);
    if (i == -1) {
        printf("Erro: variável %s não encontrada\n", name);
        return;
    }
    if (vars[i].type == T_INT)
        printf("%s = %d\n", vars[i].name, vars[i].value.intValue);
    else
        printf("%s = %s\n", vars[i].name, vars[i].value.strValue);
}

void print_history(const char* user) {
    if (user == NULL || current_user == NULL) {
        printf("Erro interno: usuário indefinido.\n");
        return;
    }
    if (strcmp(user, current_user) != 0) {
        printf("Histórico de \"%s\" não disponível nesta execução.\n", user);
        return;
    }
    printf("📜 Histórico de variáveis para %s:\n", user);
    for (int i = 0; i < var_count; i++) {
        if (vars[i].type == T_INT)
            printf("  %s = %d\n", vars[i].name, vars[i].value.intValue);
        else
            printf("  %s = %s\n", vars[i].name, vars[i].value.strValue);
    }
}

void abrir_site(const char* nome) {
    char url[256];
    snprintf(url, sizeof(url), "https://www.%s.com", nome);
    char comando[300];
    snprintf(comando, sizeof(comando), "xdg-open \"%s\" &> /dev/null", url);
    int r = system(comando);
    if (r != 0) {
        fprintf(stderr, "Erro ao tentar abrir: %s\n", url);
    } else {
        printf("🌐 Abrindo: %s\n", url);
    }
}
%}

%union {
    int num;
    char* str;
}

%token <str> STRING IDENTIFIER
%token <num> NUMBER

%token USER END DECLARE NUMTYPE STRTYPE ASSIGN ADD SUB MULT DIV
%token PRINT INPUT BIND IF WHILE BLOCK_START BLOCK_END SEARCH HISTORY
%token EQ NEQ GT LT GTE LTE

%type <num> expression_int
%type <str> expression_str
%type <str> tipo

%%

programa:
    USER STRING {
        current_user = strdup($2);
        printf("Usuário: %s\n", current_user);
    }
    statements END {
        printf("Programa PSL processado com sucesso!\n");
    }
;

statements:
    /* vazio */
  | statements statement
;

statement:
    DECLARE tipo IDENTIFIER {
        if (strcmp($2, "int") == 0) {
            int zero = 0;
            set_var($3, T_INT, &zero);
        } else {
            char* vazio = "";
            set_var($3, T_STRING, vazio);
        }
    }
  | ASSIGN IDENTIFIER expression_int {
        set_var($2, T_INT, &$3);
    }
  | ASSIGN IDENTIFIER expression_str {
        set_var($2, T_STRING, $3);
    }
  | PRINT IDENTIFIER {
        print_var($2);
    }
  | HISTORY STRING {
        print_history($2);
    }
  | SEARCH STRING {
        abrir_site($2);
    }
  | INPUT
  | BIND IDENTIFIER IDENTIFIER
;

tipo:
    NUMTYPE { $$ = "int"; }
  | STRTYPE { $$ = "string"; }
;

expression_int:
    NUMBER { $$ = $1; }
;

expression_str:
    STRING { $$ = $1; }
;

%%