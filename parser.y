%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"

void yyerror(const char *s);
int yylex(void);
extern FILE *yyin;
extern int yylineno;

// For debugging
void debug_msg(const char* msg) {
    fprintf(stderr, "DEBUG: %s\n", msg);
}

// Global variables for state tracking
char *saved_alt_text = NULL;
char *paragraph_text = NULL;
char *link_text = NULL;
char *link_url = NULL;

// For handling code blocks
char *code_lines[100];  // Store up to 100 lines of code
int code_line_count = 0;
char *code_lang = NULL;

// For conditional processing
char *condition_var = NULL;
char *condition_value = NULL;
int condition_op = OP_IGUAL;

// Global flags
int enum_count = 1;
%}

%union {
    char *str;
    int num;
    int op;  // Changed from op_type to int for compatibility
}

/* Tokens */
%token <str> INDENTED_TEXT CODIGO CABECALHO ALT SRC STATUS_S STATUS_N
%token <str> TEXTO URL STATUS_SIM STATUS_NAO
%token <num> REPETIR
%token <op> OP_REL

/* Tokens without values */
%token TITULO SUBTITULO PARAGRAFO LISTA ENUMERAR TAREFAS IMAGEM DIVISOR TABELA LINK NOTA CITACAO ENTAO SENAO NEWLINE SE

/* Non-terminals with types */
%type <str> indented_lines

%%

document:
    blocks
    ;

blocks:
    /* empty */
    | blocks block
    | blocks NEWLINE block  /* Allow newlines between blocks */
    ;

block:
    titulo_block
    | subtitulo_block
    | paragrafo_block
    | lista_block
    | enumerar_block
    | tarefas_block
    | codigo_block
    | imagem_block
    | link_block
    | nota_block
    | citacao_block
    | divisor_block
    | tabela_block
    | se_block
    | repetir_block
    | NEWLINE  /* Handle extra newlines */
    ;

titulo_block:
    TITULO INDENTED_TEXT NEWLINE
    { printf("# %s\n\n", $2); }
    ;

subtitulo_block:
    SUBTITULO INDENTED_TEXT NEWLINE
    { printf("## %s\n\n", $2); }
    ;

