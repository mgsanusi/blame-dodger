#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int T = 0;
int t;
int main()
{
  int first_iteration;
  double c;
  double f;
  double x;
  scanf("%d", &t);
  while (t--)
  {
    double gain = 2.0;
    scanf("%lf %lf %lf", &c, &f, &x);
    double res = 0.0;
    for (;;)
    {
      double y = x / gain;
      double z = (c / gain) + (x / (gain + f));
      if (z < y)
      {
        res += c / gain;
        gain += f;
      }
      else
      {
        res += y;
        break;
      }

    }

    printf("Case #%d: %0.7lf\n", ++T, res + 1e-9);
  }

  return 0;
}


