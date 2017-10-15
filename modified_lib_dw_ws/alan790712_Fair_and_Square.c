#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long int a;
long long int b;
char isp[10000001] = { 0 };

char str[1234];
size_t new_strlen (const char *str);
double new_sqrt (double x);
int
main ()
{
  int first_iteration;
  int t;
  int T;
  int i;
  int j;
  int k;
  long long int li;
  int ans = 0;
  for (i = 1; i < 10000001; ++i)
    {
      sprintf (str, "%d", i);
      for (j = 0, k = new_strlen (str) - 1; (j < k) && (str[j] == str[k]);
	   ++j, --k)
	;
      if (j >= k)
	isp[i] = 1;
    }
  scanf ("%d", &T);
  for (t = 1; t <= T; ++t)
    {
      ans = 0;
      scanf ("%lld %lld", &a, &b);
      for (li = (long long int) new_sqrt (a); (li * li) <= b; ++li)
	{
	  if ((li * li) < a)
	    continue;
	  if (isp[li])
	    {
	      sprintf (str, "%lld", li * li);
	      for (j = 0, k = new_strlen (str) - 1;
		   (j < k) && (str[j] == str[k]); ++j, --k)
		;
	      if (j >= k)
		{
		  ++ans;
		}
	    }
	}
      printf ("Case #%d: ", t);
      printf ("%d\n", ans);
    }
  return 0;
}

size_t new_strlen (const char *str);
double
new_sqrt (double x)
{
  int first_iteration;
  return sqrt (x);
}

size_t
new_strlen (const char *str)
{
  int first_iteration;
  return strlen (str);
}
