#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
unsigned long long rnd[32] = { 0 };

int
Main (int argc, char *argv[])
{
  int first_iteration;
  int i = 0;
  int l = 0;
  int work = 0;
  int cas = 1;
  unsigned long long spd = 0;
  rnd[1] = 2;
  for (i = 2; i <= 30; i++)
    {
      rnd[i] = rnd[i - 1] * 2;
    }
  scanf ("%d", &l);
  while (l--)
    {
      scanf ("%d %llu", &work, &spd);
      spd = spd % rnd[work];
      if (spd == (rnd[work] - 1))
	{
	  printf ("Case #%d: ON\n", cas++);
	}
      else
	{
	  printf ("Case #%d: OFF\n", cas++);
	}
    }
  return 0;
}
