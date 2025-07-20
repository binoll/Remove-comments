#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *get_file(const char *path, const char *mode) { return fopen(path, mode); }

void remove_comments(char *line, CommentState *state, Language lang) {
  for (size_t i = 0; line[i] != '\0'; ++i) {
    if (state->escape_next) {
      state->escape_next = false;
      continue;
    }

    // Обработка строк
    if (state->in_string) {
      if (line[i] == '\\') {
        state->escape_next = true;
      } else if (line[i] == state->string_quote) {
        state->in_string = false;
      }
      continue;
    }

    // Обработка начала строк
    if (!state->in_multiline) {
      if (line[i] == '"' || line[i] == '\'') {
        state->in_string = true;
        state->string_quote = line[i];
        continue;
      }
    }

    // Обработка комментариев
    switch (lang) {
    case LANG_C:
    case LANG_JAVA:
      if (state->in_multiline) {
        if (line[i] == '*' && line[i + 1] == '/') {
          state->in_multiline = false;
          line[i++] = ' ';
          line[i] = ' ';
        } else {
          line[i] = (line[i] == '\n') ? '\n' : ' ';
        }
      } else if (line[i] == '/' && line[i + 1] == '*') {
        state->in_multiline = true;
        line[i++] = ' ';
        line[i] = ' ';
      } else if (line[i] == '/' && line[i + 1] == '/') {
        memset(line + i, ' ', strlen(line + i));
        return;
      }
      break;

    case LANG_PYTHON:
      if (line[i] == '#') {
        memset(line + i, ' ', strlen(line + i));
        return;
      } else if (line[i] == '\\' && line[i + 1] == '\n') {
        i++; // Игнорируем экранированный перенос
      }
      break;

    case LANG_ASM:
      if (line[i] == ';' || line[i] == '#') {
        memset(line + i, ' ', strlen(line + i));
        return;
      }
      break;
    }
  }
}

int parse_file(FILE *file_src, FILE *file_dist, Language lang) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  CommentState state = {false, false, false, 0};

  while ((read = getline(&line, &len, file_src)) != -1) {
    if (read == -1)
      break; // Обработка ошибки чтения

    remove_comments(line, &state, lang);
    size_t line_len = strlen(line);

    if (fwrite(line, 1, line_len, file_dist) != line_len) {
      free(line);
      return EXIT_FAILURE;
    }
  }

  free(line);
  return EXIT_SUCCESS;
}
