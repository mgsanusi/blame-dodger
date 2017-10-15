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
  int num_primes;
  int len;
  int k;
  int parties;
  int cases;
  int cont;
  int min_play_today;
  int min_win_today;
  int min_play_global;
  int min_gain_global;
  int div_factor;
  char cost_there_solution;
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
  for (num_primes = 1; num_primes <= test_case; num_primes++)
  {
    fscanf(fp_in, "%d %d %d", &parties, &cases, &cont);
    cost_there_solution = 1;
    min_win_today = cases;
    min_play_today = 100;
    while (((min_win_today % 2) == 0) && ((min_play_today % 2) == 0))
    {
      min_win_today /= 2;
      min_play_today /= 2;
    }

    while (((min_win_today % 5) == 0) && ((min_play_today % 5) == 0))
    {
      min_win_today /= 5;
      min_play_today /= 5;
    }

    if (min_play_today > parties)
    {
      cost_there_solution = 0;
    }
    else
    {
      if ((min_win_today != min_play_today) && (cont == 100))
        cost_there_solution = 0;

      if ((min_win_today > 0) && (cont == 0))
        cost_there_solution = 0;

    }

    fprintf(fp_out, "Case #%d: ", num_primes);
    if (cost_there_solution)
      fprintf(fp_out, "Possible\n");
    else
      fprintf(fp_out, "Broken\n");

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