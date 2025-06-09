/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INDENTED_TEXT = 258,           /* INDENTED_TEXT  */
    CODIGO = 259,                  /* CODIGO  */
    CABECALHO = 260,               /* CABECALHO  */
    ALT = 261,                     /* ALT  */
    SRC = 262,                     /* SRC  */
    STATUS_S = 263,                /* STATUS_S  */
    STATUS_N = 264,                /* STATUS_N  */
    TEXTO = 265,                   /* TEXTO  */
    URL = 266,                     /* URL  */
    STATUS_SIM = 267,              /* STATUS_SIM  */
    STATUS_NAO = 268,              /* STATUS_NAO  */
    REPETIR = 269,                 /* REPETIR  */
    OP_REL = 270,                  /* OP_REL  */
    TITULO = 271,                  /* TITULO  */
    SUBTITULO = 272,               /* SUBTITULO  */
    PARAGRAFO = 273,               /* PARAGRAFO  */
    LISTA = 274,                   /* LISTA  */
    ENUMERAR = 275,                /* ENUMERAR  */
    TAREFAS = 276,                 /* TAREFAS  */
    IMAGEM = 277,                  /* IMAGEM  */
    DIVISOR = 278,                 /* DIVISOR  */
    TABELA = 279,                  /* TABELA  */
    LINK = 280,                    /* LINK  */
    NOTA = 281,                    /* NOTA  */
    CITACAO = 282,                 /* CITACAO  */
    ENTAO = 283,                   /* ENTAO  */
    SENAO = 284,                   /* SENAO  */
    NEWLINE = 285,                 /* NEWLINE  */
    SE = 286                       /* SE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"

    char *str;
    int num;
    int op;  // Changed from op_type to int for compatibility

#line 101 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
