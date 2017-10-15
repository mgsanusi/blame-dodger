#include <stdio.h>
#include <string.h>
int flag[20];
int prfl;
int found[(20 * 100000) + 1];
int use[20];
int print;
int set[20][2];
void base(int d, int total)
{
  if (d == 20)
  {
    if (total == prfl)
    {
      if (print < 2)
      {
        for (int j = 0; j < 20; j++)
          set[j][print] = use[j];

        print++;
      }

    }
    else
      found[total]++;

    return;
  }

  use[d] = 1;
  base(d + 1, total + flag[d]);
  use[d] = 0;
  base(d + 1, total);
}

int Main()
{
  int count;
  scanf("%d", &count);
  for (int h = 1; h <= count; h++)
  {
    int newdiam;
    scanf("%d", &newdiam);
    printf("Case #%d:\n", h);
    for (int j = 0; j < 20; j++)
      scanf("%d", &flag[j]);

    memset(found, 0, sizeof(found));
    memset(use, 0, sizeof(use));
    print = 0;
    prfl = -1;
    base(0, 0);
    for (int j = 0; j <= (20 * 100000); j++)
      if (found[j] >= 2)
    {
      prfl = j;
      break;
    }


    if (prfl == (-1))
      printf("Impossible\n");
    else
    {
      base(0, 0);
      int first = 0;
      for (int j = 0; j < 20; j++)
        if ((set[j][0] == 1) && (set[j][1] == 0))
        printf("%s%d", first++ ? " " : "", flag[j]);


      printf("\n");
      first = 0;
      for (int j = 0; j < 20; j++)
        if ((set[j][1] == 1) && (set[j][0] == 0))
        printf("%s%d", first++ ? " " : "", flag[j]);


      printf("\n");
    }

  }

}


