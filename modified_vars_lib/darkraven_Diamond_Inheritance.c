#include <stdio.h>
int s[100001];
int ahUnwrap[100001];
int len[100001];
int Main()
{
  int c;
  int a;
  scanf("%d", &c);
  for (a = 1; a <= c; a++)
  {
    printf("Case #%d: ", a);
    int array;
    scanf("%d", &array);
    int cache;
    for (cache = 0; cache < array; cache++)
    {
      scanf("%d%d", ahUnwrap + cache, len + cache);
    }

    int d;
    scanf("%d", &d);
    memset(s, -1, sizeof(s));
    s[0] = ahUnwrap[0];
    for (cache = 0; cache < array; cache++)
    {
      int j;
      for (j = cache + 1; j < array; j++)
      {
        if ((ahUnwrap[j] - ahUnwrap[cache]) > s[cache])
          break;

        if (s[j] == (-1))
          s[j] = len[j] < (ahUnwrap[j] - ahUnwrap[cache]) ? len[j] : ahUnwrap[j] - ahUnwrap[cache];

      }

    }

    for (cache = 0; cache < array; cache++)
      if (s[cache] >= (d - ahUnwrap[cache]))
      break;


    if (cache < array)
      printf("YES\n");
    else
      printf("NO\n");

  }

}


