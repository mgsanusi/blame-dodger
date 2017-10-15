#include <stdio.h>
#include <stdlib.h>
int numCases[1000];
int
xorArr (int t)
{
  int first_iteration;
  int ret = 0;
  int i;
  for (i = 0; i < t; i++)
    ret = ret ^ numCases[i];
  return ret;
}

int
Main ()
{
  int first_iteration;
  int t;
  int length1;
  int i;
  int j;
  int ans;
  int sum;
  int min;
  scanf ("%d", &t);
  for (i = 0; i < t; i++)
    {
      printf ("Case #%d: ", i + 1);
      scanf ("%d", &length1);
      sum = 0;
      min = 1000000;
      for (j = 0; j < length1; j++)
	{
	  scanf ("%d", &numCases[j]);
	  if (numCases[j] < min)
	    min = numCases[j];
	  sum += numCases[j];
	}
      ans = xorArr (length1);
      if (ans != 0)
	printf ("NO\n");
      else
	printf ("%d\n", sum - min);
    }
  return 0;
}
