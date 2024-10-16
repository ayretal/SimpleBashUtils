#include "s21_cat.h"

int main(int argc, char **argv) {
  use_flags flags = {0};
  parser_flags(argc, argv, &flags);
  if (flags.b == 1) flags.n = 0;

  for (int i = optind; i < argc; i++) {
    read_file(argv[i], &flags);
  }
  return 0;
}

void parser_flags(int argc, char **argv, use_flags *flags) {
  int opt;
  static struct option options[] = {{"number-nonblank", 0, 0, 'b'},
                                    {"number", 0, 0, 'n'},
                                    {"squeeze-blank", 0, 0, 's'}};
  while ((opt = getopt_long(argc, argv, "benstvET", options, NULL)) != -1) {
    if (opt == 'b') flags->b = 1;
    if (opt == 'E') flags->e = 1;
    if (opt == 'n') flags->n = 1;
    if (opt == 's') flags->s = 1;
    if (opt == 'T') flags->t = 1;
    if (opt == 'v') flags->v = 1;
    if (opt == 'e') {
      flags->e = 1;
      flags->v = 1;
    }
    if (opt == 't') {
      flags->t = 1;
      flags->v = 1;
    }
  }
}

void read_file(char const *file_name, use_flags const *flags) {
  FILE *file = fopen(file_name, "r");

  if (file != NULL) {
    int count = 1;
    int empty = 0;
    int last = '\n';
    int current;

    while ((current = fgetc(file)) != EOF) {
      if (flags->s && current == '\n' && last == '\n') {
        empty++;
        if (empty > 1) {
          continue;
        }
      } else {
        empty = 0;
      }
      if (last == '\n' && ((flags->b && current != '\n') || flags->n))
        printf("%6d\t", count++);

      else if ((flags->b && current == '\n' && last == '\n' && flags->e))
        printf("\t");
      if (flags->e && current == '\n') printf("%c", '$');
      if (flags->t && current == '\t') {
        printf("%c", '^');
        current = 'I';
      }
      if (flags->v) {
        if (current < 32 && current != '\n' && current != '\t') {
          printf("^");
          current += 64;
        }
        if (current == 127) {
          printf("^");
          current = '?';
        }
        if (current > 127) {
          printf("M-");
          current -= 128;
        }
      }
      printf("%c", current);
      last = current;
    }
    fclose(file);
  } else {
    fprintf(stderr, "cat: %s: No such file or directory\n", file_name);
  }
}