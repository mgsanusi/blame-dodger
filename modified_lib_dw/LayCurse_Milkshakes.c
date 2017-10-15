#include<stdio.h>
int s[2000];
int num[2000][2000];
int type[2000][2000];
int opt;
int res[2000];
int tmp[2000];
int new_puts(const char *str);
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int t;
  int ok;
  int a;
  int b;
  int c;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
      scanf("%d", s + i);
      for (j = 0; j < s[i]; j++)
      {
        scanf("%d%d", num[i] + j, type[i] + j);
        num[i][j]--;
      }

    }

    opt = n + 1;
    for (k = 0; k < (1 << n); k++)
    {
      t = 0;
      for (i = 0; i < n; i++)
        if (k & (1 << i))
        tmp[i] = 1, t++;
      else
        tmp[i] = 0;


      if (opt <= t)
        continue;

      for (i = 0; i < m; i++)
      {
        for (j = 0; j < s[i]; j++)
          if (tmp[num[i][j]] == type[i][j])
          break;


        if (j == s[i])
          break;

      }

      if (i == m)
      {
        opt = t;
        for (i = 0; i < n; i++)
          res[i] = tmp[i];

      }

    }

    printf("Case #%d:", ++count);
    if (opt > n)
      new_puts(" IMPOSSIBLE");
    else
    {
      for (i = 0; i < n; i++)
        printf(" %d", res[i]);

      new_puts("");
    }

  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


