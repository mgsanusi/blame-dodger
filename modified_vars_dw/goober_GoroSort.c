#include <stdio.h>
int Main()
{
  int first_iteration;
  int x;
  scanf("%d", &x);
  for (int t = 1; t <= x; t++)
  {
    int good = 0;
    unsigned long long k;
    unsigned long long place;
    unsigned long long res;
    scanf("%lld %lld %lld", &k, &place, &res);
    if ((res == 100) || (res == 0))
      good = place == res;
    else
      if (k >= 100)
      good = 1;
    else
      for (int c = 1; c <= k; c++)
      if (((c * place) % 100) == 0)
      good = 1;




    printf("Case #%d: %s\n", t, good ? "Possible" : "Broken");
  }

  return 0;
}


