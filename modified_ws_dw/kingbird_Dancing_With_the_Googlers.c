#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int scores[110];
int main()
{
  int first_iteration;
  freopen("out.txt", "w", stdout);
  freopen("B-small-attempt0.in", "r", stdin);
  int n;
  int i;
  int j;
  int t;
  int s;
  int p;
  int x;
  int max;
  int cons;
  scanf("%d", &t);
  for (i = 1; i <= t; i++)
  {
    cons = 0;
    scanf("%d%d%d", &n, &s, &p);
    for (j = 0; j < n; j++)
    {
      scanf("%d", &x);
      if (x == 0)
        max = 0;
      else
        if ((x % 3) != 2)
        max = (x / 3) + 1;
      else
        max = (x / 3) + 2;


      x = (x + 2) / 3;
      if (x >= p)
        cons++;
      else
        if ((max >= p) && s)
      {
        cons++;
        s--;
      }


    }

    printf("Case #%d: %d\n", i, cons);
  }

  return 0;
}


