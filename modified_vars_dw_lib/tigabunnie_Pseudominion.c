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
  int trialCase;
  int teamsPlayed;
  int hotTemp;
  int tmp;
  int t;
  int t;
  int z;
  int win;
  int gamePlay;
  int cnt;
  double sw[100];
  double owp[100];
  double oowp[100];
  double rpi[100];
  char readChar;
  char matchTable[100][100];
  FILE *fpIn;
  FILE *fpOut;
  if (argc != 3)
  {
    printf("provide input and output file names as first 2 command line parameters\n");
    new_exit(1);
  }

  if ((fpIn = new_fopen(argv[1], "r")) == 0)
  {
    printf("can't open file %s\n", argv[1]);
    new_exit(1);
  }

  if ((fpOut = new_fopen(argv[2], "w")) == 0)
  {
    printf("can't open file %s\n", argv[2]);
    new_exit(1);
  }

  fscanf(fpIn, "%d\n", &trialCase);
  for (teamsPlayed = 1; teamsPlayed <= trialCase; teamsPlayed++)
  {
    fscanf(fpIn, "%d\n", &z);
    for (hotTemp = 0; hotTemp < z; hotTemp++)
    {
      for (tmp = 0; tmp < z; tmp++)
      {
        fscanf(fpIn, "%c", &readChar);
        matchTable[hotTemp][tmp] = readChar;
      }

      fscanf(fpIn, "\n");
    }

    for (hotTemp = 0; hotTemp < z; hotTemp++)
    {
      gamePlay = 0;
      win = 0;
      for (tmp = 0; tmp < z; tmp++)
        if (matchTable[hotTemp][tmp] != '.')
      {
        gamePlay++;
        if (matchTable[hotTemp][tmp] == '1')
          win++;

      }


      sw[hotTemp] = ((double) win) / gamePlay;
    }

    for (hotTemp = 0; hotTemp < z; hotTemp++)
    {
      cnt = 0;
      owp[hotTemp] = 0;
      for (tmp = 0; tmp < z; tmp++)
        if (matchTable[hotTemp][tmp] != '.')
      {
        win = 0;
        gamePlay = 0;
        for (t = 0; t < z; t++)
          if ((t != hotTemp) && (matchTable[tmp][t] != '.'))
        {
          gamePlay++;
          if (matchTable[tmp][t] == '1')
            win++;

        }


        owp[hotTemp] += ((double) win) / gamePlay;
        cnt++;
      }


      owp[hotTemp] /= cnt;
    }

    for (hotTemp = 0; hotTemp < z; hotTemp++)
    {
      cnt = 0;
      oowp[hotTemp] = 0;
      for (tmp = 0; tmp < z; tmp++)
        if (matchTable[hotTemp][tmp] != '.')
      {
        oowp[hotTemp] += owp[tmp];
        cnt++;
      }


      oowp[hotTemp] /= cnt;
    }

    for (hotTemp = 0; hotTemp < z; hotTemp++)
    {
      rpi[hotTemp] = ((0.25 * sw[hotTemp]) + (0.5 * owp[hotTemp])) + (0.25 * oowp[hotTemp]);
    }

    fprintf(fpOut, "Case #%d:\n", teamsPlayed);
    for (hotTemp = 0; hotTemp < z; hotTemp++)
    {
      fprintf(fpOut, "%lf\n", rpi[hotTemp]);
    }

  }

  new_fclose(fpIn);
  new_fclose(fpOut);
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