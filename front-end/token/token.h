#ifndef TOKEN_H
#define TOKEN_H


typedef enum{
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_EQ;
    TOKEN_NOTEQ,
    TOKEN_LET,
    TOKEN_IDENTIFIER,
    TOKEN_SEMICOLON,
    TOKEN_IF,
    TOKEN_WHILE,
    TOKEN_FUN,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_CALL
} TokenType;

typedef struct{
    TokenType type;
    int value;
    char ident[64];
} Token;

#endif