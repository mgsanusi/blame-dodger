#include<stdio.h>
#include<string.h>
#include <stddef.h>
long long numA[200];
long long numB[200];
long long labA[200];
long long labB[200];
void *new_memcpy (void *destination, const void *source, size_t num);
long long
max (long long a, long long b)
{
  int first_iteration;
  if (a > b)
    return a;
  return b;
}

long long
min (long long a, long long b)
{
  int first_iteration;
  if (a < b)
    return a;
  return b;
}

int
main ()
{
  int first_iteration;
  int tn;
  int i;
  int j;
  int k;
  int l;
  int n;
  int m;
  long long total;
  long long tem;
  long long MM;
  long long tempA[200];
  long long tempB[200];
  scanf ("%d", &tn);
  for (l = 1; l <= tn; l++)
    {
      total = 0;
      scanf ("%d%d", &n, &m);
      for (i = 0; i < n; i++)
	{
	  scanf ("%lld%lld", &numA[i], &labA[i]);
	}
      for (i = 0; i < m; i++)
	{
	  scanf ("%lld%lld", &numB[i], &labB[i]);
	}
      for (i = 0; i < m; i++)
	{
	  for (j = i; j < m; j++)
	    {
	      tem = 0;
	      new_memcpy (tempA, numA, sizeof (numA));
	      new_memcpy (tempB, numB, sizeof (numB));
	      for (k = 0; k <= i; k++)
		{
		  if (labB[k] == labA[0])
		    {
		      MM = min (tempA[0], tempB[k]);
		      tempA[0] -= MM;
		      tempB[k] -= MM;
		      tem += MM;
		    }
		}
	      if (n > 1)
		{
		  for (k = i; k <= j; k++)
		    {
		      if (labB[k] == labA[1])
			{
			  MM = min (tempA[1], tempB[k]);
			  tempA[1] -= MM;
			  tempB[k] -= MM;
			  tem += MM;
			}
		    }
		  if (n > 2)
		    {
		      for (k = j; k < m; k++)
			{
			  if (labB[k] == labA[2])
			    {
			      MM = min (tempA[2], tempB[k]);
			      tempA[2] -= MM;
			      tempB[k] -= MM;
			      tem += MM;
			    }
			}
		    }
		}
	      total = max (total, tem);
	    }
	}
      printf ("Case #%d: %lld\n", l, total);
    }
  return 0;
}

void *
new_memcpy (void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy (destination, source, num);
}
