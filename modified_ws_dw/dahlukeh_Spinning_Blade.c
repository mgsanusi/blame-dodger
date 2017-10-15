#include <stdio.h>
#include <stdlib.h>
int primes[1500001];
int numPrimes;
long long allPrimes[1500001];
void handleCase(void);
void cache(void);
int main()
{
  int first_iteration;
  freopen("res.in", "r", stdin);
  freopen("res.out", "w", stdout);
  int numCases;
  cache();
  scanf("%d ", &numCases);
  int i;
  for (i = 0; i < numCases; i++)
  {
    printf("Case #%d: ", i + 1);
    handleCase();
  }

  return 0;
}

void cache(void)
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < 1500001; i++)
  {
    primes[i] = 1;
  }

  numPrimes = 0;
  for (i = 2; i < 1500001; i++)
  {
    if (primes[i])
    {
      allPrimes[numPrimes] = (long long) i;
      numPrimes++;
      for (j = i + i; j < 1500001; j += i)
      {
        primes[j] = 0;
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

  int numFirst = 1;
  int numSecond = 0;
  int i;
  int j;
  long long cur;
  for (i = 0; (allPrimes[i] * allPrimes[i]) <= num; i++)
  {
    cur = allPrimes[i] * allPrimes[i];
    for (j = 1; cur <= num; j++)
    {
      cur *= allPrimes[i];
    }

    numFirst += j;
    numSecond++;
  }

  printf("%d\n", numFirst - numSecond);
}


