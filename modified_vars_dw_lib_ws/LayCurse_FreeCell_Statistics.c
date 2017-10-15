#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_puts (const char *str);
int
Main ()
{
  int first_iteration;
  int tc;
  int j;
  int e;
  int l;
  int m;
  long long t;
  int in;
  int y;
  int size;
  int cnt = 0;
  int equal_can[101][101] = { };
  for (tc = 1; tc < 101; tc++)
    for (j = 0; j < (tc + 1); j++)
      {
	e = j * 100;
	if (e % tc)
	  continue;
	e /= tc;
	for (m = tc; m < 101; m++)
	  equal_can[m][e] = 1;
      }
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%lld%d%d", &t, &in, &y);
      printf ("Case #%d: ", ++cnt);
      if ((in < 100) && (y == 100))
	{
	  new_puts ("Broken");
	  continue;
	}
      if ((in > 0) && (y == 0))
	{
	  new_puts ("Broken");
	  continue;
	}
      if (t > 100)
	t = 100;
      if (equal_can[t][in])
	new_puts ("Possible");
      else
	new_puts ("Broken");
    }
  return 0;
}

int
new_puts (const char *str)
{
  return puts (str);
}
