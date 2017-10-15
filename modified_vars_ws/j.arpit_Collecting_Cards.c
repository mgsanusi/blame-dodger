#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buff[100];
int l;
int
comp (char *y, char *b)
{
  return (*y) - (*b);
}

int
Main ()
{
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
	    putchar (buff[type]);
	  for (type = cur - 1; buff[type] <= buff[need - 1]; --type)
	    ;
	  putchar (buff[type]);
	  for (k = cur - 1; k > type; --k)
	    putchar (buff[k]);
	  putchar (buff[need - 1]);
	  for (k = type - 1; k >= need; --k)
	    putchar (buff[k]);
	}
      else
	{
	  for (type = cur - 1; buff[type] == '0'; --type)
	    ;
	  putchar (buff[type]);
	  putchar ('0');
	  for (k = cur - 1; k > type; --k)
	    putchar (buff[k]);
	  for (k = type - 1; k >= 0; --k)
	    putchar (buff[k]);
	}
      putchar ('\n');
    }
  return 0;
}
