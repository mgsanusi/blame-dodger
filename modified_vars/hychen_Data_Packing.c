#include<stdio.h>
#include<math.h>
double p1000[1000][1000];
double useSize[3][1000];
void readtable()
{
  int sum;
  int b;
  int n;
  n = 1000;
  FILE *e1;
  e1 = fopen("table1000.txt", "r");
  for (sum = 0; sum < n; sum++)
  {
    for (b = 0; b < n; b++)
    {
      fscanf(e1, "%lf", p1000[sum] + b);
    }

  }

  fclose(e1);
  n = 3;
  e1 = fopen("table3.txt", "r");
  for (sum = 0; sum < n; sum++)
  {
    for (b = 0; b < n; b++)
    {
      fscanf(e1, "%lf", useSize[sum] + b);
    }

  }

  fclose(e1);
}

int d[1000];
int Main(int argc, char *argv[])
{
  int sum;
  int t;
  int e1;
  int n;
  double (*v)[1000];
  double x;
  readtable();
  scanf("%d", &t);
  for (e1 = 1; e1 <= t; e1++)
  {
    scanf("%d", &n);
    if (n == 1000)
      v = p1000;
    else
      if (n == 3)
      v = useSize;
    else
      continue;


    for (sum = 0; sum < n; sum++)
    {
      scanf("%d", d + sum);
    }

    x = 1;
    for (sum = 0; sum < n; sum++)
    {
      x *= v[sum][d[sum]] * n;
    }

    printf("Case #%d: ", e1);
    puts(x < 1 ? "GOOD" : "BAD");
  }

  return 0;
}


