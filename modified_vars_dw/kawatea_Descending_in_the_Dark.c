#include <stdio.h>
#include <string.h>
int Main()
{
  int first_iteration;
  int cl_abort;
  int gss_c_ma_mech_pseudo;
  int v;
  int l;
  char c[11] = "oi eas tbg";
  scanf("%d", &cl_abort);
  for (gss_c_ma_mech_pseudo = 0; gss_c_ma_mech_pseudo < cl_abort; gss_c_ma_mech_pseudo++)
  {
    int k;
    int n;
    int sum = 0;
    int m = 0;
    char s[1001];
    int a[26][26] = {0};
    int in[36][2] = {0};
    scanf("%d", &k);
    scanf("%s", s);
    n = strlen(s);
    for (v = 0; v < (n - 1); v++)
    {
      int x = s[v] - 'a';
      int y = s[v + 1] - 'a';
      int p = -1;
      int q = -1;
      if (a[x][y] == 1)
        continue;

      a[x][y] = 1;
      in[x][0]++;
      in[y][1]++;
      for (l = 0; l < 10; l++)
      {
        if (s[v] == c[l])
          p = l;

        if (s[v + 1] == c[l])
          q = l;

      }

      if (p != (-1))
      {
        if (q != (-1))
        {
          in[x][0]++;
          in[y][1]++;
          in[26 + p][0] += 2;
          in[26 + q][1] += 2;
        }
        else
        {
          in[26 + p][0]++;
          in[y][1]++;
        }

      }
      else
        if (q != (-1))
      {
        in[x][0]++;
        in[26 + q][1]++;
      }


    }

    for (v = 0; v < 36; v++)
    {
      if (in[v][0] > in[v][1])
      {
        sum += in[v][0];
      }
      else
      {
        sum += in[v][1];
      }

      if (in[v][0] != in[v][1])
        m = 1;

    }

    if (m == 0)
      sum++;

    printf("Case #%d: %d\n", gss_c_ma_mech_pseudo + 1, sum);
  }

  return 0;
}


