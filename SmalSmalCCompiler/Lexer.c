#include "Lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Lexer* init_lexer(char* src) {
	Lexer* lexer = malloc(sizeof(Lexer));
	lexer->src = src;
	lexer->src_size = strlen(src);
	lexer->position = 0;
	lexer->current = src[0];
	return lexer;
}

char lexer_peek(Lexer* lexer,int offset) {
	if (lexer->current + offset > lexer->src_size)
		return '\0';
	return lexer->src[lexer->position + offset];
}

void lexer_skip_whitespace(Lexer* lexer) {
	while (lexer->position < lexer->src_size) {
		if (lexer->current == 32 || lexer->current == 9 || lexer->current == 10 || lexer->current == 11 || lexer->current == 13 || lexer->current == 12)
			lexer_progress(lexer);
	}
}

void lexer_skip_line(Lexer* lexer) {
	while (lexer->current != '\n')
		lexer_progress(lexer);
	lexer_progress(lexer);
}

void lexer_skip_comment(Lexer* lexer) {
	while (lexer->current != '*' && lexer_peek(lexer, 1) != '/')
		lexer_progress(lexer);
	lexer_progress(lexer);
	lexer_progress(lexer);
}

void lexer_progress(Lexer* lexer) {
	lexer->position += (lexer->position < lexer->src_size&& lexer->current != '\0');
	lexer->current = lexer->src[lexer->position];
}

Token** get_tokens(Lexer* lexer) {
	Token** tokens = malloc(sizeof(Token*));
	unsigned int tokensCount = 0;
	while (lexer->position < lexer->src_size) {
		if (lexer->current == 32 || lexer->current == 9 || lexer->current == 10 || lexer->current == 11 || lexer->current == 13 || lexer->current == 12)
			lexer_progress(lexer);
		else if (isalpha(lexer->current)) {
			char* value = malloc(sizeof(char));
			unsigned int valueSize = 0;
			while (isalpha(lexer->current)) {
				value[valueSize] = lexer->current;
				value = realloc(value, sizeof(char) * (valueSize + 2));
				valueSize++;
				lexer_progress(lexer);
			}
			value[valueSize] = '\0';
			Token* token = init_token(value, TOKEN_ID);
			tokens = realloc(tokens, sizeof(Token*) * (tokensCount + 1));
			tokens[tokensCount] = token;
			tokensCount++;
		}
		else if (isalnum(lexer->current)) {
			char* value = malloc(sizeof(char));
			unsigned int valueSize = 0;
			while (isalnum(lexer->current)) {
				value[valueSize] = lexer->current;
				value = realloc(value, sizeof(char) * (valueSize + 2));
				valueSize++;
				lexer_progress(lexer);
			}
			value[valueSize] = '\0';
			Token* token = init_token(value, TOKEN_NUMBER);
			tokens = realloc(tokens, sizeof(Token*) * (tokensCount + 1));
			tokens[tokensCount] = token;
			tokensCount++;
		}

		else {
			char* value = malloc(sizeof(char) * 2);
			value[1] = '\0';
			value[0] = lexer->current;
			TOKEN_TYPE type = TOKEN_ID;
			switch (lexer->current) {
				case '=':
					type = TOKEN_EQUALS;
					break;
				case '+':
					type = TOKEN_PLUS;
					break;
				case '*':
					type = TOKEN_STAR;
					break;
				case '-':
					type = TOKEN_MINUS;
					break;
				case ';':
					type = TOKEN_SEMICOLON;
					break;
				case ':':
					type = TOKEN_COLON;
					break;
				case '(':
					type = TOKEN_LEFT_BRACKETS;
					break;
				case ')':
					type = TOKEN_RIGHT_BRACKETS;
					break;
				case '{':
					type = TOKEN_LEFT_CURLY_BRACKETS;
					break;
				case '}':
					type = TOKEN_RIGHT_CURLY_BRACKETS;
					break;
				case '[':
					type = TOKEN_LEFT_SQUARE_BRACKETS;
					break;
				case ']':
					type = TOKEN_RIGHT_SQUARE_BRACKETS;
					break;
				case '<':
					type = TOKEN_LEFT_TRIANGLE_BRACKETS;
					break;
				case '>':
					type = TOKEN_RIGHT_TRIANGLE_BRACKETS;
					break;
				case '!':
					type = TOKEN_EXCLAMTION_MARK;
					break;
				case '.':
					type = TOKEN_DOT;
					break;
				case '\'':
					type = TOKEN_APPRENTICES;
					break;
				case '\\':
					type = TOKEN_LEFT_SLASH;
					break;
				case '/':
					type = TOKEN_RIGHT_SLASH;
					break;
				case '%':
					type = TOKEN_PRECENT;
					break;
			}
			Token* token = init_token(value, type);
			tokens = realloc(tokens, sizeof(Token*) * (tokensCount + 1));
			tokens[tokensCount] = token;
			tokensCount++;
			lexer_progress(lexer);
		}
	}
	Token* token = init_token("", TOKEN_EOF);
	tokens[tokensCount] = token;
	tokensCount++;
	return tokens;
}

Token* lexer_next_token(Lexer* lexer) {
	
}