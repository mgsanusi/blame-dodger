#include <stdio.h>
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int s[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int Main()
{
  char buf[100][100];
  int y;
  int tt;
  int n;
  int by;
  int tot;
  int k;
  int a;
  int str;
  int r;
  int l;
  scanf("%d", &y);
  for (a = 0; a < y; a++)
  {
    scanf("%d%d", &tt, &n);
    gets(buf[0]);
    for (by = 0; by < tt; by++)
    {
      gets(buf[by]);
    }

    r = (l = 0);
    for (by = 0; by < tt; by++)
    {
      k = 0;
      for (tot = tt - 1; tot >= 0; tot--)
      {
        if (buf[by][tot] == '.')
        {
          k++;
        }
        else
        {
          buf[by][tot + k] = buf[by][tot];
          if (k)
            buf[by][tot] = '.';

        }

      }

    }

    for (by = 0; by < tt; by++)
    {
      for (tot = 0; tot < tt; tot++)
      {
        if (buf[by][tot] != '.')
        {
          for (str = 0; str < 8; str++)
          {
            int temp = 1;
            for (k = 1; k < n; k++)
            {
              int tc = by + (dx[str] * k);
              int sq = tot + (s[str] * k);
              if (((((tc < 0) || (tc >= tt)) || (sq < 0)) || (sq >= tt)) || (buf[tc][sq] != buf[by][tot]))
              {
                temp = 0;
              }

            }

            if (temp)
            {
              if (buf[by][tot] == 'R')
                r = 1;
              else
                if (buf[by][tot] == 'B')
                l = 1;


            }

          }

        }

      }

    }

    if (r && l)
    {
      printf("Case #%d: Both\n", a + 1);
    }
    else
      if (r)
    {
      printf("Case #%d: Red\n", a + 1);
    }
    else
      if (l)
    {
      printf("Case #%d: Blue\n", a + 1);
    }
    else
    {
      printf("Case #%d: Neither\n", a + 1);
    }



  }

}


