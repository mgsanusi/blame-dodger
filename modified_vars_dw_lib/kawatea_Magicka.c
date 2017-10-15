#include <stdio.h>
int Main()
{
  int first_iteration;
  int source;
  int tn;
  int j;
  int k;
  int num;
  scanf("%d", &source);
  for (tn = 0; tn < source; tn++)
  {
    int c;
    int d;
    int xdrs;
    int a = 0;
    char matrix[101];
    char ib[36][4];
    char a[28][3];
    char res[101];
    scanf("%d", &c);
    for (j = 0; j < c; j++)
      scanf("%s", ib[j]);

    scanf("%d", &d);
    for (j = 0; j < d; j++)
      scanf("%s", a[j]);

    scanf("%d", &xdrs);
    scanf("%s", matrix);
    for (j = 0; j < xdrs; j++)
    {
      int f = 0;
      res[a] = matrix[j];
      for (k = 0; k < c; k++)
      {
        if (ib[k][0] == res[a])
        {
          if ((a > 0) && (ib[k][1] == res[a - 1]))
          {
            res[a - 1] = ib[k][2];
            f = 1;
            break;
          }

        }
        else
          if (ib[k][1] == res[a])
        {
          if ((a > 0) && (ib[k][0] == res[a - 1]))
          {
            res[a - 1] = ib[k][2];
            f = 1;
            break;
          }

        }


      }

      if (f == 0)
      {
        for (k = 0; k < d; k++)
        {
          if (a[k][0] == res[a])
          {
            for (num = 0; num < a; num++)
            {
              if (a[k][1] == res[num])
              {
                a = 0;
                k = d;
                f = 1;
                break;
              }

            }

          }
          else
            if (a[k][1] == res[a])
          {
            for (num = 0; num < a; num++)
            {
              if (a[k][0] == res[num])
              {
                a = 0;
                k = d;
                f = 1;
                break;
              }

            }

          }


        }

      }

      if (f == 0)
        a++;

    }

    printf("Case #%d: [", tn + 1);
    for (j = 0; j < a; j++)
    {
      printf("%c", res[j]);
      if (j < (a - 1))
        printf(", ");

    }

    printf("]\n");
  }

  return 0;
}


