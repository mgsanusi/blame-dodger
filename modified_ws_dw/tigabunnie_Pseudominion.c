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
  int N;
  int wins;
  int games_played;
  int count;
  double wp[100];
  double owp[100];
  double oowp[100];
  double rpi[100];
  char read_char;
  char match_table[100][100];
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
    fscanf(fp_in, "%d\n", &N);
    for (j = 0; j < N; j++)
    {
      for (k = 0; k < N; k++)
      {
        fscanf(fp_in, "%c", &read_char);
        match_table[j][k] = read_char;
      }

      fscanf(fp_in, "\n");
    }

    for (j = 0; j < N; j++)
    {
      games_played = 0;
      wins = 0;
      for (k = 0; k < N; k++)
        if (match_table[j][k] != '.')
      {
        games_played++;
        if (match_table[j][k] == '1')
          wins++;

      }


      wp[j] = ((double) wins) / games_played;
    }

    for (j = 0; j < N; j++)
    {
      count = 0;
      owp[j] = 0;
      for (k = 0; k < N; k++)
        if (match_table[j][k] != '.')
      {
        wins = 0;
        games_played = 0;
        for (n = 0; n < N; n++)
          if ((n != j) && (match_table[k][n] != '.'))
        {
          games_played++;
          if (match_table[k][n] == '1')
            wins++;

        }


        owp[j] += ((double) wins) / games_played;
        count++;
      }


      owp[j] /= count;
    }

    for (j = 0; j < N; j++)
    {
      count = 0;
      oowp[j] = 0;
      for (k = 0; k < N; k++)
        if (match_table[j][k] != '.')
      {
        oowp[j] += owp[k];
        count++;
      }


      oowp[j] /= count;
    }

    for (j = 0; j < N; j++)
    {
      rpi[j] = ((0.25 * wp[j]) + (0.5 * owp[j])) + (0.25 * oowp[j]);
    }

    fprintf(fp_out, "Case #%d:\n", i);
    for (j = 0; j < N; j++)
    {
      fprintf(fp_out, "%lf\n", rpi[j]);
    }

  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}


