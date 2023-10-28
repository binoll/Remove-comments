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

void remove_comments(const char* line, char* new_line, const size_t count, size_t* new_count) {
	int i = 0;
	bool is_string = false;

	strcpy(new_line, line);
	while(new_line[i] != '\0') {
		if (new_line[i] == '\"') {
			is_string = true;
		}
		if(!is_string && new_line[i] == '/' && new_line[i + 1] == '/') {
			new_line[i] = '\n';
			new_line[i + 1] = '\0';
		}
		++i;
	}
	*new_count = i;
	return;
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
		size_t new_count = 0;

		remove_comments(line, new_line, count, &new_count);
		fwrite(new_line, sizeof(char), new_count, file_dist);
	}
	fclose(file_src);
	fclose(file_dist);
	return EXIT_SUCCESS;
}

