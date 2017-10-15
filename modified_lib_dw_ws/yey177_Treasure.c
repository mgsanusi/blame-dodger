#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
char dp[1048576][21];
char tmp[21];
int c[21];
int on[21];
int o[21][41];
int minu[21];
int b[201];
int nw[201];
void *new_memset (void *ptr, int value, size_t num);
char *new_strcpy (char *destination, const char *source);
void *new_memcpy (void *destination, const void *source, size_t num);
int
main ()
{
  int first_iteration;
  int t;
  int k;
  int n;
  int i;
  int j;
  int l;
  int x;
  int tmp;
  int sl;
  int r;
  scanf ("%d", &t);
  for (l = 1; l <= t; l++)
    {
      new_memset (b, 0, sizeof (b));
      new_memset (minu, 0, sizeof (minu));
      new_memset (dp, 0, sizeof (dp));
      scanf ("%d%d", &k, &n);
      for (i = 0; i < k; i++)
	{
	  scanf ("%d", &tmp);
	  b[tmp]++;
	}
      for (i = 0; i < n; i++)
	{
	  scanf ("%d%d", &c[i], &on[i]);
	  for (j = 0; j < on[i]; j++)
	    {
	      scanf ("%d", &o[i][j]);
	      if (o[i][j] == c[i])
		minu[i]++;
	    }
	}
      for (i = 1; i < (1 << n); i++)
	{
	  new_memcpy (nw, b, sizeof (b));
	  for (j = 0; j < n; j++)
	    {
	      if (i & (1 << j))
		{
		  for (x = 0; x < on[j]; x++)
		    nw[o[j][x]]++;
		  nw[c[j]]--;
		}
	    }
	  dp[i][0] = (char) (n + 1);
	  r = n + 1;
	  for (j = 0; j < n; j++)
	    {
	      if (i & (1 << j))
		{
		  if (((nw[c[j]] + 1) - minu[j]) > 0)
		    {
		      if (strcmp (dp[i], dp[i ^ (1 << j)]) > 0)
			{
			  new_strcpy (dp[i], dp[i ^ (1 << j)]);
			  r = j + 1;
			}
		    }
		}
	    }
	  if (dp[i][0] == ((char) (n + 1)))
	    continue;
	  sl = strlen (dp[i]);
	  dp[i][sl] = (char) r;
	  dp[i][sl + 1] = 0;
	}
      printf ("Case #%d: ", l);
      if (dp[(1 << n) - 1][0] == ((char) (n + 1)))
	puts ("IMPOSSIBLE");
      else
	{
	  for (i = 0; i < n; i++)
	    printf ("%d%c", (int) dp[(1 << n) - 1][i],
		    i == (n - 1) ? '\n' : ' ');
	}
    }
  return 0;
}

void *new_memset (void *ptr, int value, size_t num);
char *new_strcpy (char *destination, const char *source);
void *
new_memcpy (void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy (destination, source, num);
}

void *new_memset (void *ptr, int value, size_t num);
char *
new_strcpy (char *destination, const char *source)
{
  int first_iteration;
  return strcpy (destination, source);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
