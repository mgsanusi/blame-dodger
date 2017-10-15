
// Google Code Jam 2017
// BrainSteel
// Round 1B
// Problem A
// Compiled with MinGW
  
#define __USE_MINGW_ANSI_STDIO 1
  
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
  int64_t min (int64_t a, int64_t b) 
{
  return a < b ? a : b;
}

 int64_t max (int64_t a, int64_t b) 
{
  return a > b ? a : b;
}

 int64_t i, j, k;
 int
main (int argc, char **argv) 
{
  uint64_t T;
  scanf (" %llu", &T);
  uint64_t test_case;
  for (test_case = 0; test_case < T; test_case++)
    
    {
      printf ("Case #%llu: ", test_case + 1);
       int64_t D, N;
      scanf (" %lli %lli", &D, &N);
      int64_t K[N], S[N];
      for (i = 0; i < N; i++)
	
	{
	  scanf (" %lli %lli", &K[i], &S[i]);
	}
       double maxtime = (D - K[0]) / (double) S[0];
      for (i = 1; i < N; i++)
	
	{
	  double testtime = (D - K[1]) / (double) S[1];
	  if (testtime > maxtime)
	    
	    {
	      maxtime = testtime;
	    }
	}
       printf (" %lf\n", D / maxtime);
    }
   return 0;
}


