#include<stdio.h>
#include<string.h>
#include<stdio.h>

#include <stddef.h>
void * new_memset(void *ptr, int value, int num);

int Main()
{
  int first_iteration;
  int tot;
  int numbers;
  int pre;
  int dis[2];
  char which[4];
  char bishop[204][2];
  char rook[104][2];
  char bishopput[104][104];
  char rookput[104][104];
  int bishopf[200][2];
  int rookf[100][2];
  int queenf[100][2];
  int bcnt;
  int rcnt;
  int qcnt;
  int cnt;
  scanf("%d", &tot);
  for (int i = 1; i <= tot; i++)
  {
    bcnt = 0;
    rcnt = 0;
    qcnt = 0;
    cnt = 0;
    scanf("%d%d", &numbers, &pre);
    new_memset(bishop, '0', 408);
    new_memset(rook, '0', 208);
    new_memset(bishopput, '0', 10816);
    new_memset(rookput, '0', 10816);
    for (int tl = 0; tl < pre; tl++)
    {
      scanf("%s", which);
      scanf("%d%d", &dis[0], &dis[1]);
      if ((which[0] == '+') || (which[0] == 'o'))
      {
        bishop[dis[0] + dis[1]][0] = '1';
        bishop[(dis[0] - dis[1]) + numbers][1] = '1';
        bishopput[dis[0]][dis[1]] = '3';
      }

      if ((which[0] == 'x') || (which[0] == 'o'))
      {
        rook[dis[0]][0] = '1';
        rook[dis[1]][1] = '1';
        rookput[dis[0]][dis[1]] = '3';
      }

    }

    for (int dy = numbers, k = 1; dy >= t; dy--, t++)
    {
      for (int tl = t; tl <= dy; tl++)
      {
        if (bishop[t + tl][0] == '0')
        {
          if (bishop[(t - tl) + numbers][1] == '0')
          {
            bishopput[t][tl] = '2';
            bishop[tl + t][0] = '1';
            bishop[(t - tl) + numbers][1] = '1';
          }

        }

        if (bishop[dy + tl][0] == '0')
        {
          if (bishop[(dy - tl) + numbers][1] == '0')
          {
            bishopput[dy][tl] = '2';
            bishop[dy + tl][0] = '1';
            bishop[(dy - tl) + numbers][1] = '1';
          }

        }

      }

    }

    for (int tl = 1; tl <= numbers; tl++)
    {
      for (int t = 1; t <= numbers; t++)
      {
        if ((rook[tl][0] == '0') && (rook[t][1] == '0'))
        {
          rookput[tl][t] = '2';
          rook[tl][0] = '1';
          rook[t][1] = '1';
        }

      }

    }

    for (int tl = 1; tl <= numbers; tl++)
    {
      for (int t = 1; t <= numbers; t++)
      {
        if ((rookput[tl][t] == '2') && (bishopput[tl][t] >= '2'))
        {
          queenf[qcnt][0] = tl;
          queenf[qcnt][1] = t;
          qcnt++;
        }
        else
          if ((rookput[tl][t] == '3') && (bishopput[tl][t] == '3'))
          cnt += 2;
        else
          if ((rookput[tl][t] == '3') && (bishopput[tl][t] == '2'))
        {
          queenf[qcnt][0] = tl;
          queenf[qcnt][1] = t;
          qcnt++;
        }
        else
          if (rookput[tl][t] == '2')
        {
          rookf[rcnt][0] = tl;
          rookf[rcnt][1] = t;
          rcnt++;
        }
        else
          if (bishopput[tl][t] == '2')
        {
          bishopf[bcnt][0] = tl;
          bishopf[bcnt][1] = t;
          bcnt++;
        }
        else
          if ((rookput[tl][t] == '3') || (bishopput[tl][t] == '3'))
          cnt += 1;






      }

    }

    printf("Case #%d: %d %d\n", i, ((cnt + rcnt) + bcnt) + (2 * qcnt), (rcnt + bcnt) + qcnt);
    for (int tl = 0; tl < qcnt; tl++)
      printf("o %d %d\n", queenf[tl][0], queenf[tl][1]);

    for (int tl = 0; tl < bcnt; tl++)
      printf("+ %d %d\n", bishopf[tl][0], bishopf[tl][1]);

    for (int tl = 0; tl < rcnt; tl++)
      printf("x %d %d\n", rookf[tl][0], rookf[tl][1]);

  }

  return 0;
}



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}