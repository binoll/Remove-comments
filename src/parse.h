// Copyright 2023 binoll
#pragma once

#include "../lib.h"

extern FILE* get_file(const char*, const char*);

extern void remove_comments(char*);

extern int parse_file(FILE*, FILE*);
