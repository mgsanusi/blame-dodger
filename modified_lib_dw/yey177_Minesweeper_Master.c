#include <stdio.h>
int new_putchar(int character);
int new_puts(const char *str);
int main()
{
  int first_iteration;
  int t;
  int cas;
  int r;
  int c;
  int m;
  int i;
  int j;
  int k;
  int l;
  int low;
  int high;
  scanf("%d", &t);
  for (cas = 1; cas <= t; cas++)
  {
    scanf("%d%d%d", &r, &c, &m);
    printf("Case #%d:\n", cas);
    if (r == 1)
    {
      for (i = 0; i < m; i++)
        new_putchar('*');

      for (i = m; i < (c - 1); i++)
        new_putchar('.');

      new_puts("c");
      continue;
    }
    else
      if (c == 1)
    {
      for (i = 0; i < m; i++)
        new_puts("*");

      for (i = m; i < (r - 1); i++)
        new_puts(".");

      new_puts("c");
      continue;
    }
    else
      if (m == ((r * c) - 1))
    {
      for (i = 1; i <= r; i++)
      {
        for (j = 1; j <= c; j++)
        {
          new_putchar((i == r) && (j == c) ? 'c' : '*');
        }

        new_puts("");
      }

      continue;
    }



    for (i = 0; i <= (r - 2); i++)
    {
      for (j = 0; j <= (c - 2); j++)
      {
        low = (r * c) - ((r - i) * (c - j));
        high = low + (((r - 2) - i) * ((c - 2) - j));
        if ((low <= m) && (m <= high))
        {
          m -= low;
          for (k = 1; k <= i; k++)
          {
            for (l = 1; l <= c; l++)
              new_putchar('*');

            new_puts("");
          }

          for (k = i + 1; k <= (r - 2); k++)
          {
            for (l = 1; l <= j; l++)
              new_putchar('*');

            for (l = j + 1; l <= (c - 2); l++)
            {
              new_putchar(m > 0 ? '*' : '.');
              m--;
            }

            new_puts("..");
          }

          for (k = r - 1; k <= r; k++)
          {
            for (l = 1; l <= j; l++)
              new_putchar('*');

            for (l = j + 1; l <= c; l++)
              new_putchar((k == r) && (l == c) ? 'c' : '.');

            new_puts("");
          }

          goto END;
        }

      }

    }

    new_puts("Impossible");
    END:
    continue;

  }

  return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}

int new_putchar(int character)
{
  int first_iteration;
  return putchar(character);
}


