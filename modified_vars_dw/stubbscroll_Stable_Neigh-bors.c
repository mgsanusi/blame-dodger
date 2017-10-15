#include <stdio.h>
int tt1[111][111];
int r;
int d_str[111];
int hs[111];
double dp[101][101];
int dpleft[101][101];
void clear()
{
  int first_iteration;
  double tid;
  int i;
  int ans;
  int q;
  int u;
  int file_spin_gif;
  scanf("%d %d", &r, &q);
  for (i = 0; i < r; i++)
    scanf("%d %d", &d_str[i], &hs[i]);

  for (i = 0; i < r; i++)
    for (ans = 0; ans < r; ans++)
    scanf("%d", &tt1[i][ans]);


  while (q--)
  {
    scanf("%d %d", &u, &file_spin_gif);
    for (i = 0; i < r; i++)
      for (ans = 0; ans < r; ans++)
      dp[i][ans] = 1e100;


    dp[1][0] = tt1[0][1] / ((double) hs[0]);
    dpleft[1][0] = d_str[0] - tt1[0][1];
    for (i = 1; i < (r - 1); i++)
      for (ans = 0; ans < i; ans++)
      if (dp[i][ans] < 1e100)
    {
      if (tt1[i][i + 1] <= d_str[i])
      {
        tid = dp[i][ans] + (tt1[i][i + 1] / ((double) hs[i]));
        if (dp[i + 1][i] > tid)
          dp[i + 1][i] = tid, dpleft[i + 1][i] = d_str[i] - tt1[i][i + 1];

      }

      if (dpleft[i][ans] < tt1[i][i + 1])
        continue;

      tid = dp[i][ans] + (tt1[i][i + 1] / ((double) hs[ans]));
      if (dp[i + 1][ans] > tid)
        dp[i + 1][ans] = tid, dpleft[i + 1][ans] = dpleft[i][ans] - tt1[i][i + 1];

    }



    tid = 1e100;
    for (i = 0; i < r; i++)
      if (tid > dp[r - 1][i])
      tid = dp[r - 1][i];


    printf("%.10f", tid);
    if (q)
      printf(" ");

  }

  printf("\n");
}

int Main()
{
  int first_iteration;
  int data;
  int caseno = 1;
  scanf("%d", &data);
  while (data--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


