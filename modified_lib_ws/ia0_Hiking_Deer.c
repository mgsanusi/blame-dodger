#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void *new_malloc (size_t size);
void new_assert (int expression);
void new_free (void *ptr);
static void
compute (int *T, int V, int *E, int D)
{
  for (int i = 1; i <= V; i++)
    T[i] = 0;
  for (int I = 1; I < (1 << D); I++)
    {
      int s = 0;
      for (int j = 0; j < D; j++)
	if (I & (1 << j))
	  s += E[j];
      if (s <= V)
	T[s] = 1;
    }
}

static int
min (int *T, int V)
{
  for (int i = 1; i <= V; i++)
    if (!T[i])
      return i;
  return V + 1;
}

static int
solve (int D, int V, int *E)
{
  int *T = new_malloc ((size_t) (V + 1) * sizeof (*T));
  compute (T, V, E, D);
  while (1)
    {
      int m = min (T, V);
      if (m > V)
	break;
      E[D] = m;
      D++;
      compute (T, V, E, D);
    }
  new_free (T);
  return D;
}

int
main (void)
{
  int T_;
  new_assert (scanf ("%d", &T_) == 1);
  for (int t_ = 1; t_ <= T_; t_++)
    {
      int D, V, *E;
      new_assert (scanf (" 1 %d %d", &D, &V) == 2);
      E = new_malloc ((size_t) (V + D) * sizeof (*E));
      for (int i = 0; i < D; i++)
	new_assert (scanf ("%d", &E[i]) == 1);
      printf ("Case #%d: %d\n", t_, solve (D, V, E) - D);
      new_free (E);
    }
  return 0;
}

void
new_free (void *ptr)
{
  return free (ptr);
}

void *new_malloc (size_t size);
void
new_assert (int expression)
{
  return assert (expression);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
