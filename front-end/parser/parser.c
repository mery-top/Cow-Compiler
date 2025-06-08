#include <stdio.h>
#include "../token/token.h"
#include "../ast/ast.h"
#include <string.h>

int pos =0;

ASTNode *parse_expression(Token *tokens);

ASTNode *parse(Token *tokens){
    if(tokens[pos].type == TOKEN_LET){
        pos++;
        if(tokens[pos++].type != TOKEN_IDENTIFIER){
            return NULL;
        }
        char name[64];
        strcpy(name, tokens[pos++].ident);

        if(tokens[pos++].type != TOKEN_ASSIGN){
            return NULL;
        }

        ASTNode *value = parse_expression(tokens);

        if(tokens[pos].type!= TOKEN_SEMICOLON){
            return NULL;
        }

        return create_var_declare_node(name, value);
    }

    return NULL;
}

ASTNode *parse_expression(Token *tokens){
    ASTNode *left;
    if(tokens[pos].type == TOKEN_NUMBER){
        left = create_num_node(tokens[pos++].value);
    }else if(tokens[pos].type == TOKEN_IDENTIFIER){
        left = create_var_node(tokens[pos++].ident);
    }else{
        return NULL;
    }

    while(tokens[pos].type == TOKEN_PLUS || tokens[pos].type == TOKEN_MINUS ){
        char op = (tokens[pos++].type == TOKEN_PLUS) ? '+' : '-';
        ASTNode *right = parse_expression(tokens);
        left = create_binary_node(op, left, right);
    }

    return left;
}

