#include "Token.h"
#include <stdlib.h>
#include <stdio.h>

Token* init_token(char* value, TOKEN_TYPE type) {
	Token* token = malloc(sizeof(Token));
	token->value = value;
	token->type = type;
	return token;
}

void print_token(Token* token) {
	printf("<type: %s | value: %s>\n", token_type_to_string(token), token->value);
}

char* token_type_to_string(Token* token) {
	switch (token->type) {
		case TOKEN_ID:
			return "TOKEN_ID";
		case TOKEN_NUMBER:
			return "TOKEN_NUMBER";
		case TOKEN_EQUALS:
			return "TOKEN_EQUALS";
		case TOKEN_PLUS:
			return "TOKEN_PLUS";
		case TOKEN_STAR:
			return "TOKEN_STAR";
		case TOKEN_MINUS:
			return "TOKEN_MINUS";
		case TOKEN_SEMICOLON:
			return "TOKEN_SEMICOLON";
		case TOKEN_COLON:
			return "TOKEN_COLON";
		case TOKEN_LEFT_BRACKETS:
			return "TOKEN_LEFT_BRACKETS";
		case TOKEN_RIGHT_BRACKETS:
			return "TOKEN_RIGHT_BRACKETS";
		case TOKEN_LEFT_CURLY_BRACKETS:
			return "TOKEN_LEFT_CURLY_BRACKETS";
		case TOKEN_RIGHT_CURLY_BRACKETS:
			return "TOKEN_RIGHT_CURLY_BRACKETS";
		case TOKEN_LEFT_SQUARE_BRACKETS:
			return "TOKEN_LEFT_SQUARE_BRACKETS";
		case TOKEN_RIGHT_SQUARE_BRACKETS:
			return "TOKEN_RIGHT_SQUARE_BRACKETS";
		case TOKEN_LEFT_TRIANGLE_BRACKETS:
			return "TOKEN_LEFT_TRIANGLE_BRACKETS";
		case TOKEN_RIGHT_TRIANGLE_BRACKETS:
			return "TOKEN_RIGHT_TRIANGLE_BRACKETS";
		case TOKEN_EXCLAMTION_MARK:
			return "TOKEN_EXCLAMTION_MARK";
		case TOKEN_DOT:
			return "TOKEN_DOT";
		case TOKEN_APPRENTICES:
			return "TOKEN_APPRENTICES";
		case TOKEN_LEFT_SLASH:
			return "TOKEN_LEFT_SLASH";
		case TOKEN_RIGHT_SLASH:
			return "TOKEN_RIGHT_SLASH";
		case TOKEN_PRECENT:
			return "TOKEN_PRECENT";
		case TOKEN_EOF:
			return "TOKEN_EOF";
	}
}