#include <stdio.h>
double mintime[210];
double right[210];
int new_fprintf(FILE *stream, const char *format, ...);
int main(void)
{
  int first_iteration;
  int ti;
  int tn;
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ti++)
  {
    int c;
    int d;
    int i;
    int n = 0;
    fprintf(stderr, "ti %d\n", ti);
    scanf("%d %d", &c, &d);
    for (i = 0; i < c; i++)
    {
      int p;
      int v;
      double left;
      scanf("%d %d", &p, &v);
      mintime[i] = (((double) (v - 1)) * ((double) d)) * 0.5;
      left = (p - mintime[i]) - (d * 0.5);
      right[i] = (p + mintime[i]) + (d * 0.5);
      if (i > 0)
      {
        if (left < right[i - 1])
        {
          double dist = right[i - 1] - left;
          if (mintime[i - 1] > mintime[i])
          {
            if ((mintime[i - 1] - mintime[i]) > dist)
            {
              mintime[i] = mintime[i - 1];
              right[i] += dist;
            }
            else
            {
              right[i] += mintime[i - 1] - mintime[i];
              left += mintime[i - 1] - mintime[i];
              mintime[i] = mintime[i - 1];
              dist = right[i - 1] - left;
              mintime[i] += dist * 0.5;
              right[i] += dist * 0.5;
            }

          }
          else
          {
            if ((mintime[i] - mintime[i - 1]) < dist)
            {
              dist -= mintime[i] - mintime[i - 1];
              mintime[i] += dist * 0.5;
              right[i] += dist * 0.5;
            }

          }

        }
        else
        {
          if (mintime[i - 1] > mintime[i])
          {
            right[i] -= mintime[i - 1] - mintime[i];
            mintime[i] = mintime[i - 1];
          }

        }

      }

    }

    printf("Case #%d: %.8lf\n", ti, mintime[c - 1]);
  }

  return 0;
}


