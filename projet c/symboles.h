/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_SYMBOLES_H_INCLUDED
# define YY_YY_SYMBOLES_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    FIN = 0,                       /* FIN  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIANT = 258,             /* IDENTIFIANT  */
    EGALE = 259,                   /* EGALE  */
    PLUS = 260,                    /* PLUS  */
    MOINS = 261,                   /* MOINS  */
    FOIS = 262,                    /* FOIS  */
    TYPE_ENTIER = 263,             /* TYPE_ENTIER  */
    PARENTHESE_OUVRANTE = 264,     /* PARENTHESE_OUVRANTE  */
    PARENTHESE_FERMANTE = 265,     /* PARENTHESE_FERMANTE  */
    POINT_VIRGULE = 266,           /* POINT_VIRGULE  */
    SI = 267,                      /* SI  */
    LE = 268,                      /* LE  */
    GE = 269,                      /* GE  */
    GT = 270,                      /* GT  */
    OU = 271,                      /* OU  */
    ET = 272,                      /* ET  */
    RETOURNER = 273,               /* RETOURNER  */
    ENTIER = 274,                  /* ENTIER  */
    ECRIRE = 275,                  /* ECRIRE  */
    TYPE_BOOLEEN = 276,            /* TYPE_BOOLEEN  */
    VRAI = 277,                    /* VRAI  */
    FAUX = 278,                    /* FAUX  */
    TANTQUE = 279,                 /* TANTQUE  */
    NON = 280,                     /* NON  */
    DIVISER = 281,                 /* DIVISER  */
    MODULO = 282,                  /* MODULO  */
    SINON = 283,                   /* SINON  */
    LT = 284,                      /* LT  */
    BLOC_OUVRANT = 285,            /* BLOC_OUVRANT  */
    BLOC_FERMANT = 286,            /* BLOC_FERMANT  */
    VIRGULE = 287                  /* VIRGULE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "analyse_syntaxique.y"

    int entier;
    n_programme* prog;
    n_l_instructions* l_inst;
    n_instruction* inst;
    l_expr* l_exp;
    n_exp* exp;
    n_parm* parm;
    l_parm* l_parm;
    char* string;

#line 108 "symboles.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYMBOLES_H_INCLUDED  */
