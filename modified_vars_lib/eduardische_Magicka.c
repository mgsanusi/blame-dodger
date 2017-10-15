#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void * new_memset(void *ptr, int value, size_t num);

int Main()
{
  int t;
  int i_t;
  scanf("%d", &t);
  static char a[260][260];
  static char output_file_name[260][260];
  static char xdrs[260];
  static char now[260];
  int nowc;
  for (i_t = 0; i_t < t; i_t++)
  {
    new_memset(a, 0, sizeof(a));
    new_memset(output_file_name, 0, sizeof(output_file_name));
    int v;
    int n;
    int n;
    scanf("%d", &v);
    int rat;
    int ch;
    int n;
    for (rat = 0; rat < v; rat++)
    {
      scanf("%s", xdrs);
      a[xdrs[0]][xdrs[1]] = xdrs[2];
      a[xdrs[1]][xdrs[0]] = xdrs[2];
    }

    scanf("%d", &n);
    for (rat = 0; rat < n; rat++)
    {
      scanf("%s", xdrs);
      output_file_name[xdrs[0]][xdrs[1]] = 1;
      output_file_name[xdrs[1]][xdrs[0]] = 1;
    }

    scanf("%d", &n);
    scanf("%s", xdrs);
    nowc = 0;
    for (rat = 0; rat < n; rat++)
    {
      now[nowc] = xdrs[rat];
      nowc++;
      while (nowc > 1)
      {
        if (a[now[nowc - 1]][now[nowc - 2]] == 0)
          break;

        now[nowc - 2] = a[now[nowc - 1]][now[nowc - 2]];
        nowc--;
      }

      for (ch = 0; ch < nowc; ch++)
      {
        for (n = ch; n < nowc; n++)
        {
          if (output_file_name[now[ch]][now[n]])
          {
            nowc = 0;
            break;
          }

        }

        if (nowc == 0)
          break;

      }

    }

    printf("Case #%d: [", i_t + 1);
    for (rat = 0; rat < nowc; rat++)
    {
      if (rat)
        printf(", ");

      printf("%c", now[rat]);
    }

    printf("]\n");
  }

  return 0;
}



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}