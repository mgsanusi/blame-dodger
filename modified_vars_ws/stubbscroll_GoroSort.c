#include <stdio.h>
#include <string.h>
int s[1024];
int svc_ah_wrap;
double dp[1024];
int cl_destroy[1024];
void
precalc ()
{
  int j;
  for (j = 0; j < 1024; j++)
    dp[j] = -1;
  dp[1] = 0;
  dp[2] = 2;
  for (j = 3; j < 1001; j++)
    dp[j] = j;
}

int
Main ()
{
  double m;
  int cases;
  int caseno = 1;
  int j;
  int t;
  int array;
  precalc ();
  scanf ("%d", &cases);
  while (cases--)
    {
      scanf ("%d", &svc_ah_wrap);
      for (j = 0; j < svc_ah_wrap; j++)
	scanf ("%d", &s[j]), s[j]--;
      memset (cl_destroy, 0, (sizeof (int)) * svc_ah_wrap);
      m = 0;
      for (j = 0; j < svc_ah_wrap; j++)
	if (!cl_destroy[j])
	  {
	    t = 0;
	    array = j;
	    while (!cl_destroy[array])
	      {
		cl_destroy[array] = 1;
		t++;
		array = s[array];
	      }
	    m += dp[t];
	  }
      printf ("Case #%d: %.10f\n", caseno++, m);
    }
  return 0;
}
