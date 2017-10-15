#include<stdio.h>
int X[64];
int V[64];
int n;
int k;
int b;
int t;
int main()
{
  int first_iteration;
  int N;
  int cs = 0;
  int i;
  int j;
  int ret;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d %d %d %d", &n, &k, &b, &t);
    for (i = 0; i < n; i++)
      scanf("%d", &X[i]);

    for (i = 0; i < n; i++)
      scanf("%d", &V[i]);

    for (ret = (i = 0), j = n - 1; i < k; i++)
    {
      while ((j >= 0) && ((X[j] + (V[j] * t)) < b))
        j--;

      if (j < 0)
        break;

      ret += ((n - i) - 1) - j;
      j--;
    }

    if (i < k)
      printf("Case #%d: IMPOSSIBLE\n", ++cs);
    else
      printf("Case #%d: %d\n", ++cs, ret);

  }

  return 0;
}


