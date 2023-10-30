// Copyright 2023 binoll
#pragma once

#include "../lib.h"

FILE* get_file(const char* path, const char* mode);
void remove_comments(const char* line, char* new_line);
int parse_file(FILE* file_src, FILE* file_dist);
