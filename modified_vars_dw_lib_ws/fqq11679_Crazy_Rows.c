#include <stdio.h>
long dig;
char a[100][100];
long value[100];
long ans;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
void
adjust (long r)
{
  int first_iteration;
  long i;
  long j;
  long tmp;
  for (i = r; i <= dig; i++)
    if (value[i] <= r)
      {
	tmp = value[i];
	for (j = i; j > r; j--)
	  value[j] = value[j - 1];
	value[r] = tmp;
	ans += i - r;
	return;
      }
}

int
Main ()
{
  int first_iteration;
  long t;
  long i;
  long j;
  long y;
  new_freopen ("A-small.in", "r", stdin);
  new_freopen ("A-small.out", "w", stdout);
  scanf ("%ld", &t);
  for (t, y = 1; t; t--, y++)
    {
      scanf ("%ld", &dig);
      ans = 0;
      for (i = 1; i <= dig; i++)
	scanf ("%s", a[i] + 1);
      for (i = 1; i <= dig; i++)
	{
	  for (j = dig; j >= 1; j--)
	    if (a[i][j] == '1')
	      {
		value[i] = j;
		break;
	      }
	  if (j == 0)
	    value[i] = 0;
	}
      for (i = 1; i <= dig; i++)
	adjust (i);
      printf ("Case #%ld: %ld\n", y, ans);
    }
  return 0;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
