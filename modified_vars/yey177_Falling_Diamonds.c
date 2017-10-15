#include <stdio.h>
#include <string.h>
double count[1000][2000];
int Main()
{
  int b;
  int n;
  int x;
  int y;
  int k;
  int a;
  int em;
  int exy;
  int rsc;
  double nb;
  scanf("%d", &b);
  for (k = 1; k <= b; k++)
  {
    scanf("%d%d%d", &n, &x, &y);
    if (x < 0)
      x = -x;

    a = (x + y) / 2;
    exy = 0;
    while ((n - ((4 * exy) + 1)) >= 0)
    {
      n -= (4 * exy) + 1;
      exy++;
    }

    em = exy;
    if (a < em)
    {
      nb = 1.0;
      goto END;
    }

    if (a > em)
    {
      nb = 0.0;
      goto END;
    }

    if (x == 0)
    {
      nb = 0.0;
      goto END;
    }

    memset(count, 0, sizeof(count));
    count[0][0] = 1.0;
    for (exy = 0; exy < n; exy++)
    {
      for (rsc = 0 > (exy - (em * 2)) ? 0 : exy - (em * 2); rsc <= ((em * 2) < exy ? em * 2 : exy); rsc++)
      {
        if ((exy - rsc) >= (em * 2))
          count[exy + 1][rsc + 1] += count[exy][rsc];
        else
          if (rsc == (em * 2))
          count[exy + 1][rsc] += count[exy][rsc];
        else
        {
          count[exy + 1][rsc] += count[exy][rsc] * 0.5;
          count[exy + 1][rsc + 1] += count[exy][rsc] * 0.5;
        }


      }

    }

    nb = 0.0;
    for (rsc = 0; (n - rsc) > y; rsc++)
    {
      nb += count[n][rsc];
    }

    END:
    printf("Case #%d: %.8lf\n", k, nb);

  }

  return 0;
}


