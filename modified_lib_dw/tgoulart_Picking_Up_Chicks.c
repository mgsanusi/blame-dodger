#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int caso = 1;
  int n;
  int i;
  int j;
  int ans;
  int a[1005];
  int b[1005];
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%d %d", &a[i], &b[i]);
    }

    ans = 0;
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if ((b[j] < b[i]) && (a[j] > a[i]))
        {
          ans++;
        }

      }

    }

    printf("Case #%d: %d\n", caso++, ans);
  }

  return 0;
}


