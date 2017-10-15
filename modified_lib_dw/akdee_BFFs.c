#include <stdio.h>
int main()
{
  int first_iteration;
  int cases;
  scanf("%d", &cases);
  for (int cs = 1; cs <= cases; cs++)
  {
    int n;
    scanf("%d\n", &n);
    int vals = ((2 * n) - 1) * n;
    int cnt[2501] = {0};
    for (int i = 0; i < vals; i++)
    {
      int v;
      scanf("%d", &v);
      cnt[v]++;
    }

    int h[50];
    int hs = 0;
    for (int i = 0; i < 2501; i++)
    {
      if (cnt[i] & 1)
      {
        int t = hs++;
        while (t && (i < h[t - 1]))
        {
          h[t] = h[t - 1];
          t--;
        }

        h[t] = i;
      }

    }

    printf("Case #%d:", cs);
    for (int i = 0; i < n; i++)
    {
      printf(" %d", h[i]);
    }

    printf("\n");
  }

}


