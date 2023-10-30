// Copyright 2023 binoll
#include "parse.h"
#include <stdio.h>

FILE* get_file(const char* path, const char* mode) {
	FILE* file = NULL;

	if((file = fopen(path, mode)) == NULL) {
		printf("Error! Can not read or write %s!\n", path);
		return NULL;
	}
	return file;
}

void remove_comments(const char* line, char* new_line) {
	static bool is_multiline;
	bool is_string = false;

	strcpy(new_line, line);
	for(int i = 0; new_line[i] != '\0'; ++i) {
		if(new_line[i] == '\"') {
			is_string = true;
		}
		if(!is_string && !is_multiline && new_line[i] == '/' && new_line[i + 1] == '/') {
			new_line[i] = '\n';
			new_line[i + 1] = '\0';
		}
		if(!is_string && new_line[i] == '/' && new_line[i + 1] == '*') {
			is_multiline = true;
			new_line[i] = ' ';
		} else if(!is_string && new_line[i] == '*' && new_line[i + 1] == '/') {
			new_line[i] = '\n';
			new_line[i + 1] = '\0';
			is_multiline = false;
		} else if(!is_string && is_multiline) {
			if (new_line[i + 1] == '\0') {
				new_line[i] = '\n';
				new_line[i + 1] = '\0';
			} else {
				new_line[i] = ' ';
			}
		}
	}
}

int parse_file(FILE* file_src, FILE* file_dist) {
	size_t len = 0, count = 0;
	char* line = NULL;

	if(file_src == NULL) {
		printf("Error! Can not open FILE_SRC\n");
		return EXIT_FAILURE;
	}
	if(file_dist == NULL) {
		printf("Error! Can not open FILE_DIST\n");
		return EXIT_FAILURE;
	}

	while((count = getline(&line, &len, file_src)) != -1) {
		char new_line[count];

		remove_comments(line, new_line);
		fwrite(new_line, sizeof(char), strlen(new_line), file_dist);
	}
	fclose(file_src);
	fclose(file_dist);
	return EXIT_SUCCESS;
}