paragrafo_block:
    PARAGRAFO indented_lines
    { 
        // Print accumulated paragraph text
        if (paragraph_text) {
            printf("%s\n\n", paragraph_text);
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
    ;

indented_lines:
    INDENTED_TEXT NEWLINE
    { 
        if (paragraph_text) {
            free(paragraph_text);
            paragraph_text = NULL;
        }
        paragraph_text = strdup($1);
        $$ = paragraph_text;
    }
    | indented_lines INDENTED_TEXT NEWLINE
    { 
        char *new_text = malloc(strlen(paragraph_text) + strlen($2) + 2); // +2 for space and null terminator
        sprintf(new_text, "%s %s", paragraph_text, $2);
        free(paragraph_text);
        paragraph_text = new_text;
        $$ = paragraph_text;
    }
    ;

lista_block:
    LISTA lista_items
    { printf("\n"); } // Add extra newline after list
    ;

lista_items:
    INDENTED_TEXT NEWLINE
    { printf("- %s\n", $1); }
    | lista_items INDENTED_TEXT NEWLINE
    { printf("- %s\n", $2); }
    ;

enumerar_block:
    ENUMERAR { enum_count = 1; } enumerar_items
    { printf("\n"); } // Add extra newline after list
    ;

enumerar_items:
    INDENTED_TEXT NEWLINE
    { printf("1. %s\n", $1); enum_count = 2; }
    | enumerar_items INDENTED_TEXT NEWLINE
    { printf("%d. %s\n", enum_count++, $2); }
    ;

tarefas_block:
    TAREFAS tarefas_items
    { printf("\n"); } // Add extra newline after list
    ;

tarefas_items:
    STATUS_S NEWLINE
    { printf("- [x] %s\n", $1); }
    | STATUS_N NEWLINE
    { printf("- [ ] %s\n", $1); }
    | STATUS_SIM NEWLINE
    { printf("- [x] %s\n", $1); }
    | STATUS_NAO NEWLINE
    { printf("- [ ] %s\n", $1); }
    | tarefas_items STATUS_S NEWLINE
    { printf("- [x] %s\n", $2); }
    | tarefas_items STATUS_N NEWLINE
    { printf("- [ ] %s\n", $2); }
    | tarefas_items STATUS_SIM NEWLINE
    { printf("- [x] %s\n", $2); }
    | tarefas_items STATUS_NAO NEWLINE
    { printf("- [ ] %s\n", $2); }
    ;

codigo_block:
    CODIGO 
    { 
        // Reset code block state
        code_line_count = 0;
        if (code_lang) free(code_lang);
        code_lang = strdup($1);
        
        // Free any previous code lines
        for (int i = 0; i < 100; i++) {
            if (code_lines[i]) {
                free(code_lines[i]);
                code_lines[i] = NULL;
            }
        }
    }
    codigo_content
    { 
        // Print the code block with proper formatting
        printf("```%s\n", code_lang);
        for (int i = 0; i < code_line_count; i++) {
            printf("%s\n", code_lines[i]);
            free(code_lines[i]);
            code_lines[i] = NULL;
        }
        printf("```\n\n");
        code_line_count = 0;
    }
    ;

codigo_content:
    codigo_lines
    ;

codigo_lines:
    INDENTED_TEXT NEWLINE
    { 
        // Store code line
        code_lines[code_line_count++] = strdup($1);
    }
    | codigo_lines INDENTED_TEXT NEWLINE
    { 
        // Store additional code line
        code_lines[code_line_count++] = strdup($2);
    }
    ;

imagem_block:
    IMAGEM alt_line src_line
    ;

alt_line:
    ALT NEWLINE
    { 
        if (saved_alt_text) free(saved_alt_text);
        saved_alt_text = strdup($1);
    }
    ;

src_line:
    SRC NEWLINE
    { 
        printf("![%s](%s)\n\n", saved_alt_text ? saved_alt_text : "", $1);
        if (saved_alt_text) {
            free(saved_alt_text);
            saved_alt_text = NULL;
        }
    }
    ;

link_block:
    LINK texto_line url_line
    ;

texto_line:
    TEXTO NEWLINE
    {
        if (link_text) free(link_text);
        link_text = strdup($1);
    }
    ;

url_line:
    URL NEWLINE
    {
        printf("[%s](%s)\n\n", link_text ? link_text : "", $1);
        if (link_text) {
            free(link_text);
            link_text = NULL;
        }
    }
    ;

nota_block:
    NOTA indented_lines
    {
        if (paragraph_text) {
            printf("> *Note:* %s\n\n", paragraph_text);
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
    ;

citacao_block:
    CITACAO indented_lines
    {
        if (paragraph_text) {
            printf("> %s\n\n", paragraph_text);
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
    ;

divisor_block:
    DIVISOR NEWLINE
    { printf("---\n\n"); }
    ;

tabela_block:
    TABELA cabecalho_line tabela_rows
    { printf("\n"); } // Add extra newline after table
    ;

cabecalho_line:
    CABECALHO NEWLINE
    {
        char *s = strdup($1);
        char *token, *saveptr;
        
        // Print header row
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n|");
        
        // Print separator row
        s = strdup($1);
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            printf(" --- |");
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
    ;

tabela_rows:
    INDENTED_TEXT NEWLINE
    {
        char *s = strdup($1);
        char *token, *saveptr;
        
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
    | tabela_rows INDENTED_TEXT NEWLINE
    {
        char *s = strdup($2);
        char *token, *saveptr;
        
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
    | tabela_rows INDENTED_TEXT /* Handle EOF without newline */
    {
        char *s = strdup($2);
        char *token, *saveptr;
        
        printf("|");
        token = strtok_r(s, ",", &saveptr);
        while (token != NULL) {
            token = trim(token);
            printf(" %s |", token);
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("\n");
        free(s);
    }
    ;

se_block:
    SE
    {
        // Just output a comment for the conditional block
        printf("<!-- Conditional block (simplified) -->\n\n");
    }
    ;

repetir_block:
    REPETIR
    {
        // Just output a comment for the repeat block
        printf("<!-- Repeat block %d times (simplified) -->\n\n", $1);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s na linha %d\n", s, yylineno);
}