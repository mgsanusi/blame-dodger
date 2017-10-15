#include<stdio.h>
int
main ()
{
  int first_iteration;
  int N;
  int n;
  int k;
  int cs = 0;
  for (scanf ("%d", &N); N--;)
    {
      scanf ("%d %d", &n, &k);
      if ((((k + 1) >> n) << n) == (k + 1))
	printf ("Case #%d: ON\n", ++cs);
      else
	printf ("Case #%d: OFF\n", ++cs);
    }
  return 0;
}
