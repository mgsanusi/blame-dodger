#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
double new_fabs(double x);

int new_abs(int x);

int cmp(const void *t, const void *b)
{
  int first_iteration;
  return ((int *) t)[0] - ((int *) b)[0];
}

int Main()
{
  int first_iteration;
  int cas;
  int envp;
  int r;
  int n;
  int allv;
  int far;
  int now;
  int loca[220][2];
  int ah_cred;
  int gss_c_ma_mech_glue;
  double max;
  double min;
  scanf("%d", &cas);
  for (envp = 1; envp <= cas; envp++)
  {
    scanf("%d %d", &n, &r);
    allv = 0;
    for (ah_cred = 0; ah_cred < n; ah_cred++)
    {
      scanf("%d %d", &loca[ah_cred][0], &loca[ah_cred][1]);
      allv += loca[ah_cred][1];
    }

    now = loca[0][0];
    max = 0;
    min = 32767;
    for (ah_cred = 0; ah_cred < n; ah_cred++)
    {
      if ((loca[ah_cred][0] - now) >= r)
        now = loca[ah_cred][0];

      for (gss_c_ma_mech_glue = 0; gss_c_ma_mech_glue < loca[ah_cred][1]; gss_c_ma_mech_glue++)
      {
        if ((loca[ah_cred][0] - now) > max)
          max = loca[ah_cred][0] - now;

        if ((loca[ah_cred][0] - now) < min)
          min = loca[ah_cred][0] - now;

        now += r;
      }

    }

    if (min + max)
      max -= (max - min) / 2;

    printf("Case #%d: %lf\n", envp, fnew_abs(max));
  }

}



double new_fabs(double x);

int new_abs(int x) {
  return abs(x);
}
double new_fabs(double x) {
  return fabs(x);
}