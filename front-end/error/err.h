#ifndef ERR_H
#define ERR_H
#include "../lexer/lexer.h"
#include "../token/token.h"
#include "../ast/ast.h"

void print_tokens(Token *tokens);
char* token_type_to_string(TokenType type);
void print_tree(ASTNode *tree);
#endif