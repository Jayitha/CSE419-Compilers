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
    BREAK = 260,
    CALLOUT = 261,
    CHAR = 262,
    CHAR_LITERAL = 263,
    CLASS = 264,
    CLOSE_ANG = 265,
    CLOSE_CURLY = 266,
    CLOSE_PARAN = 267,
    COLON = 268,
    COMMA = 269,
    CONTINUE = 270,
    DECLARE = 271,
    ELSE = 272,
    FALSE = 273,
    FOR = 274,
    ID = 275,
    IF = 276,
    INT = 277,
    INT_LITERAL = 278,
    OPEN_ANG = 279,
    OPEN_CURLY = 280,
    OPEN_PARAN = 281,
    PROGRAM = 282,
    QM = 283,
    RETURN = 284,
    STRING_LITERAL = 285,
    SEMICOLON = 286,
    TRUE = 287,
    UINT = 288,
    VOID = 289,
    WHILE = 290,
    LOGICAL_OR = 291,
    LOGICAL_AND = 292,
    EQUALITY = 293,
    NONEQUALITY = 294,
    LESSTHAN = 295,
    GREATERTHAN = 296,
    LEQ = 297,
    GEQ = 298,
    SUB = 299,
    ADD = 300,
    MULTIPLY = 301,
    DIVIDE = 302,
    MODULO = 303,
    LOGICAL_NOT = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
