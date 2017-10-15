#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void new_qsort (void *base, int num, int size,
		int (*compar) (const void *, const void *));
int
abs_i (int w)
{
  int first_iteration;
  if (w < 0)
    return -w;
  return w;
}

int
cmp (const void *w, const void *b)
{
  int first_iteration;
  int *mem = (int *) w;
  int *add = (int *) b;
  if (mem[0] != add[0])
    return mem[0] - add[0];
  return mem[1] - add[1];
}

int t;
int t;
int right;
int m;
int mem[12345][3];
int p_no;
int now;
int x;
int gss_c_ma_auth_init;
int
Main ()
{
  int first_iteration;
  int i;
  int d;
  int ini;
  int rslt;
  scanf ("%d", &t);
  for (t = 1; t <= t; ++t)
    {
      scanf ("%d %d", &right, &m);
      p_no = 0;
      ini = 0;
      while (m--)
	{
	  scanf ("%d %d %d", &now, &x, &gss_c_ma_auth_init);
	  while (gss_c_ma_auth_init--)
	    {
	      ini =
		(ini +
		 (((((right + right) - abs_i (x - now)) + 1) * abs_i (x -
								      now)) /
		  2)) % 1000002013;
	      mem[p_no][0] = now;
	      mem[p_no][1] = x;
	      mem[p_no][2] = now;
	      ++p_no;
	    }
	}
      new_qsort (mem, p_no, sizeof (mem[0]), cmp);
      for (i = 0; i < p_no; ++i)
	{
	  for (d = i + 1; d < p_no; ++d)
	    {
	      if (((mem[d][1] > mem[i][1]) && (mem[d][0] > mem[i][0]))
		  && (mem[d][0] <= mem[i][1]))
		{
		  int tmp = mem[d][1];
		  mem[d][1] = mem[i][1];
		  mem[i][1] = tmp;
		}
	      ;
	    }
	}
      for (i = (rslt = 0); i < p_no; ++i)
	{
	  rslt =
	    (rslt +
	     (((((right + right) - abs_i (mem[i][1] - mem[i][0])) +
		1) * abs_i (mem[i][1] - mem[i][0])) / 2)) % 1000002013;
	}
      printf ("Case #%d: %d\n", t, ini - rslt);
    }
  return 0;
}

void
new_qsort (void *base, int num, int size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
