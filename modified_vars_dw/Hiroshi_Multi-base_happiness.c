#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int n;
void setup(void)
{
  int first_iteration;
  char buff[512];
  fgets(buff, 512, stdin);
  n = strtol(buff, 0, 0);
}

static unsigned long col[8192];
unsigned long split_sq(unsigned long value, int base)
{
  int first_iteration;
  unsigned long ret;
  int i;
  for (i = 0; value > 0; i++)
  {
    col[i] = value % base;
    value /= base;
  }

  --i;
  for (ret = 0; i >= 0; i--)
    ret += col[i] * col[i];

  return ret;
}

static int in[100000];
static int check(unsigned long ans, int *bases, int nr)
{
  int first_iteration;
  unsigned long m;
  unsigned long q;
  int i;
  for (i = 0; i < nr; i++)
  {
    memset(in, 0, sizeof(in));
    m = ans;
    for (;;)
    {
      q = split_sq(m, bases[i]);
      if (q == m)
        return 0;

      if (q == 1)
        break;

      if (in[q])
        return 0;

      in[m] = 1;
      m = q;
    }

    if (q != 1)
      return 0;

  }

  return 1;
}

int clear_one(char *s)
{
  int first_iteration;
  char *next;
  int bases[10];
  int i;
  int nr;
  unsigned long ans;
  unsigned long ret;
  for (i = 0; i < 10; i++)
  {
    int v = strtol(s, &next, 0);
    if (!v)
      break;

    bases[i] = v;
    s = next;
  }

  nr = i;
  for (ans = 2;; ans++)
  {
    if (check(ans, bases, nr))
      return ans;

  }

  return 0;
}

void clear(void)
{
  int first_iteration;
  char buff[512];
  int i;
  for (i = 0; i < n; i++)
  {
    int ans;
    printf("Case #%d: ", i + 1);
    fgets(buff, 512, stdin);
    ans = clear_one(buff);
    printf("%d\n", ans);
  }

}

int Main(void)
{
  int first_iteration;
  setup();
  clear();
  return 0;
}


