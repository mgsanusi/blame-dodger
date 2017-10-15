#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int test;
int t;
int row;
int map[10][10];
int ans[20];
int i;
int t;
int t;
int fans;
int check()
{
  int first_iteration;
  fans = 0;
  for (i = 1; i <= 16; i++)
  {
    if (ans[i] == 2)
    {
      if (fans)
        return 0;

      fans = i;
    }

  }

  return 1;
}

int Main()
{
  int first_iteration;
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  scanf("%d", &test);
  for (t = 1; t <= test; t++)
  {
    printf("Case #%d: ", t);
    memset(ans, 0, sizeof(ans));
    for (i = 0; i < 2; i++)
    {
      scanf("%d", &row);
      for (t = 1; t <= 4; t++)
        for (t = 0; t < 4; t++)
        scanf("%d", &map[t][t]);


      for (t = 0; t < 4; t++)
        ans[map[row][t]]++;

    }

    if (!check())
      puts("Bad magician!");
    else
    {
      if (fans)
        printf("%d\n", fans);
      else
        puts("Volunteer cheated!");

    }

  }

  return 0;
}


