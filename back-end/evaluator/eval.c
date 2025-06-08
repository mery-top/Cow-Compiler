#include <stdio.h>
#include "eval.h"


void generate_code(ASTNode *node){
    int result = 0;
    if (node->type == AST_VAR_DECL){
        node= node->left;
    }

    if(node->left->type == AST_BINARY){
        int left = node->left->value;
        int right = node->right->value;

        result = (node->op == '+') ? (left+right) : (left-right);
    }else if(node->left->type == AST_NUMBER){
        result =  node->value;
    }

    printf("The result is:%d\n", result);
}