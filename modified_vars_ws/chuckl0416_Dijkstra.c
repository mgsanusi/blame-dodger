#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int i;
int t;
int i;
int res;
int arr_m;
int
tilling ()
{
  if (i >= 7)
    return 0;
  if ((res * arr_m) % i)
    return 0;
  if (i == 1)
    return 1;
  if (i == 2)
    return 1;
  if (res < arr_m)
    res ^= (arr_m ^= (res ^= arr_m));
  if (res < i)
    return 0;
  if (i == 3)
    if (arr_m > 1)
      return 1;
  if (i == 4)
    if (arr_m > 2)
      return 1;
  return 0;
}

int
Main ()
{
  freopen ("D-small-attempt1.in", "r", stdin);
  freopen ("D-small-attempt1.out", "w", stdout);
  scanf ("%d", &i);
  for (t = 1; t <= i; t++)
    {
      printf ("Case #%d: ", t);
      scanf ("%d%d%d", &i, &res, &arr_m);
      if (tilling ())
	puts ("GABRIEL");
      else
	puts ("RICHARD");
    }
  return 0;
}
