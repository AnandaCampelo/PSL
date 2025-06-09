%{
#include "parser.tab.h"
#include "common.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Debug function
void debug_token(const char* name, const char* value) {
    fprintf(stderr, "TOKEN: %s = '%s'\n", name, value);
}
%}

%option noyywrap
%option yylineno

%%

^titulo[ \t]*\n                  { debug_token("TITULO", yytext); return TITULO; }
^subtitulo[ \t]*\n               { debug_token("SUBTITULO", yytext); return SUBTITULO; }
^paragrafo[ \t]*\n               { debug_token("PARAGRAFO", yytext); return PARAGRAFO; }
^lista[ \t]*\n                   { debug_token("LISTA", yytext); return LISTA; }
^enumerar[ \t]*\n                { debug_token("ENUMERAR", yytext); return ENUMERAR; }
^tarefas[ \t]*\n                 { debug_token("TAREFAS", yytext); return TAREFAS; }
^citacao[ \t]*\n                 { debug_token("CITACAO", yytext); return CITACAO; }
^codigo[ \t]+([a-zA-Z0-9]+)[ \t]*\n   { 
                                    yylval.str = strdup(yytext + 7); 
                                    // Remove "codigo " prefix and trailing whitespace/newline
                                    yylval.str[strcspn(yylval.str, " \t\n")] = '\0';
                                    debug_token("CODIGO", yylval.str);
                                    return CODIGO; 
                                  }
^imagem[ \t]*\n                  { debug_token("IMAGEM", yytext); return IMAGEM; }
^link[ \t]*\n                    { debug_token("LINK", yytext); return LINK; }
^nota[ \t]*\n                    { debug_token("NOTA", yytext); return NOTA; }
^divisor[ \t]*\n                 { debug_token("DIVISOR", yytext); return DIVISOR; }
^tabela[ \t]*\n                  { debug_token("TABELA", yytext); return TABELA; }

^se[ \t]+[^\n]*\n                { debug_token("SE", yytext); return SE; }
^entao[ \t]*\n                   { debug_token("ENTAO", yytext); return ENTAO; }
^senao[ \t]*\n                   { debug_token("SENAO", yytext); return SENAO; }

^repetir[ \t]+([0-9]+)[ \t]+vezes[ \t]*\n { 
                                    char *temp = strdup(yytext + 8); // Skip "repetir "
                                    char *end = strstr(temp, " vezes");
                                    if (end) *end = '\0';
                                    yylval.num = atoi(temp);
                                    free(temp);
                                    debug_token("REPETIR", yytext);
                                    return REPETIR; 
                                  }

^[ \t]*texto[ \t]+([^\n]*)       { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "texto"
                                    start += 5;
                                    
                                    // Skip whitespace after "texto"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("TEXTO", yylval.str);
                                    return TEXTO; 
                                  }

^[ \t]*url[ \t]+([^\n]*)         { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "url"
                                    start += 3;
                                    
                                    // Skip whitespace after "url"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("URL", yylval.str);
                                    return URL; 
                                  }

^[ \t]*cabecalho[ \t]+([^\n]*)   { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "cabecalho"
                                    start += 9;
                                    
                                    // Skip whitespace after "cabecalho"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("CABECALHO", yylval.str);
                                    return CABECALHO; 
                                  }

^[ \t]*alt[ \t]+([^\n]*)         { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "alt"
                                    start += 3;
                                    
                                    // Skip whitespace after "alt"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("ALT", yylval.str);
                                    return ALT; 
                                  }

^[ \t]*src[ \t]+([^\n]*)         { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "src"
                                    start += 3;
                                    
                                    // Skip whitespace after "src"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("SRC", yylval.str);
                                    return SRC; 
                                  }

^[ \t]*s[ \t]+([^\n]*)           { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "s"
                                    start += 1;
                                    
                                    // Skip whitespace after "s"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("STATUS_S", yylval.str);
                                    return STATUS_S; 
                                  }

^[ \t]*n[ \t]+([^\n]*)           { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "n"
                                    start += 1;
                                    
                                    // Skip whitespace after "n"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("STATUS_N", yylval.str);
                                    return STATUS_N; 
                                  }

^[ \t]*sim[ \t]+([^\n]*)         { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "sim"
                                    start += 3;
                                    
                                    // Skip whitespace after "sim"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("STATUS_SIM", yylval.str);
                                    return STATUS_SIM; 
                                  }

^[ \t]*não[ \t]+([^\n]*)         { 
                                    char *temp = strdup(yytext);
                                    char *start = temp;
                                    
                                    // Skip initial whitespace
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    // Skip "não"
                                    start += 3;
                                    
                                    // Skip whitespace after "não"
                                    while(*start && (*start == ' ' || *start == '\t')) start++;
                                    
                                    yylval.str = strdup(start);
                                    free(temp);
                                    debug_token("STATUS_NAO", yylval.str);
                                    return STATUS_NAO; 
                                  }

^[ ]{4}([^\n]*)                  { 
                                    yylval.str = strdup(yytext + 4); // Skip 4 spaces
                                    debug_token("INDENTED_TEXT", yylval.str);
                                    return INDENTED_TEXT; 
                                  }

\n                                { debug_token("NEWLINE", "\\n"); return NEWLINE; }

^[ \t]*\n                        { debug_token("BLANK_LINE", "empty"); /* Skip blank lines */ }

[ \t]+                           { /* ignore whitespace */ }
.                                { /* ignore other characters */ }

<<EOF>>                          { debug_token("EOF", "end of file"); return 0; }

%%