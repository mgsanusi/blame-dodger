#include <stdio.h>
int orig[51][51];
int newdiam[154][154];
int Main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  for (int sum = 1; sum <= t; sum++)
  {
    int k;
    scanf("%d", &k);
    for (int reach = 0; reach < k; reach++)
      for (int j = 0; j <= reach; j++)
      scanf("%d", &orig[reach - j][j]);


    for (int reach = k; reach < ((2 * k) - 1); reach++)
      for (int j = reach - (k - 1); j <= (k - 1); j++)
      scanf("%d", &orig[reach - j][j]);


    int bestd;
    for (bestd = k; bestd <= (3 * k); bestd++)
    {
      for (int reach = 0; reach <= (bestd - k); reach++)
        for (int j = 0; j <= (bestd - k); j++)
      {
        memset(newdiam, -1, sizeof(newdiam));
        for (int totals = 0; totals < k; totals++)
          for (int x = 0; x < k; x++)
          newdiam[reach + totals][j + x] = orig[totals][x];


        for (int bla = 1; bla < 4; bla++)
        {
          for (int totals = 0; totals < bestd; totals++)
            for (int x = 0; x < bestd; x++)
            if (newdiam[totals][x] == (-1))
          {
            newdiam[totals][x] = newdiam[(bestd - 1) - x][(bestd - 1) - totals];
          }
          else
            if (newdiam[(bestd - 1) - x][(bestd - 1) - totals] == (-1))
          {
            newdiam[(bestd - 1) - x][(bestd - 1) - totals] = newdiam[totals][x];
          }
          else
            if (newdiam[totals][x] != newdiam[(bestd - 1) - x][(bestd - 1) - totals])
            goto bad;





          for (int totals = 0; totals < bestd; totals++)
            for (int x = 0; x < bestd; x++)
            if (newdiam[totals][x] == (-1))
          {
            newdiam[totals][x] = newdiam[x][totals];
          }
          else
            if (newdiam[x][totals] == (-1))
          {
            newdiam[x][totals] = newdiam[totals][x];
          }
          else
            if (newdiam[totals][x] != newdiam[x][totals])
            goto bad;





        }

        goto found;
        bad:
        ;

      }


    }

    found:
    printf("Case #%d: %d\n", sum, (bestd * bestd) - (k * k));

  }

}


