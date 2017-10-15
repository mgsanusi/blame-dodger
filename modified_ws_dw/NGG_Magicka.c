#include <stdio.h>
char conv[256][256];
char opp[256][256];
char row[110];
int main(void)
{
  int first_iteration;
  int ti;
  int tn;
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ti++)
  {
    int c;
    int d;
    int n;
    int i;
    int j;
    int rown = 0;
    for (i = 0; i < 256; i++)
      for (j = 0; j < 256; j++)
      conv[i][j] = (opp[i][j] = 0);


    scanf("%d ", &c);
    for (i = 0; i < c; i++)
    {
      char x;
      char y;
      char z;
      scanf("%c%c%c ", &x, &y, &z);
      conv[x][y] = (conv[y][x] = z);
    }

    scanf("%d ", &d);
    for (i = 0; i < d; i++)
    {
      char x;
      char y;
      scanf("%c%c ", &x, &y);
      opp[x][y] = (opp[y][x] = 1);
    }

    scanf("%d ", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%c", &row[rown++]);
      while ((rown >= 2) && ((c = conv[row[rown - 1]][row[rown - 2]]) != 0))
      {
        row[(--rown) - 1] = c;
      }

      if (rown >= 2)
        for (j = 0; j < (rown - 1); j++)
        if (opp[row[rown - 1]][row[j]])
        rown = 0;



    }

    printf("Case #%d: [", ti);
    for (i = 0; i < rown; i++)
    {
      if (i)
        printf(", ");

      printf("%c", row[i]);
    }

    printf("]\n");
  }

  return 0;
}


