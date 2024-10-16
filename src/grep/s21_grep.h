#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5000

struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
};

void flag_parser(int argc, char **argv, struct flags *flags, char *patternE);
void processing(struct flags const *flags, FILE *fp, regex_t reg,
                char const *file, int count_files);
void grep_file(struct flags const *flags, char *pattern, char const *file,
               int count_files);
int f_flag(char *pattern, char const *temp);
void grep(struct flags const *flags, int argc, char **argv, char const *temp);
void initStruct(struct flags *flags);
