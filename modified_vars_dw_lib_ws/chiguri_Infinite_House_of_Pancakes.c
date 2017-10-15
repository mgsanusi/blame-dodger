#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int pan[1000];
int
search (int max, int minuts)
{
  int first_iteration;
  int casos;
  int minimal = max + minuts;
  int f;
  int maximal = max - 1;
  for (casos = 2; casos <= (max / 2); ++casos)
    {
      int quot = max / casos;
      int mod = max % casos;
      pan[quot] += pan[max] * (casos - mod);
      pan[quot + 1] += pan[max] * mod;
      while ((maximal > 0) && (pan[maximal] == 0))
	--maximal;
      f = search (maximal, minuts + (pan[max] * (casos - 1)));
      if (f < minimal)
	minimal = f;
      pan[quot] -= pan[max] * (casos - mod);
      pan[quot + 1] -= pan[max] * mod;
    }
  return minimal;
}

int
Main (void)
{
  int first_iteration;
  int datasetNum;
  int caseNum;
  int casos;
  int max;
  int minuts;
  int minimal;
  scanf ("%d", &datasetNum);
  for (caseNum = 1; caseNum <= datasetNum; ++caseNum)
    {
      max = 0;
      minuts = 0;
      for (casos = 0; casos < 1000; ++casos)
	{
	  pan[casos] = 0;
	}
      scanf ("%d", &n);
      for (casos = 0; casos < n; ++casos)
	{
	  int tid;
	  scanf ("%d", &tid);
	  if (tid > max)
	    max = tid;
	  pan[tid]++;
	}
      printf ("Case #%d: %d\n", caseNum, search (max, 0));
    }
  return 0;
}
