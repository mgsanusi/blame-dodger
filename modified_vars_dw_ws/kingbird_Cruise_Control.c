#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int score[222];
int state[222];
int total;
int flag;
double chance;
int
Main ()
{
  int first_iteration;
  freopen ("A-small-attempt2.in", "r", stdin);
  freopen ("output.txt", "w", stdout);
  int cases;
  int caseI;
  int i;
  int cp;
  int word;
  double r;
  double sum;
  double sum2;
  scanf ("%d", &cases);
  for (caseI = 1; caseI <= cases; caseI++)
    {
      scanf ("%d", &word);
      r = 0;
      for (i = 0; i < word; i++)
	{
	  scanf ("%d", &score[i]);
	  r += score[i];
	}
      printf ("Case #%d:", caseI);
      for (i = 0; i < word; i++)
	{
	  total = 0;
	  sum2 = 0;
	  memset (state, 0, sizeof (state));
	again:
	  chance =
	    (100 * ((((2 * r) - sum2) / (word - total)) - score[i])) / r;
	  sum = score[i] + ((r * chance) / 100);
	  flag = 0;
	  if (chance > 0.000001)
	    for (cp = 0; cp < word; cp++)
	      {
		if ((sum < score[cp]) && (state[cp] == 0))
		  {
		    state[cp] = 1;
		    total++;
		    flag = 1;
		    sum2 += score[cp];
		  }
	      }
	  if (flag == 1)
	    goto again;
	  if (chance >= 0.0)
	    printf (" %f", chance);
	  else
	    printf (" %f", 0.0);
	}
      printf ("\n");
    }
  return 0;
}
