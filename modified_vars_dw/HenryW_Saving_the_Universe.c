#include <stdio.h>
#include <string.h>
int b;
int b;
int a;
char engines[1001][1001];
char queries[1001][1001];
int costs[1001][1001];
void dp()
{
  int first_iteration;
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
  int first_iteration;
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
  int first_iteration;
  FILE *y = fopen("input.txt", "r");
  FILE *out = fopen("output.txt", "w");
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
      fgets(engines[flag], 1000, y);

    fscanf(y, "%d ", &a);
    fprintf(stdout, "%d\n", a);
    for (flag = 0; flag < a; flag++)
      fgets(queries[flag], 1000, y);

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


