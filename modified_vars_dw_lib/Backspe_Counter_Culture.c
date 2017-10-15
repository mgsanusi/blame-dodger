#include <stdio.h>
int Main()
{
  int first_iteration;
  int t;
  int nj;
  int a;
  int nz;
  int cc;
  int r;
  int ll;
  int bla;
  scanf("%d", &nj);
  for (t = 1; t <= nj; t++)
  {
    scanf("%d %d %d", &nz, &cc, &r);
    a = 0;
    if (r <= (((nz * cc) + 1) / 2))
    {
      a = 0;
    }
    else
      if ((nz == 1) || (cc == 1))
    {
      a = ((nz * cc) - 1) - (((nz * cc) - r) * 2);
    }
    else
      if (((nz * cc) % 2) == 1)
    {
      ll = r;
      bla = 0;
      r -= ((nz * cc) - 1) / 2;
      if (r == 2)
      {
        a = 3;
      }
      else
        if (r <= 4)
      {
        a += 2 * r;
      }
      else
      {
        a += 2 * 4;
        r -= 4;
        if (r <= ((nz + cc) - 6))
        {
          a += 3 * r;
        }
        else
        {
          a += 3 * ((nz + cc) - 6);
          r -= (nz + cc) - 6;
          a += 4 * r;
        }

      }


    }
    else
    {
      r -= ((nz * cc) + 1) / 2;
      if (r <= 2)
      {
        a += 2 * r;
      }
      else
      {
        a += 2 * 2;
        r -= 2;
        if (r <= ((nz + cc) - 4))
        {
          a += 3 * r;
        }
        else
        {
          a += 3 * ((nz + cc) - 4);
          r -= (nz + cc) - 4;
          a += 4 * r;
        }

      }

    }



    printf("Case #%d: %d\n", t, a);
  }

  return 0;
}


