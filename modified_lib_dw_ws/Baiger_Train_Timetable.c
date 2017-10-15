#include <stdio.h>
int t;
int na;
int nb;
int queue_a[101];
int queue_b[101];
int a;
int b;
int tail_a;
int tail_b;
int pa;
int pb;
int a_dep[101];
int a_arr[101];
int b_dep[101];
int b_arr[101];
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
void
new_qsort (int a1[], int a2[], int p, int r)
{
  int first_iteration;
  int i = p;
  int j = r;
  int key = a1[(p + r) >> 1];
  first_iteration = 1;
  while ((i <= j) || (first_iteration == 1))
    {
      if (first_iteration)
	first_iteration = 0;
      while (a1[i] < key)
	i++;
      while (a1[j] > key)
	j--;
      if (i <= j)
	{
	  int tmp = a1[i];
	  a1[i] = a1[j];
	  a1[j] = tmp;
	  tmp = a2[i];
	  a2[i] = a2[j];
	  a2[j] = tmp;
	  i++;
	  j--;
	}
    }
  if (p < j)
    new_qsort (a1, a2, p, j);
  if (r > i)
    new_qsort (a1, a2, i, r);
}

int
found (int queue[], int tail, int limit)
{
  int first_iteration;
  int i;
  for (i = 0; i <= tail; i++)
    {
      if (queue[i] <= limit)
	return i;
    }
  return -1;
}

void
next_train ()
{
  int first_iteration;
  int p;
  if ((nb == 0) || (a_dep[pa] <= b_dep[pb]))
    {
      if ((tail_a == (-1))
	  || ((p = found (queue_a, tail_a, a_dep[pa])) == (-1)))
	a++;
      else
	{
	  queue_a[p] = queue_a[tail_a];
	  tail_a--;
	}
      tail_b++;
      queue_b[tail_b] = a_arr[pa] + t;
      na--;
      pa++;
    }
  else
    {
      if ((tail_b == (-1))
	  || ((p = found (queue_b, tail_b, b_dep[pb])) == (-1)))
	b++;
      else
	{
	  queue_b[p] = queue_b[tail_b];
	  tail_b--;
	}
      tail_a++;
      queue_a[tail_a] = b_arr[pb] + t;
      nb--;
      pb++;
    }
}

int
main ()
{
  int first_iteration;
  int n;
  int i;
  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    {
      scanf ("%d\n%d %d", &t, &na, &nb);
      int j;
      int dep_h;
      int dep_min;
      int arr_h;
      int arr_min;
      for (j = 0; j < na; j++)
	{
	  scanf ("%d:%d %d:%d", &dep_h, &dep_min, &arr_h, &arr_min);
	  a_dep[j] = (dep_h * 60) + dep_min;
	  a_arr[j] = (arr_h * 60) + arr_min;
	}
      a_dep[na] = 2400;
      for (j = 0; j < nb; j++)
	{
	  scanf ("%d:%d %d:%d", &dep_h, &dep_min, &arr_h, &arr_min);
	  b_dep[j] = (dep_h * 60) + dep_min;
	  b_arr[j] = (arr_h * 60) + arr_min;
	}
      b_dep[nb] = 2400;
      new_qsort (a_dep, a_arr, 0, na - 1);
      new_qsort (b_dep, b_arr, 0, nb - 1);
      a = (b = (pa = (pb = 0)));
      tail_a = (tail_b = -1);
      for (j = 0; (na + nb) > 0; j++)
	next_train ();
      printf ("Case #%d: %d %d\n", i, a, b);
    }
  return 0;
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  int first_iteration;
  return qsort (base, num, size, compar);
}
