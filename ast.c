#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

struct ASTNode *getASTNodeProgram(struct ASTNode *var_decls,
										struct ASTNode *method_decls,
										programType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Program;
	node->programNode.var_decls = var_decls;
	node->programNode.method_decls = method_decls;
	node->programNode.type = type;

	return node;
}

struct ASTNode *getASTNodeVarDecls(struct ASTNode *var_decl,
										struct ASTNode *var_decls)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = VarDecls;
	node->varDeclsNode.var_decl = var_decl;
	node->varDeclsNode.var_decls = var_decls;

	return node;
}

struct ASTNode *getASTNodeVarDecl(struct ASTNode *type,
										struct ASTNode *location)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = VarDecl;
	node->varDeclNode.type = type;
	node->varDeclNode.location = location;

	return node;
}				

struct ASTNode *getASTNodeMethodDecls(struct ASTNode *method_decl,
										struct ASTNode *method_decls)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = MethodDecls;
	node->methodDeclsNode.method_decl = method_decl;
	node->methodDeclsNode.method_decls = method_decls;

	return node;
}

struct ASTNode *getASTNodeMethodDecl(char *id,
											struct ASTNode *method_args,
										struct ASTNode *block)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = MethodDecl;
	node->methodDeclNode.id = strdup(id);
	node->methodDeclNode.method_args = method_args;
	node->methodDeclNode.block = block;

	return node;
}

struct ASTNode *getASTNodeMethodArgs(struct ASTNode *method_arg, struct ASTNode *method_args, methodArgsType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = MethodArgs;
	node->methodArgsNode.method_arg = method_arg;
	node->methodArgsNode.method_args = method_args;
	node->methodArgsNode.type = type;
	return node;
}

struct ASTNode *getASTNodeMethodArg(struct ASTNode *id_type, char *id, struct ASTNode *index1, struct ASTNode *index2, methodArgType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = MethodArg;
	node->methodArgNode.id_type = id_type;
	node->methodArgNode.id = id;
	node->methodArgNode.index1 = index1;
	node->methodArgNode.index2 = index2;
	node->methodArgNode.type = type;
	return node;
}

struct ASTNode *getASTNodeBlock(struct ASTNode *var_decls, struct ASTNode *statements, blockType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Block;
	node->blockNode.var_decls = var_decls;
	node->blockNode.statements = statements;
	node->blockNode.type = type;
	return node;
}

struct ASTNode *getASTNodeStatements(struct ASTNode *statement, struct ASTNode *statements)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Statements;
	node->statementsNode.statement = statement;
	node->statementsNode.statements = statements;
	return node;
}

struct ASTNode *getASTNodeStatement(struct ASTNode *arg1, struct ASTNode *arg2, struct ASTNode *arg3, struct ASTNode *arg4, struct ASTNode *arg5, statementType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Statement;
	node->statementNode.arg1 = arg1;
	node->statementNode.arg2 = arg2;
	node->statementNode.arg3 = arg3;
	node->statementNode.arg4 = arg4;
	node->statementNode.arg5 = arg5;
	node->statementNode.type = type;
	return node;
}

struct ASTNode *getASTNodeIfElse(struct ASTNode *ifexpr, struct ASTNode *then, struct ASTNode *elsethen)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = IfElse;
	node->ifElseNode.ifexpr = ifexpr;
	node->ifElseNode.then = then;
	node->ifElseNode.elsethen = elsethen;
	return node;
}

struct ASTNode *getASTNodeMethodCall(struct ASTNode *functionName, struct ASTNode *args)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = MethodCall;
	node->methodCallNode.functionName = functionName;
	node->methodCallNode.args = args;
	return node;
}

struct ASTNode *getASTNodeCalloutArgs(struct ASTNode *expr, struct ASTNode *callout_args)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = CalloutArgs;
	node->calloutArgsNode.expr = expr;
	node->calloutArgsNode.callout_args = callout_args;
	return node;
}

struct ASTNode *getASTNodeExpr(struct ASTNode *arg1, struct ASTNode *arg2, exprType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Expr;
	node->exprNode.arg1 = arg1;
	node->exprNode.arg2 = arg2;
	node->exprNode.type = type;
	return node;
}

