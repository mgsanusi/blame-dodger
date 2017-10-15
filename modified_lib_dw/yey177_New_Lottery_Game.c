#include <stdio.h>
#include <string.h>
#include <stddef.h>
long long dp[8][32];
long long pow2[64];
int as[40];
int bs[40];
int ks[40];
void *new_memset(void *ptr, int value, size_t num);
int main()
{
  int first_iteration;
  int a;
  int b;
  int k;
  int t;
  int tt;
  int i;
  int cnta;
  int cntb;
  int cntk;
  int cnt;
  int tmp;
  scanf("%d", &t);
  pow2[0] = 1;
  for (i = 1; i < 63; i++)
    pow2[i] = 2 * pow2[i - 1];

  for (tt = 1; tt <= t; tt++)
  {
    scanf("%d%d%d", &a, &b, &k);
    a--;
    b--;
    k--;
    new_memset(dp, 0, sizeof(dp));
    new_memset(as, 0, sizeof(as));
    new_memset(bs, 0, sizeof(bs));
    new_memset(ks, 0, sizeof(ks));
    tmp = a;
    cnta = 0;
    while (tmp > 0)
    {
      as[cnta++] = tmp & 1;
      tmp >>= 1;
    }

    tmp = b;
    cntb = 0;
    while (tmp > 0)
    {
      bs[cntb++] = tmp & 1;
      tmp >>= 1;
    }

    tmp = k;
    cntk = 0;
    while (tmp > 0)
    {
      ks[cntk++] = tmp & 1;
      tmp >>= 1;
    }

    cnt = cntk > (cnta > cntb ? cnta : cntb) ? cntk : cnta > cntb ? cnta : cntb;
    dp[0][0] = 1 - ks[0];
    dp[1][0] = (1 - ks[0]) * as[0];
    dp[2][0] = (1 - ks[0]) * bs[0];
    dp[3][0] = ((1 - ks[0]) * as[0]) * bs[0];
    for (i = 1; i <= cnt; i++)
    {
      if (ks[i] == 1)
      {
        dp[0][i] = dp[0][i - 1];
        if ((as[i] == 0) && (bs[i] == 0))
        {
          dp[1][i] = 0;
          dp[2][i] = 0;
          dp[3][i] = 0;
        }
        else
          if ((as[i] == 1) && (bs[i] == 0))
        {
          dp[1][i] = dp[1][i - 1];
          dp[2][i] = 0;
          dp[3][i] = 0;
        }
        else
          if ((as[i] == 0) && (bs[i] == 1))
        {
          dp[1][i] = 0;
          dp[2][i] = dp[2][i - 1];
          dp[3][i] = 0;
        }
        else
        {
          dp[1][i] = dp[1][i - 1];
          dp[2][i] = dp[2][i - 1];
          dp[3][i] = dp[3][i - 1];
        }



      }
      else
      {
        dp[0][i] = (dp[0][i - 1] * 3) + pow2[i * 2];
        if ((as[i] == 0) && (bs[i] == 0))
        {
          dp[1][i] = dp[1][i - 1] * 2;
          dp[2][i] = dp[2][i - 1] * 2;
          dp[3][i] = dp[3][i - 1];
        }
        else
          if ((as[i] == 1) && (bs[i] == 0))
        {
          dp[1][i] = ((dp[0][i - 1] * 2) + dp[1][i - 1]) + (((a & (pow2[i] - 1)) + 1) * pow2[i]);
          dp[2][i] = dp[2][i - 1] * 2;
          dp[3][i] = dp[2][i - 1] + dp[3][i - 1];
        }
        else
          if ((as[i] == 0) && (bs[i] == 1))
        {
          dp[1][i] = dp[1][i - 1] * 2;
          dp[2][i] = ((dp[0][i - 1] * 2) + dp[2][i - 1]) + (pow2[i] * ((b & (pow2[i] - 1)) + 1));
          dp[3][i] = dp[1][i - 1] + dp[3][i - 1];
        }
        else
        {
          dp[1][i] = ((dp[0][i - 1] * 2) + dp[1][i - 1]) + (((a & (pow2[i] - 1)) + 1) * pow2[i]);
          dp[2][i] = ((dp[0][i - 1] * 2) + dp[2][i - 1]) + (pow2[i] * ((b & (pow2[i] - 1)) + 1));
          dp[3][i] = ((dp[0][i - 1] + dp[1][i - 1]) + dp[2][i - 1]) + (((a & (pow2[i] - 1)) + 1) * ((b & (pow2[i] - 1)) + 1));
        }



      }

    }

    printf("Case #%d: %lld\n", tt, (((long long) (a + 1)) * (b + 1)) - dp[3][cnt]);
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


