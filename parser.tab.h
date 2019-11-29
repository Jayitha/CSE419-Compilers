/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    BOOL = 259,
    CALLOUT = 260,
    CHAR = 261,
    CHAR_LITERAL = 262,
    CLOSE_ANG = 263,
    CLOSE_CURLY = 264,
    CLOSE_PARAN = 265,
    COLON = 266,
    COMMA = 267,
    DECLARE = 268,
    ELSE = 269,
    FALSE = 270,
    FOR = 271,
    ID = 272,
    IF = 273,
    INT = 274,
    INT_LITERAL = 275,
    OPEN_ANG = 276,
    OPEN_CURLY = 277,
    OPEN_PARAN = 278,
    PROGRAM = 279,
    QM = 280,
    STRING_LITERAL = 281,
    SEMICOLON = 282,
    TRUE = 283,
    VOID = 284,
    WHILE = 285,
    LOGICAL_OR = 286,
    LOGICAL_AND = 287,
    EQUALITY = 288,
    NONEQUALITY = 289,
    LESSTHAN = 290,
    GREATERTHAN = 291,
    LEQ = 292,
    GEQ = 293,
    SUB = 294,
    ADD = 295,
    MULTIPLY = 296,
    DIVIDE = 297,
    MODULO = 298,
    LOGICAL_NOT = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  struct ASTNode *  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
