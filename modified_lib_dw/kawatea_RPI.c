#include <stdio.h>
int new_puts(const char *str);
int main()
{
  int first_iteration;
  int t;
  int r;
  int c;
  int i;
  int j;
  int k;
  char s[50][51];
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    int f = 0;
    scanf("%d %d", &r, &c);
    for (j = 0; j < r; j++)
      scanf("%s", s[j]);

    for (j = 0; j < (r - 1); j++)
    {
      for (k = 0; k < (c - 1); k++)
      {
        if (s[j][k] == '#')
        {
          if (((s[j][k + 1] == '#') && (s[j + 1][k] == '#')) && (s[j + 1][k + 1] == '#'))
          {
            s[j][k] = (s[j + 1][k + 1] = '/');
            s[j][k + 1] = (s[j + 1][k] = '\\');
          }
          else
          {
            f = 1;
            j = r;
            break;
          }

        }

      }

    }

    if (f == 0)
    {
      for (j = 0; j < r; j++)
      {
        for (k = 0; k < c; k++)
        {
          if (s[j][k] == '#')
          {
            f = 1;
            j = r;
            break;
          }

        }

      }

    }

    printf("Case #%d:\n", i + 1);
    if (f == 1)
    {
      new_puts("Impossible");
    }
    else
    {
      for (j = 0; j < r; j++)
        printf("%s\n", s[j]);

    }

  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


