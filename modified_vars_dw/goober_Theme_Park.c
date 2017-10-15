#include <stdio.h>
int Main()
{
  int first_iteration;
  int num;
  int c;
  scanf("%d", &num);
  for (c = 1; c <= num; c++)
  {
    int r;
    int p;
    int n;
    int caseno;
    long long lastval[1000];
    int lastride[1000];
    int o[1000];
    int gin;
    int d;
    int rides;
    int firstgr;
    char timejump;
    long long total;
    scanf("%d %d %d", &r, &p, &n);
    for (caseno = 0; caseno < n; caseno++)
    {
      lastval[caseno] = -1;
      lastride[caseno] = -1;
      scanf("%d", &o[caseno]);
    }

    total = 0;
    rides = -1;
    gin = 0;
    d = 0;
    firstgr = 0;
    timejump = 0;
    while (rides < r)
    {
      if (((gin + o[d]) > p) || (d == firstgr))
      {
        total += gin;
        gin = 0;
        rides++;
        if ((!timejump) && (lastval[d] != (-1)))
        {
          long long master = rides - lastride[d];
          long long skipval = total - lastval[d];
          long long skipcount = (r - rides) / master;
          total += skipcount * skipval;
          rides += skipcount * master;
          timejump = 1;
        }

        lastride[d] = rides;
        lastval[d] = total;
        firstgr = d;
      }

      gin += o[d];
      if ((++d) >= n)
        d = 0;

    }

    printf("Case #%d: %lld\n", c, total);
  }

  return 0;
}


