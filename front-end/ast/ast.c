#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"


ASTNode *create_num_node(int value){
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = AST_NUMBER;
    node->value = value;
    return node;
}

ASTNode* create_var_node(char *name){
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = AST_VAR;
    strcpy(node->name, name);
    return node;
}

ASTNode *create_var_declare_node(char *name, int value){
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = AST_VAR_DECL;
    node->value =value;
    strcpy(node->name, name);
    return node;
}

ASTNode *create_binary_node(char op, ASTNode *left, ASTNode *right){
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = AST_BINARY;
    node->op = op;
    node->left = left;
    node->right = right;
    return node;
}

void free_ast(ASTNode *node){
    if(!node){
        return;
    }
    free_ast(node->left);
    free_ast(node->right);
    free(node);
}





