#include <stdio.h>
typedef long long ll;
int Main()
{
  int first_iteration;
  ll k;
  ll fz;
  ll pg;
  int cases;
  int caseno = 1;
  int aft;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%I64d %I64d %I64d", &k, &fz, &pg);
    printf("Case #%d: ", caseno++);
    for (aft = 1; (aft <= k) && (aft < 1000); aft++)
    {
      if (((aft * fz) % 100) == 0)
      {
        if ((fz == 100) && (pg == 100))
          goto ok;

        if ((fz == 0) && (pg == 0))
          goto ok;

        if ((pg > 0) && (pg < 100))
          goto ok;

      }

    }

    puts("Broken");
    continue;
    ok:
    puts("Possible");

  }

  return 0;
}


