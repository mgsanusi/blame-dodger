#include <stdio.h>
#include <stdlib.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fprintf(FILE *stream, const char *format, ...);

int qwerty(int a)
{
  if (a == 0)
    return 1;
  else
    return 10 * qwerty(a - 1);

}

int haze(int bin, int a)
{
  int in = bin / qwerty(a);
  return in % 10;
}

int Main()
{
  FILE *fp;
  fp = new_fopen("output.txt", "w");
  int s;
  int t;
  int i;
  int min;
  int bin = 1000000;
  fprintf(fp, "Case #1: \n");
  for (i = 1; i <= 50; i++)
  {
    t = 0;
    fprintf(fp, "1");
    for (min = 0; min < 7; min++)
    {
      if (haze(bin, min))
        fprintf(fp, "11");
      else
        fprintf(fp, "00");

    }

    fprintf(fp, "1 3 4 5 6 7 8 9 10 11 \n");
    if (haze(bin, 0) == 0)
      bin++;
    else
    {
      while (haze(bin, t) == 1)
      {
        t++;
      }

      bin += 9;
      for (s = 1; s < t; s++)
        bin += 8 * qwerty(s);

    }

  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}