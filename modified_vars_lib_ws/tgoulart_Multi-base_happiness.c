#include <stdio.h>
#include <string.h>
int
tovet (char b[], int j[])
{
  int i = 0;
  int off;
  char *ptr = b;
  char prev;
  for (ptr = b; sscanf (ptr, "%d%c%n", &j[i], &prev, &off) == 2;
       i++, ptr += off)
    ;
  return ++i;
}

char happy[11][1000];
int
calc (int choose, int base)
{
  int rslt = 0;
  while (choose)
    {
      rslt += (choose % base) * (choose % base);
      choose /= base;
    }
  return rslt;
}

int
verify (int choose, int base)
{
  if (happy[base][choose] >= 0)
    {
      return happy[base][choose];
    }
  choose = calc (choose, base);
  if (happy[base][choose] == (-2))
    {
      return 0;
    }
  if (happy[base][choose] == (-1))
    {
      happy[base][choose] = -2;
      happy[base][choose] = verify (choose, base);
    }
  return happy[base][choose];
}

int
Main ()
{
  int caso = 1;
  int i;
  int k;
  int x;
  int j[15];
  int choose;
  char b[1000];
  memset (happy, -1, sizeof (happy));
  for (k = 2; k <= 10; k++)
    {
      happy[k][1] = 1;
      for (i = 2; i < 1000; i++)
	{
	  if (happy[k][i] == (-1))
	    {
	      happy[k][i] = verify (i, k);
	    }
	}
    }
  scanf ("%d\n", &x);
  while (x--)
    {
      choose = tovet (gets (b), j);
      for (i = 2; 1; i++)
	{
	  for (k = 0; k < choose; k++)
	    {
	      if (!happy[j[k]][calc (i, j[k])])
		{
		  break;
		}
	    }
	  if (k == choose)
	    {
	      break;
	    }
	}
      printf ("Case #%d: %d\n", caso++, i);
    }
  return 0;
}
