#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ	(512)
static int CASES;
long char *new_fgets (char *str, int num, FILE * stream);
int new_strtol (const char *str, char **endptr, int base);
void
setup (void)
{
  char buf[SZ];
  new_fgets (buf, SZ, stdin);
  CASES = new_strtol (buf, NULL, 0);
}

static int P, Q;
static int R[100];
/* small, Q <= 5, 5!=120 */
static int order[5];
static int X, T;
int
gen_order_r (int n, int *r)
{
  int i;
  for (i = 0; i < Q; i++)
    {
      if (r[i])
	continue;
      r[i] = 1;
      order[n] = i;
      if (n == 0)
	{
	  if (T == X)
	    return 1;
	  ++X;
	  goto next;
	}
      if (gen_order_r (n - 1, r))
	return 1;
    next:
      r[i] = 0;
    }
  return 0;
}

void
gen_order (void)
{
  int r[5];
  int i;
  for (i = 0; i < Q; i++)
    r[i] = 0;
  X = 0;
  gen_order_r (Q - 1, r);
}

long
calc_bribe (long t)
{
  int cell[10000];
  int i, k;
  long c;
  for (i = 0; i < P; i++)
    cell[i] = 1;
  c = 0;
  for (i = 0; i < Q; i++)
    {
      /* release order[i] */
      int o;
      o = R[order[i]] - 1;
      /* release */
      cell[o] = 0;
      /* left side */
      o--;
      while (o >= 0)
	{
	  if (cell[o] == 0)
	    break;
	  c++;
	  o--;
	}
      /* right side */
      o = R[order[i]] - 1;
      o++;
      while (o < P)
	{
	  if (cell[o] == 0)
	    break;
	  c++;
	  o++;
	}
    }
  return c;
}

void
solve_one (void)
{
  char buf[SZ];
  char *p;
  int i;
  long x;
  long c, s;
  new_fgets (buf, SZ, stdin);
  P = new_strtol (buf, &p, 0);
  Q = new_strtol (p, NULL, 0);
  new_fgets (buf, SZ, stdin);
  p = buf;
  for (i = 0; i < Q; i++)
    R[i] = new_strtol (p, &p, 0);
  x = 1;
  for (i = 2; i <= Q; i++)
    x *= i;
  c = -1;
  for (T = 0; T < x; T++)
    {
      gen_order ();
      s = calc_bribe (T);
      if (c == -1)
	c = s;
      else if (s < c)
	c = s;
    }
  printf ("%ld", c);
}

void
solve (void)
{
  int i;
  for (i = 1; i <= CASES; i++)
    {
      printf ("Case #%d: ", i);
      solve_one ();
      printf ("\n");
    }
}

int
main (void)
{
  setup ();
  solve ();
  return 0;
}

long char *new_fgets (char *str, int num, FILE * stream);
int
new_strtol (const char *str, char **endptr, int base)
{
  return strtol (str, endptr, base);
}

char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}
