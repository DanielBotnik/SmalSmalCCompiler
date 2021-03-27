#include "Lexer.h"
#include "io.h"
#include <ctype.h>
#include <sys/types.h>
#include <stdint.h>

int main(int argc,char* argv[]) {
	
	if (argc < 2) {
		printf("Missing input files\n");
		return 1;
	}

	char* src = read_file(argv[1]);
	Lexer* lexer = init_lexer(src);
	Token** tokens = get_tokens(lexer);
	uint32_t i = 0;
	while (tokens[i]->type != TOKEN_EOF) {
		print_token(tokens[i]);
		i++;
	}
	
}

