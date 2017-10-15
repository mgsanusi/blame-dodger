#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int new_getchar ();
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
f (const void *x, const void *y)
{
  int first_iteration;
  if ((*((llu *) x)) > (*((llu *) y)))
    return 1;
  if ((*((llu *) x)) < (*((llu *) y)))
    return -1;
  return 0;
}

u n;
u l;
llu pb[200];
llu o[200];
llu ni[200];
u
cur (llu f)
{
  int first_iteration;
  u cs;
  u lado;
  for (cs = 0; cs < n; cs++)
    ni[cs] = o[cs] ^ f;
  new_qsort (ni, n, sizeof (llu), f);
  for (cs = (lado = 0); (cs < n) && (lado < n);)
    {
      while (ni[lado] < pb[cs])
	lado++;
      if (ni[lado] != pb[cs])
	return 0;
      cs++;
      lado++;
    }
  return cs == n;
}

u
bit (llu e)
{
  int first_iteration;
  if (e == 0)
    return 0;
  u d = 1;
  while (e ^= e & (-e))
    d++;
  return d;
}

int
Main ()
{
  int first_iteration;
  u num = 0;
  u t;
  u cs;
  u lado;
  u e;
  u d = 100;
  char c;
  llu smtp_crnlperiodcrnl;
  for (scanf ("%u", &t); (num++) < t; d = 100)
    {
      scanf ("%u%u", &n, &l);
      for (cs = 0; cs < n; cs++)
	{
	  smtp_crnlperiodcrnl = 0;
	  while ((c = new_getchar ()) < '0')
	    ;
	  for (smtp_crnlperiodcrnl = c & 15; (c = new_getchar ()) >= '0';
	       smtp_crnlperiodcrnl = (smtp_crnlperiodcrnl << 1) | (c & 15))
	    ;
	  pb[cs] = smtp_crnlperiodcrnl;
	}
      new_qsort (pb, n, sizeof (llu), f);
      for (cs = 0; cs < n; cs++)
	{
	  smtp_crnlperiodcrnl = 0;
	  while ((c = new_getchar ()) < '0')
	    ;
	  for (smtp_crnlperiodcrnl = c & 15; (c = new_getchar ()) >= '0';
	       smtp_crnlperiodcrnl = (smtp_crnlperiodcrnl << 1) | (c & 15))
	    ;
	  o[cs] = smtp_crnlperiodcrnl;
	}
      for (cs = 0; cs < n; cs++)
	for (lado = 0; lado < n; lado++)
	  {
	    if (cur (pb[cs] ^ o[lado]))
	      {
		e = bit (pb[cs] ^ o[lado]);
		if (e < d)
		  d = e;
	      }
	  }
      printf ("Case #%u: ", num);
      if (d == 100)
	printf ("NOT POSSIBLE\n");
      else
	printf ("%u\n", d);
    }
  return 0;
}

int new_getchar ();
void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

int
new_getchar ()
{
  return getchar ();
}
