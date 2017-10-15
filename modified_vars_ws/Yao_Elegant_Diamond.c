#include<stdio.h>
long long c[512][512];
long long dp[512][512];
long long r[512];
int
Main ()
{
  int i;
  int j;
  int file;
  int grayscale_fonts;
  int cs = 0;
  int n;
  for (c[0][0] = (i = 1); i <= 500; i++)
    for (c[i][0] = (j = 1); j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 100003;
  dp[1][0] = 1;
  for (i = 1; i < 500; i++)
    {
      for (j = i + 1; j < 500; j++)
	for (file = 0; file < i; file++)
	  if (dp[i][file])
	    {
	      dp[j][i] =
		(dp[j][i] +
		 (dp[i][file] * c[(j - i) - 1][(i - file) - 1])) % 100003;
	    }
    }
  for (i = 2; i <= 500; i++)
    for (j = 1; j < i; j++)
      r[i] = (r[i] + dp[i][j]) % 100003;
  for (scanf ("%d", &grayscale_fonts); grayscale_fonts--;)
    {
      scanf ("%d", &n);
      printf ("Case #%d: %lld\n", ++cs, r[n]);
    }
  return 0;
}
