#include <stdio.h>
#include <math.h>
int Main()
{
  int first_iteration;
  int tc;
  int __;
  scanf("%d", &tc);
  for (__ = 1; __ <= tc; __++)
  {
    int n;
    int a1[10001];
    int b[10001];
    int s[10001] = {0};
    int d;
    scanf("%d", &n);
    int k2;
    for (k2 = 0; k2 < n; k2++)
      scanf("%d %d", a1 + k2, b + k2);

    scanf("%d", a1 + k2);
    b[n] = 0;
    s[n] = -1;
    s[0] = a1[0];
    int area2;
    for (k2 = 0; k2 < n; k2++)
    {
      for (area2 = k2 + 1; area2 <= n; area2++)
      {
        if (s[k2] < (a1[area2] - a1[k2]))
          break;

        int temp = a1[area2] - a1[k2];
        if (temp > b[area2])
          temp = b[area2];

        if (temp > s[area2])
          s[area2] = temp;

      }

    }

    printf("Case #%d: ", __);
    if (s[n] >= 0)
      printf("YES\n");
    else
      printf("NO\n");

  }

  return 0;
}