struct ASTNode *getASTNodeLocation(char *id, struct ASTNode *index1, struct ASTNode *index2, locationType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Location;
	node->locationNode.id = strdup(id);
	node->locationNode.index1 = index1;
	node->locationNode.index2 = index2;
	node->locationNode.type = type;
	return node;
}

struct ASTNode *getASTNodeINTLiteral(int val)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = INTLiteral;
	node->intLiteral = val;
	return node;
}

struct ASTNode *getASTNodeCHARLiteral(char val)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = CHARLiteral;
	node->charLiteral = val;
	return node;
}

struct ASTNode *getASTNodeBOOLLiteral(boolType val)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = BOOLLiteral;
    switch(val)
	{
		case TRUE_BOOL: node->BOOLLiteralNode.value = true;
		                break;
		case FALSE_BOOL: node->BOOLLiteralNode.value = false;
		                break;
	}
	node->BOOLLiteralNode.type = val;
	return node;
}

struct ASTNode *getASTNodeSTRINGLiteral(char* val)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = STRINGLiteral;
	node->stringLiteral=strdup(val);
	return node;
}

struct ASTNode *getASTNodeType(typeType type)
{
	struct ASTNode *node;
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Type;
	node->type = type;
	return node;
}

void printPostFix(struct ASTNode *root)
{
	if(root==NULL)
	    return;
	switch (root->nodetype) 
	{
		case Program:
		{
			printPostFix(root->programNode.var_decls);
			printPostFix(root->programNode.method_decls);
			break;
		}

		case VarDecls:
		{
			printPostFix(root->varDeclsNode.var_decl);
			printPostFix(root->varDeclsNode.var_decls);
			break;
		}

		case VarDecl:
		{
			printPostFix(root->varDeclNode.type);
			printPostFix(root->varDeclNode.location);
			printf(" -> VARIABLE_DECLARATION\n");
			break;
		}

		case MethodDecls:
		{
			printPostFix(root->methodDeclsNode.method_decl);
			printPostFix(root->methodDeclsNode.method_decls);
			break;
		}

		case MethodDecl:
		{
			printf(" %s -> ID\n",root->methodDeclNode.id);
			printPostFix(root->methodDeclNode.method_args);
			printPostFix(root->methodDeclNode.block);
			printf(" -> METHOD_DECLARATION\n");
			break;
		}

		case MethodArgs:
		{
			printPostFix(root->methodArgsNode.method_arg);
			printPostFix(root->methodArgsNode.method_args);
			break;
		}

		case MethodArg:
		{
			printPostFix(root->methodArgNode.id_type);
			// printf(" %s -> ID\n",root->methodArgNode.id);
			printPostFix(root->methodArgNode.index1);
			printPostFix(root->methodArgNode.index2);
			printf(" -> METHOD_ARGS\n");
			break;
		}

		case Block:
		{
			printPostFix(root->blockNode.var_decls);
			printPostFix(root->blockNode.statements);
			printf(" -> BLOCK\n");
			break;
		}

		case Statements:
		{
			printPostFix(root->statementsNode.statement);
			printPostFix(root->statementsNode.statements);
			break;
		}

		case Statement:
		{
			printPostFix(root->statementNode.arg1);
			printPostFix(root->statementNode.arg2);
			printPostFix(root->statementNode.arg3);
			printPostFix(root->statementNode.arg4);
			printPostFix(root->statementNode.arg5);
			switch(root->statementNode.type)
			{
				case ASSIGNMENT_STATEMENTTYPE: printf(" -> ASSIGNMENT_STATEMENT\n");break;
				//case METHOD_CALL_STATEMENTTYPE: printf(" -> METHOD_CALL_STATEMENT\n");break;
				//case IFTHENELSE_STATEMENTTYPE: printf(" -> IFTHENELSE_STATEMENT\n");break;
				case TERNARY_STATEMENTTYPE: printf(" -> TERNARY_STATEMENT\n");break;
				case WHILE_STATEMENTTYPE: printf(" -> WHILE_STATEMENT\n");break;
				case FOR_STATEMENTTYPE: printf(" -> FOR_STATEMENT\n");break;
				//case BLOCK_STATEMENTTYPE: printf(" -> BLOCK_STATEMENT\n");break;
				default: break;
			}
			break;
		}

		case IfElse:
		{
			printPostFix(root->ifElseNode.ifexpr);
			printPostFix(root->ifElseNode.then);
			printPostFix(root->ifElseNode.elsethen);
			printf(" -> IF_ELSE_STATEMENT\n");
			break;
		}

		case MethodCall:
		{
			printPostFix(root->methodCallNode.functionName);
			printPostFix(root->methodCallNode.args);
			printf(" -> METHOD_CALL\n");
			break;
		}

		case CalloutArgs:
		{
			printPostFix(root->calloutArgsNode.expr);
			printPostFix(root->calloutArgsNode.callout_args);
			break;
		}

		case Expr:
		{
			printPostFix(root->exprNode.arg1);
			printPostFix(root->exprNode.arg2);
			switch(root->exprNode.type)
			{
				case LOCATION_EXPRTYPE: printf(" -> LOCATION_EXPRESSION\n");break;
				case LITERAL_EXPRTYPE: printf(" -> LITERAL_EXPRESSION\n");break;
				case ADD_EXPRTYPE: printf(" -> ADD_EXPRESSION\n");break;
				case SUB_EXPRTYPE: printf(" -> SUB_EXPRESSION\n");break;
				case MUL_EXPRTYPE: printf(" -> MUL_EXPRESSION\n");break;
				case DIV_EXPRTYPE: printf(" -> DIV_EXPRESSION\n");break;
				case MOD_EXPRTYPE: printf(" -> MOD_EXPRESSION\n");break;
				case LEQ_EXPRTYPE: printf(" -> LEQ_EXPRESSION\n");break;
				case GEQ_EXPRTYPE: printf(" -> GEQ_EXPRESSION\n");break;
				case LESSTHAN_EXPRTYPE: printf(" -> LESSTHAN_EXPRESSION\n");break;
				case GREATERTHAN_EXPRTYPE: printf(" -> GREATERTHAN_EXPRESSION\n");break;
				case EQUALITY_EXPRTYPE: printf(" -> EQUALITY_EXPRESSION\n");break;
				case NONEQUALITY_EXPRTYPE: printf(" -> NONEQUALITY_EXPRESSION\n");break;
				case LOGICAL_OR_EXPRTYPE: printf(" -> LOGICAL_OR_EXPRESSION\n");break;
				case LOGICAL_AND_EXPRTYPE: printf(" -> LOGICAL_AND_EXPRESSION\n");break;
				case UNISUB_EXPRTYPE: printf(" -> UNISUB_EXPRESSION\n");break;
				case LOGICAL_NOT_EXPRTYPE: printf(" -> LOGICAL_NOT_EXPRESSION\n");break;
				case EXPR_PARAN_EXPRTYPE: printf(" -> EXPR_PARAN_EXPRESSION\n");break;
			}
			break;
		}

		case Location:
		{
			printf(" %s -> ID\n",root->locationNode.id);
			printPostFix(root->locationNode.index1);
			printPostFix(root->locationNode.index2);
			break;
		}

		case INTLiteral:
		{
			printf(" %d -> INT_LITERAL\n",root->intLiteral);
			break;
		}
		case CHARLiteral:
		{
			printf(" %c -> CHAR_LITERAL\n", root->charLiteral);
			break;
		}
		case BOOLLiteral:
		{
			switch(root->BOOLLiteralNode.type)
			{
				case TRUE_BOOL: printf(" TRUE -> BOOL_LIT\n");
				                break;
				case FALSE_BOOL: printf(" FALSE -> BOOL_LIT\n");
				                break;
			}
			break;
		}
        case STRINGLiteral:
		{
			printf(" %s -> STRING_LITERAL\n", root->stringLiteral);
			break;
		}
		case Type:
		{
			switch(root->type)
			{
				case INT_TYPETYPE: printf("INT_TYPE\n");break;
				case BOOL_TYPETYPE: printf("BOOL_TYPE\n");break;
				case CHAR_TYPETYPE: printf("CHAR_TYPE\n");break;
			}
		}
	}
}






