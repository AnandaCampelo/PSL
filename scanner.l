%{
#include "parser.tab.h"
#include <string.h>
#include <stdio.h>

// Debug function
void debug_token(const char* name, const char* value) {
    // Uncomment for verbose debugging
    // fprintf(stderr, "TOKEN: %s = '%s'\n", name, value);
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
^codigo[ \t]+([a-zA-Z0-9]+)[ \t]*\n   { 
                                    yylval.str = strdup(yytext + 7); 
                                    // Remove "codigo " prefix and trailing whitespace/newline
                                    yylval.str[strcspn(yylval.str, " \t\n")] = '\0';
                                    debug_token("CODIGO", yylval.str);
                                    return CODIGO; 
                                  }
^imagem[ \t]*\n                  { debug_token("IMAGEM", yytext); return IMAGEM; }
^divisor[ \t]*\n                 { debug_token("DIVISOR", yytext); return DIVISOR; }
^tabela[ \t]*\n                  { debug_token("TABELA", yytext); return TABELA; }

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

^[ ]{4}([^\n]*)                  { 
                                    yylval.str = strdup(yytext + 4); // Skip 4 spaces
                                    debug_token("INDENTED_TEXT", yylval.str);
                                    return INDENTED_TEXT; 
                                  }

\n                                { debug_token("NEWLINE", "\\n"); return NEWLINE; }

^[ \t]*\n                        { debug_token("BLANK_LINE", "empty"); /* Skip blank lines */ }

[ \t]+                           { /* ignore whitespace */ }
.                                { /* ignore other characters */ }

%%