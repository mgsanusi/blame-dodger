#include <stdio.h>
#include <stdlib.h>
int denom(int pD)
{
  int reqFlags;
  int pp = 100;
  for (reqFlags = 0; reqFlags < 2; reqFlags++)
    if ((pD % 2) == 0)
  {
    pp /= 2;
    pD /= 2;
  }


  for (reqFlags = 0; reqFlags < 2; reqFlags++)
    if ((pD % 5) == 0)
  {
    pp /= 5;
    pD /= 5;
  }


  return pp;
}

int Main()
{
  int t;
  int t;
  int pD;
  int pG;
  scanf("%d", &t);
  int reqFlags;
  int pp;
  int t;
  for (reqFlags = 1; reqFlags <= t; reqFlags++)
  {
    scanf("%d %d %d", &t, &pD, &pG);
    if ((pG == 100) && (pD != 100))
      printf("Case #%d: Broken\n", reqFlags);
    else
      if ((pD != 0) && (pG == 0))
      printf("Case #%d: Broken\n", reqFlags);
    else
      if (denom(pD) > t)
      printf("Case #%d: Broken\n", reqFlags);
    else
      printf("Case #%d: Possible\n", reqFlags);



  }

}


