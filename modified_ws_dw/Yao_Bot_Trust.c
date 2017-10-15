#include<stdio.h>
int main()
{
  int first_iteration;
  int a[1024];
  int s;
  int N;
  int n;
  int i;
  int j;
  int cs = 0;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d", &n);
    for (s = (i = 0); i < n; i++)
      scanf("%d", &a[i]), s ^= a[i];

    if (s)
    {
      printf("Case #%d: NO\n", ++cs);
      continue;
    }

    for (s = (i = (j = 0)); i < n; i++)
    {
      s += a[i];
      if (a[i] < a[j])
        j = i;

    }

    printf("Case #%d: %d\n", ++cs, s - a[j]);
  }

  return 0;
}


