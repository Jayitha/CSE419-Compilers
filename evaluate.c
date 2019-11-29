// Symbol Table
#include "evaluate.h"

struct symbolTableStack * symbolTable = NULL; // Points to the first symbol table in symbol table stack
struct symbolTableStack * current = NULL; // Points to current or top of symbol table stack
struct symbolTableStack * previous = NULL; // Points to "Penultimate" symbol table. Heh, I learnt SOMETHING from Chemistry
struct symbolNode * functionArgPointer = NULL; // When traversing the function argument list during a function call, this pointer points to that argument which is to be initialised


// Function that creates a data node given the id, the type and the size
struct symbolNode * newData(char* id, dataType type, int index1, int index2)
{
	struct symbolNode *node = (struct symbolNode *)malloc(sizeof(struct symbolNode));
	node->id=strdup(id);
	node->stype = DATA;
	node->dataNode.type = type;
	node->dataNode.index1 = index1;
    node->dataNode.index2 = index2;
	node->next=NULL;
	// Performing initialisation
	// Int = 0
	// Char = ' '
	// Bool = False
	switch(node->dataNode.type)
	{
        case INT_DATATYPE: node->dataNode.intval = 0; break;
        case CHAR_DATATYPE: node->dataNode.charval = ' '; break;
        case BOOL_DATATYPE: node->dataNode.boolval = false; break;
        case INT_1D_DATATYPE: {
            node->dataNode.intarr = (int *)malloc(index1*sizeof(int));
            int i = 0;
            for(i=0; i<index1; i = i + 1)
                *(node->dataNode.intarr + i) = 0;
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
                    *(node->dataNode.intarr + (index1*i) + j) = 0;
            break;
        }
        case CHAR_2D_DATATYPE: {
            node->dataNode.chararr = (char *)malloc(index2*index1*sizeof(char));
            int i = 0;
            int j = 0;
            for(i=0; i<index1; i = i + 1)
                for(j=0; j<index2; j = j+ 1)
                    *(node->dataNode.chararr + (index1*i) + j) = ' ';
            break;
        }
        case BOOL_2D_DATATYPE: {
            node->dataNode.boolarr = (bool *)malloc(index2*index1*sizeof(bool));
            int i = 0;
            int j = 0;
            for(i=0; i<index1; i = i + 1)
                for(j=0; j<index2; j = j+ 1)
                    *(node->dataNode.boolarr + (index1*i) + j) = false;
            break;
        }

    }

	return node;
}

// Function that creats a symbol node for a function declared given it's id and the pointer to the AST node where it's definition blcok begins
struct symbolNode * newFunction(char *id, struct ASTNode *block)
{
	struct symbolNode* node = (struct symbolNode *)malloc(sizeof(struct symbolNode));
    node->id = id;
	node->stype = FUNCTION;
	node->functionNode.front = NULL; // Curretly arguments not initialised
	node->functionNode.numOfArgs = 0;
	node->next=NULL;
	node->functionNode.block = block;
	return node;
}

// To //free memory space, we delete symbol tables when their scope runs out
void deleteSymbolTable(struct symbolTableStack* root)
{
	struct symbolNode *temp1 = root->front;
	struct symbolNode *temp2 = NULL;
	root->front=NULL;
	while(temp1!=NULL)
	{
		temp2 = temp1->next;
		//free(temp1);
		temp1 = temp2;
	}
	//free(root);
}

// Function that searches through the whole SYMBOL TABLE STACK for the symbol node id of type
// Returns the pointer to the declration in the innermost applicable scope i.e. the latest declaration
// This facilitates scope, usage of a varible overrides it's global declaration
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
			{
			    found = temp1;
				break;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
    if(found==NULL)
	{
		printf("\nError: Undeclared Variable/Function or Out Of Scope");
		exit(0);
	}
    return(found);
}

// Checks to see if id exists in the top symbol stack i.e. in the current scope excluding the global scope
bool checkExists(char *id)
{
    //checks to see if symbol exists in latest stack for declaration purposes
	if(current == NULL || current->front==NULL) // If current scope has no variables declared yet
	    return false;
    struct symbolNode *temp = current->front;
    while(temp!=NULL)
    {
        if(strcmp(temp->id,id)==0)
            return true;
        temp=temp->next;
    }
    return false;
}

