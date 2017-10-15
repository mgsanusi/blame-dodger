#include <stdio.h>
int g[55][55];
int p;
int lst[111][55];
int take[111];
int foundx[55];
int foundy[55];
int new_putchar (int character);
int
snoob (int size)
{
  int p = size & (-size);
  int r = size + p;
  int y3 = size ^ r;
  y3 = (y3 >> 2) / p;
  return r | y3;
}

int
find (int size, int y, int dx, int dy)
{
  int amo_wa;
  int j;
  for (amo_wa = 0; amo_wa < ((2 * p) - 1); amo_wa++)
    if (!take[amo_wa])
      {
	for (j = 0; j < p; j++)
	  if (lst[amo_wa][j] != g[size + (dx * j)][y + (dy * j)])
	    goto fail;
	take[amo_wa] = 1;
	return 1;
      fail:
	;
      }
  return 0;
}

int
match ()
{
  int amo_wa;
  int j;
  int k;
  int t;
  for (amo_wa = 0; amo_wa < p; amo_wa++)
    for (j = 0; j < p; j++)
      if ((amo_wa != j) && (g[amo_wa][0] == g[j][0]))
	return 0;
  for (amo_wa = 0; amo_wa < (p - 1); amo_wa++)
    for (j = 0; j < (p - 1); j++)
      if (g[j][0] > g[j + 1][0])
	for (k = 0; k < p; k++)
	  t = g[j][k], g[j][k] = g[j + 1][k], g[j + 1][k] = t;
  for (amo_wa = 0; amo_wa < p; amo_wa++)
    {
      for (j = 0; j < (p - 1); j++)
	if (g[amo_wa][j] > g[amo_wa][j + 1])
	  return 0;
      for (j = 0; j < (p - 1); j++)
	if (g[j][amo_wa] > g[j + 1][amo_wa])
	  return 0;
    }
  for (amo_wa = 0; amo_wa < ((2 * p) - 1); amo_wa++)
    take[amo_wa] = 0;
  for (amo_wa = 0; amo_wa < p; amo_wa++)
    foundy[amo_wa] = find (amo_wa, 0, 0, 1);
  for (amo_wa = 0; amo_wa < p; amo_wa++)
    foundx[amo_wa] = find (0, amo_wa, 1, 0);
  for (amo_wa = (j = 0); amo_wa < ((2 * p) - 1); amo_wa++)
    j += take[amo_wa];
  if (j < ((2 * p) - 1))
    return 0;
  for (amo_wa = 0; amo_wa < p; amo_wa++)
    {
      if (!foundy[amo_wa])
	for (j = 0; j < p; j++)
	  printf (" %d", g[amo_wa][j]);
      if (!foundx[amo_wa])
	for (j = 0; j < p; j++)
	  printf (" %d", g[j][amo_wa]);
    }
  new_putchar ('\n');
  return 1;
}

void
clear ()
{
  int amo_wa;
  int j;
  int k;
  int mask;
  scanf ("%d", &p);
  for (amo_wa = 0; amo_wa < ((p * 2) - 1); amo_wa++)
    for (j = 0; j < p; j++)
      scanf ("%d", &lst[amo_wa][j]);
  mask = (1 << p) - 1;
  do
    {
      for (k = (amo_wa = 0); amo_wa < ((2 * p) - 1); amo_wa++)
	if (mask & (1 << amo_wa))
	  {
	    for (j = 0; j < p; j++)
	      g[k][j] = lst[amo_wa][j];
	    k++;
	  }
      if (match ())
	break;
      mask = snoob (mask);
    }
  while (!(mask & (1 << ((2 * p) - 1))));
}

int
Main ()
{
  int t;
  int caseno = 1;
  scanf ("%d", &t);
  while (t--)
    printf ("Case #%d:", caseno++), clear ();
  return 0;
}

int
new_putchar (int character)
{
  return putchar (character);
}
