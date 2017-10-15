#include<stdio.h>
double is[70000];
double next[70000];
int
Main ()
{
  int runleft;
  int j;
  int t;
  int lbeg;
  int owp;
  int num_queries;
  int node;
  int round;
  int size;
  int cnt = 0;
  int flag;
  int target = 1000000;
  double p;
  double answer;
  double per;
  double sum;
  double choose;
  double tmp1;
  double tmp2;
  double tmp;
  int c;
  int b;
  int c1;
  int x;
  scanf ("%d", &size);
  while (size--)
    {
      fprintf (stderr, "%d\n", size);
      scanf ("%d%lf%d", &num_queries, &p, &flag);
      node = (1 << num_queries) + 1;
      for (runleft = 0; runleft < node; runleft++)
	is[runleft] = 0;
      is[node - 1] = 1;
      for (round = 0; round < num_queries; round++)
	{
	  for (runleft = 0; runleft < node; runleft++)
	    next[runleft] = 0;
	  for (runleft = 0; runleft < node; runleft++)
	    {
	      c = 0;
	      b = runleft;
	      if (b > ((node - 1) - runleft))
		b = (node - 1) - runleft;
	      while (c >= (b + 10))
		{
		  c1 = ((c + c) + b) / 3;
		  x = ((c + b) + b) / 3;
		  tmp1 =
		    (p * is[runleft + c1]) + ((1 - p) * is[runleft - c1]);
		  tmp2 = (p * is[runleft + x]) + ((1 - p) * is[runleft - x]);
		  if (tmp1 > tmp2)
		    b = x;
		  else
		    c = c1;
		}
	      choose = 0;
	      for (t = c; t < (b + 1); t++)
		{
		  tmp = (p * is[runleft + t]) + ((1 - p) * is[runleft - t]);
		  if (choose < tmp)
		    choose = tmp;
		}
	      next[runleft] = choose;
	    }
	  for (runleft = 0; runleft < node; runleft++)
	    is[runleft] = next[runleft];
	}
      per = ((double) target) / (node - 1);
      sum = 0;
      for (runleft = 0; runleft < (node - 1); runleft++)
	{
	  sum += per;
	  if (((double) flag) < (sum - 1e-8))
	    break;
	}
      answer = is[runleft];
      printf ("Case #%d: %0.8lf\n", ++cnt, answer);
    }
  return 0;
}
