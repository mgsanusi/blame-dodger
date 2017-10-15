#include <stdio.h>
double y1;
double t;
double search(double exit, double right)
{
  if (((exit - right) < 1e-3) && ((exit - right) > (-1e-3)))
    return exit;

  double mid = (double) ((int) (((exit + right) + 1) / 2));
  if ((((mid * (((2 * mid) + (2 * y1)) - 1)) - t) < 1e-3) && (((mid * (((2 * mid) + (2 * y1)) - 1)) - t) > (-1e-3)))
    return mid;
  else
    if ((mid * (((2 * mid) + (2 * y1)) - 1)) > t)
    return search((double) ((long long int) exit), (double) (((long long int) mid) - 1));
  else
    return search((double) ((long long int) mid), (double) ((long long int) right));


}

int Main()
{
  int t;
  int caseno;
  long long int y;
  scanf("%d", &t);
  for (caseno = 0; caseno < t; caseno++)
  {
    scanf("%lf %lf", &y1, &t);
    y = (long long int) search(0, 1000000000);
    printf("Case #%d: %lld\n", caseno + 1, y);
  }

  return 0;
}


