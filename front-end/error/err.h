#ifndef ERR_H
#define ERR_H
#include "../lexer/lexer.h"
#include "../token/token.h"

void print_tokens(Token *tokens);
char* token_type_to_string(TokenType type);

#endif