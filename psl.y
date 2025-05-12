%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
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

%%
programa:
    USER STRING statements END {
        printf("Usuário: %s\n", $2);
    }
;

statements:
    /* vazio */
  | statements statement
;

statement:
    DECLARE tipo IDENTIFIER
  | ASSIGN IDENTIFIER expression
  | PRINT expression
  | INPUT
  | BIND IDENTIFIER IDENTIFIER
  | SEARCH STRING
  | HISTORY STRING
;

tipo:
    NUMTYPE
  | STRTYPE
;

expression:
    NUMBER
  | STRING
  | IDENTIFIER
;
%%