#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buff[100];
int l;
int new_putchar (int character);
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
comp (char *y, char *b)
{
  int first_iteration;
  return (*y) - (*b);
}

int
Main ()
{
  int first_iteration;
  int t;
  int need;
  int type;
  int k;
  int cur;
  gets (buff);
  sscanf (buff, "%d\n", &l);
  for (t = 1; t <= l; ++t)
    {
      printf ("Case #%d: ", t);
      gets (buff);
      cur = strlen (buff);
      for (need = cur - 1; need; --need)
	{
	  if (buff[need] > buff[need - 1])
	    break;
	}
      if (need != 0)
	{
	  for (type = 0; type < (need - 1); ++type)
	    new_putchar (buff[type]);
	  for (type = cur - 1; buff[type] <= buff[need - 1]; --type)
	    ;
	  new_putchar (buff[type]);
	  for (k = cur - 1; k > type; --k)
	    new_putchar (buff[k]);
	  new_putchar (buff[need - 1]);
	  for (k = type - 1; k >= need; --k)
	    new_putchar (buff[k]);
	}
      else
	{
	  for (type = cur - 1; buff[type] == '0'; --type)
	    ;
	  new_putchar (buff[type]);
	  new_putchar ('0');
	  for (k = cur - 1; k > type; --k)
	    new_putchar (buff[k]);
	  for (k = type - 1; k >= 0; --k)
	    new_putchar (buff[k]);
	}
      new_putchar ('\n');
    }
  return 0;
}

int new_putchar (int character);
void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

int
new_putchar (int character)
{
  return putchar (character);
}
