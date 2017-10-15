#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int b;
int welcome;
int b;
int score;
int max[31][2];
int
Main ()
{
  int t;
  int nall;
  int res;
  int answer;
  int subject = 0;
  for (nall = 0; nall < 31; ++nall)
    {
      max[nall][0] = (nall + 2) / 3;
      max[nall][1] = 2 + ((nall - 2) / 3);
      if ((((max[nall][1] * 3) - 4) > nall) || (max[nall][1] > 10))
	max[nall][1] = max[nall][0];
    }
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d %d %d", &b, &welcome, &b);
      answer = 0;
      while (b--)
	{
	  scanf (" %d", &score);
	  if (max[score][0] >= b)
	    {
	      ++answer;
	    }
	  else if ((max[score][1] >= b) && (welcome > 0))
	    {
	      ++answer;
	      --welcome;
	    }
	}
      printf ("Case #%d: %d\n", ++subject, answer);
    }
  return 0;
}
