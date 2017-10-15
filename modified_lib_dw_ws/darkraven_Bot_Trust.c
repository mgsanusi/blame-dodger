#include<stdio.h>
int g[101][101][101];
int b[101];
int o[101];
int oc;
int bc;
int next[101];
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
	  char tmp;
	  scanf ("%s", &tmp);
	  scanf ("%d", b + i);
	  b[i]--;
	  if (tmp == 'O')
	    o[i] = 0;
	  else
	    o[i] = 1;
	}
      int p[2];
      int ptr = 0;
      int ans = 0;
      p[0] = (p[1] = -1);
      for (i = n - 1; i >= 0; i--)
	{
	  p[o[i]] = i;
	  next[i] = p[!o[i]];
	}
      p[0] = (p[1] = 0);
      for (; ptr < n; ptr++)
	{
	  int tmp =
	    ((p[o[ptr]] - b[ptr]) >
	     0 ? p[o[ptr]] - b[ptr] : -(p[o[ptr]] - b[ptr])) + 1;
	  p[o[ptr]] = b[ptr];
	  ans += tmp;
	  if (next[ptr] >= 0)
	    {
	      if (((p[!o[ptr]] - b[next[ptr]]) >
		   0 ? p[!o[ptr]] - b[next[ptr]] : -(p[!o[ptr]] -
						     b[next[ptr]])) <= tmp)
		p[!o[ptr]] = b[next[ptr]];
	      else
		{
		  if (p[!o[ptr]] > b[next[ptr]])
		    p[!o[ptr]] -= tmp;
		  else
		    p[!o[ptr]] += tmp;
		}
	    }
	}
      printf ("Case #%d: %d\n", pp, ans);
    }
  return 0;
}
