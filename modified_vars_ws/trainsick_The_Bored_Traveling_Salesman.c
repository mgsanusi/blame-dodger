#include <stdio.h>
typedef struct node
{
  struct node *next;
  int j;
} node;
node tmp[11];
int steps;
int max;
node *tosort;
int inversions;
void
readstuff (void)
{
  int f;
  max = -1;
  scanf ("%d", &steps);
  for (f = 0; f < steps; f++)
    {
      scanf ("%d", &tmp[f].j);
      if (tmp[f].j > max)
	max = tmp[f].j;
    }
}

node *
merge (node * k, node * t)
{
  node c0;
  node *x = &c0;
  int acnt = 0;
  while (k || t)
    {
      if ((t == 0) || (k && (k->j <= t->j)))
	{
	  acnt++;
	  x = (x->next = k);
	  k = k->next;
	}
      else
	{
	  inversions += acnt;
	  x = (x->next = t);
	  t = t->next;
	}
    }
  return c0.next;
}

int
bump (void)
{
  int f = 0;
  while ((f < steps) && (tmp[f].j >= max))
    {
      tmp[f].j = (2 * max) - tmp[f].j;
      f++;
    }
  if (f >= steps)
    return 0;
  tmp[f].j = (2 * max) - tmp[f].j;
  return 1;
}

node *
sort (int flag)
{
  node *k;
  node *t;
  if (flag == 1)
    {
      k = tosort++;
      k->next = 0;
      return k;
    }
  else
    {
      k = sort (flag / 2);
      t = sort (flag - (flag / 2));
      return merge (k, t);
    }
}

void
mincmp (void)
{
  int base;
  readstuff ();
  tosort = tmp;
  inversions = 0;
  sort (steps);
  base = inversions;
  while (bump ())
    {
      tosort = tmp;
      inversions = 0;
      sort (steps);
      if (inversions < base)
	base = inversions;
    }
  printf ("%d\n", base);
}

int
Main (int argc, char **argv)
{
  int f;
  int tc;
  scanf ("%d", &tc);
  for (f = 1; f <= tc; f++)
    {
      printf ("Case #%d: ", f);
      mincmp ();
    }
  return 0;
}
