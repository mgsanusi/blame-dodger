#include <stdio.h>
#include <stdlib.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

int Main(int argc, char **argv)
{
  int first_iteration;
  int test_case;
  int previst;
  int target;
  int out;
  int a;
  int c;
  int row;
  int col;
  char read_char;
  char tile[50][50];
  char be_act;
  char be_there_solution;
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

  fscanf(fp_in, "%d\n", &test_case);
  for (previst = 1; previst <= test_case; previst++)
  {
    fscanf(fp_in, "%d %d\n", &row, &col);
    for (target = 0; target < row; target++)
    {
      for (out = 0; out < col; out++)
      {
        fscanf(fp_in, "%c", &read_char);
        tile[target][out] = read_char;
      }

      fscanf(fp_in, "\n");
    }

    do
    {
      be_act = 1;
      for (target = 0; target < (row - 1); target++)
        for (out = 0; out < (col - 1); out++)
      {
        if ((((((tile[target][out] == '#') && (tile[target + 1][out] == '#')) && (tile[target][out + 1] == '#')) && (tile[target + 1][out + 1] == '#')) && ((target == 0) || (tile[target - 1][out] != '#'))) && ((out == 0) || (tile[target][out - 1] != '#')))
        {
          be_act = 0;
          tile[target][out] = '/';
          tile[target + 1][out] = '\\';
          tile[target][out + 1] = '\\';
          tile[target + 1][out + 1] = '/';
        }

      }


    }
    while (be_act == 0);
    be_there_solution = 1;
    for (target = 0; target < row; target++)
      for (out = 0; out < col; out++)
      if (tile[target][out] == '#')
    {
      be_there_solution = 0;
      target = row;
      break;
    }



    fprintf(fp_out, "Case #%d:\n", previst);
    if (be_there_solution)
    {
      for (target = 0; target < row; target++)
      {
        for (out = 0; out < col; out++)
          fprintf(fp_out, "%c", tile[target][out]);

        fprintf(fp_out, "\n");
      }

    }
    else
      fprintf(fp_out, "Impossible\n");

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