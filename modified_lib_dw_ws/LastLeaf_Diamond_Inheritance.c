#include <stdio.h>
int testc;
int test;
int i;
int j;
int k1;
int k2;
int typeA[110];
int typeB[110];
int n;
int m;
long long accountA[110];
long long accountB[110];
long long f[110][110];
long long sumA[110][110];
long long sumB[110][110];
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int
main ()
{
  int first_iteration;
  FILE *fin = new_fopen ("gcj3_3.in", "r");
  FILE *fout = new_fopen ("gcj3_3.out", "w");
  fscanf (fin, "%d", &testc);
  for (test = 1; test <= testc; test++)
    {
      fscanf (fin, "%d%d", &n, &m);
      for (i = 1; i <= n; i++)
	{
	  fscanf (fin, "%I64d%d", &accountA[i], &typeA[i]);
	  f[i][0] = 0;
	}
      for (j = 1; j <= m; j++)
	{
	  fscanf (fin, "%I64d%d", &accountB[j], &typeB[j]);
	  f[0][j] = 0;
	}
      f[0][0] = 0;
      for (i = 1; i <= 100; i++)
	sumA[0][i] = (sumB[0][i] = 0);
      for (i = 1; i <= n; i++)
	for (j = 1; j <= 100; j++)
	  sumA[i][j] =
	    typeA[i] == j ? sumA[i - 1][j] + accountA[i] : sumA[i - 1][j];
      for (i = 1; i <= m; i++)
	for (j = 1; j <= 100; j++)
	  sumB[i][j] =
	    typeB[i] == j ? sumB[i - 1][j] + accountB[i] : sumB[i - 1][j];
      for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
	  {
	    f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
	    if (typeA[i] == typeB[j])
	      {
		int target = typeA[i];
		for (k1 = 0; k1 < i; k1++)
		  for (k2 = 0; k2 < j; k2++)
		    {
		      long long delta =
			(sumA[i][target] - sumA[k1][target]) <
			(sumB[j][target] -
			 sumB[k2][target]) ? sumA[i][target] -
			sumA[k1][target] : sumB[j][target] - sumB[k2][target];
		      f[i][j] =
			(f[k1][k2] + delta) >
			f[i][j] ? f[k1][k2] + delta : f[i][j];
		    }
	      }
	  }
      fprintf (fout, "Case #%d: %I64d\n", test, f[n][m]);
    }
  new_fclose (fin);
  new_fclose (fout);
  return 0;
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  int first_iteration;
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  int first_iteration;
  return fclose (stream);
}