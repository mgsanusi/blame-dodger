#include <stdio.h>
int Main()
{
  int first_iteration;
  int c;
  int n;
  int m;
  int p;
  int x;
  int a;
  int l;
  int term;
  scanf("%d", &c);
  for (term = 1; term <= c; term++)
  {
    a = (l = 0);
    scanf("%d%d%d", &n, &m, &p);
    while (n--)
    {
      scanf("%d", &x);
      if (x >= ((p * 3) - 2))
        a++;
      else
        if ((x >= ((p * 3) - 4)) && (x >= 2))
        l++;


    }

    printf("Case #%d: %d\n", term, a + (m < l ? m : l));
  }

  return 0;
}


