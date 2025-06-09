#ifndef ERR_H
#define ERR_H
#include "../front-end/lexer/lexer.h"
#include "../front-end/token/token.h"

void print_tokens(Token *tokens);
char* token_type_to_string(TokenType type);

#endif