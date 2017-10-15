#include <stdio.h>
#include <string.h>
long long account_b[8][32];
long long pow2[64];
int no[40];
int cs[40];
int mode[40];
int Main()
{
  int a;
  int s2;
  int k;
  int flag;
  int j;
  int cps;
  int cnta;
  int cntb;
  int cntk;
  int count;
  int tmp;
  scanf("%d", &flag);
  pow2[0] = 1;
  for (cps = 1; cps < 63; cps++)
    pow2[cps] = 2 * pow2[cps - 1];

  for (j = 1; j <= flag; j++)
  {
    scanf("%d%d%d", &a, &s2, &k);
    a--;
    s2--;
    k--;
    memset(account_b, 0, sizeof(account_b));
    memset(no, 0, sizeof(no));
    memset(cs, 0, sizeof(cs));
    memset(mode, 0, sizeof(mode));
    tmp = a;
    cnta = 0;
    while (tmp > 0)
    {
      no[cnta++] = tmp & 1;
      tmp >>= 1;
    }

    tmp = s2;
    cntb = 0;
    while (tmp > 0)
    {
      cs[cntb++] = tmp & 1;
      tmp >>= 1;
    }

    tmp = k;
    cntk = 0;
    while (tmp > 0)
    {
      mode[cntk++] = tmp & 1;
      tmp >>= 1;
    }

    count = cntk > (cnta > cntb ? cnta : cntb) ? cntk : cnta > cntb ? cnta : cntb;
    account_b[0][0] = 1 - mode[0];
    account_b[1][0] = (1 - mode[0]) * no[0];
    account_b[2][0] = (1 - mode[0]) * cs[0];
    account_b[3][0] = ((1 - mode[0]) * no[0]) * cs[0];
    for (cps = 1; cps <= count; cps++)
    {
      if (mode[cps] == 1)
      {
        account_b[0][cps] = account_b[0][cps - 1];
        if ((no[cps] == 0) && (cs[cps] == 0))
        {
          account_b[1][cps] = 0;
          account_b[2][cps] = 0;
          account_b[3][cps] = 0;
        }
        else
          if ((no[cps] == 1) && (cs[cps] == 0))
        {
          account_b[1][cps] = account_b[1][cps - 1];
          account_b[2][cps] = 0;
          account_b[3][cps] = 0;
        }
        else
          if ((no[cps] == 0) && (cs[cps] == 1))
        {
          account_b[1][cps] = 0;
          account_b[2][cps] = account_b[2][cps - 1];
          account_b[3][cps] = 0;
        }
        else
        {
          account_b[1][cps] = account_b[1][cps - 1];
          account_b[2][cps] = account_b[2][cps - 1];
          account_b[3][cps] = account_b[3][cps - 1];
        }



      }
      else
      {
        account_b[0][cps] = (account_b[0][cps - 1] * 3) + pow2[cps * 2];
        if ((no[cps] == 0) && (cs[cps] == 0))
        {
          account_b[1][cps] = account_b[1][cps - 1] * 2;
          account_b[2][cps] = account_b[2][cps - 1] * 2;
          account_b[3][cps] = account_b[3][cps - 1];
        }
        else
          if ((no[cps] == 1) && (cs[cps] == 0))
        {
          account_b[1][cps] = ((account_b[0][cps - 1] * 2) + account_b[1][cps - 1]) + (((a & (pow2[cps] - 1)) + 1) * pow2[cps]);
          account_b[2][cps] = account_b[2][cps - 1] * 2;
          account_b[3][cps] = account_b[2][cps - 1] + account_b[3][cps - 1];
        }
        else
          if ((no[cps] == 0) && (cs[cps] == 1))
        {
          account_b[1][cps] = account_b[1][cps - 1] * 2;
          account_b[2][cps] = ((account_b[0][cps - 1] * 2) + account_b[2][cps - 1]) + (pow2[cps] * ((s2 & (pow2[cps] - 1)) + 1));
          account_b[3][cps] = account_b[1][cps - 1] + account_b[3][cps - 1];
        }
        else
        {
          account_b[1][cps] = ((account_b[0][cps - 1] * 2) + account_b[1][cps - 1]) + (((a & (pow2[cps] - 1)) + 1) * pow2[cps]);
          account_b[2][cps] = ((account_b[0][cps - 1] * 2) + account_b[2][cps - 1]) + (pow2[cps] * ((s2 & (pow2[cps] - 1)) + 1));
          account_b[3][cps] = ((account_b[0][cps - 1] + account_b[1][cps - 1]) + account_b[2][cps - 1]) + (((a & (pow2[cps] - 1)) + 1) * ((s2 & (pow2[cps] - 1)) + 1));
        }



      }

    }

    printf("Case #%d: %lld\n", j, (((long long) (a + 1)) * (s2 + 1)) - account_b[3][count]);
  }

  return 0;
}


