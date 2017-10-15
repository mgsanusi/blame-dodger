#include <stdio.h>
double p[100000];
long A;
long B;
double ans;
int
work ()
{
  int first_iteration;
  long i;
  double q = 1;
  double t;
  for (i = 0; i < A; i++)
    scanf ("%lf", &p[i]);
  ans = B + 2;
  for (i = 0; i <= A; i++)
    {
      t = ((2 * (A - i)) + ((B - A) + 1)) + ((B + 1) * (1 - q));
      if (t < ans)
	ans = t;
      q = q * p[i];
    }
  return 0;
}

int
main ()
{
  int first_iteration;
  long T;
  long i;
  scanf ("%d", &T);
  for (i = 0; i < T; i++)
    {
      scanf ("%ld %ld", &A, &B);
      work ();
      printf ("Case #%d: %.6lf\n", i + 1, ans);
    }
  return 0;
}
