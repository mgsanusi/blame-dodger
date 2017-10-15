#include <stdio.h>
int
Main ()
{
  int caseCnt;
  int subjectI;
  int cases;
  int t;
  int elevation[10][10];
  int sinkCnt;
  int sinkY[2];
  int sinkX[2];
  int orga;
  int j;
  int f;
  int tmp;
  int k;
  int dir;
  int drop;
  scanf ("%d", &caseCnt);
  for (subjectI = 1; subjectI <= caseCnt; subjectI++)
    {
      scanf ("%d %d", &cases, &t);
      for (orga = 0; orga < cases; orga++)
	for (j = 0; j < t; j++)
	  scanf ("%d", &elevation[orga][j]);
      sinkCnt = 0;
      printf ("Case #%d:\n", subjectI);
      for (orga = 0; orga < cases; orga++)
	{
	  for (j = 0; j < t; j++)
	    {
	      tmp = orga, f = j;
	      dir = 1;
	      while (dir != 0)
		{
		  dir = 0, drop = 0;
		  if ((tmp > 0)
		      && ((elevation[tmp][f] - elevation[tmp - 1][f]) > drop))
		    dir = 1, drop = elevation[tmp][f] - elevation[tmp - 1][f];
		  if ((f > 0)
		      && ((elevation[tmp][f] - elevation[tmp][f - 1]) > drop))
		    dir = 2, drop = elevation[tmp][f] - elevation[tmp][f - 1];
		  if ((f < (t - 1))
		      && ((elevation[tmp][f] - elevation[tmp][f + 1]) > drop))
		    dir = 3, drop = elevation[tmp][f] - elevation[tmp][f + 1];
		  if ((tmp < (cases - 1))
		      && ((elevation[tmp][f] - elevation[tmp + 1][f]) > drop))
		    dir = 4, drop = elevation[tmp][f] - elevation[tmp + 1][f];
		  switch (dir)
		    {
		    case 1:
		      tmp--;
		      break;
		    case 2:
		      f--;
		      break;
		    case 3:
		      f++;
		      break;
		    case 4:
		      tmp++;
		      break;
		    }
		}
	      for (k = 0; k < sinkCnt; k++)
		if ((sinkY[k] == tmp) && (sinkX[k] == f))
		  break;
	      if (k == sinkCnt)
		sinkY[k] = tmp, sinkX[k] = f, sinkCnt++;
	      printf ("%c ", 'a' + ((char) k));
	    }
	  printf ("\n");
	}
    }
  return 0;
}
