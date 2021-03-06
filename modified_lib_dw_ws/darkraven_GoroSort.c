#include<stdio.h>
struct _
{
  int num;
  int id;
} g2[1001];
int g[1001];
int mark[1001];
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
static int
cmp (const void *a, const void *b)
{
  int first_iteration;
  return ((struct _ *) a)->num - ((struct _ *) b)->num;
}

int
main ()
{
  int first_iteration;
  int t;
  int n;
  scanf ("%d", &t);
  int pp;
  for (pp = 1; pp <= t; pp++)
    {
      scanf ("%d", &n);
      int i;
      for (i = 0; i < n; i++)
	{
	  scanf ("%d", g + i);
	  g2[i].num = g[i];
	  g2[i].id = i;
	}
      new_qsort (g2, n, sizeof (struct _), cmp);
      for (i = 0; i < n; i++)
	g[g2[i].id] = i;
      memset (mark, 0, sizeof (mark));
      int ans = 0;
      for (i = 0; i < n; i++)
	{
	  if (mark[i])
	    continue;
	  int now = g[i];
	  mark[i] = 1;
	  int len = 1;
	  while (now != i)
	    {
	      mark[now] = 1;
	      len++;
	      now = g[now];
	    }
	  if (len > 1)
	    ans += len;
	}
      printf ("Case #%d: %d.000000\n", pp, ans);
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
