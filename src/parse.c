// Copyright 2023 binoll
#include "parse.h"
#include <stdio.h>

FILE* get_file(const char* path, const char* mode) {
    return fopen(path, mode);
}

int parse_file(FILE* file_src, FILE* file_dist) {
    char* line = NULL;
    size_t len;

    while (getline(&line, &len, file_src) != -1) {
        remove_comments(line);
        len = strlen(line);
        if (fwrite(line, sizeof(char), len, file_dist) != len) {
            fclose(file_src);
            fclose(file_dist);
            return EXIT_FAILURE;
        }
    }
    fclose(file_src);
    fclose(file_dist);
    free(line);
    return EXIT_SUCCESS;
}

void remove_comments(char* line) {
    static bool is_multiline = false;
    bool is_string = false;

    for (size_t i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '\"') {
            is_string = true;
        } else if (line[i] == ';') {
            is_string = false;
        }
        if (!is_string && !is_multiline && line[i] == '/' && line[i + 1] == '/') {
            line[i] = '\n';
            line[i + 1] = '\0';
        }
        if (!is_string && line[i] == '/' && line[i + 1] == '*') {
            is_multiline = true;
            line[i] = ' ';
        } else if (!is_string && line[i] == '*' && line[i + 1] == '/') {
            line[i] = '\n';
            line[i + 1] = '\0';
            is_multiline = false;
        } else if (!is_string && is_multiline) {
            if (line[i + 1] == '\0') {
                line[i] = '\n';
                line[i + 1] = '\0';
            } else {
                line[i] = ' ';
            }
        }
    }
}
