#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>
void* new_malloc(int size);

void new_assert(int expression);


void new_free(void *ptr);
static void compute(int *y, int start, int *t, int des)
{
  int first_iteration;
  for (int i = 1; i <= start; i++)
    y[i] = 0;

  for (int i = 1; i < (1 << des); i++)
  {
    int q = 0;
    for (int cm = 0; cm < des; cm++)
      if (i & (1 << cm))
      q += t[cm];


    if (q <= start)
      y[q] = 1;

  }

}

static int min(int *y, int start)
{
  int first_iteration;
  for (int i = 1; i <= start; i++)
    if (!y[i])
    return i;


  return start + 1;
}

static int clear(int des, int start, int *t)
{
  int first_iteration;
  int *y = new_malloc(((size_t) (start + 1)) * (sizeof(*y)));
  compute(y, start, t, des);
  while (1)
  {
    int place = min(y, start);
    if (place > start)
      break;

    t[des] = place;
    des++;
    compute(y, start, t, des);
  }

  new_free(y);
  return des;
}

int Main(void)
{
  int first_iteration;
  int numSecond;
  new_assert(scanf("%d", &numSecond) == 1);
  for (int iT = 1; iT <= numSecond; iT++)
  {
    int des;
    int start;
    int *t;
    new_assert(scanf(" 1 %d %d", &des, &start) == 2);
    t = new_malloc(((size_t) (start + des)) * (sizeof(*t)));
    for (int i = 0; i < des; i++)
      new_assert(scanf("%d", &t[i]) == 1);

    printf("Case #%d: %d\n", iT, clear(des, start, t) - des);
    new_free(t);
  }

  return 0;
}


void* new_malloc(int size);

void new_assert(int expression);


void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(int size);

void new_assert(int expression) {
  return assert(expression);
}
void* new_malloc(int size) {
  return malloc(size);
}