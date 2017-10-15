#include<stdio.h>
#include<stdlib.h>
int b[32];
int a[1024];
int n;
int m;
int p;
int main()
{
  int first_iteration;
  int N;
  int i;
  int j;
  int cs = 0;
  int ret;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d %d %d", &n, &m, &p);
    for (i = 0; i < 32; i++)
      b[i] = 0;

    for (i = 0; i < n; i++)
      scanf("%d", &a[i]), b[a[i]]++;

    ret = 0;
    for (i = 0; i <= 30; i++)
      if (b[i])
    {
      if (i >= ((p * 3) - 2))
        ret += b[i];
      else
        if (((i >= ((p * 3) - 4)) && m) && i)
      {
        if (m > b[i])
          ret += b[i], m -= b[i];
        else
          ret += m, m = 0;

      }


    }


    printf("Case #%d: %d\n", ++cs, ret);
  }

  return 0;
}


