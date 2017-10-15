#include<stdio.h>
#include<string.h>
#include<math.h>
int z[10005];
int len[10005];
int maxL[10005];
int min(int l, int c)
{
  int first_iteration;
  if (l < c)
    return l;

  return c;
}

int Main()
{
  int first_iteration;
  int io;
  int x;
  int skipC;
  int number;
  int k;
  int tar;
  int beP;
  int beN;
  int nowL;
  int d;
  scanf("%d", &io);
  for (k = 1; k <= io; k++)
  {
    scanf("%d", &x);
    for (skipC = 0; skipC < x; skipC++)
    {
      scanf("%d%d", &z[skipC], &len[skipC]);
    }

    scanf("%d", &tar);
    beP = 1;
    memset(maxL, -1, sizeof(maxL));
    maxL[0] = min(z[0], len[0]);
    if (maxL[0] < z[0])
      beP = 0;

    for (skipC = 0; skipC < x; skipC++)
    {
      nowL = maxL[skipC];
      d = -1;
      for (number = skipC + 1; number < x; number++)
      {
        if (nowL >= (z[number] - z[skipC]))
        {
          d = min(len[number], z[number] - z[skipC]);
          if ((maxL[number] == (-1)) || (maxL[number] < d))
            maxL[number] = d;

        }

      }

    }

    beN = 1;
    for (skipC = 0; skipC < x; skipC++)
    {
      if ((maxL[skipC] != (-1)) && ((maxL[skipC] + z[skipC]) >= tar))
        beN = 0;

    }

    if (beP && (beN == 0))
      printf("Case #%d: YES\n", k);
    else
      printf("Case #%d: NO\n", k);

  }

  return 0;
}


