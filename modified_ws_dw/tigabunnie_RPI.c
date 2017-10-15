#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  int first_iteration;
  int test_cases;
  int i;
  int j;
  int k;
  int n;
  int m;
  int row;
  int col;
  char read_char;
  char tiles[50][50];
  char is_done;
  char is_there_solution;
  FILE *fp_in;
  FILE *fp_out;
  if (argc != 3)
  {
    printf("provide input and output file names as first 2 command line parameters\n");
    exit(1);
  }

  if ((fp_in = fopen(argv[1], "r")) == 0)
  {
    printf("can't open file %s\n", argv[1]);
    exit(1);
  }

  if ((fp_out = fopen(argv[2], "w")) == 0)
  {
    printf("can't open file %s\n", argv[2]);
    exit(1);
  }

  fscanf(fp_in, "%d\n", &test_cases);
  for (i = 1; i <= test_cases; i++)
  {
    fscanf(fp_in, "%d %d\n", &row, &col);
    for (j = 0; j < row; j++)
    {
      for (k = 0; k < col; k++)
      {
        fscanf(fp_in, "%c", &read_char);
        tiles[j][k] = read_char;
      }

      fscanf(fp_in, "\n");
    }

    do
    {
      is_done = 1;
      for (j = 0; j < (row - 1); j++)
        for (k = 0; k < (col - 1); k++)
      {
        if ((((((tiles[j][k] == '#') && (tiles[j + 1][k] == '#')) && (tiles[j][k + 1] == '#')) && (tiles[j + 1][k + 1] == '#')) && ((j == 0) || (tiles[j - 1][k] != '#'))) && ((k == 0) || (tiles[j][k - 1] != '#')))
        {
          is_done = 0;
          tiles[j][k] = '/';
          tiles[j + 1][k] = '\\';
          tiles[j][k + 1] = '\\';
          tiles[j + 1][k + 1] = '/';
        }

      }


    }
    while (is_done == 0);
    is_there_solution = 1;
    for (j = 0; j < row; j++)
      for (k = 0; k < col; k++)
      if (tiles[j][k] == '#')
    {
      is_there_solution = 0;
      j = row;
      break;
    }



    fprintf(fp_out, "Case #%d:\n", i);
    if (is_there_solution)
    {
      for (j = 0; j < row; j++)
      {
        for (k = 0; k < col; k++)
          fprintf(fp_out, "%c", tiles[j][k]);

        fprintf(fp_out, "\n");
      }

    }
    else
      fprintf(fp_out, "Impossible\n");

  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}


