#include <stdio.h>
int ed[1024];
int a[1024];
long long e[1024];
int
Main (void)
{
  int p1;
  int ti;
  scanf ("%d", &p1);
  for (ti = 1; ti <= p1; ti++)
    {
      int r;
      int k;
      int v;
      int c;
      int awal;
      int time;
      long long man;
      long long ret;
      scanf ("%d %d %d", &r, &k, &v);
      for (c = 0; c < v; c++)
	{
	  scanf ("%d", ed + c);
	  a[c] = -1;
	}
      time = 0;
      man = 0;
      c = 0;
      while (a[c] == (-1))
	{
	  int y = 0;
	  a[c] = time;
	  e[c] = man;
	  for (awal = 0; awal < v; awal++)
	    {
	      int z = (c + awal) % v;
	      if ((y + ed[z]) > k)
		break;
	      y += ed[z];
	    }
	  c = (c + awal) % v;
	  time++;
	  man += y;
	}
      if (a[c] > time)
	{
	  for (c = 0; c < v; c++)
	    {
	      if (a[c] == time)
		{
		  ret = e[c];
		  break;
		}
	    }
	}
      else
	{
	  int b;
	  r -= a[c];
	  ret = e[c];
	  time -= a[c];
	  man -= e[c];
	  ret += man * (r / time);
	  r %= time;
	  b = -1;
	  for (awal = 0; awal < v; awal++)
	    {
	      if ((a[awal] <= (a[c] + r))
		  && ((b == (-1)) || (a[awal] > a[b])))
		b = awal;
	    }
	  ret += e[b] - e[c];
	}
      printf ("Case #%d: %d\n", ti, ret);
    }
  return 0;
}
