#include "../token/token.h"
#include "lexer.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

Token* tokenize(char *input){
    Token* tokens = malloc(256 * sizeof(Token));
    int pos = 0;

    while(*input){
        if(isspace(*input)){
            input++;
        }else if(isdigit(*input)){
            tokens[pos].type = TOKEN_NUMBER;
            tokens[pos].value = strtol(input, &input, 10);
            pos++;
            input++;
        }else if (*input == '+') {
            tokens[pos++].type = TOKEN_PLUS; input++;
        } else if (*input == '-') {
            tokens[pos++].type = TOKEN_MINUS; input++;
        } else if (*input == '*') {
            tokens[pos++].type = TOKEN_STAR; input++;
        } else if (*input == '/') {
            tokens[pos++].type = TOKEN_SLASH; input++;
        } else if(*input == '='){
            tokens[pos++].type = TOKEN_ASSIGN; input++;
        }
    }
}