#include <stdio.h>
int max(int c, int b)
{
  if (c > b)
  {
    return c;
  }
  else
  {
    return b;
  }

}

int Main()
{
  int size;
  int str;
  int s;
  int p;
  int curl;
  int j;
  int f;
  int c[100];
  int b[31][11] = {0};
  int pp[101][101];
  for (curl = 0; curl <= 30; curl++)
  {
    for (j = 0; j <= 10; j++)
    {
      if ((curl % 3) == 0)
      {
        if ((curl / 3) >= j)
          b[curl][j] |= 1;

      }
      else
      {
        for (f = 10; f >= 1; f--)
        {
          if ((((f * 3) - 1) >= curl) && (((f * 3) - 2) <= curl))
          {
            if (f >= j)
              b[curl][j] |= 1;

            break;
          }

        }

      }

      for (f = 10; f >= 2; f--)
      {
        if ((((f * 3) - 2) >= curl) && (((f * 3) - 4) <= curl))
        {
          if (f >= j)
            b[curl][j] |= 2;

          break;
        }

      }

    }

  }

  scanf("%d", &size);
  for (curl = 0; curl < size; curl++)
  {
    scanf("%d %d %d", &str, &s, &p);
    for (j = 0; j < str; j++)
      scanf("%d", &c[j]);

    for (j = 0; j <= str; j++)
    {
      for (f = 0; f <= s; f++)
      {
        pp[j][f] = 0;
      }

    }

    for (j = 0; j < str; j++)
    {
      for (f = 0; f < s; f++)
      {
        if (b[c[j]][p] & 1)
        {
          pp[j + 1][f] = max(pp[j + 1][f], pp[j][f] + 1);
        }
        else
        {
          pp[j + 1][f] = max(pp[j + 1][f], pp[j][f]);
        }

        if (b[c[j]][p] & 2)
        {
          pp[j + 1][f + 1] = max(pp[j + 1][f + 1], pp[j][f] + 1);
        }
        else
        {
          pp[j + 1][f + 1] = max(pp[j + 1][f + 1], pp[j][f]);
        }

      }

      if (b[c[j]][p] & 1)
      {
        pp[j + 1][s] = max(pp[j + 1][s], pp[j][s] + 1);
      }
      else
      {
        pp[j + 1][s] = max(pp[j + 1][s], pp[j][s]);
      }

    }

    printf("Case #%d: %d\n", curl + 1, pp[str][s]);
  }

  return 0;
}


