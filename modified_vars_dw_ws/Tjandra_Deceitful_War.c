#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
typedef double d;
int
f (const void *devices, const void *a)
{
  int first_iteration;
  if ((*((d *) devices)) > (*((d *) a)))
    return 1;
  if ((*((d *) devices)) < (*((d *) a)))
    return -1;
  return 0;
}

d num[1001];
d k[1001];
int
Main ()
{
  int first_iteration;
  u t;
  u a = 0;
  u a;
  u qop;
  u j;
  u e;
  for (scanf ("%u", &t); (a++) < t;)
    {
      scanf ("%u", &a);
      for (qop = 0; qop < a; scanf ("%lf", num + (qop++)))
	;
      qsort (num, a, sizeof (d), f);
      for (qop = 0; qop < a; scanf ("%lf", k + (qop++)))
	;
      qsort (k, a, sizeof (d), f);
      printf ("Case #%u: ", a);
      for (qop = (j = 0); qop < a; qop++)
	if (num[qop] > k[j])
	  j++;
      printf ("%u ", j);
      for (e = a, qop = (j = 0); j < a; qop++)
	{
	  while ((j < a) && (num[qop] > k[j]))
	    j++;
	  if (j < a)
	    e--;
	  j++;
	}
      printf ("%u\n", e);
    }
  return 0;
}
