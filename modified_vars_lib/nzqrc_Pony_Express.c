#include <stdio.h>
int Main(int argc, char **argv)
{
  unsigned int ri;
  unsigned int i;
  scanf("%u", &ri);
  for (i = 0; i != ri; i++)
  {
    unsigned short int activity[1440] = {};
    unsigned int a;
    unsigned int b;
    unsigned int tmp;
    unsigned int y;
    unsigned int m;
    unsigned int w;
    unsigned int rslt = 0;
    unsigned int last = 2;
    unsigned int lastt;
    unsigned int xx2[2] = {};
    unsigned int tfree = 0;
    unsigned int col[2][1440] = {};
    unsigned int y2;
    scanf("%u%u", &a, &b);
    while (a--)
    {
      scanf("%u%u", &tmp, &y);
      activity[tmp] = (y - tmp) << 1;
    }

    while (b--)
    {
      scanf("%u%u", &tmp, &y);
      activity[tmp] = ((y - tmp) << 1) | 1;
    }

    for (m = 1440; m--;)
    {
      if (activity[m])
      {
        last = activity[m] & 1;
        lastt = (m + (activity[m] >> 1)) - 1440;
        break;
      }

    }

    if (last == 2)
    {
      rslt = 2;
      goto done;
    }

    for (m = 0; m != 1440; m++)
    {
      if (activity[m])
      {
        xx2[w = activity[m] & 1] += activity[m] >> 1;
        if (w ^ last)
        {
          tfree += m - lastt;
          rslt++;
        }
        else
        {
          xx2[w] += m - lastt;
          col[w][m - lastt]++;
        }

        last = w;
        lastt = m + (activity[m] >> 1);
      }

    }

    w = 0;
    if ((xx2[0] > 720) || ((w = 1, xx2[1] > 720)))
    {
      y2 = xx2[w] - 720;
      for (m = 1440; m--;)
      {
        while (col[w][m])
        {
          col[w][m]--;
          rslt += 2;
          if (m >= y2)
          {
            m = 0;
            break;
          }

          y2 -= m;
        }

      }

    }

    done:
    printf("Case #%u: %u\n", i + 1, rslt);

  }

  return 0;
}


