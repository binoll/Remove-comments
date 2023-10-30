// Copyright 2023 binoll
#include "src/parse.h"

int main(int argc, char* argv[]) {
	const char* name = argv[0];
	const char* path_src = argv[1];
	const char* path_dist = argv[2];
	FILE* file_src = NULL;
	FILE* file_dist = NULL;

	if(argc != 3) {
		printf("Error! Usage: %s \"path_src\" \"path_dist\"\n", name);
		exit(EXIT_FAILURE);
	}
	if((file_src = get_file(path_src, "r")) == NULL) {
		printf("Error! Can not open %s\n", path_src);
		exit(EXIT_FAILURE);
	}
	if((file_dist = get_file(path_dist, "w")) == NULL) {
		printf("Error! Can not open %s\n", path_dist);
		exit(EXIT_FAILURE);
	}
	parse_file(file_src, file_dist);
	return EXIT_SUCCESS;
}

