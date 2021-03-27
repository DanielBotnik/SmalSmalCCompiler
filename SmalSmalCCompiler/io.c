#include "io.h"
#include <sys/types.h>

char* read_file(const char* filename) {
    FILE* file;
    fopen_s(&file,filename, "rb");
    fseek(file, 0, SEEK_END);
    unsigned int fileSize = ftell(file);
    rewind(file);
    char* buffer = malloc(fileSize + 1);
    fread(buffer, sizeof(char), fileSize, file);
    fclose(file);
    buffer[fileSize] = '\0';
    return buffer;
}
