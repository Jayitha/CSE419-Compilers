
#include<stdbool.h>

typedef enum  astnodetype {
	Program, 
	VarDecls,
	VarDecl, 
	MethodDecls, 
	MethodDecl, 
	MethodArgs, 
	MethodArg, 
	Block,  
	Statements,
	Statement, 
	IfElse,
	MethodCall,
	CalloutArgs,
	Expr,
	Location,
	INTLiteral,
	CHARLiteral,
	BOOLLiteral,
	STRINGLiteral,
	Type,
 } ASTNodeType;

typedef enum programtype {BOTH_PROGRAM, METHOD_DECLS_ONLY_PROGRAM, VAR_DECLS_ONLY_PROGRAM} programType;
typedef enum methodargstype {VOID_METHODARGSTYPE, NONVOID_METHODARGSTYPE, MULTIPLE_METHODARGSTYPE} methodArgsType;
typedef enum methodargtypes {SINGLE_METHODARGTYPE, ARRAY_METHODARGTYPE, MATRIX_METHODARGTYPE} methodArgType;
typedef enum locationtypes {SINGLE_LOCATIONTYPE, ARRAY_LOCATIONTYPE, MATRIX_LOCATIONTYPE} locationType;
typedef enum blocktype {BOTH_BLOCKTYPE, STATEMENTS_ONLY_BLOCKTYPE, VAR_DECLS_ONLY_BLOCKTYPE} blockType;
typedef enum statementtype {ASSIGNMENT_STATEMENTTYPE, METHOD_CALL_STATEMENTTYPE, IFTHENELSE_STATEMENTTYPE, TERNARY_STATEMENTTYPE, WHILE_STATEMENTTYPE, FOR_STATEMENTTYPE,  BLOCK_STATEMENTTYPE} statementType;
typedef enum exprtype {LOCATION_EXPRTYPE, LITERAL_EXPRTYPE, ADD_EXPRTYPE, SUB_EXPRTYPE, MUL_EXPRTYPE, DIV_EXPRTYPE, MOD_EXPRTYPE, LEQ_EXPRTYPE, GEQ_EXPRTYPE, LESSTHAN_EXPRTYPE, GREATERTHAN_EXPRTYPE, EQUALITY_EXPRTYPE, NONEQUALITY_EXPRTYPE, LOGICAL_OR_EXPRTYPE, LOGICAL_AND_EXPRTYPE, UNISUB_EXPRTYPE, LOGICAL_NOT_EXPRTYPE, EXPR_PARAN_EXPRTYPE} exprType;
typedef enum typetype {INT_TYPETYPE, BOOL_TYPETYPE, CHAR_TYPETYPE} typeType;
typedef enum booltype {TRUE_BOOL, FALSE_BOOL} boolType;
extern struct ASTNode *getASTNodeProgram(struct ASTNode *var_decls,
										struct ASTNode *method_decls,
										programType type);

extern struct ASTNode *getASTNodeVarDecls(struct ASTNode *var_decl,
										struct ASTNode *var_decls);

extern struct ASTNode *getASTNodeVarDecl(struct ASTNode *type,
										struct ASTNode *location);

extern struct ASTNode *getASTNodeMethodDecls(struct ASTNode *method_decl,
										struct ASTNode *method_decls);

extern struct ASTNode *getASTNodeMethodDecl(
                                            char *id,
											struct ASTNode *method_args,
										struct ASTNode *block);

extern struct ASTNode *getASTNodeMethodArgs(struct ASTNode *method_arg, struct ASTNode *method_args, methodArgsType type);

extern struct ASTNode *getASTNodeMethodArg(struct ASTNode *id_type, char *id, struct ASTNode *index1, struct ASTNode *index2, methodArgType type);

extern struct ASTNode *getASTNodeBlock(struct ASTNode *var_decls, struct ASTNode *statements, blockType type);

