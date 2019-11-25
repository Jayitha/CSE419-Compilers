// Symbol Table
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

typedef enum symboltype {DATA, FUNCTION} symbolType;

typedef enum datatype {INT_DATATYPE, CHAR_DATATYPE, BOOL_DATATYPE,  INT_1D_DATATYPE, INT_2D_DATATYPE, CHAR_1D_DATATYPE, CHAR_2D_DATATYPE, BOOL_1D_DATATYPE, BOOL_2D_DATATYPE} dataType;

struct dataSymbolNode {
        dataType type;
	    int index1;
	    int index2;
	    union{
            int intval;
            char charval;
            bool boolval;
            int *intarr;
            char *chararr;
            bool *boolarr; 
        };
};

struct functionSymbolNode{
			int numOfArgs;
            struct symbolNode *front;
			struct ASTNode* block;
};

struct symbolNode {
	char* id;
	symbolType stype;
	struct symbolNode *next;
	union{
		struct dataSymbolNode dataNode;
        struct functionSymbolNode functionNode;
	};
};

struct symbolTableStack {
	struct symbolNode * front;
	struct symbolTableStack * next;
};

struct symbolTableStack * symbolTable = NULL;
struct symbolTableStack * current = NULL;
struct symbolTableStack * previous = NULL;
struct symbolNode * functionArgPointer = NULL;

struct symbolNode * newData(char* id, dataType type, int index1, int index2)
{
	struct symbolNode *node = (struct symbolNode *)malloc(sizeof(struct symbolNode));
	node->id=id;
	node->stype = DATA;
	node->dataNode.type = type;
	node->dataNode.index1 = index1;
    node->dataNode.index2 = index2;
	node->next=NULL;
	switch(node->dataNode.type)
	{
        case INT_DATATYPE: node->dataNode.intval = 0; break;
        case UINT_DATATYPE: node->dataNode.uintval = 0; break;
        case CHAR_DATATYPE: node->dataNode.charval = ' '; break;
        case BOOL_DATATYPE: node->dataNode.boolval = false; break;
        case INT_1D_DATATYPE: {
            node->dataNode.intarr = (int *)malloc(index1*sizeof(int));
            int i = 0;
            for(i=0; i<index1; i = i + 1)
                *(node->dataNode.intarr + i) = 0;
            break;
        }
        case UINT_1D_DATATYPE: {
            node->dataNode.uintarr = (unsigned int *)malloc(index1*sizeof(unsigned int));
            int i = 0;
            for(i=0; i<index1; i = i + 1)
                *(node->dataNode.uintarr + i) = 0;
            break;
        }
        case CHAR_1D_DATATYPE: {
            node->dataNode.chararr = (char *)malloc(index1*sizeof(char));
            int i = 0;
            for(i=0; i<index1; i = i + 1)
                *(node->dataNode.chararr + i) = ' ';
            break;
        }
        case BOOL_1D_DATATYPE: {
            node->dataNode.boolarr = (bool *)malloc(index1*sizeof(bool));
            int i = 0;
            for(i=0; i<index1; i = i + 1)
                *(node->dataNode.boolarr + i) = false;
            break;
        }
        case INT_2D_DATATYPE: {
            node->dataNode.intarr = (int *)malloc(index2*index1*sizeof(int));
            int i = 0;
            int j = 0;
            for(i=0; i<index1; i = i + 1)
                for(j=0; j<index2; j = j+ 1)
                    *(node->dataNode.intarr*i + j) = 0;
            break;
        }
        case UINT_2D_DATATYPE: {
            node->dataNode.uintarr = (unsigned int *)malloc(index2*index1*sizeof(unsigned int));
            int i = 0;
            int j = 0;
            for(i=0; i<index1; i = i + 1)
                for(j=0; j<index2; j = j+ 1)
                    *(node->dataNode.uintarr*i + j) = 0;
            break;
        }
        case CHAR_2D_DATATYPE: {
            node->dataNode.chararr = (char *)malloc(index2*index1*sizeof(char));
            int i = 0;
            int j = 0;
            for(i=0; i<index1; i = i + 1)
                for(j=0; j<index2; j = j+ 1)
                    *(node->dataNode.chararr*i + j) = ' ';
            break;
        }
        case BOOL_2D_DATATYPE: {
            node->dataNode.boolarr = (bool *)malloc(index2*index1*sizeof(bool));
            int i = 0;
            int j = 0;
            for(i=0; i<index1; i = i + 1)
                for(j=0; j<index2; j = j+ 1)
                    *(node->dataNode.boolarr*i + j) = false;
            break;
        }

    }

