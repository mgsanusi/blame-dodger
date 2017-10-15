#include <stdio.h>
int Main(int argc, char **argv)
{
  unsigned int numCase;
  unsigned int caseNo;
  scanf("%u", &numCase);
  for (caseNo = 0; caseNo != numCase; caseNo++)
  {
    unsigned int rts;
    unsigned int y;
    unsigned int ans;
    unsigned int t[3];
    unsigned int p[3];
    unsigned int inputS;
    unsigned int t;
    unsigned int area;
    unsigned int area1;
    char can = 1;
    scanf("%*u%u%u%u%u%u%u", &rts, &t[2], &y, &t[0], &ans, &t[1]);
    if ((((t[2] > ans) || (t[0] > rts)) || (t[1] > y)) || (((((!(!rts)) + (!(!y))) + (!(!ans))) > 1) && (((t[2] && (t[2] == ans)) || (t[0] && (t[0] == rts))) || (t[1] && (t[1] == y)))))
    {
      can = 0;
    }

    p[0] = rts - t[0];
    p[1] = y - t[1];
    p[2] = ans - t[2];
    if (((p[0] > (p[1] + p[2])) || (p[1] > (p[2] + p[0]))) || (p[2] > (p[0] + p[1])))
    {
      can = 0;
    }

    printf("Case #%u: ", caseNo + 1);
    if (!can)
    {
      puts("IMPOSSIBLE");
      continue;
    }

    if (!((p[0] || p[1]) || p[2]))
    {
      area1 = rts ? 0 : y ? 1 : ans ? 2 : !fputs("!!0", stderr);
      while (t[area1])
      {
        putchar("GVO"[area1]);
        putchar("RYB"[area1]);
        t[area1]--;
      }

      putchar('\n');
      continue;
    }

    inputS = (p[0] > p[1]) && (p[0] > p[2]) ? 0 : p[1] > p[2] ? 1 : 2;
    t = (inputS + 1) % 3;
    area = (inputS + 2) % 3;
    {
      putchar("RYB"[inputS]);
      p[inputS]--;
      while (t[inputS])
      {
        putchar("GVO"[inputS]);
        putchar("RYB"[inputS]);
        t[inputS]--;
      }

    }
    while (p[inputS])
    {
      area1 = p[t] > p[area] ? t : area;
      {
        putchar("RYB"[area1]);
        p[area1]--;
        while (t[area1])
        {
          putchar("GVO"[area1]);
          putchar("RYB"[area1]);
          t[area1]--;
        }

      }
      {
        putchar("RYB"[inputS]);
        p[inputS]--;
        while (t[inputS])
        {
          putchar("GVO"[inputS]);
          putchar("RYB"[inputS]);
          t[inputS]--;
        }

      }
    }

    if (p[t] < p[area])
    {
      area1 = t;
      t = area;
      area = area1;
    }

    if (p[t] > p[area])
    {
      {
        putchar("RYB"[t]);
        p[t]--;
        while (t[t])
        {
          putchar("GVO"[t]);
          putchar("RYB"[t]);
          t[t]--;
        }

      }
    }

    while (p[area])
    {
      {
        putchar("RYB"[area]);
        p[area]--;
        while (t[area])
        {
          putchar("GVO"[area]);
          putchar("RYB"[area]);
          t[area]--;
        }

      }
      {
        putchar("RYB"[t]);
        p[t]--;
        while (t[t])
        {
          putchar("GVO"[t]);
          putchar("RYB"[t]);
          t[t]--;
        }

      }
    }

    putchar('\n');
    if (((((p[0] || p[1]) || p[2]) || t[0]) || t[1]) || t[2])
    {
      fprintf(stderr, "Leftover unicorns -- case %u!", caseNo);
    }

  }

  return 0;
}


