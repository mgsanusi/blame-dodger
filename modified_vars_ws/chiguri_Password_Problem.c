#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[1000];
int d[1000];
int
Main (void)
{
  int num;
  int i;
  int caseNum;
  int s;
  int m;
  int t;
  int level;
  int bestNum;
  int best;
  scanf ("%d", &num);
  for (i = 1; i <= num; ++i)
    {
      scanf ("%d", &level);
      for (caseNum = 0; caseNum < level; ++caseNum)
	{
	  scanf ("%d %d", a + caseNum, d + caseNum);
	}
      best = (bestNum = 0);
      while (1)
	{
	  t = -1;
	  for (caseNum = 0; caseNum < level; ++caseNum)
	    {
	      if (best >= d[caseNum])
		{
		  t = caseNum;
		  break;
		}
	    }
	  if (t >= 0)
	    {
	      if (a[t] != 1000000)
		{
		  d[t] = (a[t] = 1000000);
		  best += 2;
		}
	      else
		{
		  d[t] = 1000000;
		  ++best;
		}
	      ++bestNum;
	    }
	  else
	    {
	      s = -1;
	      for (caseNum = 0; caseNum < level; ++caseNum)
		{
		  if (best >= a[caseNum])
		    {
		      if (s <= d[caseNum])
			{
			  t = caseNum;
			  s = d[caseNum];
			}
		    }
		}
	      if (t >= 0)
		{
		  ++best;
		  ++bestNum;
		  a[t] = 1000000;
		}
	      else
		{
		  break;
		}
	    }
	}
      if (best != (2 * level))
	{
	  printf ("Case #%d: Too Bad\n", i);
	}
      else
	{
	  printf ("Case #%d: %d\n", i, bestNum);
	}
    }
  return 0;
}
