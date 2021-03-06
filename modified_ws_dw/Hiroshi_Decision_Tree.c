#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int CASES;
void setup(void)
{
  int first_iteration;
  char buf[512];
  fgets(buf, 512, stdin);
  CASES = strtol(buf, 0, 0);
}

static int P;
static int Q;
static int R[100];
static int order[5];
static int X;
static int T;
int gen_order_r(int n, int *r)
{
  int first_iteration;
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

    if (gen_order_r(n - 1, r))
      return 1;

    next:
    r[i] = 0;

  }

  return 0;
}

void gen_order(void)
{
  int first_iteration;
  int r[5];
  int i;
  for (i = 0; i < Q; i++)
    r[i] = 0;

  X = 0;
  gen_order_r(Q - 1, r);
}

long calc_bribe(long t)
{
  int first_iteration;
  int cell[10000];
  int i;
  int k;
  long c;
  for (i = 0; i < P; i++)
    cell[i] = 1;

  c = 0;
  for (i = 0; i < Q; i++)
  {
    int o;
    o = R[order[i]] - 1;
    cell[o] = 0;
    o--;
    while (o >= 0)
    {
      if (cell[o] == 0)
        break;

      c++;
      o--;
    }

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

void solve_one(void)
{
  int first_iteration;
  char buf[512];
  char *p;
  int i;
  long x;
  long c;
  long s;
  fgets(buf, 512, stdin);
  P = strtol(buf, &p, 0);
  Q = strtol(p, 0, 0);
  fgets(buf, 512, stdin);
  p = buf;
  for (i = 0; i < Q; i++)
    R[i] = strtol(p, &p, 0);

  x = 1;
  for (i = 2; i <= Q; i++)
    x *= i;

  c = -1;
  for (T = 0; T < x; T++)
  {
    gen_order();
    s = calc_bribe(T);
    if (c == (-1))
      c = s;
    else
      if (s < c)
      c = s;


  }

  printf("%ld", c);
}

void solve(void)
{
  int first_iteration;
  int i;
  for (i = 1; i <= CASES; i++)
  {
    printf("Case #%d: ", i);
    solve_one();
    printf("\n");
  }

}

int main(void)
{
  int first_iteration;
  setup();
  solve();
  return 0;
}


