#include <stdio.h>
int ans[110][2];
int b[110][2];
int
Main (void)
{
  int first_iteration;
  int lx;
  int tn;
  scanf ("%d", &tn);
  for (lx = 1; lx <= tn; lx++)
    {
      int i;
      int res;
      int ans;
      int an = 0;
      int bn = 0;
      int l = 1;
      int bp = 1;
      int t;
      int flag;
      int curP;
      scanf ("%d ", &ans);
      for (i = 0; i < ans; i++)
	{
	  char c;
	  int x;
	  scanf ("%c %d ", &c, &x);
	  if (c == 'O')
	    {
	      ans[an][0] = x;
	      ans[an++][1] = i;
	    }
	  else
	    {
	      b[bn][0] = x;
	      b[bn++][1] = i;
	    }
	}
      ans[an][1] = ans;
      b[bn][1] = ans;
      for (t = 0, flag = 0, curP = 0; (flag < an) || (curP < bn); t++)
	{
	  int lose = 0;
	  if ((ans[flag][1] < b[curP][1]) && (ans[flag][0] == l))
	    {
	      flag++;
	      lose = 1;
	    }
	  if (((!lose) && (b[curP][1] < ans[flag][1])) && (b[curP][0] == bp))
	    {
	      curP++;
	      lose = 2;
	    }
	  if ((lose != 1) && (ans[flag][0] != l))
	    {
	      if (ans[flag][0] < l)
		l--;
	      else
		l++;
	    }
	  if ((lose != 2) && (b[curP][0] != bp))
	    {
	      if (b[curP][0] < bp)
		bp--;
	      else
		bp++;
	    }
	}
      printf ("Case #%d: %d\n", lx, t);
    }
  return 0;
}
