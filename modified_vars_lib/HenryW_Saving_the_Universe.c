#include <stdio.h>
#include <string.h>
int b;
int b;
int a;
char engines[1001][1001];
char queries[1001][1001];
int costs[1001][1001];
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

void dp()
{
  int i;
  int flag;
  int b;
  for (i = 0; i < b; i++)
  {
    costs[0][i] = 0;
    if (strcmp(queries[0], engines[i]) == 0)
      costs[0][i] = 20000;

  }

  for (i = 1; i < a; i++)
  {
    for (flag = 0; flag < b; flag++)
    {
      costs[i][flag] = 20000;
      for (b = 0; b < b; b++)
      {
        if (flag == b)
          continue;

        if ((costs[i - 1][b] + 1) < costs[i][flag])
          costs[i][flag] = costs[i - 1][b] + 1;

      }

      if (strcmp(queries[i], engines[flag]))
      {
        if (costs[i - 1][flag] < costs[i][flag])
          costs[i][flag] = costs[i - 1][flag];

      }

    }

  }

  return;
}

void printarr()
{
  int i;
  int flag;
  printf("***\n");
  for (i = 0; i < a; i++, printf("\n"))
    for (flag = 0; flag < b; flag++)
    printf("%5d ", costs[i][flag]);


  printf("***\n\n");
  return;
}

void Main()
{
  FILE *y = new_fopen("input.txt", "r");
  FILE *out = new_fopen("output.txt", "w");
  int i;
  int flag;
  int mincost;
  fscanf(y, "%d ", &b);
  fprintf(stdout, "%d\n", b);
  for (i = 0; i < b; i++)
  {
    fscanf(y, "%d ", &b);
    fprintf(stdout, "%d\n", b);
    for (flag = 0; flag < b; flag++)
      new_fgets(engines[flag], 1000, y);

    fscanf(y, "%d ", &a);
    fprintf(stdout, "%d\n", a);
    for (flag = 0; flag < a; flag++)
      new_fgets(queries[flag], 1000, y);

    if (a == 0)
    {
      fprintf(out, "Case #%d: 0\n", i + 1);
      continue;
    }

    dp();
    printarr();
    mincost = 100000;
    for (flag = 0; flag < b; flag++)
      if (mincost > costs[a - 1][flag])
      mincost = costs[a - 1][flag];


    fprintf(out, "Case #%d: %d\n", i + 1, mincost);
  }

}



FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}