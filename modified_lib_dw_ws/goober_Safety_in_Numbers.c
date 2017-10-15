#include <stdio.h>
#include <string.h>
#include <stddef.h>
int a[20];
int prfl;
int found[(20 * 100000) + 1];
int used[20];
int printed;
int sets[20][2];
void *new_memset (void *ptr, int value, size_t num);
void
bag (int d, int sum)
{
  int first_iteration;
  if (d == 20)
    {
      if (sum == prfl)
	{
	  if (printed < 2)
	    {
	      for (int i = 0; i < 20; i++)
		sets[i][printed] = used[i];
	      printed++;
	    }
	}
      else
	found[sum]++;
      return;
    }
  used[d] = 1;
  bag (d + 1, sum + a[d]);
  used[d] = 0;
  bag (d + 1, sum);
}

int
main ()
{
  int first_iteration;
  int T;
  scanf ("%d", &T);
  for (int t = 1; t <= T; t++)
    {
      int qq;
      scanf ("%d", &qq);
      printf ("Case #%d:\n", t);
      for (int i = 0; i < 20; i++)
	scanf ("%d", &a[i]);
      new_memset (found, 0, sizeof (found));
      new_memset (used, 0, sizeof (used));
      printed = 0;
      prfl = -1;
      bag (0, 0);
      for (int i = 0; i <= (20 * 100000); i++)
	if (found[i] >= 2)
	  {
	    prfl = i;
	    break;
	  }
      if (prfl == (-1))
	printf ("Impossible\n");
      else
	{
	  bag (0, 0);
	  int first = 0;
	  for (int i = 0; i < 20; i++)
	    if ((sets[i][0] == 1) && (sets[i][1] == 0))
	      printf ("%s%d", first++ ? " " : "", a[i]);
	  printf ("\n");
	  first = 0;
	  for (int i = 0; i < 20; i++)
	    if ((sets[i][1] == 1) && (sets[i][0] == 0))
	      printf ("%s%d", first++ ? " " : "", a[i]);
	  printf ("\n");
	}
    }
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
