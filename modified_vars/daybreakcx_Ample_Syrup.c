#include <stdio.h>
#include <inttypes.h>
#include <string.h>
int16_t reach[2][2][2][721];
uint8_t take[2][1440];
int result;
int tn;
int previst;
int finish;
int v;
int n;
int sum;
int ans;
int Main()
{
  fscanf(stdin, "%d", &tn);
  for (result = 1; result <= tn; ++result)
  {
    fprintf(stdout, "Case #%d: ", result);
    memset(take, 0, sizeof(take));
    fscanf(stdin, "%d%d", &n, &sum);
    for (previst = 0; previst < n; ++previst)
    {
      fscanf(stdin, "%d%d", &finish, &v);
      for (; finish < v; ++finish)
        take[0][finish] = 1;

    }

    for (previst = 0; previst < sum; ++previst)
    {
      fscanf(stdin, "%d%d", &finish, &v);
      for (; finish < v; ++finish)
        take[1][finish] = 1;

    }

    memset(reach[0], 0, sizeof(reach[0]));
    if (!take[0][0])
      reach[0][0][0][1] = 1;

    if (!take[1][0])
      reach[0][1][1][0] = 1;

    for (previst = 1; previst < 1440; ++previst)
    {
      memset(reach[previst & 1], 0, sizeof(reach[previst & 1]));
      for (finish = 0; finish < 2; ++finish)
        for (v = 0; v <= 720; ++v)
      {
        if (!take[0][previst])
        {
          if ((v > 0) && reach[1 - (previst & 1)][finish][0][v - 1])
            reach[previst & 1][finish][0][v] = reach[1 - (previst & 1)][finish][0][v - 1];

          if (((v > 0) && reach[1 - (previst & 1)][finish][1][v - 1]) && ((!reach[previst & 1][finish][0][v]) || ((reach[1 - (previst & 1)][finish][1][v - 1] + 1) < reach[previst & 1][finish][0][v])))
            reach[previst & 1][finish][0][v] = reach[1 - (previst & 1)][finish][1][v - 1] + 1;

        }

        if (!take[1][previst])
        {
          if (reach[1 - (previst & 1)][finish][1][v])
            reach[previst & 1][finish][1][v] = reach[1 - (previst & 1)][finish][1][v];

          if (reach[1 - (previst & 1)][finish][0][v] && ((!reach[previst & 1][finish][1][v]) || ((reach[1 - (previst & 1)][finish][0][v] + 1) < reach[previst & 1][finish][1][v])))
            reach[previst & 1][finish][1][v] = reach[1 - (previst & 1)][finish][0][v] + 1;

        }

      }


    }

    for (ans = reach[1][0][0][720], previst = 0; previst < 2; ++previst)
      for (finish = 0; finish < 2; ++finish)
      if (reach[1][previst][finish][720] && ((ans == 0) || ((reach[1][previst][finish][720] - (previst == finish ? 1 : 0)) < ans)))
      ans = reach[1][previst][finish][720] - (previst == finish ? 1 : 0);



    fprintf(stdout, "%d\n", ans);
  }

  return 0;
}


