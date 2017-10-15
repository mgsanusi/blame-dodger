#include "stdio.h"
#include "string.h"
double fac[1002];
double choose[1002][1002];
double derange[1002];
double f[1002];
void fill_fac()
{
  int first_iteration;
  int i = 0;
  fac[0] = 1;
  for (i = 1; i < 1002; i++)
  {
    fac[i] = fac[i - 1] * i;
  }

}

void fill_choose()
{
  int first_iteration;
  int i = 0;
  int j = 0;
  for (i = 0; i < 1002; i++)
  {
    choose[i][0] = 1;
    choose[i][i] = 1;
  }

  for (i = 0; i < 1002; i++)
  {
    for (j = 1; j < i; j++)
    {
      choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
    }

  }

}

void fill_derange()
{
  int first_iteration;
  int i = 0;
  derange[0] = 1;
  for (i = 1; i < 1002; i++)
  {
    derange[i] = (derange[i - 1] * i) + ((i % 2) == 0 ? 1 : -1);
  }

}

void fill_f()
{
  int first_iteration;
  int n = 0;
  int k = 0;
  memset(f, 0, sizeof(f));
  f[0] = 0;
  f[2] = 2;
  for (n = 3; n < 1002; n++)
  {
    f[n] = 1;
    for (k = 1; k < (n - 1); k++)
    {
      f[n] += (((double) choose[n][k]) * ((double) derange[n - k])) * ((double) (f[n - k] + 1));
    }

    f[n] = (((double) f[n]) + derange[n]) / (((double) fac[n]) - derange[n]);
  }

}

int main()
{
  int first_iteration;
  int T;
  int N;
  int t = 0;
  int i = 0;
  int j = 0;
  fill_fac();
  fill_choose();
  fill_derange();
  fill_f();
  FILE *fp;
  fp = fopen("ds0.in", "r");
  fscanf(fp, "%d", &T);
  for (t = 1; t <= T; t++)
  {
    fscanf(fp, "%d ", &N);
    int num = 0;
    int diff_cnt = 0;
    for (i = 1; i <= N; i++)
    {
      fscanf(fp, "%d", &num);
      if (num != i)
        diff_cnt++;

    }

    printf("Case #%d: %.6lf\n", t, (double) f[diff_cnt]);
  }

  fclose(fp);
  return 0;
}


