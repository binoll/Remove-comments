// Copyright 2023 binoll
#include "src/parse.h"

int main(int argc, char* argv[]) {
    const char* name = argv[0];
    const char* path_src = argv[1];
    const char* path_dist = argv[2];
    FILE* file_src = NULL;
    FILE* file_dist = NULL;

    if (argc != 3) {
        fprintf(stderr, "[-] Error: Usage: %s (path_src) (path_dist).\n", name);
        return EXIT_FAILURE;
    }
    if ((file_src = get_file(path_src, "r")) == NULL) {
        fprintf(stderr, "[-] Error: Can not open \"%s\".\n", path_src);
        return EXIT_FAILURE;
    }
    if ((file_dist = get_file(path_dist, "w")) == NULL) {
        fprintf(stderr, "[-] Error: Can not open \"%s\".\n", path_dist);
        return EXIT_FAILURE;
    }
    if (parse_file(file_src, file_dist) == EXIT_FAILURE) {
        fprintf(stderr, "[-] Error: Something went wrong...\n");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "[+] Success: The comments have been deleted!\n");
    return EXIT_SUCCESS;
}