extern struct ASTNode *getASTNodeStatements(struct ASTNode *statement, struct ASTNode *statements);

extern struct ASTNode *getASTNodeStatement(struct ASTNode *arg1, struct ASTNode *arg2, struct ASTNode *arg3, struct ASTNode *arg4, struct ASTNode *arg5, statementType type);

extern struct ASTNode *getASTNodeIfElse(struct ASTNode *ifexpr, struct ASTNode *then, struct ASTNode *elsethen);

extern struct ASTNode *getASTNodeMethodCall(struct ASTNode *functionName, struct ASTNode *args);

extern struct ASTNode *getASTNodeCalloutArgs(struct ASTNode *expr, struct ASTNode *callout_args);

extern struct ASTNode *getASTNodeExpr(struct ASTNode *arg1, struct ASTNode *arg2, exprType type);

extern struct ASTNode *getASTNodeLocation(char *id, struct ASTNode *index1, struct ASTNode *index2, locationType type);

extern struct ASTNode *getASTNodeINTLiteral(int val);

extern struct ASTNode *getASTNodeCHARLiteral(char val);

extern struct ASTNode *getASTNodeBOOLLiteral(boolType type);

extern struct ASTNode *getASTNodeSTRINGLiteral(char* val);

extern struct ASTNode *getASTNodeType(typeType type);

extern void printPostFix(struct ASTNode *root);

extern void printPostFix(struct ASTNode *root);


struct ASTNode {
	ASTNodeType nodetype;

	union {
	    struct ASTProgram {
			struct ASTNode *var_decls;
			struct ASTNode *method_decls;
			programType type;
		} programNode;

		struct ASTVarDecls {
			struct ASTNode *var_decl;
			struct ASTNode *var_decls;
		} varDeclsNode;

		struct ASTVarDecl {
			struct ASTNode *type;
			struct ASTNode *location;
		} varDeclNode;

		struct ASTMethodDecls {
			struct ASTNode *method_decl;
			struct ASTNode *method_decls;
		} methodDeclsNode;

		struct ASTMethodDecl {
			char *id;
			struct ASTNode *method_args;
			struct ASTNode *block;
		} methodDeclNode;

		struct ASTMethodArgs {
			struct ASTNode *method_arg;
			struct ASTNode *method_args;
			methodArgType type;
		} methodArgsNode;

		struct ASTMethodArg {
			struct ASTNode *id_type;
			char *id;
			struct ASTNode *index1;
			struct ASTNode *index2;
			methodArgType type;
		} methodArgNode;

		struct ASTBlock {
			struct ASTNode *var_decls;
			struct ASTNode *statements;
			blockType type;
		} blockNode;

		struct ASTStatements {
			struct ASTNode *statement;
			struct ASTNode *statements;
		} statementsNode;

		struct ASTStatement {
			struct ASTNode *arg1;
			struct ASTNode *arg2;
			struct ASTNode *arg3;
			struct ASTNode *arg4;
			struct ASTNode *arg5;
			statementType type;
		} statementNode;

		struct ASTIfElse {
			struct ASTNode *ifexpr;
			struct ASTNode *then;
			struct ASTNode *elsethen;
		} ifElseNode;

		struct ASTMethodCall {
			struct ASTNode *functionName;
			struct ASTNode *args;
		} methodCallNode;

		struct ASTCalloutArgs {
			struct ASTNode *expr;
			struct ASTNode *callout_args;
		} calloutArgsNode;

		struct ASTExpr {
			struct ASTNode *arg1;
			struct ASTNode *arg2;
			exprType type;
		} exprNode;

		struct ASTLocation {
			char *id;
			struct ASTNode *index1;
			struct ASTNode *index2;
			locationType type;
		} locationNode;
        
		struct ASTBOOLLiteral {
			bool value;
			boolType type;
		} BOOLLiteralNode;

		int intLiteral;
		char charLiteral;
		char *stringLiteral;
		typeType type;
	};

};

