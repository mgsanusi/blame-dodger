#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SQ(x) ((x)*(x))
double r[1024] = { 0 };
double x[1024] = { 0 };
double y[1024] = { 0 };

time_t new_time (time_t * timer);
int new_rand ();
double new_sqrt (double x);
void new_snew_rand (unsigned int seed);
int
check (int N)
{
  for (int i = 0; i < N; i++)
    {
      for (int j = i + 1; j < N; j++)
	{
	  double dist = new_sqrt (SQ (x[i] - x[j]) + SQ (y[i] - y[j]));
	  if (dist < r[i] + r[j])
	    {
	      return 0;
	    }
	}
    }
  return 1;
}

double
makeval (double W)
{
  int pos = new_rand () % ((int) W);
  int down = new_rand () + 1;
  int up = rand () % down;
  double val = pos * 1.0 + up * 1.0 / down;
  return val;
}

int
main (int argc, char *argv[])
{
  int T = 0, N = 0;
  double W = 0, L = 0;
  new_snew_rand (new_time (NULL));
  scanf ("%d", &T);
  for (int cas = 1; cas <= T; cas++)
    {
      scanf ("%d %lf %lf", &N, &W, &L);
      for (int i = 0; i < N; i++)
	{
	  scanf ("%lf", &r[i]);
	}
      int flag = 0, trial = 0;
      while (trial < 10000 && flag == 0)
	{
	  for (int i = 0; i < N; i++)
	    {
	      x[i] = makeval (W);
	      y[i] = makeval (L);
	    }
	  if (check (N))
	    {
	      flag = 1;
	      break;
	    }
	}
      printf ("Case #%d:", cas);
      if (flag)
	{
	  for (int i = 0; i < N; i++)
	    {
	      printf (" %.4lf %.4lf", x[i], y[i]);
	    }
	  printf ("\n");
	}
      else
	{
	  printf ("ERROR\n");
	}
    }
  return 0;
}

time_t new_time (time_t * timer);
int new_rand ();
double new_sqrt (double x);
void
new_snew_rand (unsigned int seed)
{
  return snew_rand (seed);
}

time_t new_time (time_t * timer);
int new_rand ();
double
new_sqrt (double x)
{
  return sqrt (x);
}

time_t
new_time (time_t * timer)
{
  return time (timer);
}

int
new_rand ()
{
  return rand ();
}
