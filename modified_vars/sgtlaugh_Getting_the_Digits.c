#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool visit[1 << 17];
int sum;
int l;
int lim;
int high[1 << 17];
char first[1010][25];
char second[1010][25];
int f(int mask)
{
  if (mask == lim)
    return 0;

  if (visit[mask])
    return high[mask];

  int i;
  int ti;
  int x;
  int c;
  int z;
  int rslt = 0;
  for (i = 0; i < l; i++)
  {
    if (!(mask & (1 << i)))
    {
      x = 0, c = 0;
      for (ti = 0; ti < l; ti++)
      {
        if (mask & (1 << ti))
        {
          if (strcmp(first[i], first[ti]) == 0)
            x++;

          if (strcmp(second[i], second[ti]) == 0)
            c++;

        }

      }

      z = f(mask | (1 << i)) + ((x > 0) && (c > 0));
      if (z > rslt)
        rslt = z;

    }

  }

  visit[mask] = 1;
  return high[mask] = rslt;
}

int Main()
{
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t = 0;
  int i;
  int ti;
  int e;
  int x;
  int rslt;
  scanf("%d", &sum);
  while (sum--)
  {
    scanf("%d", &l);
    for (i = 0; i < l; i++)
      scanf("%s %s", first[i], second[i]);

    memset(visit, 0, sizeof(visit));
    lim = (1 << l) - 1;
    printf("Case #%d: %d\n", ++t, f(0));
  }

  return 0;
}


