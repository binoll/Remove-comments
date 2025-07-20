#include "parse.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "[-] Usage: %s <language> <input> <output>\n", argv[0]);
    fprintf(stderr, "    Languages: c, python, asm, java\n");
    return EXIT_FAILURE;
  }

  // Определение языка
  Language lang;
  if (strcmp(argv[1], "c") == 0)
    lang = LANG_C;
  else if (strcmp(argv[1], "python") == 0)
    lang = LANG_PYTHON;
  else if (strcmp(argv[1], "asm") == 0)
    lang = LANG_ASM;
  else if (strcmp(argv[1], "java") == 0)
    lang = LANG_JAVA;
  else {
    fprintf(stderr, "[-] Unknown language: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Открытие файлов
  FILE *file_src = fopen(argv[2], "r");
  FILE *file_dist = fopen(argv[3], "w");
  if (!file_src || !file_dist) {
    fprintf(stderr, "[-] File error\n");
    if (file_src)
      fclose(file_src);
    if (file_dist)
      fclose(file_dist);
    return EXIT_FAILURE;
  }

  // Обработка файла
  if (parse_file(file_src, file_dist, lang) != EXIT_SUCCESS) {
    fprintf(stderr, "[-] Processing error\n");
    fclose(file_src);
    fclose(file_dist);
    return EXIT_FAILURE;
  }

  // Завершение работы
  fclose(file_src);
  fclose(file_dist);
  printf("[+] Comments removed successfully\n");
  return EXIT_SUCCESS;
}
