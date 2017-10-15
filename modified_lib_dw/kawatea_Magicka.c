#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int i;
  int j;
  int k;
  int l;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    int c;
    int d;
    int n;
    int p = 0;
    char s[101];
    char s1[36][4];
    char s2[28][3];
    char ans[101];
    scanf("%d", &c);
    for (j = 0; j < c; j++)
      scanf("%s", s1[j]);

    scanf("%d", &d);
    for (j = 0; j < d; j++)
      scanf("%s", s2[j]);

    scanf("%d", &n);
    scanf("%s", s);
    for (j = 0; j < n; j++)
    {
      int f = 0;
      ans[p] = s[j];
      for (k = 0; k < c; k++)
      {
        if (s1[k][0] == ans[p])
        {
          if ((p > 0) && (s1[k][1] == ans[p - 1]))
          {
            ans[p - 1] = s1[k][2];
            f = 1;
            break;
          }

        }
        else
          if (s1[k][1] == ans[p])
        {
          if ((p > 0) && (s1[k][0] == ans[p - 1]))
          {
            ans[p - 1] = s1[k][2];
            f = 1;
            break;
          }

        }


      }

      if (f == 0)
      {
        for (k = 0; k < d; k++)
        {
          if (s2[k][0] == ans[p])
          {
            for (l = 0; l < p; l++)
            {
              if (s2[k][1] == ans[l])
              {
                p = 0;
                k = d;
                f = 1;
                break;
              }

            }

          }
          else
            if (s2[k][1] == ans[p])
          {
            for (l = 0; l < p; l++)
            {
              if (s2[k][0] == ans[l])
              {
                p = 0;
                k = d;
                f = 1;
                break;
              }

            }

          }


        }

      }

      if (f == 0)
        p++;

    }

    printf("Case #%d: [", i + 1);
    for (j = 0; j < p; j++)
    {
      printf("%c", ans[j]);
      if (j < (p - 1))
        printf(", ");

    }

    printf("]\n");
  }

  return 0;
}


