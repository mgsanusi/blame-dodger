#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void doTestCase();
int main()
{
  int first_iteration;
  int i;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    printf("Case #%d: ", i);
    doTestCase();
  }

  return 0;
}

void doTestCase()
{
  int first_iteration;
  int p;
  int i;
  int t;
  int c = 0;
  scanf("%d", &p);
  int l = 1 << p;
  int M[l];
  int PM[l];
  for (i = 0; i < l; i++)
  {
    scanf("%d", &t);
    M[i] = p - t;
    PM[i] = 0;
  }

  for (i = 0; i < (l - 1); i++)
  {
    scanf("%*d");
  }

  int r;
  int sr;
  int ri;
  char f;
  for (ri = p; ri >= 1; ri--)
  {
    r = 1 << ri;
    f = 0;
    for (sr = 0; sr < l; sr += r)
    {
      for (i = sr; i < (sr + r); i++)
      {
        if (PM[i] < M[i])
        {
          f = 1;
          break;
        }

      }

      if (i < (sr + r))
      {
        for (i = sr; i < (sr + r); i++)
          PM[i]++;

        c++;
      }

    }

  }

  printf("%d\n", c);
}


