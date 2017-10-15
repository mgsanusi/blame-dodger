#include <stdio.h>
char ch;
char b[110][110];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int a[110][110];
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_getchar();
void Flood1(int x, int y)
{
  int first_iteration;
  int i;
  int j;
  int x0;
  int y0;
  int x1;
  int y1;
  int min;
  if (b[x][y] != '0')
    return;

  b[x][y] = ch;
  for (i = 0; i < 4; i++)
  {
    x0 = x + dx[i];
    y0 = y + dy[i];
    if (b[x0][y0] != '0')
      continue;

    min = 1000000;
    for (j = 0; j < 4; j++)
    {
      x1 = x0 + dx[j];
      y1 = y0 + dy[j];
      if ((b[x1][y1] != ' ') && (a[x1][y1] < min))
        min = a[x1][y1];

    }

    for (j = 0; j < 4; j++)
    {
      x1 = x0 + dx[j];
      y1 = y0 + dy[j];
      if ((b[x1][y1] != ' ') && (a[x1][y1] == min))
        break;

    }

    if (((min < a[x0][y0]) && (x1 == x)) && (y1 == y))
      Flood1(x0, y0);

  }

}

void Flood(int x, int y)
{
  int first_iteration;
  int i;
  int x0;
  int y0;
  int min = 1000000;
  if (b[x][y] != '0')
    return;

  b[x][y] = ch;
  for (i = 0; i < 4; i++)
  {
    x0 = x + dx[i];
    y0 = y + dy[i];
    if ((b[x0][y0] != ' ') && (a[x0][y0] < min))
      min = a[x0][y0];

  }

  for (i = 0; i < 4; i++)
  {
    x0 = x + dx[i];
    y0 = y + dy[i];
    if ((b[x0][y0] != ' ') && (a[x0][y0] == min))
      break;

  }

  if (min < a[x][y])
    Flood(x0, y0);

  b[x][y] = '0';
  Flood1(x, y);
  printf("%d %d \n", x, y);
}

int main()
{
  int first_iteration;
  FILE *fin = new_fopen("b1.in", "r");
  FILE *fout = new_fopen("b1.out", "w");
  int i;
  int j;
  int k;
  int t;
  int h;
  int w;
  int test;
  fscanf(fin, "%d", &t);
  for (test = 1; test <= t; test++)
  {
    printf("%d\n", test);
    fscanf(fin, "%d%d", &h, &w);
    for (i = 0; i < 110; i++)
      for (j = 0; j < 110; j++)
      b[i][j] = ' ';


    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
      b[i][j] = '0', fscanf(fin, "%d", &a[i][j]);


    ch = 'a';
    for (i = 1; i <= h; i++)
      for (j = 1; j <= w; j++)
      if (b[i][j] == '0')
    {
      Flood(i, j);
      ch++;
    }



    fprintf(fout, "Case #%d:\n", test);
    for (i = 1; i <= h; i++)
    {
      for (j = 1; j < w; j++)
        fprintf(fout, "%c ", b[i][j]);

      fprintf(fout, "%c\n", b[i][w]);
    }

  }

  return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_getchar()
{
  int first_iteration;
  return getchar();
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}


