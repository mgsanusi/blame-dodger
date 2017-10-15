#include<stdio.h>
int Main()
{
  int i;
  int j;
  int k;
  int c;
  int c;
  int n;
  int size;
  int count = 0;
  int x;
  int y;
  int mp[100][100];
  int val[2];
  int a[2];
  int max2[10000];
  int cs[10000];
  int st_size;
  int rslt;
  int na;
  int t;
  int tmp;
  int misc;
  int ny;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &x, &y);
    scanf("%d%d%d%d", val, a, val + 1, a + 1);
    rslt = 0;
    scanf("%d%d", &na, &t);
    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
      mp[i][j] = 0;


    mp[na][t] = 1;
    max2[0] = na;
    cs[0] = t;
    st_size = 1;
    tmp = 1;
    while (st_size)
    {
      i = max2[--st_size];
      j = cs[st_size];
      for (k = 0; k < 2; k++)
      {
        misc = i + val[k];
        ny = j + a[k];
        if ((((misc < 0) || (ny < 0)) || (misc >= x)) || (ny >= y))
          continue;

        if (mp[misc][ny])
          continue;

        tmp++;
        mp[misc][ny] = 1;
        max2[st_size] = misc;
        cs[st_size++] = ny;
      }

    }

    if (tmp > rslt)
      rslt = tmp;

    printf("Case #%d: %d\n", ++count, rslt);
  }

  return 0;
}