void evaluateWrite(struct ASTNode * root)
{
	printf("WRITE_METHOD\n");
	struct result* ret = evaluate(root->methodCallNode.args->calloutArgsNode.expr);
	switch(root->methodCallNode.args->calloutArgsNode.expr->exprNode.type)
	{
		case LOCATION_EXPRTYPE:{
			char * r = evaluate(root->methodCallNode.args->calloutArgsNode.callout_args->calloutArgsNode.expr)->chararr;
			if(strcmp("int", r)==0)
			    printf("\n%d",ret->intval);
			else if(strcmp("char", r)==0)
			    printf("\n%c",ret->charval);
			else if(strcmp("bool",r)==0)
			{
				if(ret->boolval)
				    printf("\nTrue");
				else
				    printf("\nFalse");
			}
			else
			{
				printf("\nErr: Invalid Datatype");
			}
			break;
		}
		case LITERAL_EXPRTYPE:{
			printf("\n%s",ret->chararr);
			break;
		}
		default: printf("\nError cannot pass these arguments");
		exit(0);
	}
}

void evaluateRead(struct ASTNode * root)
{
	printf("\nEvaluating Method Read");
	return;
}

// The interpreter
struct result* evaluate(struct ASTNode *root)
{
	if(root==NULL)
	    return NULL;
	switch(root->nodetype)
	{
		case Program:{
			printf("PROGRAM\n");
			evaluate(root->programNode.var_decls);
			evaluate(root->programNode.method_decls);
			break;
		}
		case VarDecls:{
			printf("VARDECLS\n");
			evaluate(root->varDeclsNode.var_decl);
			evaluate(root->varDeclsNode.var_decls);
			break;
		}
		case VarDecl:{
			printf("VARIABLE DECLARATION\n");

            // Getting the ID of the new data symbol
			struct ASTNode *location = root->varDeclNode.location;
            if(checkExists(location->locationNode.id))
            {
                printf("Error: Redeclaration of variable within same scope");
                exit(0);
            }

            // Getting index1 and index2, default = 0
            int index1 = 0, index2 = 0;
			if(location->locationNode.index1!=NULL)
			{
				struct result *r = evaluate(location->locationNode.index1);
			    index1 = r->intval;
				//free(r);
			}
			if(location->locationNode.index2!=NULL)
            {
				struct result *r = evaluate(location->locationNode.index2);
			    index2 = r->intval;
				//free(r);
			}
            if(index1 < 0 || index2 < 0)
            {
                printf("Error: cannot have negative indeces");
                exit(0);
            }

            //Flag tells me if it's atomic, an array or a matrix datatype
			int dimensions = 0;
            switch(location->locationNode.type)
			{
				case ARRAY_LOCATIONTYPE: dimensions = 1; break;
				case MATRIX_LOCATIONTYPE: dimensions = 2; break;
			}
            
			// Finding the data type of the to-be-declared variable
			dataType argtype;
			switch(root->varDeclNode.type->type)
			{
				case INT_TYPETYPE: {
                    switch(dimensions)
                    {
                        case 0: argtype = INT_DATATYPE; break;
                        case 1: argtype = INT_1D_DATATYPE; break;
                        case 2: argtype = INT_2D_DATATYPE; break;
                    }
                    break;
                }
                case CHAR_TYPETYPE: {
                    switch(dimensions)
                    {
                        case 0: argtype = CHAR_DATATYPE; break;
                        case 1: argtype = CHAR_1D_DATATYPE; break;
                        case 2: argtype = CHAR_2D_DATATYPE; break;
                    }
                    break;
                }
                case BOOL_TYPETYPE: {
                    switch(dimensions)
                    {
                        case 0: argtype = BOOL_DATATYPE; break;
                        case 1: argtype = BOOL_1D_DATATYPE; break;
                        case 2: argtype = BOOL_2D_DATATYPE; break;
                    }
                    break;
                }
			}
			
			// Creating a new symbol node for this symbol
			struct symbolNode *temp = newData(location->locationNode.id, argtype, index1, index2);

            // If this is the first symbol to EVER be declared
			if(symbolTable==NULL)
			{
				symbolTable = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			    symbolTable->front = temp;
				symbolTable->next = NULL;
				current = symbolTable;
			}
			// If this symbol is the first to be created in this scope
			else if(current->front==NULL)
			    current->front = temp;
			// Meh.
			else{
                temp->next = current->front;
			    current->front = temp;
			}
			break;
		}

        case MethodDecls:{
			printf("METHODDECLS\n");
			evaluate(root->methodDeclsNode.method_decl);
			evaluate(root->methodDeclsNode.method_decls);
			break;
		}

		case MethodDecl:{
			printf("METHODDECL\n");

			// Check if this function already in this scope
            if(checkExists(root->methodDeclNode.id))
            {
                printf("\nError: Redeclaration of function within same scope");
                exit(0);
            }

			// Creates a new symbol node with the function id and pointer to block to execute
			struct symbolNode * temp = newFunction(root->methodDeclNode.id,root->methodDeclNode.block);

			// If this is the first symbol to EVER be declared
			if(symbolTable==NULL)
			{
				symbolTable = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			    symbolTable->front = temp;
				symbolTable->next = NULL;
				current = symbolTable;
			}

			// If this symbol is the first to be created in this scope
			else if(current->front==NULL)
			    current->front = temp;

			// Meh.
			else{
                temp->next = current->front;
			    current->front = temp;
			}

			// If there are any arguments, create the argument list
            evaluate(root->methodDeclNode.method_args);

			// If function being declared is main, execute main function. Adding to the list prevents redeclaration
			if(strcmp(root->methodDeclNode.id,"main")==0)
                evaluate(root->methodDeclNode.block);
			
			break;
		}
		case MethodArgs:{
			printf("METHODARGS\n");
			// If method has arguments
			if(root->methodArgsNode.type!=VOID_METHODARGSTYPE)
			{
				evaluate(root->methodArgsNode.method_arg);
				evaluate(root->methodArgsNode.method_args);
			}
			else 
			printf("\nVOID arguments");
			break;
		}

		case MethodArg:{
            printf("METHODARG\n");

			// Finding the dimensionality of the argument
			dataType type;

            int dimensions = 0;
            switch(root->methodArgNode.type)
			{
				case ARRAY_METHODARGTYPE: dimensions = 1; break;
				case MATRIX_METHODARGTYPE: dimensions = 2; break;
			}

			int index1 = 0, index2 = 0;
			if(root->methodArgNode.index1!=NULL)
			{
				struct result * r = evaluate(root->methodArgNode.index1);
			    index1 = r->intval;
				//free(r);
			}
			if(root->methodArgNode.index2!=NULL)
			{
				struct result * r = evaluate(root->methodArgNode.index2);
			    index2 = r->intval;
				//free(r);
			}

            // Assigning the datatype
			switch(root->methodArgNode.id_type->type)
			{
				case INT_TYPETYPE: {
                    switch(dimensions)
                    {
                        case 0: type = INT_DATATYPE; break;
                        case 1: type = INT_1D_DATATYPE; break;
                        case 2: type = INT_2D_DATATYPE; break;
                    }
                    break;
                }
                case CHAR_TYPETYPE: {
                    switch(dimensions)
                    {
                        case 0: type = CHAR_DATATYPE; break;
                        case 1: type = CHAR_1D_DATATYPE; break;
                        case 2: type = CHAR_2D_DATATYPE; break;
                    }
                    break;
                }
                case BOOL_TYPETYPE: {
                    switch(dimensions)
                    {
                        case 0: type = BOOL_DATATYPE; break;
                        case 1: type = BOOL_1D_DATATYPE; break;
                        case 2: type = BOOL_2D_DATATYPE; break;
                    }
                    break;
                }
			}

            // Adding this method argument to the list of method arguments
			struct symbolNode * newtemp = newData(root->methodArgNode.id, type, index1, index2);
            struct symbolNode *temp = current->front->functionNode.front;

			// First argument of function
			if(temp==NULL)
			{
			    temp = newtemp;
				printf("\nAdded first one");
			}
			else
			{
				// It's important for the order to be the same in functions
			    while(temp->next!=NULL)
			        temp = temp->next;
			    temp->next = newtemp;
				printf("\nAdded another one");
			}
			current->front->functionNode.numOfArgs = current->front->functionNode.numOfArgs + 1; 
		}

		case Block:{
			printf("BLOCK\n");

			// Creatig new scope
			struct symbolTableStack * temp = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			current->next = temp; // new scope is on top of the old scope
			temp->front = NULL; // new scope is empty
			temp->next = NULL;
            previous = current; // the penultimate scope changes
			current = temp; // new scope currently under play

			 evaluate(root->blockNode.var_decls);
			 evaluate(root->blockNode.statements);

            // Post block execution, the symbol table is deleted
			deleteSymbolTable(current);

            // Adjust values of current and previous
			temp = symbolTable;
			current = NULL; 
			previous->next = NULL;
			if(temp->next == NULL)
			{
			    temp = NULL;
			}			
			else{
			 while(temp->next!=previous)
		         temp = temp->next;
			}
			current = previous;
			previous = temp;
			break;
		}

		case Statements:{
			printf("STATEMENTS\n");
			evaluate(root->statementsNode.statement);
			evaluate(root->statementsNode.statements);
			break;
		}

		case Statement:{
			printf("STATEMENT\n");
			switch(root->statementNode.type)
			{
				case ASSIGNMENT_STATEMENTTYPE:{
                    
					printf("ASSIGNMENT_STATEMENT\n");

					// Getting id of variable to be changed
					char *id = (char *)malloc(sizeof(char)*strlen(root->statementNode.arg1->locationNode.id));
					strcpy(id,root->statementNode.arg1->locationNode.id);

                    // Finds pointer to symbol of this variable
					struct symbolNode* found=NULL;
                    found = findSymbolNode(id, DATA);

                    // Finding the index of where to store value if array
				    int index1 = 0, index2 = 0;
                    
					if(root->statementNode.arg1->locationNode.index1!=NULL)
					{
						struct result * r = evaluate(root->statementNode.arg1->locationNode.index1);
					    index1 = r->intval;
						//free(r);
					}

					if(root->statementNode.arg1->locationNode.index2!=NULL)
					{
						struct result * r = evaluate(root->statementNode.arg1->locationNode.index2);
					    index2 = r->intval;
						//free(r);
					}

					if((index1 != 0 && index1 >= found->dataNode.index1) || (index2!= 0 && index2 >= found->dataNode.index2) || index1 < 0 || index2 < 0)
					{
						printf("\nError: Index out of range");
						exit(0);
					}

                    // Computing the data to be assigned
					struct result * r = evaluate(root->statementNode.arg2);

                    // Assigning data to variable
					switch(found->dataNode.type)
					{
						case INT_DATATYPE: found->dataNode.intval = r->intval; break;
						case CHAR_DATATYPE: found->dataNode.charval = r->charval; break;
						case BOOL_DATATYPE: found->dataNode.boolval = r->boolval; break;
						case INT_1D_DATATYPE: *(found->dataNode.intarr + index1) = r->intval; break;
						case CHAR_1D_DATATYPE: *(found->dataNode.chararr + index1) = r->charval; break;
						case BOOL_1D_DATATYPE: *(found->dataNode.boolarr + index1) = r->boolval; break;
						case INT_2D_DATATYPE: *(found->dataNode.intarr + found->dataNode.index1 * index1 + index2) = r->intval; break;
						case CHAR_2D_DATATYPE: *(found->dataNode.chararr + found->dataNode.index1 * index1 + index2) = r->charval; break;
						case BOOL_2D_DATATYPE: *(found->dataNode.boolarr + found->dataNode.index1 * index1 + index2) = r->boolval; break;
					}
					//free(r);
					break;
				}

				case METHOD_CALL_STATEMENTTYPE:{
                    evaluate(root->statementNode.arg1);
					break;
				}

				case IFTHENELSE_STATEMENTTYPE:{
                    evaluate(root->statementNode.arg1);
					break;
				}
				case TERNARY_STATEMENTTYPE:{
					printf("TERNARY_STATEMENT\n");
					struct result * r = evaluate(root->statementNode.arg1);
                    if(r->boolval)
                        evaluate(root->statementNode.arg2);
                    else
                        evaluate(root->statementNode.arg3);
					//free(r);
					break;
				}
				case WHILE_STATEMENTTYPE:{
					printf("WHILE_STATEMENT\n");
					struct result * r = evaluate(root->statementNode.arg1);
                    bool iterator = r->boolval;
                    while(iterator)
                    {
						//free(r);
                        evaluate(root->statementNode.arg2);
						r = evaluate(root->statementNode.arg1);
						iterator = r->boolval;
                    }
					//free(r);
					break;
				}
				case FOR_STATEMENTTYPE:{
					printf("FOR_STATEMENT\n");
					struct result * r = evaluate(root->statementNode.arg1);
                    bool iterator = r->boolval;
                    while(iterator)
                    {
						//free(r);
                        evaluate(root->statementNode.arg3);
						evaluate(root->statementNode.arg2);
						r = evaluate(root->statementNode.arg1);
						iterator = r->boolval;
                    }
					//free(r);
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
			printf("IF_ELSE_STATEMENT\n");
			struct result * r = evaluate(root->ifElseNode.ifexpr);
            if(r->boolval)
                evaluate(root->ifElseNode.then);
            else
                evaluate(root->ifElseNode.elsethen);
			//free(r);
			break;
		}
		case MethodCall:{
			printf("METHOD_CALL\n");
            char *id = strdup(root->methodCallNode.functionName->stringLiteral);
            // If function is read or write execute special functions
			printf("%s",id);
			if(strcmp(id,"read")==0)
			{
			    evaluateRead(root);
				break;
			}
			else if(strcmp(id,"write")==0)
			{
				evaluateWrite(root);
				break;
			}

			//Otherwise
            struct symbolNode * found = findSymbolNode(id, FUNCTION);
            
			//Creating new scope to execute this function
			struct symbolTableStack * temp = (struct symbolTableStack *)malloc(sizeof(struct symbolTableStack));
			current->next = temp;
			temp->front = NULL;
			temp->next = NULL;
            previous = current;
			current = temp;

            // Creating data list for function parameters
			struct symbolNode * temp1 = found->functionNode.front;
			if(temp1 == NULL)
			    printf("oops");
			while(temp1!=NULL)
			{
				if(current->front==NULL)
				{
					printf("\nAdding new data");
				    current->front = newData(temp1->id, temp1->dataNode.type, temp1->dataNode.index1, temp1->dataNode.index2);
					temp1 = temp1 -> next;
				    continue;
				}
                struct symbolNode * newtemp = current->front;
				while(newtemp->next!=NULL)
				    newtemp = newtemp->next;
				newtemp->next = newData(temp1->id, temp1->dataNode.type, temp1->dataNode.index1, temp1->dataNode.index2);
				temp1 = temp1->next;
			}

			// Used by callout args to initialise variables
            functionArgPointer = current->front;
			evaluate(root->methodCallNode.args);

			// If not enough function parameters specified, uses default values
			evaluate(found->functionNode.block);

            // Deletes scope
            temp = symbolTable;
			deleteSymbolTable(current);
			current = NULL;
			previous->next = NULL;
			if(temp->next == NULL)
			{
			    temp = NULL;
			}			
			else{
			 while(temp->next!=previous)
		         temp = temp->next;
			}
			current = previous;
			previous = temp;
			break;
		}

		case CalloutArgs:{
			printf("CALLOUT_ARGS\n");
			if(functionArgPointer==NULL)
			{
				printf("\nErr: too many function parameters given");
				exit(0);
			}

			struct result * r = evaluate(root->calloutArgsNode.expr);

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
						    *(functionArgPointer->dataNode.intarr + functionArgPointer->dataNode.index1 * i + j) = *(r->intarr + functionArgPointer->dataNode.index1 *i + j);
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
						    *(functionArgPointer->dataNode.chararr + functionArgPointer->dataNode.index1 * i + j) = *(r->chararr + functionArgPointer->dataNode.index1 *i + j);
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
						    *(functionArgPointer->dataNode.boolarr + functionArgPointer->dataNode.index1 * i + j) = *(r->boolarr + functionArgPointer->dataNode.index1 *i + j);
					break;
				}
			}
			//free(r);
			functionArgPointer = functionArgPointer -> next;
			evaluate(root->calloutArgsNode.callout_args);
			break;
		}
		case Expr:{
			printf("EXPRESSION\n");
			struct result * ret = (struct result *)malloc(sizeof(struct result));
			struct result *o1, *o2;

			switch(root->exprNode.type)
			{
				case LOCATION_EXPRTYPE:{
					printf("LOCATION\n");

					struct ASTNode * location = root->exprNode.arg1;
                    struct symbolNode * found = findSymbolNode(location->locationNode.id, DATA);
					int index1 = 0, index2 = 0;
					if(location->locationNode.index1!=NULL)
			        {
			        	struct result *r = evaluate(location->locationNode.index1);
			            index1 = r->intval;
			        	//free(r);
			        }
			        if(location->locationNode.index2!=NULL)
                    {
			        	struct result *r = evaluate(location->locationNode.index2);
			            index2 = r->intval;
			        	//free(r);
			        }
					if(index1 > found->dataNode.index1 || index2 > found->dataNode.index2 || index1 < 0 || index2 < 0)
					{
						printf("\nErr: Invalid indices. Out of scope");
						exit(0);
					}

					switch(found->dataNode.type)
                    {
						case INT_DATATYPE:{
							ret->type = INT_DATATYPE;
							ret->intval = found->dataNode.intval;
							break;
						}

						case INT_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->type = INT_1D_DATATYPE;
								ret->intarr = (int *)malloc(index1 * sizeof(int));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->intarr + i) = *(found->dataNode.intarr + i);
								break;
							}
							ret->type = INT_DATATYPE;
							ret->intval = *(found->dataNode.intarr + index1);
							break;
						}

						case INT_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
                                ret->type = INT_2D_DATATYPE;
								ret->intarr = (int *)malloc(index1* index2 * sizeof(int));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->intarr  + index1 * i + j) = *(found->dataNode.intarr + index1  * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->type = INT_DATATYPE;
								ret->intval = *(found->dataNode.intarr + found->dataNode.index1 * index1 + index2);
								break;
							}
							else{
                                printf("\nErr: One index out of range");
								exit(0);
							}
						}
						case CHAR_DATATYPE:{
							ret->type = CHAR_DATATYPE;
							ret->charval = found->dataNode.charval;
							break;
						}

