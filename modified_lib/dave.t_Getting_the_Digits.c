#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

int count[256];
int digits[10];

char S[3000];
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);


int main(void) {

  int i, k, len, t, T;

  in = new_fopen(fileNameIn, "r");
  out = new_fopen(fileNameOut, "w");

  fscanf(in,"%d",&T);
  
  for (t=1; t <= T; t++) {
    for (i=0; i < 26; ++i) {
      count['A' + i] = 0;
    }
    for (i=0; i < 10; ++i) {
      digits[i] = 0;
    }
    fprintf(out, "Case #%d: ", t);
    fscanf(in, "%s", S);
    len = strlen(S);
    for (i=0; i < len; ++i) {
      count[S[i]]++;
    }
    digits[0] = count['Z'];
    digits[2] = count['W'];
    digits[6] = count['X'];
    digits[7] = count['S'] - digits[6];
    digits[5] = count['V'] - digits[7];
    digits[8] = count['G'];
    digits[3] = count['H'] - digits[8];
    digits[4] = count['F'] - digits[5];
    digits[9] = count['I'] - digits[5] - digits[6] - digits[8];
    digits[1] = count['O'] - digits[0] - digits[2] - digits[4];
    
    for (i=0; i < 10; ++i) {
      for (k=0; k < digits[i]; ++k) {
        fprintf(out, "%d", i);
      }
    }
    fprintf(out, "\n");
  }

  new_fclose(in);
  new_fclose(out);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}