	return node;
}

struct symbolNode * newFunction(char *id, struct ASTNode *block)
{
	struct symbolNode* node = (struct symbolNode *)malloc(sizeof(struct symbolNode));
    node->id = id;
	node->stype = FUNCTION;
	node->functionNode.front = NULL;
	node->functionNode.numOfArgs = 0;
	node->next=NULL;
	node->functionNode.block = block;
	return node;
}

void deleteSymbolTable(struct symbolTableStack* root)
{
	struct symbolNode *temp1 = root->front;
	struct symbolNode *temp2 = NULL;
	root->front=NULL;
	while(temp1!=NULL)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	free(root);
}

struct symbolNode * findSymbolNode(char *id, symbolType type)
{
    //Finds latest occurance of a symbol in the symbol stack
    struct symbolTableStack* temp = symbolTable;
    struct symbolNode* found = NULL;
    while(temp!=NULL)
	{
		struct symbolNode* temp1 = temp->front;
		while(temp1!=NULL)
		{
			if(temp1->stype==type && strcmp(temp1->id, id)==0)
			    found = temp1;
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
    if(found==NULL)
	{
		printf("Error: Undeclared Variable or Function or out of scope");
		exit(0);
	}
    return(found);
}

bool checkExists(char *id)
{
    //checks to see if symbol exists in latest stack for declaration purposes
	if(current == NULL || current->front==NULL)
	    return true;
    struct symbolNode *temp = current->front;
    while(temp!=NULL)
    {
        if(strcmp(temp->id,id)==0)
            return true;
        temp=temp->next;
    }
    return false;
}

union result{
	int intval;
	bool boolval;
	char charval;
	int *intarr;
	char *chararr;
	bool *boolarr;
};

union result* evaluate(struct ASTNode *root)
{
	if(root==NULL)
	    return NULL;
	switch(root->nodetype)
	{
		case Program:{
            symbolTable->front=NULL;
			evaluate(root->programNode.var_decls);
			evaluate(root->programNode.method_decls);
			break;
		}
		case VarDecls:{
			evaluate(root->varDeclsNode.var_decl);
			evaluate(root->varDeclsNode.var_decls);
			break;
		}
		case VarDecl:{
			struct ASTNode *location = root->varDeclNode.location;
            if(checkExists(location->locationNode.id)
            {
                printf("Error: Redeclaration of variable within same scope");
                exit(0);
            }
            int index1 = 1, index2 = 1;
			if(location->locationNode.index1!=NULL)
			{
				union result *r = evaluate(location->locationNode.index1);
			    index1 = r->intval;
				free(r);
			}
			if(location->locationNode.index2!=NULL)
            {
				union result *r = evaluate(location->locationNode.index1);
			    index1 = r->intval;
				free(r);
			}
            if(index1 <= 0 || index2 <= 0)
            {
                printf("Error: cannot have negative indeces");
                exit(0);
            }

			int flag = 0;
            switch(location->locationNode.type)
			{
				case ARRAY_LOCATIONTYPE: flag = 1; break;
				case MATRIX_LOCATIONTYPE: flag = 2; break;
			}
            
			dataType argtype;
			switch(root->varDeclNode.type->type)
			{
				case INT_TYPETYPE: {
                    switch(flag)
                    {
                        case 0: argtype = INT_DATATYPE; break;
                        case 1: argtype = INT_1D_DATATYPE; break;
                        case 2: argtype = INT_2D_DATATYPE; break;
                    }
                    break;
                }
                case CHAR_TYPETYPE: {
                    switch(flag)
                    {
                        case 0: argtype = CHAR_DATATYPE; break;
                        case 1: argtype = CHAR_1D_DATATYPE; break;
                        case 2: argtype = CHAR_2D_DATATYPE; break;
                    }
                    break;
                }
                case BOOL_TYPETYPE: {
                    switch(flag)
                    {
                        case 0: argtype = BOOL_DATATYPE; break;
                        case 1: argtype = BOOL_1D_DATATYPE; break;
                        case 2: argtype = BOOL_2D_DATATYPE; break;
                    }
                    break;
                }
			}
			
			struct symbolNode *temp = newData(location->locationNode.id, argtype, index1, index2);

			if(symbolTable==NULL)
			{
				symbolTable = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			    symbolTable->front = temp;
				current = symbolTable;
			}
			else if(current->front==NULL)
			    current->front = temp;
			else{
                temp->next = current->front;
			    current->front = temp;
			}
			if(previous!=NULL)
			    previous->next = current->front;
			break;
		}

        case MethodDecls:{
			evaluate(root->methodDeclsNode.method_decl);
			evaluate(root->methodDeclsNode.method_decls);
			break;
		}

		case MethodDecl:{
            if(checkExists(root->methodDeclNode.id)
            {
                printf("Error: Redeclaration of function within same scope");
                exit(0);
            }
			struct symbolNode * temp = newFunction(root->methodDeclNode.id,root->methodDeclNode.block);
			if(symbolTable==NULL)
			{
				symbolTable = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			    symbolTable->front = temp;
				current = symbolTable;
			}
			else if(current->front==NULL)
			    current->front = temp;
			else{
                temp->next = current->front;
			    current->front = temp;
			}
			if(previous!=NULL)
			    previous->next = current->front;
            evaluate(root->methodDeclNode.method_args);
			break;
		}
		case MethodArgs:{
			if(root->methodArgsNode.type!=VOID_METHODARGSTYPE)
			{
				evaluate(root->methodArgsNode.method_arg);
				evaluate(root->methodArgsNode.method_args);
			}
			break;
		}

		case MethodArg:{

			dataType type;

            int flag = 0;
            switch(root->methodArgNode.type)
			{
				case ARRAY_METHODARGTYPE: flag = 1; break;
				case MATRIX_METHODARGTYPE: flag = 2; break;
			}

			int index1 = 0, index2 = 0;
			if(root->methodArgNode.index1!=NULL)
			    index1 = root->methodArgNode.index1->intLiteral;
			if(root->methodArgNode.index2!=NULL)
			    index2 = root->methodArgNode.index2->intLiteral;

			switch(root->methodArgNode.id_type->type)
			{
				case INT_TYPETYPE: {
                    switch(flag)
                    {
                        case 0: type = INT_DATATYPE; break;
                        case 1: type = INT_1D_DATATYPE; break;
                        case 2: type = INT_2D_DATATYPE; break;
                    }
                    break;
                }
                case CHAR_TYPETYPE: {
                    switch(flag)
                    {
                        case 0: type = CHAR_DATATYPE; break;
                        case 1: type = CHAR_1D_DATATYPE; break;
                        case 2: type = CHAR_2D_DATATYPE; break;
                    }
                    break;
                }
                case BOOL_TYPETYPE: {
                    switch(flag)
                    {
                        case 0: type = BOOL_DATATYPE; break;
                        case 1: type = BOOL_1D_DATATYPE; break;
                        case 2: type = BOOL_2D_DATATYPE; break;
                    }
                    break;
                }
			}

			struct symbolNode * newtemp = newData(root->methodArgNode.id, type, index1, index2);
            struct symbolNode *temp = current->front->functionNode.front;
			current->front->functionNode.numOfArgs = current->front->functionNode.numOfArgs + 1;
			while(temp->next!=NULL)
			    temp = temp->next;
			temp->next = newtemp; 
		}

		case Block:{
			struct symbolTableStack * temp = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			current->next = temp;
			temp->front = NULL;
			temp->next = NULL;
            previous = current;
			current = temp;

			evaluate(root->blockNode.var_decls);
			evaluate(root->blockNode.statements);

			temp = symbolTable;
			while(temp->next!=parent)
		        temp = temp->next;
			deleteSymbolTable(current);
			current = parent;
			current->next = NULL;
			parent = temp;
			break;
		}

		case Statements:{
			evaluate(root->statementsNode.statement);
			evaluate(root->statementsNode.statements);
			break;
		}

		case Statement:{
			switch(root->statementNode.type)
			{
				case ASSIGNMENT_STATEMENTTYPE:{

					char *id;
					strcpy(id,root->statementNode.arg1->locationNode.id);

					struct symbolNode* found=NULL;
                    found = findSymbolNode(id, DATA);

					int index1 = 0, index2 = 0;

					if(root->statementNode.arg1->locationNode.index1!=NULL)
					    index1 = evaluate(root->statementNode.arg1->locationNode.index1)->intval;
					if(root->statementNode.arg1->locationNode.index2!=NULL)
					    index2 = evaluate(root->statementNode.arg1->locationNode.index2)->intval;
					if(index1 >= found->dataNode.index1 || index2 >= found->dataNode.index2 || index1 < 0 || index2 < 0)
					{
						printf("Error: Index out of range");
						exit(0);
					}
					union result * r = evaluate(root->statementNode.arg2);

					switch(found->dataNode.type)
					{
						case INT_DATATYPE: found->dataNode.intval = r->intval; break;
						case CHAR_DATATYPE: found->dataNode.charval = r->charval; break;
						case BOOL_DATATYPE: found->dataNode.boolval = r->boolval; break;
						case INT_1D_DATATYPE: *(found->dataNode.intarr + index1) = r->intval; break;
						case CHAR_1D_DATATYPE: *(found->dataNode.chararr + index1) = r->charval; break;
						case BOOL_1D_DATATYPE: *(found->dataNode.boolarr + index1) = r->boolval; break;
						case INT_2D_DATATYPE: *(found->dataNode.intarr * index1 + index2) = r->intval; break;
						case CHAR_2D_DATATYPE: *(found->dataNode.chararr * index1 + index2) = r->charval; break;
						case BOOL_2D_DATATYPE: *(found->dataNode.boolarr * index1 + index2) = r->boolval; break;
					}
					free(r);
					break;
				}

				case METHOD_CALL_STATEMENTTYPE:{
                    struct ASTNode *temp = root->statementNode.arg1;
                    evaluate(temp);
					break;
				}

				case IFTHENELSE_STATEMENTTYPE:{
                    struct ASTNode *temp = root->statementNode.arg1;
                    evaluate(temp);
					break;
				}
				case TERNARY_STATEMENTTYPE:{
					union result * r = evaluate(root->statementNode.arg1);
                    if(r->boolval)
                        evaluate(root->statementNode.arg2);
                    else
                        evaluate(root->statementNode.arg3);
					free(r);
					break;
				}
				case WHILE_STATEMENTTYPE:{
					union result * r = evaluate(root->statementNode.arg1);
                    while(r->boolval)
                    {
                        evaluate(root->statementNode.arg2);
                    }
					free(r);
					break;
				}
				case FOR_STATEMENTTYPE:{
                    char *id = strdup(root->statementNode.arg1->stringLiteral);
                    struct symbolNode* found = findSymbolNode(id, DATA);
                    union result *r = evaluate(root->statementNode.arg2);

                    switch(found->dataNode.type)
					{
						case INT_DATATYPE: found->dataNode.intval = r->intval; break;
						case UINT_DATATYPE: found->dataNode.uintval = r->uintval; break;
						case CHAR_DATATYPE: found->dataNode.charval = r->charval; break;
						case BOOL_DATATYPE: found->dataNode.boolval = r->boolval; break;
						case INT_1D_DATATYPE: *(found->dataNode.intarr + index1) = r->intval; break;
						case UINT_1D_DATATYPE: *(found->dataNode.uintarr + index1) = r->uintval; break;
						case CHAR_1D_DATATYPE: *(found->dataNode.chararr + index1) = r->charval; break;
						case BOOL_1D_DATATYPE: *(found->dataNode.boolarr + index1) = r->boolval; break;
						case INT_2D_DATATYPE: *(found->dataNode.intarr * index1 + index2) = r->intval; break;
						case UINT_2D_DATATYPE: *(found->dataNode.uintarr * index1 + index2) = r->uintval; break;
						case CHAR_2D_DATATYPE: *(found->dataNode.chararr * index1 + index2) = r->charval; break;
						case BOOL_2D_DATATYPE: *(found->dataNode.boolarr * index1 + index2) = r->boolval; break;
					}
                    free(r);
					r = evaluate(root->statementNode.arg3);
                    while(r->boolval)
                    {
                        evaluate(root->statementNode.arg5);
                        evaluate(root->statementNode.arg4);
                    }
					free(r);
					break;
				}
				case BLOCK_STATEMENTTYPE:{
                    evaluate(root->statementNode.arg1);
					break;
				}
			}
			break;
		}
		case IfElse:{
			union result * r = root->statementNode.arg1->ifElseNode.ifexpr);
            if(evaluate(r->boolval)
                evaluate(root->statementNode.arg1->ifElseNode.then);
            else
                evaluate(root->statementNode.arg1->ifElseNode.elsethen);
			free(r);
			break;
		}
		case MethodCall:{
            char *id = strdup(root->methodCallNode.functionName);
            struct symbolNode * found = findSymbolNode(id, FUNCTION);
            
			struct symbolTableStack * temp = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			current->next = temp;
			temp->front = NULL;
			temp->next = NULL;
            previous = current;
			current = temp;

			struct symbolNode * temp = found->functionNode.front;
			while(temp!=NULL)
			{
				if(current->front==NULL)
				{
				    current->front = newData(temp->dataNode.id, temp->dataNode.type, temp->dataNode.index1, temp->dataNode.index2);
					temp = temp -> next;
				    continue;
				}
                struct symbolNode * newtemp = current->front;
				while(newtemp->next!=NULL)
				    newtemp = newtemp->next;
				newtemp->next = newData(temp->dataNode.id, temp->dataNode.type, temp->dataNode.index1, temp->dataNode.index2);
				temp = temp->next;
			}
            functionArgPointer = current->front;
			evaluate(root->methodCallNode.args->CalloutArgsNode);
			if(functionArgPointer!=NULL)
			{
				print("Err: Insufficient function arguments");
				exit(0);
			}
			evaluate(found->functionNode.block);

            temp = symbolTable;
			while(temp->next!=parent)
		        temp = temp->next;
			deleteSymbolTable(current);
			current = parent;
			current->next = NULL;
			parent = temp;
			break;
		}
		case CalloutArgs:{
			if(functionArgPointer==NULL)
			{
				printf("Err: too many function parameters given");
				exit(0);
			}
			union result * r = evaluate(root->CalloutArgsNode.expr);
			switch(functionArgPointer->dataNode.type)
			{
				case INT_DATATYPE:{
					functionArgPointer->dataNode.intval = r->intval;
					break;
				}

				case INT_1D_DATATYPE:{
					int i = 0;
					for(i = 0; i < functionArgPointer->dataNode.index1; i = i + 1)
					    *(functionArgPointer->dataNode.intarr + i) = *(r->intarr + i);
					break;
				}

				case INT_2D_DATATYPE:{
					int i=0;
					int j=0;
					for(i = 0; i < functionArgPointer->dataNode.index1; i=i+1)
					    for(j=0; j < functionArgPointer->dataNode.index2; j = j + 1)
						    *(functionArgPointer->dataNode.intarr * i + j) = *(r->intarr*i + j);
					break;
				}
				case CHAR_DATATYPE:{
					functionArgPointer->dataNode.charval = r->charval;
					break;
				}

				case CHAR_1D_DATATYPE:{
					int i = 0;
					for(i = 0; i < functionArgPointer->dataNode.index1; i = i + 1)
					    *(functionArgPointer->dataNode.chararr + i) = *(r->chararr + i);
					break;
				}

				case CHAR_2D_DATATYPE:{
					int i=0;
					int j=0;
					for(i = 0; i < functionArgPointer->dataNode.index1; i=i+1)
					    for(j=0; j < functionArgPointer->dataNode.index2; j = j + 1)
						    *(functionArgPointer->dataNode.chararr * i + j) = *(r->chararr*i + j);
					break;
				}
				case BOOL_DATATYPE:{
					functionArgPointer->dataNode.boolval = r->boolval;
					break;
				}

				case BOOL_1D_DATATYPE:{
					int i = 0;
					for(i = 0; i < functionArgPointer->dataNode.index1; i = i + 1)
					    *(functionArgPointer->dataNode.boolarr + i) = *(r->boolarr + i);
					break;
				}

				case BOOL_2D_DATATYPE:{
					int i=0;
					int j=0;
					for(i = 0; i < functionArgPointer->dataNode.index1; i=i+1)
					    for(j=0; j < functionArgPointer->dataNode.index2; j = j + 1)
						    *(functionArgPointer->dataNode.boolarr * i + j) = *(r->boolarr*i + j);
					break;
				}
			}
			free(r);
			functionArgPointer = functionArgPointer -> next;
			evaluate(root->CalloutArgsNode.callout_args);
			break;
		}
		case Expr:{
			union result * ret = (union result *)malloc(sizeof(union result));
			union result *o1, *o2;
			switch(root->exprNode.type)
			{
				case LOCATION_EXPRTYPE:{
					union result * ret = (union result *)malloc(sizeof(union result));

					struct ASTNode * location = root->exprNode.arg1;
                    struct symbolNode * found = findSymbolNode(location->locationNode.id);
					int index1 = 0, index2 = 0;
					if(location->locationNode.index1!=NULL)
			        {
			        	union result *r = evaluate(location->locationNode.index1);
			            index1 = r->intval;
			        	free(r);
			        }
			        if(location->locationNode.index2!=NULL)
                    {
			        	union result *r = evaluate(location->locationNode.index1);
			            index1 = r->intval;
			        	free(r);
			        }
					if(index1 > found->dataNode.index1 || index2 > found->dataNode.index2 || index1 < 0 || index2 < 0)
					{
						printf("Err: Invalid indices. Out of scope");
						exit(0);
					}

					switch(found->dataNode.type)
                    {
						case INT_TYPETYPE:{
							ret->intval = found->dataNode.intval;
							break;
						}

						case INT_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->intarr = (int *)malloc(index1 * sizeof(int));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->intarr + i) = *(found->dataNode.intarr + i);
								break;
							}
							ret->intval = *(found->dataNode.intarr + index1);
						}

						case INT_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
								ret->intarr = (int *)malloc(sizeof(int));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->intarr * i + j) = *(found->dataNode.intarr * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->intval = *(found->dataNode.intarr * index1 + index2);
								break;
							}
							else{
                                printf("Err: One index out of range");
								exit(0);
							}
						}
						case UINT_TYPETYPE:{
							ret->uintval = found->dataNode.uintval;
							break;
						}

						case UINT_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->uintarr = (unsigned int *)malloc(index1 * sizeof(unsigned int));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->uintarr + i) = *(found->dataNode.uintarr + i);
								break;
							}
							ret->uintval = *(found->dataNode.uintarr + index1);
						}

						case UINT_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
								ret->uintarr = (unsigned int *)malloc(sizeof(unsigned int));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->uintarr * i + j) = *(found->dataNode.uintarr * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->uintval = *(found->dataNode.uintarr * index1 + index2);
								break;
							}
							else{
                                printf("Err: One index out of range");
								exit(0);
							}
						}
						case CHAR_TYPETYPE:{
							ret->charval = found->dataNode.charval;
							break;
						}

						case CHAR_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->chararr = (char *)malloc(index1 * sizeof(char));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->chararr + i) = *(found->dataNode.chararr + i);
								break;
							}
							ret->charval = *(found->dataNode.chararr + index1);
						}

						case CHAR_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
								ret->chararr = (char *)malloc(sizeof(char));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->chararr * i + j) = *(found->dataNode.chararr * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->charval = *(found->dataNode.chararr * index1 + index2);
								break;
							}
							else{
                                printf("Err: One index out of range");
								exit(0);
							}
						}
						case BOOL_TYPETYPE:{
							ret->boolval = found->dataNode.boolval;
							break;
						}

						case BOOL_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->boolarr = (bool *)malloc(index1 * sizeof(bool));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->boolarr + i) = *(found->dataNode.boolarr + i);
								break;
							}
							ret->boolval = *(found->dataNode.boolarr + index1);
						}

						case BOOL_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
								ret->boolarr = (bool *)malloc(sizeof(bool));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->boolarr * i + j) = *(found->dataNode.boolarr * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->boolval = *(found->dataNode.boolarr * index1 + index2);
								break;
							}
							else{
                                printf("Err: One index out of range");
								exit(0);
							}
						}
					}
					break;
				}
				case LITERAL_EXPRTYPE:{
					ret->intval = root->exprNode.arg1->intLiteral;
					ret->charval = root->exprNode.arg1->charLiteral;
					ret->boolval = root->exprNode.arg1->BOOLLiteralNode.value;
					break;
				}
				
				case ADD_EXPRTYPE:{
					union result * ret = (union result *)malloc(sizeof(union result));
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval + o2->intval;
					break;
				}
				case SUB_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval - o2->intval;
					break;
				}
				case MUL_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval * o2->intval;
					break;
				}
				case DIV_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval / o2->intval;
					break;
				}
				case MOD_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval % o2->intval;
					break;
				}
				case LEQ_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval <= o2->intval;
					break;
				}
				case GEQ_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval >= o2->intval;
					break;
				}
				case LESSTHAN_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval < o2->intval;
					break;
				}
				case GREATERTHAN_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval > o2->intval;
					break;
				}
				case EQUALITY_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval == o2->intval;
					break;
				}
				case NONEQUALITY_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval != o2->intval;
					break;
				}
				case LOGICAL_OR_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->boolval || o2->boolval;
					break;
				}
				case LOGICAL_AND_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->boolval && o2->boolval;
					break;
				}
				case UNISUB_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					ret->intval = -1*o1->intval;
					break;
				}
				case LOGICAL_NOT_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					ret->boolval = !(o1->boolval);
					break;
				}
				case EXPR_PARAN_EXPRTYPE:{
					return(evaluate(root->exprNode.arg1));
					break;
				}
			}
			return(ret);
		}
	}
}
