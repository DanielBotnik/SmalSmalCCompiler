#pragma once

typedef enum TOKEN_TYPE{
    TOKEN_ID,
    TOKEN_NUMBER,
    TOKEN_EQUALS,
    TOKEN_PLUS,
    TOKEN_STAR,
    TOKEN_MINUS,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_LEFT_BRACKETS,
    TOKEN_RIGHT_BRACKETS,
    TOKEN_LEFT_SQUARE_BRACKETS,
    TOKEN_RIGHT_SQUARE_BRACKETS,
    TOKEN_LEFT_TRIANGLE_BRACKETS,
    TOKEN_RIGHT_TRIANGLE_BRACKETS,
    TOKEN_LEFT_CURLY_BRACKETS,
    TOKEN_RIGHT_CURLY_BRACKETS,
    TOKEN_EXCLAMTION_MARK,
    TOKEN_APPRENTICES,
    TOKEN_DOUBLE_APPRENTICES,
    TOKEN_DOT,
    TOKEN_RIGHT_SLASH, // '/'
    TOKEN_LEFT_SLASH, // '\'
    TOKEN_PRECENT,
    TOKEN_EOF,
} TOKEN_TYPE;

typedef struct TOKEN_STRUCT {
    char* value;
    TOKEN_TYPE type;
} Token;

Token* init_token(char* value,TOKEN_TYPE type);
void print_token(Token*);
char* token_type_to_string(Token*);