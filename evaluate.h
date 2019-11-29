#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// For a symbol node tells me which type the symbol is - could be a data node or a function node
typedef enum symboltype {DATA, FUNCTION} symbolType;

// Given that it's a data type symbol, what ind of data does the symbol store
typedef enum datatype {INT_DATATYPE, CHAR_DATATYPE, BOOL_DATATYPE,  INT_1D_DATATYPE, INT_2D_DATATYPE, CHAR_1D_DATATYPE, CHAR_2D_DATATYPE, BOOL_1D_DATATYPE, BOOL_2D_DATATYPE} dataType;

// a node which stores data
struct dataSymbolNode {
        dataType type;
	    int index1;
	    int index2; // If both index 1 and index 2 are 1 implies it's not an array (could have modeled both 1D and 2D arrays using the same thing but okay. Some clean arithmatic would have been enough)
	    union{
            int intval;
            char charval;
            bool boolval;
            int *intarr;
            char *chararr;
            bool *boolarr; 
        };
};


// the node stores information about every function declared in the program
struct functionSymbolNode{
			int numOfArgs; // Number of arguments in the function
            struct symbolNode *front; // Points to a list of function arguments
			struct ASTNode* block; // Points to block node in AST corresponding to the definition of this function
};

// struct that stores everything defined in the program
struct symbolNode {
	char* id;
	symbolType stype; // DATA or FUNCTION
	struct symbolNode *next; // Points to the next symbol defined
	union{
		struct dataSymbolNode dataNode;
        struct functionSymbolNode functionNode;
	};
};

// To handle scopes, we create a stack of symbol tables where each symbol table level in a stack defines a scope
struct symbolTableStack {
	struct symbolNode * front;
	struct symbolTableStack * next;
};


// A union to send the results with, could be changed to a struct as well, actually might be better
// union result{
// 	int intval;
// 	bool boolval;
// 	char charval;
// 	int *intarr;
// 	char *chararr;
// 	bool *boolarr;
// };

// This might simplify everything instead of using union
struct result{
    dataType type;
	union{
        int intval;
		bool boolval;
		char charval;
		int *intarr;
		bool *boolarr;
		char *chararr;
	};
};

extern struct symbolNode * newData(char* id, dataType type, int index1, int index2);
extern struct symbolNode * newFunction(char *id, struct ASTNode *block);
extern void deleteSymbolTable(struct symbolTableStack* root);
extern struct symbolNode * findSymbolNode(char *id, symbolType type);
extern bool checkExists(char *id);
extern struct result* evaluate(struct ASTNode *root);