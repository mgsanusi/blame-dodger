#include <stdio.h>

double min(double x, double y) { return x<y?x:y; }

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int n;
    scanf("%d", &n);
    int s[n];
    int sum = 0;
    for (int i=0; i<n; i++)
    {
      scanf("%d", &s[i]);
      sum += s[i];
    }
    printf("Case #%d:", t);
    for (int i=0; i<n; i++)
    {
      double res = sum;
      for (int j=0; j<n; j++)
      {
        int reserve = sum;
        int cnt = 0;
        for (int k=0; k<n; k++)
          if (s[k] <= s[j])
          {
            reserve -= s[j] - s[k];
            cnt++;
          }
        if (reserve < 0)
          continue;
        double pv = s[j] + 1.0*reserve / cnt;
        res = min(res, pv);
      }
      printf(" %lf", res < s[i] ? 0.0 : 100.0*(res - s[i])/sum);
    }
    printf("\n");
  }
  return 0;
}
