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
        }else if (*input == ';') {
            tokens[pos++].type = TOKEN_SEMICOLON; input++;
        }else if(isalpha(*input)){
            int len =0;
            while(isalnum(*input)){
                tokens[pos].ident[len++] = *input;
                input++;
            }
            tokens[pos].ident[len] = '\0';
            if(strcmp(tokens[pos].ident, "let")== 0){
                tokens[pos].type = TOKEN_LET;
            }else{
                tokens[pos].type = TOKEN_IDENTIFIER;
            }
            pos++;
        }else{
            input++;
        }
    }

    tokens[pos].type = TOKEN_END;
    return tokens;
}