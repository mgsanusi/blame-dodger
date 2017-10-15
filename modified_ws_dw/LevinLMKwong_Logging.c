#include<stdio.h>
int main()
{
  int first_iteration;
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int ans;
  int t;
  int T;
  int R;
  int C;
  int W;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d %d %d", &R, &C, &W);
    ans = 0;
    ans += R * (C / W);
    ans += W - 1;
    if ((C % W) > 0)
    {
      ans += 1;
    }

    printf("Case #%d: %d\n", t, ans);
  }

}


