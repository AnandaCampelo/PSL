%{
#include "psl.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%
"✍️"          return USER;
"🛑"          return END;
"✋"          return DECLARE;
"💅"          return NUMTYPE;
"📜"          return STRTYPE;   // Usamos 📜 para evitar conflito com ✍️
"👉"          return ASSIGN;
"👆"          return ADD;
"👇"          return SUB;
"🫴"          return MULT;
"🫳"          return DIV;
"☝️"          return PRINT;
"🫵"          return INPUT;
"🤝"          return BIND;
"✊"          return IF;
"🤌"          return WHILE;
"🖐️"          return BLOCK_START;
"🖐️"          return BLOCK_END;
"🦾"          return SEARCH;
"🪬"          return HISTORY;

"👏"          return EQ;
"👋"          return NEQ;
"🤜"          return GT;
"🤛"          return LT;
"🤜🤏"        return GTE;
"🤛🤏"        return LTE;

\"[^\"]*\"    {
    yytext[yyleng - 1] = '\0';               // remove aspas finais
    yylval.str = strdup(yytext + 1);         // ignora aspas iniciais
    return STRING;
}
[0-9]+        { yylval.num = atoi(yytext); return NUMBER; }
[A-Za-z_][A-Za-z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }

[ \t\n]+      ;  // Ignora espaços
.             { printf("Caractere inesperado: %s\n", yytext); return -1; }
%%