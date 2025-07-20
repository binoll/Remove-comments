#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef enum { LANG_C, LANG_PYTHON, LANG_ASM } Language;

typedef struct CommentState {
  bool in_comment;   // Для однострочных комментариев
  bool in_multiline; // Для многострочных комментариев
  bool in_string;    // Внутри строки
  bool escape_next;  // Экранирование следующего символа
  char string_quote; // Тип кавычки для строки
} CommentState;

extern FILE *get_file(const char *, const char *);

extern void remove_comments(char *, CommentState *, Language);

extern int parse_file(FILE *, FILE *, Language);
