#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
  int first_iteration;
  int ti;
  int ii;
  int xx;
  scanf("%d %d %d\n", &ti, &ii, &xx);
  static char data[5005][20];
  static char string[27 * 20];
  int smax;
  for (smax = 0; smax < ii; smax++)
  {
    scanf("%s\n", data[smax]);
  }

  int n;
  int result;
  int no_cases;
  int n;
  for (n = 0; n < xx; n++)
  {
    scanf("%s\n", string);
    result = 0;
    for (smax = 0; smax < ii; smax++)
    {
      n = 0;
      for (no_cases = 0; no_cases <= ti; no_cases++)
      {
        if (no_cases == ti)
        {
          result++;
          break;
        }

        if (string[n] == '(')
        {
          while ((string[n] != ')') && (string[n] != data[smax][no_cases]))
            n++;

          if (string[n] == ')')
            break;

          while (string[n] != ')')
            n++;

          n++;
        }
        else
        {
          if (string[n] != data[smax][no_cases])
            break;

          n++;
        }

      }

    }

    printf("Case #%d: %d\n", n + 1, result);
  }

  return 0;
}


