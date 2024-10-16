#include <getopt.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} use_flags;

void parser_flags(int argc, char **argv, use_flags *flags);
void read_file(char const *file_name, use_flags const *flags);