#include<stdio.h>
int
Main ()
{
  long long i;
  long long j;
  long long min;
  long long l;
  long long works;
  long long next;
  long long r;
  long long add;
  long long cases;
  long long a[2000];
  long long rn[2000];
  long long now[2000];
  long long answer;
  long long interval;
  long long gain;
  long long skip;
  int size;
  int count;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%lld%lld%lld", &r, &min, &next);
      for (i = 0; i < next; i++)
	scanf ("%lld", a + i);
      for (i = 0; i < next; i++)
	rn[i] = -1;
      answer = 0;
      cases = 0;
      for (works = 0; works < r; works++)
	{
	  if (rn[cases] >= 0)
	    {
	      interval = works - rn[cases];
	      gain = answer - now[cases];
	      skip = ((r - works) - 1) / interval;
	      if (skip > 1)
		{
		  works += interval * skip;
		  answer += gain * skip;
		}
	    }
	  rn[cases] = works;
	  now[cases] = answer;
	  add = 0;
	  for (i = 0; i < next; i++)
	    {
	      if ((add + a[cases]) > min)
		break;
	      add += a[cases];
	      cases = (cases + 1) % next;
	    }
	  answer += add;
	}
      printf ("Case #%d: %lld\n", ++count, answer);
    }
  return 0;
}
