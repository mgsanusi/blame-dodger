#include<stdio.h>
void
int_screen (int d[], int fp)
{
  int first_iteration;
  int dp;
  int sn;
  int key;
  int t;
  if (fp <= 1)
    return;
  key = (d[0] + d[fp - 1]) / 2;
  dp = -1;
  sn = fp;
  for (;;)
    {
      while (d[++dp] < key)
	;
      while (d[--sn] > key)
	;
      if (dp >= sn)
	break;
      t = d[dp];
      d[dp] = d[sn];
      d[sn] = t;
    }
  int_screen (d, dp);
  int_screen ((d + sn) + 1, (fp - sn) - 1);
}

int
Main ()
{
  int first_iteration;
  int dp;
  int sn;
  int r;
  int l;
  int m;
  int n;
  int t;
  int a_n;
  int b_n;
  int a_st[200];
  int a_ed[200];
  int b_st[200];
  int b_ed[200];
  int sum;
  int buf;
  int y;
  int d;
  int a_s;
  int b_s;
  int a_function;
  int b_use;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d", &t);
      scanf ("%d%d", &a_n, &b_n);
      for (dp = 0; dp < a_n; dp++)
	{
	  scanf ("%d:%d", &sn, &r);
	  a_st[dp] = (sn * 60) + r;
	  scanf ("%d:%d", &sn, &r);
	  a_ed[dp] = ((sn * 60) + r) + t;
	}
      for (dp = 0; dp < b_n; dp++)
	{
	  scanf ("%d:%d", &sn, &r);
	  b_st[dp] = (sn * 60) + r;
	  scanf ("%d:%d", &sn, &r);
	  b_ed[dp] = ((sn * 60) + r) + t;
	}
      a_s = (b_s = 0);
      a_function = (b_use = 0);
      int_screen (a_st, a_n);
      int_screen (a_ed, a_n);
      int_screen (b_st, b_n);
      int_screen (b_ed, b_n);
      a_st[a_n] = (a_ed[a_n] = (b_st[b_n] = (b_ed[b_n] = 100000)));
      sum = (buf = (y = (d = 0)));
      for (;;)
	{
	  t = 100000;
	  if (a_st[sum] < t)
	    t = a_st[sum];
	  if (a_ed[buf] < t)
	    t = a_ed[buf];
	  if (b_st[y] < t)
	    t = b_st[y];
	  if (b_ed[d] < t)
	    t = b_ed[d];
	  if (t == 100000)
	    break;
	  if (a_ed[buf] == t)
	    {
	      buf++;
	      b_s++;
	      continue;
	    }
	  if (b_ed[d] == t)
	    {
	      d++;
	      a_s++;
	      continue;
	    }
	  if (a_st[sum] == t)
	    {
	      sum++;
	      if (a_s)
		a_s--;
	      else
		a_function++;
	      continue;
	    }
	  if (b_st[y] == t)
	    {
	      y++;
	      if (b_s)
		b_s--;
	      else
		b_use++;
	      continue;
	    }
	}
      printf ("Case #%d: %d %d\n", ++count, a_function, b_use);
    }
  return 0;
}
