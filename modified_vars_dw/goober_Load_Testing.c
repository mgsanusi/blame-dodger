#include <stdio.h>
int orig[51][51];
int newdiam[154][154];
int Main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  for (int num = 1; num <= t; num++)
  {
    int k;
    scanf("%d", &k);
    for (int tot = 0; tot < k; tot++)
      for (int past_space = 0; past_space <= tot; past_space++)
      scanf("%d", &orig[tot - past_space][past_space]);


    for (int tot = k; tot < ((2 * k) - 1); tot++)
      for (int past_space = tot - (k - 1); past_space <= (k - 1); past_space++)
      scanf("%d", &orig[tot - past_space][past_space]);


    int map;
    for (map = k; map <= (3 * k); map++)
    {
      for (int tot = 0; tot <= (map - k); tot++)
        for (int past_space = 0; past_space <= (map - k); past_space++)
      {
        memset(newdiam, -1, sizeof(newdiam));
        for (int n = 0; n < k; n++)
          for (int r = 0; r < k; r++)
          newdiam[tot + n][past_space + r] = orig[n][r];


        for (int bla = 1; bla < 4; bla++)
        {
          for (int n = 0; n < map; n++)
            for (int r = 0; r < map; r++)
            if (newdiam[n][r] == (-1))
          {
            newdiam[n][r] = newdiam[(map - 1) - r][(map - 1) - n];
          }
          else
            if (newdiam[(map - 1) - r][(map - 1) - n] == (-1))
          {
            newdiam[(map - 1) - r][(map - 1) - n] = newdiam[n][r];
          }
          else
            if (newdiam[n][r] != newdiam[(map - 1) - r][(map - 1) - n])
            goto bad;





          for (int n = 0; n < map; n++)
            for (int r = 0; r < map; r++)
            if (newdiam[n][r] == (-1))
          {
            newdiam[n][r] = newdiam[r][n];
          }
          else
            if (newdiam[r][n] == (-1))
          {
            newdiam[r][n] = newdiam[n][r];
          }
          else
            if (newdiam[n][r] != newdiam[r][n])
            goto bad;





        }

        goto found;
        bad:
        ;

      }


    }

    found:
    printf("Case #%d: %d\n", num, (map * map) - (k * k));

  }

}


