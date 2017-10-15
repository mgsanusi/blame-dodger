#include <stdio.h>
int Main()
{
  int cases;
  scanf("%d", &cases);
  for (int num = 1; num <= cases; num++)
  {
    int buff;
    scanf("%d\n", &buff);
    int vals = ((2 * buff) - 1) * buff;
    int cnt[2501] = {0};
    for (int j = 0; j < vals; j++)
    {
      int heapn;
      scanf("%d", &heapn);
      cnt[heapn]++;
    }

    int j[50];
    int qy = 0;
    for (int j = 0; j < 2501; j++)
    {
      if (cnt[j] & 1)
      {
        int max_time = qy++;
        while (max_time && (j < j[max_time - 1]))
        {
          j[max_time] = j[max_time - 1];
          max_time--;
        }

        j[max_time] = j;
      }

    }

    printf("Case #%d:", num);
    for (int j = 0; j < buff; j++)
    {
      printf(" %d", j[j]);
    }

    printf("\n");
  }

}


