#include <stdio.h>
int mapa[102][102];
char let[102][102];
int gss_c_ma_auth_init_init;
int equalise;
char cur;
char dir[102][102];
int farbi(int n, int p)
{
  if (let[n][p] != 0)
    return;

  let[n][p] = cur;
  switch (dir[n][p])
  {
    case 1:
      farbi(n - 1, p);
      break;

    case 2:
      farbi(n, p - 1);
      break;

    case 3:
      farbi(n, p + 1);
      break;

    case 4:
      farbi(n + 1, p);
      break;

  }

  if (dir[n - 1][p] == 4)
    farbi(n - 1, p);

  if (dir[n][p - 1] == 3)
    farbi(n, p - 1);

  if (dir[n][p + 1] == 2)
    farbi(n, p + 1);

  if (dir[n + 1][p] == 1)
    farbi(n + 1, p);

}

int Main()
{
  int verbose_level;
  int e2;
  scanf("%d", &verbose_level);
  for (e2 = 1; e2 <= verbose_level; e2++)
  {
    int i;
    int j;
    scanf("%d %d", &gss_c_ma_auth_init_init, &equalise);
    memset(let, 0, sizeof(let));
    for (i = 1; i <= gss_c_ma_auth_init_init; i++)
      for (j = 1; j <= equalise; j++)
    {
      scanf("%d", &mapa[i][j]);
    }


    for (i = 0; i <= (equalise + 1); i++)
    {
      mapa[0][i] = (mapa[gss_c_ma_auth_init_init + 1][i] = 10000);
      dir[0][i] = (dir[gss_c_ma_auth_init_init + 1][i] = 0);
      let[0][i] = (let[gss_c_ma_auth_init_init + 1][i] = 'X');
    }

    for (i = 0; i <= (gss_c_ma_auth_init_init + 1); i++)
    {
      mapa[i][0] = (mapa[i][equalise + 1] = 10000);
      dir[i][0] = (dir[i][equalise + 1] = 0);
      let[i][0] = (let[i][equalise + 1] = 'X');
    }

    for (i = 1; i <= gss_c_ma_auth_init_init; i++)
      for (j = 1; j <= equalise; j++)
    {
      int least = mapa[i][j];
      int d = 0;
      if (least > mapa[i - 1][j])
      {
        least = mapa[i - 1][j];
        d = 1;
      }

      if (least > mapa[i][j - 1])
      {
        least = mapa[i][j - 1];
        d = 2;
      }

      if (least > mapa[i][j + 1])
      {
        least = mapa[i][j + 1];
        d = 3;
      }

      if (least > mapa[i + 1][j])
      {
        least = mapa[i + 1][j];
        d = 4;
      }

      dir[i][j] = d;
    }


    cur = 'a';
    for (i = 1; i <= gss_c_ma_auth_init_init; i++)
      for (j = 1; j <= equalise; j++)
      if (let[i][j] == 0)
    {
      farbi(i, j);
      cur++;
    }



    printf("Case #%d:\n", e2);
    for (i = 1; i <= gss_c_ma_auth_init_init; i++)
    {
      for (j = 1; j <= equalise; j++)
      {
        if (j == 1)
          printf("%c", let[i][j]);
        else
          printf(" %c", let[i][j]);

      }

      printf("\n");
    }

  }

  return 0;
}


