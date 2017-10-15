#include "stdio.h"
#include "string.h"
double fac[1002];
double choose[1002][1002];
double derange[1002];
double b[1002];
void fill_fac()
{
  int first_iteration;
  int bn = 0;
  fac[0] = 1;
  for (bn = 1; bn < 1002; bn++)
  {
    fac[bn] = fac[bn - 1] * bn;
  }

}

void fill_choose()
{
  int first_iteration;
  int bn = 0;
  int number = 0;
  for (bn = 0; bn < 1002; bn++)
  {
    choose[bn][0] = 1;
    choose[bn][bn] = 1;
  }

  for (bn = 0; bn < 1002; bn++)
  {
    for (number = 1; number < bn; number++)
    {
      choose[bn][number] = choose[bn - 1][number] + choose[bn - 1][number - 1];
    }

  }

}

void fill_derange()
{
  int first_iteration;
  int bn = 0;
  derange[0] = 1;
  for (bn = 1; bn < 1002; bn++)
  {
    derange[bn] = (derange[bn - 1] * bn) + ((bn % 2) == 0 ? 1 : -1);
  }

}

void fill_f()
{
  int first_iteration;
  int n = 0;
  int k = 0;
  memset(b, 0, sizeof(b));
  b[0] = 0;
  b[2] = 2;
  for (n = 3; n < 1002; n++)
  {
    b[n] = 1;
    for (k = 1; k < (n - 1); k++)
    {
      b[n] += (((double) choose[n][k]) * ((double) derange[n - k])) * ((double) (b[n - k] + 1));
    }

    b[n] = (((double) b[n]) + derange[n]) / (((double) fac[n]) - derange[n]);
  }

}

int Main()
{
  int first_iteration;
  int t;
  int group;
  int p1 = 0;
  int bn = 0;
  int number = 0;
  fill_fac();
  fill_choose();
  fill_derange();
  fill_f();
  FILE *fp;
  fp = fopen("ds0.in", "r");
  fscanf(fp, "%d", &t);
  for (p1 = 1; p1 <= t; p1++)
  {
    fscanf(fp, "%d ", &group);
    int num = 0;
    int diff_cnt = 0;
    for (bn = 1; bn <= group; bn++)
    {
      fscanf(fp, "%d", &num);
      if (num != bn)
        diff_cnt++;

    }

    printf("Case #%d: %.6lf\n", p1, (double) b[diff_cnt]);
  }

  fclose(fp);
  return 0;
}


