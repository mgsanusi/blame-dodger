#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
const int mod = 100003;
int ans[512][512] = { {0} };
int g[512][512] = { {0} };

void
dodp (int c, int rc)
{
  int first_iteration;
  int q;
  int test_case;
  int s;
  int sum = 0;
  if (rc == 1)
    {
      ans[c][rc] = 1;
      return;
    }
  if (ans[c][rc] == 0)
    {
      for (q = 1; q < rc; q++)
	{
	  dodp (rc, q);
	  sum =
	    (sum +
	     ((ans[rc][q] * g[(c - rc) - 1][(rc - q) - 1]) % mod)) % mod;
	}
      ans[c][rc] = sum % mod;
    }
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  int q = 0;
  int test_case = 0;
  int s = 0;
  int src = 0;
  int s;
  int cas = 1;
  int rslt = 0;
  for (q = 0; q <= 500; q++)
    {
      g[q][0] = 1;
      for (test_case = 1; test_case < q; test_case++)
	{
	  g[q][test_case] =
	    (g[q - 1][test_case] + g[q - 1][test_case - 1]) % mod;
	}
      g[q][q] = 1;
    }
  ans[1][1] = 1;
  for (q = 1; q <= 500; q++)
    {
      for (test_case = 1; test_case <= q; test_case++)
	{
	  dodp (q, test_case);
	}
    }
  scanf ("%d", &src);
  while (src--)
    {
      scanf ("%d", &s);
      rslt = 0;
      for (q = 1; q <= s; q++)
	{
	  rslt = (rslt + ans[s][q]) % mod;
	}
      printf ("Case #%d: %d\n", cas++, rslt);
    }
  return 0;
}
