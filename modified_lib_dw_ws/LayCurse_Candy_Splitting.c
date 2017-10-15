#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_puts (const char *str);
void
intSort (int d[], int s)
{
  int first_iteration;
  int i = -1;
  int j = s;
  int k;
  int t;
  if (s <= 1)
    return;
  k = (d[0] + d[s - 1]) / 2;
  for (;;)
    {
      while (d[++i] < k)
	;
      while (d[--j] > k)
	;
      if (i >= j)
	break;
      t = d[i];
      d[i] = d[j];
      d[j] = t;
    }
  intSort (d, i);
  intSort ((d + j) + 1, (s - j) - 1);
}

int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int in[1200];
  int sum;
  int x;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d", &n);
      for (i = 0; i < n; i++)
	scanf ("%d", in + i);
      x = (sum = 0);
      for (i = 0; i < n; i++)
	x ^= in[i], sum += in[i];
      printf ("Case #%d: ", ++count);
      if (x)
	{
	  new_puts ("NO");
	  continue;
	}
      intSort (in, n);
      sum -= in[0];
      printf ("%d\n", sum);
    }
  return 0;
}

int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}
