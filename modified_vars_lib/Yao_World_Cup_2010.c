#include<stdio.h>
#include<string.h>
int a[64][64];
int flag[256][256];
int tmp;
int m;
int judge(int m)
{
  int oowp;
  int k;
  for (oowp = 0; oowp < m; oowp++)
    for (k = 0; k < m; k++)
    if (flag[oowp][k] != (-1))
  {
    if (flag[k][oowp] == (-1))
      flag[k][oowp] = flag[oowp][k];
    else
      if (flag[oowp][k] != flag[k][oowp])
      return 0;


    if (flag[(m - 1) - oowp][(m - 1) - k] == (-1))
      flag[(m - 1) - oowp][(m - 1) - k] = flag[oowp][k];
    else
      if (flag[(m - 1) - oowp][(m - 1) - k] != flag[oowp][k])
      return 0;


    if (flag[(m - 1) - k][(m - 1) - oowp] == (-1))
      flag[(m - 1) - k][(m - 1) - oowp] = flag[oowp][k];
    else
      if (flag[(m - 1) - k][(m - 1) - oowp] != flag[oowp][k])
      return 0;


  }



  return 1;
}

int cal(int m)
{
  int pg;
  int oowp;
  int k;
  int l;
  for (pg = 0; (pg + tmp) <= m; pg++)
    for (oowp = 0; (oowp + tmp) <= m; oowp++)
  {
    memset(flag, 0xff, sizeof(flag));
    for (k = 0; k < tmp; k++)
      for (l = 0; l < tmp; l++)
      flag[pg + k][oowp + l] = a[k][l];


    if (judge(m))
      return 1;

  }


  return 0;
}

int Main()
{
  int b2;
  int cs = 0;
  int pg;
  int oowp;
  int k;
  for (scanf("%d", &b2); b2--;)
  {
    scanf("%d", &tmp);
    for (pg = 0; pg < ((tmp + tmp) - 1); pg++)
    {
      for (oowp = 0; (oowp < tmp) && (oowp <= pg); oowp++)
        if ((pg - oowp) < tmp)
        scanf("%d", &a[oowp][pg - oowp]);


    }

    for (m = tmp;; m++)
    {
      if (cal(m))
        break;

    }

    printf("Case #%d: %d\n", ++cs, (m * m) - (tmp * tmp));
  }

  return 0;
}


