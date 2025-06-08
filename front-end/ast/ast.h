#ifndef AST_H
#define AST_H

typedef enum{
    AST_NUMBER,
    AST_BINARY,
    AST_VAR_DECL,
    AST_VAR,
    AST_ASSIGN
} ASTNodeType;

typedef struct ASTNode{
    ASTNodeType type;
    int value;
    char name[64];
    struct ASTNode *left;
    struct ASTNode *right;
    char op;
} ASTNode;


ASTNode *create_num_node(int value);
ASTNode *create_var_node(char *name);
ASTNode *create_var_declare_node(char *name, ASTNode *value);
ASTNode *create_binary_node(char op, ASTNode *left, ASTNode *right);
void free_ast(ASTNode *node);

#endif

