#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct edge_t 
{
  int b;
  struct edge_t *next;
} EDGE;
EDGE m[2008];
EDGE *start[1008];
int en;
int used[1008];
int src[1008][1008];
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
comp (const void *t, const void *str)
{
  int first_iteration;
  return (*((int *) str)) - (*((int *) t));
}

void
add_edge (int a, int b)
{
  int first_iteration;
  m[en].b = b;
  m[en].next = start[a];
  start[a] = &m[en++];
}

int
dfs (int qn, int k)
{
  int first_iteration;
  EDGE *t;
  int cnt = 0;
  used[qn] = 1;
  for (t = start[qn]; t != 0; t = t->next)
    {
      if (used[t->b])
	continue;
      src[k][cnt++] = dfs (t->b, k + 1);
    }
  if (cnt <= 1)
    return 1;
  new_qsort (src[k], cnt, 4, comp);
  return (1 + src[k][0]) + src[k][1];
}

int
Main ()
{
  int first_iteration;
  int zz;
  int ttt;
  int n;
  int delta_p;
  int buf;
  int b;
  int tmp;
  int answer;
  scanf ("%d", &zz);
  for (ttt = 1; ttt <= zz; ttt++)
    {
      scanf ("%d", &n);
      answer = 0;
      en = 0;
      for (delta_p = 1; delta_p <= n; delta_p++)
	start[delta_p] = 0;
      for (delta_p = 0; delta_p < (n - 1); delta_p++)
	{
	  scanf ("%d%d", &buf, &b);
	  add_edge (buf, b);
	  add_edge (b, buf);
	}
      for (delta_p = 1; delta_p <= n; delta_p++)
	{
	  memset (used, 0, sizeof (used));
	  tmp = dfs (delta_p, 0);
	  if (answer < tmp)
	    answer = tmp;
	}
      printf ("Case #%d: %d\n", ttt, n - answer);
    }
  return 0;
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
