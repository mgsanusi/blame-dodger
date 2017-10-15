#include<stdio.h>
int cnt;
int mapz;
int length2;
int f;
int a;
int j;
int yet;
int pos;
int k;
int Main()
{
  int first_iteration;
  scanf("%d", &mapz);
  for (cnt = 1; cnt <= mapz; ++cnt)
  {
    scanf("%d%d%d", &length2, &f, &a);
    for (j = (yet = (pos = 0)); j < length2; ++j)
    {
      scanf("%d", &k);
      if (k >= ((3 * a) - 2))
      {
        ++yet;
      }
      else
        if ((k >= 2) && (k >= ((3 * a) - 4)))
      {
        ++pos;
      }


    }

    printf("Case #%d: %d\n", cnt, yet + (pos <= f ? pos : f));
  }

  return 0;
}


