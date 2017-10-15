#include <stdio.h>
#include <stdlib.h>
int Main()
{
  int first_iteration;
  int z;
  int s;
  int no;
  int k;
  int casos;
  int sum;
  unsigned long long n;
  unsigned long long kc;
  scanf("%u", &s);
  for (z = 1; z <= s; z++)
  {
    scanf("%d %d %d", &k, &casos, &sum);
    for (kc = 1, no = 1; no < casos; no++)
      kc *= k;

    printf("Case #%d:", z);
    for (n = 0, no = 0; no < sum; no++)
    {
      printf(" %llu", n + 1);
      n += kc;
    }

    printf("\n");
  }

}


