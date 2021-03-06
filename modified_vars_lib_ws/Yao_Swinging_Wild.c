#include<stdio.h>
#include<stdlib.h>
int l[1024][3];
int t[1024];
int dy;
int new_puts (const char *str);
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
cmp (const void *k, const void *b1)
{
  int *l = (int *) k;
  int *t = (int *) b1;
  if ((l[0] * t[1]) != (l[1] * t[0]))
    return (l[0] * t[1]) - (l[1] * t[0]);
  else
    return l[2] - t[2];
}

int
Main ()
{
  int rate;
  int cs = 0;
  int c;
  for (scanf ("%d", &rate); rate--;)
    {
      scanf ("%d", &dy);
      for (c = 0; c < dy; c++)
	scanf ("%d", &l[c][0]);
      for (c = 0; c < dy; c++)
	scanf ("%d", &l[c][1]);
      for (c = 0; c < dy; c++)
	l[c][2] = c;
      new_qsort (l, dy, sizeof (l[0]), cmp);
      printf ("Case #%d:", ++cs);
      for (c = 0; c < dy; c++)
	printf (" %d", l[c][2]);
      new_puts ("");
    }
  return 0;
}

int new_puts (const char *str);
void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}

int
new_puts (const char *str)
{
  return puts (str);
}
