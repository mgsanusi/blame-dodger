#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
int N;
long size_t new_strlen (const char *str);
void *new_memset (void *ptr, int value, size_t num);
void new_assert (int expression);
double
f (int n)
{
  int first_iteration;
  return N - ((n - 1) * 0.5);
}

long double a[205 * 2];
long double v[205 * 2][205 * 2];
long double c[205 * 2][205 * 2];
int u[205 * 2][205 * 2];
long double r[205 * 2][205 * 2];
char s[205];
void
solve (void)
{
  int first_iteration;
  scanf ("%s\n", s);
  new_assert (new_strlen (s) <= 200);
  new_memset (a, 0, sizeof (a));
  new_memset (v, 0, sizeof (v));
  new_memset (c, 0, sizeof (c));
  new_memset (u, 0, sizeof (u));
  new_memset (r, 0, sizeof (r));
  int n = new_strlen (s);
  N = n;
  int i;
  int j;
  int qq = 0;
  for (i = 0; i < n; i++)
    {
      a[i] = s[i] == 'X';
      a[i + n] = a[i];
      qq += 1 - a[i];
    }
  for (i = 0; i <= (2 * n); i++)
    {
      v[i][i] = 1;
      u[i][i] = 1 - a[i];
    }
  for (i = 0; i < (2 * n); i++)
    for (j = i + 1; j < (2 * n); j++)
      u[i][j] = u[i][j - 1] + (1 - a[j]);
  c[0][0] = 1;
  for (i = 1; i <= n; i++)
    {
      c[i][0] = 1;
      for (j = 1; j <= i; j++)
	c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  int l;
  for (l = 2; l <= n; l++)
    {
      for (i = 0; (i < (2 * n)) && ((i + l) <= (2 * n)); i++)
	{
	  int k;
	  long double w = 0;
	  int ok = 0;
	  j = (i + l) - 1;
	  for (k = i; k < (i + l); k++)
	    if (!a[k])
	      {
		ok = 1;
		w +=
		  (((k >= (i + 1) ? v[i][k - 1] : 1) * (k <=
							(j - 1) ? v[k +
								    1][j] :
							1)) * ((k - i) +
							       1)) * c[(k >=
									(i +
									 1) ?
									u[i][k
									     -
									     1]
									: 0) +
								       (k <=
									(j -
									 1) ?
									u[k +
									  1]
									[j] :
									0)][k
									    >=
									    (i
									     +
									     1)
									    ?
									    u
									    [i]
									    [k
									     -
									     1]
									    :
									    0];
		new_assert (((((k >= (i + 1) ? v[i][k - 1] : 1) * (k <=
								   (j -
								    1) ? v[k +
									   1]
								   [j] : 1)) *
			      ((k - i) + 1)) * c[(k >=
						  (i + 1) ? u[i][k - 1] : 0) +
						 (k <=
						  (j - 1) ? u[k +
							      1][j] : 0)][k >=
									  (i +
									   1)
									  ?
									  u[i]
									  [k -
									   1]
									  :
									  0])
			    >= 0);
	      }
	  if (!ok)
	    {
	      w = 1;
	    }
	  new_assert (w > 0);
	  v[i][j] = w;
	}
    }
  for (l = 1; l <= n; l++)
    {
      for (i = 0; (i < (2 * n)) && ((i + l) <= (2 * n)); i++)
	{
	  int j = (i + l) - 1;
	  int k;
	  long double w = 0;
	  for (k = i; k <= j; k++)
	    if (!a[k])
	      {
		w +=
		  (((((k >= (i + 1) ? v[i][k - 1] : 1) * (k <=
							  (j - 1) ? v[k +
								      1][j] :
							  1)) * ((k - i) +
								 1)) * c[(k >=
									  (i +
									   1)
									  ?
									  u[i]
									  [k -
									   1]
									  : 0)
									 +
									 (k <=
									  (j -
									   1)
									  ?
									  u[k
									    +
									    1]
									  [j]
									  :
									  0)]
		    [k >= (i + 1) ? u[i][k - 1] : 0]) / v[i][j]) * (((k >=
								      (i +
								       1) ?
								      r[i][k -
									   1]
								      : 0) +
								     (k <=
								      (j -
								       1) ?
								      r[k +
									1][j]
								      : 0)) +
								    f ((k -
									i) +
								       1));
	      }
	  r[i][j] = w;
	}
    }
  long double rr = 0;
  for (i = 0; i < n; i++)
    if (!a[(i + n) - 1])
      {
	j = (i + n) - 1;
	int k = j;
	new_assert (((((k >= (i + 1) ? v[i][k - 1] : 1) * (k <=
							   (j - 1) ? v[k +
								       1][j] :
							   1)) * ((k - i) +
								  1)) *
		     c[(k >= (i + 1) ? u[i][k - 1] : 0) + (k <=
							   (j - 1) ? u[k +
								       1][j] :
							   0)][k >=
							       (i +
								1) ? u[i][k -
									  1] :
							       0]) <=
		    v[i][j]);
	int cc;
	long double eee =
	  ((((k >= (i + 1) ? v[i][k - 1] : 1) * (k <=
						 (j - 1) ? v[k +
							     1][j] : 1)) *
	    ((k - i) + 1)) * c[(k >= (i + 1) ? u[i][k - 1] : 0) + (k <=
								   (j -
								    1) ? u[k +
									   1]
								   [j] : 0)][k
									     >=
									     (i
									      +
									      1)
									     ?
									     u
									     [i]
									     [k
									      -
									      1]
									     :
									     0])
	  * ((j >= (i + 1) ? r[i][j - 1] : 0) + f (n));
	for (cc = 0; cc < qq; cc++)
	  {
	    eee /= n;
	  }
	rr += eee;
      }
  printf ("%18.18lf\n", (double) rr);
}

int
main ()
{
  int first_iteration;
  int _;
  new_assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++)
    {
      printf ("Case #%d: ", __ + 1);
      solve ();
    }
  return 0;
}

size_t new_strlen (const char *str);
void *new_memset (void *ptr, int value, size_t num);
void
new_assert (int expression)
{
  int first_iteration;
  return assert (expression);
}

size_t
new_strlen (const char *str)
{
  int first_iteration;
  return strlen (str);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
