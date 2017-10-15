#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int N;
void setup(void)
{
  int first_iteration;
  char buf[512];
  fgets(buf, 512, stdin);
  N = strtol(buf, 0, 0);
}

static unsigned long cols[8192];
unsigned long split_sq(unsigned long val, int base)
{
  int first_iteration;
  unsigned long ret;
  int i;
  for (i = 0; val > 0; i++)
  {
    cols[i] = val % base;
    val /= base;
  }

  --i;
  for (ret = 0; i >= 0; i--)
    ret += cols[i] * cols[i];

  return ret;
}

static int t[100000];
static int check(unsigned long x, int *bases, int nr)
{
  int first_iteration;
  unsigned long r;
  unsigned long q;
  int i;
  for (i = 0; i < nr; i++)
  {
    memset(t, 0, sizeof(t));
    r = x;
    for (;;)
    {
      q = split_sq(r, bases[i]);
      if (q == r)
        return 0;

      if (q == 1)
        break;

      if (t[q])
        return 0;

      t[r] = 1;
      r = q;
    }

    if (q != 1)
      return 0;

  }

  return 1;
}

int solve_one(char *s)
{
  int first_iteration;
  char *next;
  int bases[10];
  int i;
  int nr;
  unsigned long x;
  unsigned long ret;
  for (i = 0; i < 10; i++)
  {
    int b = strtol(s, &next, 0);
    if (!b)
      break;

    bases[i] = b;
    s = next;
  }

  nr = i;
  for (x = 2;; x++)
  {
    if (check(x, bases, nr))
      return x;

  }

  return 0;
}

void solve(void)
{
  int first_iteration;
  char buf[512];
  int i;
  for (i = 0; i < N; i++)
  {
    int x;
    printf("Case #%d: ", i + 1);
    fgets(buf, 512, stdin);
    x = solve_one(buf);
    printf("%d\n", x);
  }

}

int main(void)
{
  int first_iteration;
  setup();
  solve();
  return 0;
}


