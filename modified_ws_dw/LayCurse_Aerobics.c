#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int t[2000];
  int p[2000];
  int ind[2000];
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    printf("Case #%d:", ++count);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d", t + i);

    for (i = 0; i < n; i++)
      scanf("%d", p + i);

    for (i = 0; i < n; i++)
      ind[i] = i;

    for (i = 0; i < n; i++)
      p[i] = 100 - p[i];

    for (;;)
    {
      int fg = 0;
      for (i = 1; i < n; i++)
      {
        if (((t[i - 1] * 100) + (t[i] * p[i - 1])) > ((t[i] * 100) + (t[i - 1] * p[i])))
        {
          fg = 1;
          k = t[i - 1], t[i - 1] = t[i], t[i] = k;
          k = p[i - 1], p[i - 1] = p[i], p[i] = k;
          k = ind[i - 1], ind[i - 1] = ind[i], ind[i] = k;
        }

      }

      if (!fg)
        break;

    }

    for (i = 0; i < n; i++)
      printf(" %d", ind[i]);

    puts("");
  }

  return 0;
}


