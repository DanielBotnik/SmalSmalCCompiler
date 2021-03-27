#pragma once

#include "Token.h"

typedef struct LEXER_STRUCT
{
	char* src;
	char current;
	unsigned int src_size;
	unsigned int position;
} Lexer;

Lexer* init_lexer(char* src);
char lexer_peek(Lexer* lexer, int offest);
void lexer_skip_whitespace(Lexer* lexer);
void lexer_skip_line(Lexer* lexer);
void lexer_skip_comment(Lexer* lexer);
void lexer_progress(Lexer* lexer);
Token** get_tokens(Lexer* lexer);
