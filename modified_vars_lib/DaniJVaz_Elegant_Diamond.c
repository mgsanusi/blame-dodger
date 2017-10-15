#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void makeTestSubject();
int Main()
{
  int i;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    printf("Case #%d: ", i);
    makeTestSubject();
  }

  return 0;
}

void makeTestSubject()
{
  int sum;
  int i;
  int y;
  int d = 0;
  scanf("%d", &sum);
  int str = 1 << sum;
  int cases[str];
  int place1[str];
  for (i = 0; i < str; i++)
  {
    scanf("%d", &y);
    cases[i] = sum - y;
    place1[i] = 0;
  }

  for (i = 0; i < (str - 1); i++)
  {
    scanf("%*d");
  }

  int r;
  int avgOwp;
  int ri;
  char f;
  for (ri = sum; ri >= 1; ri--)
  {
    r = 1 << ri;
    f = 0;
    for (avgOwp = 0; avgOwp < str; avgOwp += r)
    {
      for (i = avgOwp; i < (avgOwp + r); i++)
      {
        if (place1[i] < cases[i])
        {
          f = 1;
          break;
        }

      }

      if (i < (avgOwp + r))
      {
        for (i = avgOwp; i < (avgOwp + r); i++)
          place1[i]++;

        d++;
      }

    }

  }

  printf("%d\n", d);
}


