#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Token definitions

typedef enum{
    TOKEN_NUMBER, TOKEN_PLUS, TOKEN_MINUS, TOKEN_END
} TokenType;

typedef struct{
    TokenType type;
    int value;
} Token;


Token* tokenize(char *input){
    Token* tokens = malloc(256 *sizeof(Token));
    int pos =0;

    while(*input){
        if(isdigit(*input)){
            token[pos].TokenType = TOKEN_NUMBER;
            //&input move the pointer till it has number
            token[pos].value = strtol(input, &input, 10);
            pos++;
        }else if(*input == '+'){
            tokens[pos].type = TOKEN_PLUS;
            pos++;
            input++;
        }else if(*input == '-'){
            tokens[pos].type = TOKEN_MINUS;
            pos++;
            input++;
        }else{
            input++;
        }
    }

    token[pos].type = TOKEN_END;
    return tokens;
    
}

int parse(Token *token, int *result){
    int pos =0;

    if(token[pos].type != TOKEN_NUMBER){
        return 0;
    }

    *result = token[pos].value;
    pos++;

    while(token[pos].type != TOKEN_END){
        if(token[pos].type == TOKEN_PLUS){
            pos++;
            if(token[pos].type !=TOKEN_NUMBER){
                return 0;
            }
            *result+= token[pos].value;
        }else if(token[pos].type == TOKEN_MINUS){
            pos++;
            if(token[pos].type !=TOKEN_NUMBER){
                return 0;
            }

            *result-=token[pos].value;
        }else{
            return 0;
        }
        pos++;
    }
    return 1;
    
    }

int main(){
    return 0;
}