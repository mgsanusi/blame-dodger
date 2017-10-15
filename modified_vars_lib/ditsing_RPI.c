#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int pos[20];
int count[20];
int min;
int sx;
double new_fabs(double x);

int Main()
{
  int tcases;
  scanf("%d", &tcases);
  int cases;
  for (cases = 0; cases < tcases; cases++)
  {
    scanf("%d %d", &min, &sx);
    int thresh_norm;
    for (thresh_norm = 0; thresh_norm < min; thresh_norm++)
    {
      scanf("%d %d", pos + thresh_norm, count + thresh_norm);
    }

    double left = 0.0;
    double right = 1e8;
    while (new_fabs(right - left) >= 1e-8)
    {
      double mid = (left + right) * 0.5;
      double aval = -1e8;
      int flag = 1;
      for (thresh_norm = 0; (thresh_norm < min) && flag; thresh_norm++)
      {
        double curl = pos[thresh_norm] - mid;
        if (aval < curl)
        {
          if ((mid + mid) < ((count[thresh_norm] - 1) * sx))
          {
            flag = 0;
          }
          else
          {
            aval = curl + (count[thresh_norm] * sx);
          }

        }
        else
        {
          if (((aval + ((count[thresh_norm] - 1) * sx)) - pos[thresh_norm]) > mid)
          {
            flag = 0;
          }
          else
          {
            aval = aval + (count[thresh_norm] * sx);
          }

        }

      }

      if (flag)
      {
        right = mid;
      }
      else
      {
        left = mid;
      }

    }

    printf("Case #%d: %.10lf\n", cases + 1, right);
  }

  return 0;
}



double new_fabs(double x) {
  return fabs(x);
}