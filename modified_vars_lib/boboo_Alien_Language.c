#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

int Main()
{
  FILE *Fin = new_fopen("a1.in", "r");
  FILE *Fout = new_fopen("a1.out", "w");
  int f;
  int t;
  int prev;
  fscanf(Fin, "%d%d%d\n", &f, &t, &prev);
  char dic[5001][17];
  int y2[17][27];
  int ratio;
  int cases;
  int k;
  int res;
  int flag;
  char ch;
  for (ratio = 1; ratio <= t; ratio++)
    new_fgets(dic[ratio], 16, Fin);

  for (k = 1; k <= prev; k++)
  {
    memset(y2, 0, sizeof(y2));
    for (cases = 1; cases <= f; cases++)
    {
      fscanf(Fin, "%c", &ch);
      if (ch == '(')
      {
        fscanf(Fin, "%c", &ch);
        while (ch != ')')
        {
          y2[cases][ch - 'a'] = 1;
          fscanf(Fin, "%c", &ch);
        }

      }
      else
        y2[cases][ch - 'a'] = 1;

    }

    fscanf(Fin, "\n");
    res = 0;
    for (ratio = 1; ratio <= t; ratio++)
    {
      for (cases = 1; (cases <= f) && (y2[cases][dic[ratio][cases - 1] - 'a'] == 1); cases++)
        ;

      if (cases > f)
        ++res;

    }

    fprintf(Fout, "Case #%d: %d\n", k, res);
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}