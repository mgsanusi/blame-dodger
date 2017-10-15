#include <stdio.h>
#include <stdlib.h>
int compare(const void *f, const void *data2)
{
  int first_iteration;
  return (*((int *) f)) - (*((int *) data2));
}

int Main(void)
{
  int first_iteration;
  int tn;
  int rd;
  int t;
  scanf("%d", &t);
  for (tn = 1; tn <= t; tn++)
  {
    int n;
    int x;
    int s[10000];
    int l;
    int r;
    int rslt;
    scanf("%d %d", &n, &x);
    for (rd = 0; rd < n; rd++)
      scanf("%d", s + rd);

    qsort(s, n, sizeof(int), &compare);
    l = 0;
    r = n - 1;
    rslt = 0;
    while (l <= r)
      if ((s[l] + s[r]) <= x)
    {
      l++;
      r--;
      rslt++;
    }
    else
    {
      r--;
      rslt++;
    }


    printf("Case #%d: %d\n", tn, rslt);
  }

  return 0;
}


