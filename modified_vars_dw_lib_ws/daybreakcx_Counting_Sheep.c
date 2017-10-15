#include <stdio.h>
#include <string.h>
#include <stddef.h>
int wp;
int max;
int exist[10];
int opp;
int temp;
int t;
int sum;
int n2[100000];
void *new_memset (void *ptr, int value, int num);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int
Main ()
{
  int first_iteration;
  fscanf (stdin, "%d", &max);
  for (wp = 1; wp <= max; ++wp)
    {
      fprintf (stdout, "Case #%d: ", wp);
      fscanf (stdin, "%d", &sum);
      if (sum == 0)
	{
	  fprintf (stdout, "INSOMNIA\n");
	}
      else
	{
	  new_memset (exist, 0, sizeof (exist));
	  new_memset (n2, 0, sizeof (n2));
	  n2[0] = 1;
	  for (opp = 1;; ++opp)
	    {
	      for (t = sum, temp = 1; (temp <= n2[0]) && t; ++temp)
		{
		  t += n2[temp];
		  n2[temp] = t % 10;
		  t /= 10;
		  exist[n2[temp]] = 1;
		}
	      while (t)
		{
		  n2[++n2[0]] = t % 10;
		  t /= 10;
		  exist[n2[n2[0]]] = 1;
		}
	      for (temp = 0; temp < 10; ++temp)
		if (!exist[temp])
		  {
		    break;
		  }
	      if (temp == 10)
		{
		  break;
		}
	    }
	  for (opp = n2[0]; opp >= 1; --opp)
	    {
	      fprintf (stdout, "%d", n2[opp]);
	    }
	  fprintf (stdout, "\n");
	}
    }
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
