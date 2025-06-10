%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
// LLVM removido  // Incluir o gerador LLVM

void yyerror(const char *s);
int yylex(void);
extern FILE *yyin;
extern int yylineno;

// Para debugging
void debug_msg(const char* msg) {
    fprintf(stderr, "DEBUG: %s\n", msg);
}

// Contexto do compilador LLVM
int* compiler_ctx = NULL;

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
    { 
        // Inicializar o compilador no início do parsing
        compiler_ctx = 0;
        if (!compiler_ctx) {
            fprintf(stderr, "Erro: Falha ao inicializar o compilador LLVM\n");
            YYABORT;
        }
    }
    blocks
    {
        // Finalizar a compilação no final do parsing
        
    }
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
    { 
        printf("# %s\n\n", $2);
        
        // Gerar código LLVM para título
        if (0) {
        }
    }
    ;

subtitulo_block:
    SUBTITULO INDENTED_TEXT NEWLINE
    { 
        printf("## %s\n\n", $2);
        
        // Gerar código LLVM para subtítulo
        if (0) {
        }
    }
    ;

paragrafo_block:
    PARAGRAFO indented_lines
    { 
        // Print accumulated paragraph text
        if (paragraph_text) {
            printf("%s\n\n", paragraph_text);
            
            // Gerar código LLVM para parágrafo
            if (0) {
            }
            
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
    { 
        printf("- %s\n", $1);
        
        // Gerar código LLVM para item de lista
        if (0) {
            char format[256];
            sprintf(format, "- %s", $1);
        }
    }
    | lista_items INDENTED_TEXT NEWLINE
    { 
        printf("- %s\n", $2);
        
        // Gerar código LLVM para item de lista
        if (0) {
            char format[256];
            sprintf(format, "- %s", $2);
        }
    }
    ;

enumerar_block:
    ENUMERAR { enum_count = 1; } enumerar_items
    { printf("\n"); } // Add extra newline after list
    ;

enumerar_items:
    INDENTED_TEXT NEWLINE
    { 
        printf("1. %s\n", $1);
        enum_count = 2;
        
        // Gerar código LLVM para item enumerado
        if (0) {
            char format[256];
            sprintf(format, "1. %s", $1);
        }
    }
    | enumerar_items INDENTED_TEXT NEWLINE
    { 
        printf("%d. %s\n", enum_count++, $2);
        
        // Gerar código LLVM para item enumerado
        if (0) {
            char format[256];
            sprintf(format, "%d. %s", enum_count-1, $2);
        }
    }
    ;

tarefas_block:
    TAREFAS tarefas_items
    { printf("\n"); } // Add extra newline after list
    ;

tarefas_items:
    STATUS_S NEWLINE
    { 
        printf("- [x] %s\n", $1);
        
        // Gerar código LLVM para tarefa concluída
        if (0) {
            char format[256];
            sprintf(format, "- [x] %s", $1);
        }
    }
    | STATUS_N NEWLINE
    { 
        printf("- [ ] %s\n", $1);
        
        // Gerar código LLVM para tarefa pendente
        if (0) {
            char format[256];
            sprintf(format, "- [ ] %s", $1);
        }
    }
    | STATUS_SIM NEWLINE
    { 
        printf("- [x] %s\n", $1);
        
        // Gerar código LLVM para tarefa concluída
        if (0) {
            char format[256];
            sprintf(format, "- [x] %s", $1);
        }
    }
    | STATUS_NAO NEWLINE
    { 
        printf("- [ ] %s\n", $1);
        
        // Gerar código LLVM para tarefa pendente
        if (0) {
            char format[256];
            sprintf(format, "- [ ] %s", $1);
        }
    }
    | tarefas_items STATUS_S NEWLINE
    { 
        printf("- [x] %s\n", $2);
        
        // Gerar código LLVM para tarefa concluída
        if (0) {
            char format[256];
            sprintf(format, "- [x] %s", $2);
        }
    }
    | tarefas_items STATUS_N NEWLINE
    { 
        printf("- [ ] %s\n", $2);
        
        // Gerar código LLVM para tarefa pendente
        if (0) {
            char format[256];
            sprintf(format, "- [ ] %s", $2);
        }
    }
    | tarefas_items STATUS_SIM NEWLINE
    { 
        printf("- [x] %s\n", $2);
        
        // Gerar código LLVM para tarefa concluída
        if (0) {
            char format[256];
            sprintf(format, "- [x] %s", $2);
        }
    }
    | tarefas_items STATUS_NAO NEWLINE
    { 
        printf("- [ ] %s\n", $2);
        
        // Gerar código LLVM para tarefa pendente
        if (0) {
            char format[256];
            sprintf(format, "- [ ] %s", $2);
        }
    }
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
        }
        printf("```\n\n");
        
        // Gerar código LLVM para bloco de código
        if (0) {
            char* full_code = (char*)malloc(1024);
            strcpy(full_code, "```");
            strcat(full_code, code_lang);
            strcat(full_code, "\n");
            
            for (int i = 0; i < code_line_count; i++) {
                strcat(full_code, code_lines[i]);
                strcat(full_code, "\n");
                free(code_lines[i]);
                code_lines[i] = NULL;
            }
            
            strcat(full_code, "```");
            free(full_code);
        }
        
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
        
        // Gerar código LLVM para imagem
        if (compiler_ctx && saved_alt_text) {
        }
        
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
        
        // Gerar código LLVM para link
        if (compiler_ctx && link_text) {
        }
        
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
            
            // Gerar código LLVM para nota
            if (0) {
                char format[1024];
                sprintf(format, "> *Note:* %s", paragraph_text);
            }
            
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
            
            // Gerar código LLVM para citação
            if (0) {
                char format[1024];
                sprintf(format, "> %s", paragraph_text);
            }
            
            free(paragraph_text);
            paragraph_text = NULL;
        }
    }
    ;

divisor_block:
    DIVISOR NEWLINE
    { 
        printf("---\n\n");
        
        // Gerar código LLVM para divisor
        if (0) {
        }
    }
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
        
        // Para LLVM, vamos gerar uma versão simplificada da tabela
        if (0) {
        }
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
        printf("<!-- Conditional block (simplified) -->\n\n");
        
        // Iniciar a estrutura condicional
        if (0) {
        }
    }
    block
    {
        // Finalizar a estrutura condicional
        if (0) {
        }
    }
    ;

repetir_block:
    REPETIR
    {
        printf("<!-- Repeat block %d times (simplified) -->\n\n", $1);
        
        // Iniciar a estrutura de repetição
        if (0) {
        }
    }
    block
    {
        // Finalizar a estrutura de repetição
        if (0) {
        }
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s na linha %d\n", s, yylineno);
}

// Adicionar função para inicializar o parser com o contexto do compilador
int parse_psl_file(const char* filename, void* ctx) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo %s\n", filename);
        return 1;
    }
    
    // Configurar o contexto do compilador
    compiler_ctx = (int*)ctx;
    
    // Configurar o lexer
    yyin = file;
    
    // Executar o parser
    int result = yyparse();
    
    // Limpar
    fclose(file);
    
    return result;
}