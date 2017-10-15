#include<stdio.h>
int rslt[100];
int d;
int x;
void
findRslt (int dig, int a, int max, int now, int tc)
{
  int ti;
  if (tc <= max)
    {
      if (tc == 0)
	{
	  x = 1;
	  d = now;
	}
      else if (tc != 1)
	{
	  rslt[now] = tc;
	  d = now + 1;
	  x = 1;
	}
      return;
    }
  for (ti = max; ti > 1; ti--)
    {
      if (x == 1)
	return;
      if (tc > (ti * (dig - now)))
	return;
      rslt[now] = ti;
      findRslt (dig, a, ti, now + 1, tc - ti);
    }
  return;
}

int
Main ()
{
  int vy;
  int cdel;
  scanf ("%d", &vy);
  for (cdel = 0; cdel < vy; cdel++)
    {
      int dig;
      int a;
      int is;
      x = 0;
      d = 0;
      scanf ("%d %d %d", &dig, &a, &is);
      is = (dig * a) - is;
      int ti;
      int key;
      if ((dig != 1) && (a != 1))
	{
	  for (ti = a; ti > 1; ti--)
	    {
	      if (x == 1)
		break;
	      if ((is >= (2 * ti)) && (is <= (ti * dig)))
		{
		  rslt[0] = (rslt[1] = ti);
		  findRslt (dig, a, ti, 2, is - (2 * ti));
		}
	    }
	  printf ("Case #%d:\n", cdel + 1);
	  if (x == 0)
	    {
	      if (is != 1)
		printf ("Impossible\n");
	      else
		{
		  printf ("c");
		  for (ti = 1; ti < a; ti++)
		    printf ("*");
		  printf ("\n");
		  for (ti = 1; ti < dig; ti++)
		    {
		      for (key = 0; key < a; key++)
			printf ("*");
		      printf ("\n");
		    }
		}
	    }
	  else
	    {
	      printf ("c");
	      for (ti = 1; ti < rslt[0]; ti++)
		printf (".");
	      for (ti = rslt[0]; ti < a; ti++)
		printf ("*");
	      printf ("\n");
	      for (ti = 1; ti < d; ti++)
		{
		  for (key = 0; key < rslt[ti]; key++)
		    printf (".");
		  for (key = rslt[ti]; key < a; key++)
		    printf ("*");
		  printf ("\n");
		}
	      for (ti = d; ti < dig; ti++)
		{
		  for (key = 0; key < a; key++)
		    printf ("*");
		  printf ("\n");
		}
	    }
	}
      else
	{
	  printf ("Case #%d:\n", cdel + 1);
	  if (dig == 1)
	    {
	      printf ("c");
	      for (ti = 1; ti < is; ti++)
		printf (".");
	      for (ti = is; ti < a; ti++)
		printf ("*");
	      printf ("\n");
	    }
	  else
	    {
	      printf ("c\n");
	      for (ti = 1; ti < is; ti++)
		printf (".\n");
	      for (ti = is; ti < dig; ti++)
		printf ("*\n");
	    }
	}
    }
  return 0;
}
