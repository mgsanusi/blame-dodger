#include <stdio.h>
char conv[256][256];
char opp[256][256];
char row[110];
int Main(void)
{
  int ti;
  int res;
  scanf("%d", &res);
  for (ti = 1; ti <= res; ti++)
  {
    int b;
    int d;
    int s;
    int count;
    int needV;
    int rown = 0;
    for (count = 0; count < 256; count++)
      for (needV = 0; needV < 256; needV++)
      conv[count][needV] = (opp[count][needV] = 0);


    scanf("%d ", &b);
    for (count = 0; count < b; count++)
    {
      char r;
      char y;
      char z;
      scanf("%c%c%c ", &r, &y, &z);
      conv[r][y] = (conv[y][r] = z);
    }

    scanf("%d ", &d);
    for (count = 0; count < d; count++)
    {
      char r;
      char y;
      scanf("%c%c ", &r, &y);
      opp[r][y] = (opp[y][r] = 1);
    }

    scanf("%d ", &s);
    for (count = 0; count < s; count++)
    {
      scanf("%c", &row[rown++]);
      while ((rown >= 2) && ((b = conv[row[rown - 1]][row[rown - 2]]) != 0))
      {
        row[(--rown) - 1] = b;
      }

      if (rown >= 2)
        for (needV = 0; needV < (rown - 1); needV++)
        if (opp[row[rown - 1]][row[needV]])
        rown = 0;



    }

    printf("Case #%d: [", ti);
    for (count = 0; count < rown; count++)
    {
      if (count)
        printf(", ");

      printf("%c", row[count]);
    }

    printf("]\n");
  }

  return 0;
}


