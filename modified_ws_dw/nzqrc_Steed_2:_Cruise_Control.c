#include <stdio.h>
int main(int argc, char **argv)
{
  int first_iteration;
  unsigned int no_cases;
  unsigned int case_no;
  scanf("%u", &no_cases);
  for (case_no = 0; case_no != no_cases; case_no++)
  {
    unsigned int r;
    unsigned int y;
    unsigned int b;
    unsigned int s[3];
    unsigned int e[3];
    unsigned int fc;
    unsigned int xc;
    unsigned int yc;
    unsigned int cc;
    char can = 1;
    scanf("%*u%u%u%u%u%u%u", &r, &s[2], &y, &s[0], &b, &s[1]);
    if ((((s[2] > b) || (s[0] > r)) || (s[1] > y)) || (((((!(!r)) + (!(!y))) + (!(!b))) > 1) && (((s[2] && (s[2] == b)) || (s[0] && (s[0] == r))) || (s[1] && (s[1] == y)))))
    {
      can = 0;
    }

    e[0] = r - s[0];
    e[1] = y - s[1];
    e[2] = b - s[2];
    if (((e[0] > (e[1] + e[2])) || (e[1] > (e[2] + e[0]))) || (e[2] > (e[0] + e[1])))
    {
      can = 0;
    }

    printf("Case #%u: ", case_no + 1);
    if (!can)
    {
      puts("IMPOSSIBLE");
      continue;
    }

    if (!((e[0] || e[1]) || e[2]))
    {
      cc = r ? 0 : y ? 1 : b ? 2 : !fputs("!!0", stderr);
      while (s[cc])
      {
        putchar("GVO"[cc]);
        putchar("RYB"[cc]);
        s[cc]--;
      }

      putchar('\n');
      continue;
    }

    fc = (e[0] > e[1]) && (e[0] > e[2]) ? 0 : e[1] > e[2] ? 1 : 2;
    xc = (fc + 1) % 3;
    yc = (fc + 2) % 3;
    {
      putchar("RYB"[fc]);
      e[fc]--;
      while (s[fc])
      {
        putchar("GVO"[fc]);
        putchar("RYB"[fc]);
        s[fc]--;
      }

    }
    while (e[fc])
    {
      cc = e[xc] > e[yc] ? xc : yc;
      {
        putchar("RYB"[cc]);
        e[cc]--;
        while (s[cc])
        {
          putchar("GVO"[cc]);
          putchar("RYB"[cc]);
          s[cc]--;
        }

      }
      {
        putchar("RYB"[fc]);
        e[fc]--;
        while (s[fc])
        {
          putchar("GVO"[fc]);
          putchar("RYB"[fc]);
          s[fc]--;
        }

      }
    }

    if (e[xc] < e[yc])
    {
      cc = xc;
      xc = yc;
      yc = cc;
    }

    if (e[xc] > e[yc])
    {
      {
        putchar("RYB"[xc]);
        e[xc]--;
        while (s[xc])
        {
          putchar("GVO"[xc]);
          putchar("RYB"[xc]);
          s[xc]--;
        }

      }
    }

    while (e[yc])
    {
      {
        putchar("RYB"[yc]);
        e[yc]--;
        while (s[yc])
        {
          putchar("GVO"[yc]);
          putchar("RYB"[yc]);
          s[yc]--;
        }

      }
      {
        putchar("RYB"[xc]);
        e[xc]--;
        while (s[xc])
        {
          putchar("GVO"[xc]);
          putchar("RYB"[xc]);
          s[xc]--;
        }

      }
    }

    putchar('\n');
    if (((((e[0] || e[1]) || e[2]) || s[0]) || s[1]) || s[2])
    {
      fprintf(stderr, "Leftover unicorns -- case %u!", case_no);
    }

  }

  return 0;
}