						case CHAR_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->type = CHAR_1D_DATATYPE;
								ret->chararr = (char *)malloc(index1 * sizeof(char));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->chararr + i) = *(found->dataNode.chararr + i);
								break;
							}
							ret->type = CHAR_DATATYPE;
							ret->charval = *(found->dataNode.chararr + index1);
							break;
						}

						case CHAR_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
								ret->type = CHAR_2D_DATATYPE;
								ret->chararr = (char *)malloc(index1 * index2 * sizeof(char));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->chararr + index1 * i + j) = *(found->dataNode.chararr + index1 * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->type = CHAR_DATATYPE;
								ret->charval = *(found->dataNode.chararr +  found->dataNode.index1 * index1 + index2);
								break;
							}
							else{
                                printf("\nErr: One index out of range");
								exit(0);
							}
						}
						case BOOL_DATATYPE:{
							ret->type = BOOL_DATATYPE;
							ret->boolval = found->dataNode.boolval;
							break;
						}

						case BOOL_1D_DATATYPE:{
							if(index1 == found->dataNode.index1){
								ret->type = BOOL_1D_DATATYPE;
								ret->boolarr = (bool *)malloc(index1 * sizeof(bool));
								int i = 0;
								for(i = 0; i < index1; i = i + 1)
								    *(ret->boolarr + i) = *(found->dataNode.boolarr + i);
								break;
							}
							ret->type = BOOL_DATATYPE;
							ret->boolval = *(found->dataNode.boolarr + index1);
							break;
						}

						case BOOL_2D_DATATYPE:{
                            if(index1 == found->dataNode.index1 && index2 == found->dataNode.index2){
								ret->type = BOOL_2D_DATATYPE;
								ret->boolarr = (bool *)malloc(index1 * index2 * sizeof(bool));
								int i=0, j=0;
								for(i=0; i < index1; i = i + 1)
								    for(j=0; j < index2; j = j + 1)
									    *(ret->boolarr + index1 * i + j) = *(found->dataNode.boolarr + index1 * i + j);
								break;
							}
							else if(index1 < found->dataNode.index1 && index2 < found->dataNode.index2){
								ret->type = BOOL_DATATYPE;
								ret->boolval = *(found->dataNode.boolarr + found->dataNode.index1 * index1 + index2);
								break;
							}
							else{
                                printf("\nErr: One index out of range");
								exit(0);
							}
						}
					}
					break;
				}
				case LITERAL_EXPRTYPE:{
					ret = evaluate(root->exprNode.arg1);
					break;
				}
				
				case ADD_EXPRTYPE:{
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->type = INT_DATATYPE;
					ret->intval = o1->intval + o2->intval;
					break;
				}
				case SUB_EXPRTYPE:{
					ret->type = INT_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval - o2->intval;
					break;
				}
				case MUL_EXPRTYPE:{
					ret->type = INT_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval * o2->intval;
					break;
				}
				case DIV_EXPRTYPE:{
					ret->type = INT_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval / o2->intval;
					break;
				}
				case MOD_EXPRTYPE:{
					ret->type = INT_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->intval = o1->intval % o2->intval;
					break;
				}
				case LEQ_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval <= o2->intval;
					break;
				}
				case GEQ_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval >= o2->intval;
					break;
				}
				case LESSTHAN_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval < o2->intval;
					break;
				}
				case GREATERTHAN_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval > o2->intval;
					break;
				}
				case EQUALITY_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					if(o1->intval == o2->intval)
						ret->boolval = true;
					else
					    ret->boolval = false;
					break;
				}
				case NONEQUALITY_EXPRTYPE:{
					root->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->intval != o2->intval;
					break;
				}
				case LOGICAL_OR_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->boolval || o2->boolval;
					break;
				}
				case LOGICAL_AND_EXPRTYPE:{
					ret->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					o2 = evaluate(root->exprNode.arg2);
					ret->boolval = o1->boolval && o2->boolval;
					break;
				}
				case UNISUB_EXPRTYPE:{
					ret->type = INT_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					ret->intval = -1*o1->intval;
					break;
				}
				case LOGICAL_NOT_EXPRTYPE:{
					root->type = BOOL_DATATYPE;
					o1 = evaluate(root->exprNode.arg1);
					ret->boolval = !(o1->boolval);
					break;
				}
				case EXPR_PARAN_EXPRTYPE:{
					ret = evaluate(root->exprNode.arg1);
					break;
				}
			}
			return(ret);
			break;
		}
		case Location:{
			break;
		}
		case INTLiteral:{
			printf("INT_LITERAL\n");
			struct result * ret = (struct result *)malloc(sizeof(struct result));
			ret->type = INT_DATATYPE;
			ret->intval = root->intLiteral;
			return(ret);
			break;
		}
		case BOOLLiteral:{
			printf("BOOL_LITERAL\n");
			struct result * ret = (struct result *)malloc(sizeof(struct result));
			ret->type = BOOL_DATATYPE;
			switch(root->BOOLLiteralNode.type)
			{
				case TRUE_BOOL: {
					ret->boolval = true;
					break;
				}
				case FALSE_BOOL: {
					ret->boolval = false;
					break;
				}
			}
			return(ret);
			break;
		}
		case STRINGLiteral:{
			printf("STRING_LITERAL\n");
            struct result * ret = (struct result *)malloc(sizeof(struct result));
			ret->type = CHAR_1D_DATATYPE;
			ret->chararr = strdup(root->stringLiteral);
			return(ret);
			break;
		}
		case CHARLiteral:{
			printf("CHAR_LITERAL\n");
			struct result * ret = (struct result *) malloc(sizeof(struct result));
			ret->type = CHAR_DATATYPE;
			ret->charval = root->charLiteral;
			return(ret);
			break;
		}
		case Type:{
			break;
		}
		default: return(NULL);
	}
}
