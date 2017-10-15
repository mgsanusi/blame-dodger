#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void new_exit(int status);
int main(int argc, char **argv)
{
  int first_iteration;
  char str[100];
  char combine_table[26][26];
  char destroy_table[26][26];
  char output_str[100];
  int test_cases;
  int num_combine;
  int num_destroy;
  int num_invoke;
  int i;
  int j;
  int k;
  int n;
  int output_str_size;
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

  fscanf(fp_in, "%d\n", &test_cases);
  for (i = 1; i <= test_cases; i++)
  {
    for (j = 0; j < 26; j++)
      for (k = 0; k < 26; k++)
    {
      combine_table[j][k] = 0;
      destroy_table[j][k] = 0;
    }


    fscanf(fp_in, "%d", &num_combine);
    for (j = 0; j < num_combine; j++)
    {
      fscanf(fp_in, " %s", str);
      j = str[0] - 'A';
      k = str[1] - 'A';
      n = (str[2] - 'A') + 1;
      combine_table[j][k] = n;
      combine_table[k][j] = n;
    }

    fscanf(fp_in, "%d", &num_destroy);
    for (j = 0; j < num_destroy; j++)
    {
      fscanf(fp_in, " %s", str);
      j = str[0] - 'A';
      k = str[1] - 'A';
      destroy_table[j][k] = 1;
      destroy_table[k][j] = 1;
    }

    fscanf(fp_in, "%d", &num_invoke);
    fscanf(fp_in, " %s\n", str);
    output_str_size = 0;
    for (j = 0; j < num_invoke; j++)
    {
      if (output_str_size == 0)
        output_str[output_str_size++] = str[j];
      else
      {
        k = str[j] - 'A';
        n = output_str[output_str_size - 1] - 'A';
        if (combine_table[k][n])
        {
          output_str[output_str_size - 1] = (combine_table[k][n] - 1) + 'A';
        }
        else
        {
          for (n = 0; n < output_str_size; n++)
            if (destroy_table[k][output_str[n] - 'A'])
          {
            output_str_size = 0;
            break;
          }


          if (output_str_size)
          {
            output_str[output_str_size++] = str[j];
          }

        }

      }

    }

    fprintf(fp_out, "Case #%d: [", i);
    for (j = 0; j < (output_str_size - 1); j++)
      fprintf(fp_out, "%c, ", output_str[j]);

    for (; j < output_str_size; j++)
      fprintf(fp_out, "%c", output_str[j]);

    fprintf(fp_out, "]\n");
  }

  new_fclose(fp_in);
  new_fclose(fp_out);
  return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void new_exit(int status)
{
  int first_iteration;
  return exit(status);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


