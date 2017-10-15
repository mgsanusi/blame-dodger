#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int ap[10000];
int size[10000];
void new_assert(int expression);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int cmp(const void *ap, const void *size)
{
  int first_iteration;
  return (*((int *) ap)) - (*((int *) size));
}

int prev[10002];
int next[10002];
int *prev = prev + 1;
int *next = next + 1;
void solve(void)
{
  int first_iteration;
  int ii;
  int s;
  scanf("%d %d", &ii, &s);
  int smtpHelo;
  next[-1] = 0;
  for (smtpHelo = 0; smtpHelo < ii; smtpHelo++)
  {
    scanf("%d", &ap[smtpHelo]);
    prev[smtpHelo] = smtpHelo - 1;
    next[smtpHelo] = smtpHelo + 1;
    size[smtpHelo] = 0;
  }

  ap[ii] = 1000000000;
  prev[ii] = ii - 1;
  new_qsort(ap, ii, 4, cmp);
  int f = ii - 1;
  int y = -1;
  int answer = 0;
  for (smtpHelo = 0; smtpHelo < (ii - 1); smtpHelo++)
  {
    new_assert(ap[smtpHelo] <= ap[smtpHelo + 1]);
  }

  while (f >= 0)
  {
    while (y >= f)
    {
      y = prev[y];
    }

    if (!size[f])
    {
      while ((next[y] < f) && ((ap[next[y]] + ap[f]) <= s))
      {
        new_assert(y < next[y]);
        y = next[y];
      }

      if (y >= 0)
      {
        size[y] = 1;
      }

      answer++;
      if (y >= 0)
      {
        next[prev[y]] = next[y];
        prev[next[y]] = prev[y];
        y = prev[y];
      }

    }

    f--;
  }

  printf(" %d\n", answer);
}

int Main()
{
  int first_iteration;
  int _;
  new_assert(scanf("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __++)
  {
    printf("Case #%d:", __ + 1);
    solve();
  }

  return 0;
}



void new_assert(int expression);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
void new_assert(int expression) {
  return assert(expression);
}