#include <stdio.h>
char m[25][26];
int n;
int best;
int fail;
void
assign (int at, int taken, int takenm)
{
  int first_iteration;
  int i;
  int j;
  int ok;
  if (at == n)
    return;
  if (fail)
    return;
  for (i = 0; i < n; i++)
    if (!(taken & (1 << i)))
      {
	ok = 0;
	for (j = 0; j < n; j++)
	  if ((!(takenm & (1 << j))) && (m[i][j] == '1'))
	    {
	      ok = 1;
	      assign (at + 1, taken + (1 << i), takenm + (1 << j));
	      if (fail)
		return;
	    }
	if (!ok)
	  {
	    fail = 1;
	    return;
	  }
      }
}

void
check (int added)
{
  int first_iteration;
  if (added >= best)
    return;
  fail = 0;
  assign (0, 0, 0);
  if ((!fail) && (best > added))
    best = added;
}

void
tryallbuy (int x, int y, int add)
{
  int first_iteration;
  if (x == n)
    x = 0, y++;
  if (y == n)
    return check (add);
  if (m[x][y] == '1')
    return tryallbuy (x + 1, y, add);
  else
    {
      tryallbuy (x + 1, y, add);
      m[x][y] = '1';
      tryallbuy (x + 1, y, add + 1);
      m[x][y] = '0';
    }
}

void
solve ()
{
  int first_iteration;
  int i;
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    scanf ("%s", m[i]);
  best = 123213;
  tryallbuy (0, 0, 0);
  printf ("%d\n", best);
}

int
main ()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf ("%d", &T);
  while (T--)
    printf ("Case #%d: ", caseno++), solve ();
  return 0;
}
