#include<stdio.h>
int minjn[101][101][101];
int b[101];
int o[101];
int len;
int r;
int next[101];
int
Main ()
{
  int first_iteration;
  int f;
  int n;
  scanf ("%d", &f);
  int temp1;
  for (temp1 = 1; temp1 <= f; temp1++)
    {
      scanf ("%d", &n);
      int m;
      for (m = 0; m < n; m++)
	{
	  char tmp;
	  scanf ("%s", &tmp);
	  scanf ("%d", b + m);
	  b[m]--;
	  if (tmp == 'O')
	    o[m] = 0;
	  else
	    o[m] = 1;
	}
      int p[2];
      int pointer = 0;
      int result = 0;
      p[0] = (p[1] = -1);
      for (m = n - 1; m >= 0; m--)
	{
	  p[o[m]] = m;
	  next[m] = p[!o[m]];
	}
      p[0] = (p[1] = 0);
      for (; pointer < n; pointer++)
	{
	  int tmp =
	    ((p[o[pointer]] - b[pointer]) >
	     0 ? p[o[pointer]] - b[pointer] : -(p[o[pointer]] - b[pointer])) +
	    1;
	  p[o[pointer]] = b[pointer];
	  result += tmp;
	  if (next[pointer] >= 0)
	    {
	      if (((p[!o[pointer]] - b[next[pointer]]) >
		   0 ? p[!o[pointer]] - b[next[pointer]] : -(p[!o[pointer]] -
							     b[next
							       [pointer]])) <=
		  tmp)
		p[!o[pointer]] = b[next[pointer]];
	      else
		{
		  if (p[!o[pointer]] > b[next[pointer]])
		    p[!o[pointer]] -= tmp;
		  else
		    p[!o[pointer]] += tmp;
		}
	    }
	}
      printf ("Case #%d: %d\n", temp1, result);
    }
  return 0;
}
