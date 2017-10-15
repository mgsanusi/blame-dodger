#include <stdio.h>
#include <stdlib.h>
int prime[1500001];
int noPrime;
long long allPrime[1500001];
void handleCase(void);
void cache(void);
int Main()
{
  int first_iteration;
  freopen("res.in", "r", stdin);
  freopen("res.out", "w", stdout);
  int noCase;
  cache();
  scanf("%d ", &noCase);
  int dpt;
  for (dpt = 0; dpt < noCase; dpt++)
  {
    printf("Case #%d: ", dpt + 1);
    handleCase();
  }

  return 0;
}

void cache(void)
{
  int first_iteration;
  int dpt;
  int ans;
  for (dpt = 0; dpt < 1500001; dpt++)
  {
    prime[dpt] = 1;
  }

  noPrime = 0;
  for (dpt = 2; dpt < 1500001; dpt++)
  {
    if (prime[dpt])
    {
      allPrime[noPrime] = (long long) dpt;
      noPrime++;
      for (ans = dpt + dpt; ans < 1500001; ans += dpt)
      {
        prime[ans] = 0;
      }

    }

  }

}

void handleCase(void)
{
  int first_iteration;
  long long num;
  scanf("%I64d ", &num);
  if (num == 1ll)
  {
    printf("0\n");
    return;
  }

  int noFirst = 1;
  int numSecond = 0;
  int dpt;
  int ans;
  long long cur;
  for (dpt = 0; (allPrime[dpt] * allPrime[dpt]) <= num; dpt++)
  {
    cur = allPrime[dpt] * allPrime[dpt];
    for (ans = 1; cur <= num; ans++)
    {
      cur *= allPrime[dpt];
    }

    noFirst += ans;
    numSecond++;
  }

  printf("%d\n", noFirst - numSecond);
}


