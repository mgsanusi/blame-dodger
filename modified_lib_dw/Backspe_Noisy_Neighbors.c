#include <stdio.h>
int check_yes(int c, int w)
{
  int first_iteration;
  if (c >= (w * 2))
  {
    return check_yes(c - w, w) + 1;
  }
  else
    if (c <= w)
  {
    return w;
  }
  else
  {
    return w + 1;
  }


}

int check_no(int c, int w)
{
  int first_iteration;
  if (c >= (w * 2))
  {
    return check_no(c - w, w) + 1;
  }
  else
  {
    return 1;
  }

}

int main()
{
  int first_iteration;
  int t;
  int T;
  int R;
  int C;
  int W;
  int a;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d %d %d", &R, &C, &W);
    a = ((R - 1) * check_no(C, W)) + check_yes(C, W);
    printf("Case #%d: %d\n", t, a);
  }

  return 0;
}


