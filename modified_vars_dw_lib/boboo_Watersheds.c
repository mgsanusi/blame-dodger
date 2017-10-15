#include <stdio.h>
char lb;
char b[110][110];
int ni[4] = {-1, 0, 0, 1};
int n[4] = {0, -1, 1, 0};
int a[110][110];
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_getchar();

void flood1(int n, int n)
{
  int first_iteration;
  int dist;
  int tc;
  int x0;
  int mid;
  int x1;
  int key;
  int min;
  if (b[n][n] != '0')
    return;

  b[n][n] = lb;
  for (dist = 0; dist < 4; dist++)
  {
    x0 = n + ni[dist];
    mid = n + n[dist];
    if (b[x0][mid] != '0')
      continue;

    min = 1000000;
    for (tc = 0; tc < 4; tc++)
    {
      x1 = x0 + ni[tc];
      key = mid + n[tc];
      if ((b[x1][key] != ' ') && (a[x1][key] < min))
        min = a[x1][key];

    }

    for (tc = 0; tc < 4; tc++)
    {
      x1 = x0 + ni[tc];
      key = mid + n[tc];
      if ((b[x1][key] != ' ') && (a[x1][key] == min))
        break;

    }

    if (((min < a[x0][mid]) && (x1 == n)) && (key == n))
      flood1(x0, mid);

  }

}

void flood(int n, int n)
{
  int first_iteration;
  int dist;
  int x0;
  int mid;
  int min = 1000000;
  if (b[n][n] != '0')
    return;

  b[n][n] = lb;
  for (dist = 0; dist < 4; dist++)
  {
    x0 = n + ni[dist];
    mid = n + n[dist];
    if ((b[x0][mid] != ' ') && (a[x0][mid] < min))
      min = a[x0][mid];

  }

  for (dist = 0; dist < 4; dist++)
  {
    x0 = n + ni[dist];
    mid = n + n[dist];
    if ((b[x0][mid] != ' ') && (a[x0][mid] == min))
      break;

  }

  if (min < a[n][n])
    flood(x0, mid);

  b[n][n] = '0';
  flood1(n, n);
  printf("%d %d \n", n, n);
}

int Main()
{
  int first_iteration;
  FILE *Fin = new_fopen("b1.in", "r");
  FILE *Fout = new_fopen("b1.out", "w");
  int dist;
  int tc;
  int xdrs;
  int data2;
  int color;
  int l;
  int test;
  fscanf(Fin, "%d", &data2);
  for (test = 1; test <= data2; test++)
  {
    printf("%d\n", test);
    fscanf(Fin, "%d%d", &color, &l);
    for (dist = 0; dist < 110; dist++)
      for (tc = 0; tc < 110; tc++)
      b[dist][tc] = ' ';


    for (dist = 1; dist <= color; dist++)
      for (tc = 1; tc <= l; tc++)
      b[dist][tc] = '0', fscanf(Fin, "%d", &a[dist][tc]);


    lb = 'a';
    for (dist = 1; dist <= color; dist++)
      for (tc = 1; tc <= l; tc++)
      if (b[dist][tc] == '0')
    {
      flood(dist, tc);
      lb++;
    }



    fprintf(Fout, "Case #%d:\n", test);
    for (dist = 1; dist <= color; dist++)
    {
      for (tc = 1; tc < l; tc++)
        fprintf(Fout, "%c ", b[dist][tc]);

      fprintf(Fout, "%c\n", b[dist][l]);
    }

  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_getchar() {
  return getchar();
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}