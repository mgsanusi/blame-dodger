#include <stdio.h>
#include <stdlib.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

int Main(int argc, char **argv)
{
  int test_case;
  int no_candy;
  int min_candy;
  int candy_sum;
  int candy_mask;
  int i;
  int res;
  int l;
  FILE *fp_in;
  FILE *fp_out;
  if (argc != 3)
  {
    printf("provide input and output file names as first 2 command line parameters\n");
    new_exit(1);
  }

  if ((fp_in = new_fopen(argv[1], "r")) == 0)
  {
    printf("can't open file %s\n", argv[1]);
    new_exit(1);
  }

  if ((fp_out = new_fopen(argv[2], "w")) == 0)
  {
    printf("can't open file %s\n", argv[2]);
    new_exit(1);
  }

  fscanf(fp_in, "%d", &test_case);
  for (i = 1; i <= test_case; i++)
  {
    fscanf(fp_in, "%d", &no_candy);
    candy_mask = 0;
    candy_sum = 0;
    min_candy = 0x3fffffff;
    for (res = 0; res < no_candy; res++)
    {
      fscanf(fp_in, "%d", &l);
      if (l < min_candy)
        min_candy = l;

      candy_mask ^= l;
      candy_sum += l;
    }

    fprintf(fp_out, "Case #%d: ", i);
    if (candy_mask)
      fprintf(fp_out, "NO\n");
    else
      fprintf(fp_out, "%d\n", candy_sum - min_candy);

  }

  new_fclose(fp_in);
  new_fclose(fp_out);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}