#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
void *new_memset(void *ptr, int value, size_t num);
int main()
{
  int first_iteration;
  int T;
  int iT;
  scanf("%d", &T);
  static char a[260][260];
  static char b[260][260];
  static char s[260];
  static char now[260];
  int nowc;
  for (iT = 0; iT < T; iT++)
  {
    new_memset(a, 0, sizeof(a));
    new_memset(b, 0, sizeof(b));
    int A;
    int B;
    int N;
    scanf("%d", &A);
    int i;
    int j;
    int k;
    for (i = 0; i < A; i++)
    {
      scanf("%s", s);
      a[s[0]][s[1]] = s[2];
      a[s[1]][s[0]] = s[2];
    }

    scanf("%d", &B);
    for (i = 0; i < B; i++)
    {
      scanf("%s", s);
      b[s[0]][s[1]] = 1;
      b[s[1]][s[0]] = 1;
    }

    scanf("%d", &N);
    scanf("%s", s);
    nowc = 0;
    for (i = 0; i < N; i++)
    {
      now[nowc] = s[i];
      nowc++;
      while (nowc > 1)
      {
        if (a[now[nowc - 1]][now[nowc - 2]] == 0)
          break;

        now[nowc - 2] = a[now[nowc - 1]][now[nowc - 2]];
        nowc--;
      }

      for (j = 0; j < nowc; j++)
      {
        for (k = j; k < nowc; k++)
        {
          if (b[now[j]][now[k]])
          {
            nowc = 0;
            break;
          }

        }

        if (nowc == 0)
          break;

      }

    }

    printf("Case #%d: [", iT + 1);
    for (i = 0; i < nowc; i++)
    {
      if (i)
        printf(", ");

      printf("%c", now[i]);
    }

    printf("]\n");
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


