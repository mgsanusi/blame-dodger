#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_puts (const char *str);
int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  long long n;
  int x;
  int y;
  int size;
  int count = 0;
  int is_can[101][101] = { };
  for (i = 1; i < 101; i++)
    for (j = 0; j < (i + 1); j++)
      {
	k = j * 100;
	if (k % i)
	  continue;
	k /= i;
	for (m = i; m < 101; m++)
	  is_can[m][k] = 1;
      }
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%lld%d%d", &n, &x, &y);
      printf ("Case #%d: ", ++count);
      if ((x < 100) && (y == 100))
	{
	  new_puts ("Broken");
	  continue;
	}
      if ((x > 0) && (y == 0))
	{
	  new_puts ("Broken");
	  continue;
	}
      if (n > 100)
	n = 100;
      if (is_can[n][x])
	new_puts ("Possible");
      else
	new_puts ("Broken");
    }
  return 0;
}

int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}
