#ifndef PARSER_H
#define PARSER_H

#include "../token/token.h"
#include "../ast/ast.h"

ASTNode *parse(Token *tokens);
ASTNode *parse_expression(Token *tokens);

#endif