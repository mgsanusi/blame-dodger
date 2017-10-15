#include <stdio.h>
typedef long long ll;
int Main()
{
  int first_iteration;
  ll l;
  ll pd;
  ll pg;
  int cases;
  int caseno = 1;
  int rxi;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%I64d %I64d %I64d", &l, &pd, &pg);
    printf("Case #%d: ", caseno++);
    for (rxi = 1; (rxi <= l) && (rxi < 1000); rxi++)
    {
      if (((rxi * pd) % 100) == 0)
      {
        if ((pd == 100) && (pg == 100))
          goto ok;

        if ((pd == 0) && (pg == 0))
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


