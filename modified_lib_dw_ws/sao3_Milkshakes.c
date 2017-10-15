#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long A[100];
long long seq[1001];
long long len[1001];
long long ans;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
void
go ()
{
  int first_iteration;
  int n;
  int m;
  long long X;
  long long Y;
  long long Z;
  int i;
  int j;
  ans = 0;
  scanf ("%d%d%I64d%I64d%I64d", &n, &m, &X, &Y, &Z);
  for (i = 0; i < m; i++)
    scanf ("%I64d", &A[i]);
  for (i = 0; i < n; i++)
    {
      seq[i] = A[i % m];
      A[i % m] = ((X * A[i % m]) + (Y * (i + 1))) % Z;
      len[i] = 1;
      for (j = 0; j < i; j++)
	{
	  if (seq[j] < seq[i])
	    len[i] = (len[i] + len[j]) % 1000000007;
	}
      ans = (ans + len[i]) % 1000000007;
    }
}

int
main ()
{
  int first_iteration;
  int cs;
  int c;
  new_freopen ("B.in", "r", stdin);
  new_freopen ("B.out", "w", stdout);
  scanf ("%d", &cs);
  for (c = 1; c <= cs; c++)
    {
      go ();
      printf ("Case #%d: %I64d\n", c, ans);
    }
  return 0;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
