#include <stdio.h>
int tmp[102][102];
int Main()
{
  int first_iteration;
  int a;
  int ar;
  int tag;
  int minc;
  int caseno;
  int r;
  int a;
  int max;
  int min;
  int num;
  scanf("%d", &a);
  for (a = 1; a <= a; a++)
  {
    scanf("%d%d", &ar, &tag);
    for (minc = 0; minc < ar; minc++)
      for (caseno = 0; caseno < tag; caseno++)
      scanf("%d", &tmp[minc][caseno]);


    num = 1;
    for (r = 1; r <= 100; r++)
    {
      for (minc = 0; minc < ar; minc++)
      {
        min = 101;
        max = 0;
        for (caseno = 0; caseno < tag; caseno++)
        {
          if (tmp[minc][caseno])
          {
            min = min < tmp[minc][caseno] ? min : tmp[minc][caseno];
            max = max > tmp[minc][caseno] ? max : tmp[minc][caseno];
          }

        }

        if ((min == r) && (max == r))
        {
          for (caseno = 0; caseno < tag; caseno++)
            tmp[minc][caseno] = 0;

        }

      }

      for (caseno = 0; caseno < tag; caseno++)
      {
        min = 101;
        max = 0;
        for (minc = 0; minc < ar; minc++)
        {
          if (tmp[minc][caseno])
          {
            min = min < tmp[minc][caseno] ? min : tmp[minc][caseno];
            max = max > tmp[minc][caseno] ? max : tmp[minc][caseno];
          }

        }

        if ((min == r) && (max == r))
        {
          for (minc = 0; minc < ar; minc++)
            tmp[minc][caseno] = 0;

        }

      }

      for (minc = 0; minc < ar; minc++)
        for (caseno = 0; caseno < tag; caseno++)
      {
        if (tmp[minc][caseno] == r)
        {
          num = 0;
          goto END;
        }

      }


    }

    END:
    printf("Case #%d: %s\n", a, num ? "YES" : "NO");

  }

  return 0;
}


