#include <stdio.h>
#include "err.h"


void print_tree(ASTNode *tree){
    if(!tree){
        return;
    }

    switch(tree->type){
        case AST_NUMBER:
            printf("Number: %d\n", tree->value);
            break;

        case AST_BINARY:
            printf("Binary Op: %s\n", tree->op);
            print_tree(tree->left);
            print_tree(tree->right);
            break;
        
        case AST_VAR_DECL:
            printf("Variable: %s\n", tree->name);
            print_tree(tree->left);
            break;

        case AST_VAR:
            printf("Variable: %s\n", tree->name);
            break;
        
        default:
            printf("Unknown\n");
    }
}

void print_tokens(Token *tokens){
    int i=0;
    while(tokens[i].type != TOKEN_END){
        printf("Token: %d: Type=%s", i, token_type_to_string(tokens[i].type));
        if(tokens[i].type == TOKEN_NUMBER){
            printf("Value= %d", tokens[i].value);
        }else if(tokens[i].type == TOKEN_IDENTIFIER){
            printf("name= %s", tokens[i].ident);
        }
        printf("\n");
        i++;
    }

}

char* token_type_to_string(TokenType type){
    switch(type){
        case TOKEN_NUMBER: return "NUMBER";
        case TOKEN_PLUS: return "PLUS";
        case TOKEN_MINUS: return "MINUS";
        case TOKEN_STAR: return "STAR";
        case TOKEN_SLASH: return "SLASH";
        case TOKEN_LPAREN: return "LPAREN";
        case TOKEN_RPAREN: return "RPAREN";
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_LET: return "LET";
        case TOKEN_ASSIGN: return "ASSIGN";
        case TOKEN_SEMICOLON: return "SEMICOLON";
        case TOKEN_END: return "END";
        default: return "UNKNOWN";
    }
}