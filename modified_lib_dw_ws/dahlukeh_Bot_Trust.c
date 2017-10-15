#include <stdio.h>
#include <stdlib.h>
int curIns[101][2];
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_abs (int x);
void handleCase (void);
int
main ()
{
  int first_iteration;
  new_freopen ("bot.in", "r", stdin);
  new_freopen ("bot.out", "w", stdout);
  int numCases;
  scanf ("%d ", &numCases);
  int i;
  for (i = 0; i < numCases; i++)
    {
      printf ("Case #%d: ", i + 1);
      handleCase ();
    }
  return 0;
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_abs (int x);
void
handleCase (void)
{
  int first_iteration;
  int numIns;
  scanf ("%d ", &numIns);
  int i;
  char person;
  for (i = 0; i < numIns; i++)
    {
      scanf ("%c %d ", &person, &curIns[i][1]);
      if (person == 'O')
	{
	  curIns[i][0] = 0;
	}
      else
	{
	  curIns[i][0] = 1;
	}
    }
  int timeTaken = 0;
  int curOrg = 1;
  int curBlue = 1;
  int leftBlueTime = 0;
  int leftOrangeTime = 0;
  int dis;
  for (i = 0; i < numIns; i++)
    {
      if (curIns[i][0] == 0)
	{
	  dis = new_abs (curIns[i][1] - curOrg);
	  if (leftOrangeTime > dis)
	    {
	      timeTaken++;
	      leftBlueTime++;
	    }
	  else
	    {
	      timeTaken += (dis - leftOrangeTime) + 1;
	      leftBlueTime += (dis - leftOrangeTime) + 1;
	    }
	  leftOrangeTime = 0;
	  curOrg = curIns[i][1];
	}
      else
	{
	  dis = new_abs (curIns[i][1] - curBlue);
	  if (leftBlueTime > dis)
	    {
	      timeTaken++;
	      leftOrangeTime++;
	    }
	  else
	    {
	      timeTaken += (dis - leftBlueTime) + 1;
	      leftOrangeTime += (dis - leftBlueTime) + 1;
	    }
	  leftBlueTime = 0;
	  curBlue = curIns[i][1];
	}
    }
  printf ("%d\n", timeTaken);
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
new_abs (int x)
{
  int first_iteration;
  return abs (x);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
