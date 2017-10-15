#include<stdio.h>
char time1[100][100];
int cs;
int y;
int choose[20][2000];
int sol(int d, int k)
{
  int first_iteration;
  int ans;
  int j;
  int device;
  int ans = 0;
  int tmp;
  int gg;
  int oku[20];
  if (d == cs)
    return 0;

  if (choose[d][k] >= 0)
    return choose[d][k];

  for (device = 0; device < (1 << y); device++)
  {
    for (ans = 0; ans < y; ans++)
      if (device & (1 << ans))
      oku[ans] = 1;
    else
      oku[ans] = 0;


    for (ans = 0; ans < y; ans++)
      if (oku[ans] && (time1[d][ans] == 'x'))
      break;


    if (ans != y)
      continue;

    for (ans = 0; ans < y; ans++)
      if (oku[ans] && (k & (1 << ans)))
      break;


    if (ans != y)
      continue;

    for (ans = 1; ans < y; ans++)
      if (oku[ans - 1] && oku[ans])
      break;


    if (ans != y)
      continue;

    gg = 0;
    for (ans = 0; ans < y; ans++)
    {
      tmp = 0;
      if (ans && oku[ans - 1])
        tmp = 1;

      if ((ans < (y - 1)) && oku[ans + 1])
        tmp = 1;

      if (tmp)
        gg ^= 1 << ans;

    }

    tmp = sol(d + 1, gg);
    for (ans = 0; ans < y; ans++)
      tmp += oku[ans];

    if (ans < tmp)
      ans = tmp;

  }

  return choose[d][k] = ans;
}

int Main()
{
  int first_iteration;
  int ans;
  int j;
  int k;
  int r;
  int device;
  int n;
  int size;
  int count = 0;
  int ans;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &cs, &y);
    for (ans = 0; ans < cs; ans++)
      scanf("%s", time1[ans]);

    for (ans = 0; ans < 20; ans++)
      for (j = 0; j < 2000; j++)
      choose[ans][j] = -1;


    ans = sol(0, 0);
    printf("Case #%d: %d\n", ++count, ans);
  }

  return 0;
}


