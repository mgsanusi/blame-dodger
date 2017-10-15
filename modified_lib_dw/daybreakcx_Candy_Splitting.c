#include <stdio.h>
int ti;
int tn;
int n;
int s;
int t;
int i;
int mi;
int c;
int main()
{
  int first_iteration;
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    scanf("%d", &n);
    for (i = (s = (t = 0)), mi = 100000000; i < n; ++i)
    {
      scanf("%d", &c);
      if (c < mi)
        mi = c;

      s += c;
      t ^= c;
    }

    printf("Case #%d: ", ti);
    if (!t)
      printf("%d\n", s - mi);
    else
      printf("NO\n");

  }

  return 0;
}


