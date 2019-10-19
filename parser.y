%{
    #include<stdio.h>
%}


%token ASSIGN
%token BOOL
%token BREAK
%token CALLOUT
%token CHAR
%token CHAR_LITERAL
%token CLASS
%token CLOSE_ANG
%token CLOSE_CURLY
%token CLOSE_PARAN
%token COLON
%token COMMA
%token CONTINUE
%token DECLARE
%token ELSE
%token FALSE
%token FOR
%token ID
%token IF
%token INT
%token INT_LITERAL
%token OPEN_ANG
%token OPEN_CURLY
%token OPEN_PARAN
%token PROGRAM
%token QM
%token RETURN
%token STRING_LITERAL
%token SEMICOLON
%token TRUE
%token UINT
%token VOID
%token WHILE

%left LOGICAL_OR
%left LOGICAL_AND
%nonassoc EQUALITY NONEQUALITY LESSTHAN GREATERTHAN LEQ GEQ
%right SUB
%left ADD
%left MULTIPLY DIVIDE MODULO
%right LOGICAL_NOT

%%

program: CLASS PROGRAM OPEN_CURLY var_decls method_decls CLOSE_CURLY
       | CLASS PROGRAM OPEN_CURLY method_decls CLOSE_CURLY
;
var_decls: var_decl var_decls
         | var_decl
;
var_decl: DECLARE type location SEMICOLON
;
method_decls: method_decl method_decls
            | method_decl
;
method_decl: return_type ID OPEN_PARAN method_args CLOSE_PARAN block
;
return_type: VOID
           | type
           | type OPEN_ANG INT_LITERAL CLOSE_ANG
           | type OPEN_ANG INT_LITERAL CLOSE_ANG OPEN_ANG INT_LITERAL CLOSE_ANG
;
method_args: VOID
           | method_arg COMMA method_args
           | method_arg
;
method_arg: type ID
          | type ID OPEN_ANG INT_LITERAL CLOSE_ANG
          | type ID OPEN_ANG INT_LITERAL CLOSE_ANG OPEN_ANG INT_LITERAL CLOSE_ANG
;
block: OPEN_CURLY var_decls statements CLOSE_CURLY
     | OPEN_CURLY statements CLOSE_CURLY
;
statements: statement statements
          | statement
;
statement: location ASSIGN expr SEMICOLON
         | method_call SEMICOLON
         | if_else_statment
         | expr QM block COLON block
         | WHILE OPEN_PARAN expr CLOSE_PARAN block
         | FOR OPEN_PARAN ID ASSIGN expr SEMICOLON expr SEMICOLON expr CLOSE_PARAN block
         | RETURN SEMICOLON
         | RETURN OPEN_PARAN expr CLOSE_PARAN SEMICOLON
         | BREAK SEMICOLON
         | CONTINUE SEMICOLON
         | block
;
if_else_statment: IF OPEN_PARAN expr CLOSE_PARAN block
                | IF OPEN_PARAN expr CLOSE_PARAN block ELSE block
;
method_call: CALLOUT OPEN_PARAN STRING_LITERAL CLOSE_PARAN
           | CALLOUT OPEN_PARAN STRING_LITERAL COMMA callout_args CLOSE_PARAN
;
callout_args: expr COMMA callout_args
            | expr
;
expr: location
    | method_call
    | literal
    | expr ADD expr
    | expr SUB expr
    | expr MULTIPLY expr
    | expr DIVIDE expr
    | expr MODULO expr
    | expr LEQ expr
    | expr GEQ expr
    | expr LESSTHAN expr
    | expr GREATERTHAN expr
    | expr EQUALITY expr
    | expr NONEQUALITY expr
    | expr LOGICAL_OR expr
    | expr LOGICAL_AND expr
    | SUB expr
    | LOGICAL_NOT expr
    | OPEN_PARAN expr CLOSE_PARAN
;
location: ID
        | ID OPEN_ANG expr CLOSE_ANG
        | ID OPEN_ANG expr CLOSE_ANG OPEN_ANG expr CLOSE_ANG
;

literal: INT_LITERAL
       | CHAR_LITERAL
       | bool_literal
       | STRING_LITERAL
;
bool_literal: TRUE
            | FALSE
;

type: INT
    | UINT
    | BOOL
    | CHAR
;
%%
yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}
main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");
}

