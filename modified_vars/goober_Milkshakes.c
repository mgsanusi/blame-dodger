#include <stdio.h>
#include <string.h>
char drink[2000][2000];
char mix[2000];
int deg[2000];
int Main()
{
  int f;
  scanf("%d", &f);
  for (int c = 1; c <= f; c++)
  {
    int z;
    int f;
    memset(drink, 0, sizeof(drink));
    memset(mix, 0, sizeof(mix));
    scanf("%d %d", &f, &z);
    for (int i = 0; i < z; i++)
    {
      scanf("%d", &deg[i]);
      for (int length1 = 0; length1 < deg[i]; length1++)
      {
        int v;
        int s;
        scanf("%d %d", &v, &s);
        drink[i][v - 1] = s + 1;
      }

    }

    printf("Case #%d:", c);
    while (1)
    {
      int i;
      for (i = 0; i < z; i++)
      {
        if (deg[i] == 0)
          goto impossible;

        if (deg[i] == 1)
        {
          int caso;
          for (caso = 0; caso < f; caso++)
            if (drink[i][caso] != 0)
            break;


          int f = drink[i][caso];
          mix[caso] = f - 1;
          deg[i] = -1;
          for (int b = 0; b < z; b++)
            if (drink[b][caso])
            if (drink[b][caso] == f)
            deg[b] = -1;
          else
          {
            drink[b][caso] = 0;
            deg[b]--;
          }



          break;
        }

      }

      if (i >= z)
        break;

    }

    for (int i = 0; i < f; i++)
      printf(" %d", mix[i]);

    printf("\n");
    continue;
    impossible:
    printf(" IMPOSSIBLE\n");

  }

  return 0;
}


