#include <stdio.h>
#include <string.h>
char n2[1048576][21];
char tmp[21];
int board[21];
int on[21];
int key[21][41];
int minu[21];
int a[201];
int xsum[201];
int Main()
{
  int t;
  int k;
  int p;
  int i;
  int t1;
  int l;
  int out;
  int tmp;
  int gap;
  int s;
  scanf("%d", &t);
  for (l = 1; l <= t; l++)
  {
    memset(a, 0, sizeof(a));
    memset(minu, 0, sizeof(minu));
    memset(n2, 0, sizeof(n2));
    scanf("%d%d", &k, &p);
    for (i = 0; i < k; i++)
    {
      scanf("%d", &tmp);
      a[tmp]++;
    }

    for (i = 0; i < p; i++)
    {
      scanf("%d%d", &board[i], &on[i]);
      for (t1 = 0; t1 < on[i]; t1++)
      {
        scanf("%d", &key[i][t1]);
        if (key[i][t1] == board[i])
          minu[i]++;

      }

    }

    for (i = 1; i < (1 << p); i++)
    {
      memcpy(xsum, a, sizeof(a));
      for (t1 = 0; t1 < p; t1++)
      {
        if (i & (1 << t1))
        {
          for (out = 0; out < on[t1]; out++)
            xsum[key[t1][out]]++;

          xsum[board[t1]]--;
        }

      }

      n2[i][0] = (char) (p + 1);
      s = p + 1;
      for (t1 = 0; t1 < p; t1++)
      {
        if (i & (1 << t1))
        {
          if (((xsum[board[t1]] + 1) - minu[t1]) > 0)
          {
            if (strcmp(n2[i], n2[i ^ (1 << t1)]) > 0)
            {
              strcpy(n2[i], n2[i ^ (1 << t1)]);
              s = t1 + 1;
            }

          }

        }

      }

      if (n2[i][0] == ((char) (p + 1)))
        continue;

      gap = strlen(n2[i]);
      n2[i][gap] = (char) s;
      n2[i][gap + 1] = 0;
    }

    printf("Case #%d: ", l);
    if (n2[(1 << p) - 1][0] == ((char) (p + 1)))
      puts("IMPOSSIBLE");
    else
    {
      for (i = 0; i < p; i++)
        printf("%d%c", (int) n2[(1 << p) - 1][i], i == (p - 1) ? '\n' : ' ');

    }

  }

  return 0;
}


