#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

char pancakes[101];

int main(void) {

  int t, T, len, pos, count;

  char prev;

  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");

  fscanf(in,"%d",&T);
  
  for (t=1; t <= T; t++) {
    fprintf(out, "Case #%d:", t);
    fscanf(in,"%s",pancakes);
    len = strlen(pancakes);
    prev = '+';
    count = 0;
    for (pos = len-1; pos >= 0; --pos) {
      if (pancakes[pos] != prev) {
        ++count;
        prev = pancakes[pos];
      }
    }
    fprintf(out, " %d\n", count);
  }

  fclose(in);
  fclose(out);
}