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


//Tokenizer

Token* tokenize(char *input){
    Token* tokens = malloc(256 *sizeof(Token));
    int pos =0;

    while(*input){
        if(isdigit(*input)){
            tokens[pos].type = TOKEN_NUMBER;
            //&input move the pointer till it has number
            tokens[pos].value = strtol(input, &input, 10);
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

    tokens[pos].type = TOKEN_END;
    return tokens;
    
}

//Parser

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


void gen_asm(int *result){
    FILE *asm_file = fopen("output.asm", "w");
    fprintf(asm_file,
    "global _start\n\n"
    "_start:\n"
    "    mov rax, 60\n"
    "    mov rdi, %d\n"
    "    syscall\n", *result);

    fclose(asm_file);
}



//Main function

int main(int argc, char *argv[]){

    if(argc !=2){
        printf("Give me the filename sucker");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file){
        printf("File didn't open sucker");
        return 1;
    }


    char input[1024];
    fread(input, 1, sizeof(input)-1, file);
    input[1023] = '\0';
    fclose(file);

    Token *tokens = tokenize(input);
    int result;


    if(parse(tokens, &result)){
        printf("Result: %d\n", result);
    }else{
        printf("Error parsing");
    }

    gen_asm(&result);

    free(tokens);

    return 0;
}