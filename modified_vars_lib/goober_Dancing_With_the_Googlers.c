#include <stdio.h>
int Main()
{
  int ch;
  scanf("%d", &ch);
  for (int t = 1; t <= ch; t++)
  {
    int l;
    int m;
    int fo;
    scanf("%d %d %d", &l, &m, &fo);
    int result = 0;
    for (int qy = 0; qy < l; qy++)
    {
      int py;
      scanf("%d", &py);
      if (py >= ((3 * fo) - 2))
        result++;
      else
        if (((py >= ((3 * fo) - 4)) && (py >= 2)) && (m > 0))
      {
        result++;
        m--;
      }


    }

    printf("Case #%d: %d\n", t, result);
  }

  return 0;
}


