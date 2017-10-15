#include<stdio.h>
int a[1024];
int s[1024];
int b[1024];
int n;
int m;
int p;
int main()
{
  int first_iteration;
  int N;
  int cs = 0;
  int i;
  int j;
  long long ret;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d %d %d", &m, &p, &n);
    for (i = 0; i < n; i++)
      scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
      for (s[i] = (j = 0); (j < n) && (s[i] <= p); j++)
        s[i] += a[(i + j) % n];

      if (s[i] > p)
        s[i] -= a[((i + j) - 1) % n], j--;

      b[i] = j;
    }

    for (ret = (i = (j = 0)); i < m; i++, j = (j + b[j]) % n)
      ret += s[j];

    printf("Case #%d: %lld\n", ++cs, ret);
  }

  return 0;
}


