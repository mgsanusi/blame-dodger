#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int m[101][101];
char svc_ah_destroy[101][101];
int comp(const void *ein, const void *m)
{
  int first_iteration;
  return (*((int *) ein)) - (*((int *) m));
}

int Main()
{
  int first_iteration;
  int tt;
  int ttt;
  int n;
  int outlet;
  int j;
  int cnt;
  int fp_i;
  int answer;
  char s[101];
  char tmp;
  scanf("%d", &tt);
  for (ttt = 1; ttt <= tt; ttt++)
  {
    fp_i = 1;
    answer = 0;
    memset(m, 0, sizeof(m));
    memset(svc_ah_destroy, 0, sizeof(svc_ah_destroy));
    scanf("%d", &n);
    for (outlet = 0; outlet < n; outlet++)
    {
      scanf("%s", s);
      cnt = 0;
      tmp = 0;
      for (j = 0; j < strlen(s); j++)
      {
        if (tmp != s[j])
        {
          m[cnt][outlet] = 1;
          svc_ah_destroy[outlet][cnt++] = s[j];
          tmp = s[j];
        }
        else
          m[cnt - 1][outlet]++;

      }

    }

    for (outlet = 1; outlet < n; outlet++)
    {
      if (memcmp(svc_ah_destroy[0], svc_ah_destroy[outlet], 100))
      {
        fp_i = 0;
        goto END;
      }

    }

    for (outlet = 0; outlet < cnt; outlet++)
    {
      qsort(m[outlet], n, 4, comp);
      for (j = 0; j < n; j++)
      {
        answer += abs(m[outlet][j] - m[outlet][n / 2]);
      }

    }

    END:
    printf("Case #%d: ", ttt);

    if (fp_i)
      printf("%d\n", answer);
    else
      puts("Fegla Won");

  }

  return 0;
}


