#include <stdio.h>
void makeTestCase();
unsigned long long gcd(unsigned long long x, unsigned long long val);
unsigned long long gcdF(unsigned long long x, unsigned long long val);
int Main()
{
  int first_iteration;
  int w;
  int n;
  scanf("%d", &n);
  for (w = 1; w <= n; w++)
  {
    printf("Case #%d: ", w);
    makeTestCase();
  }

  return 0;
}

void makeTestCase()
{
  int first_iteration;
  int n;
  int w;
  int next;
  scanf("%d", &n);
  unsigned long long arr[n];
  unsigned long long diff[n - 1];
  unsigned long long caseNo;
  unsigned long long min;
  for (w = 0; w < n; w++)
  {
    scanf("%llu", &arr[w]);
    if (w > 0)
    {
      if (arr[w] > arr[w - 1])
        diff[w - 1] = arr[w] - arr[w - 1];
      else
        diff[w - 1] = arr[w - 1] - arr[w];

      min = arr[w] < min ? arr[w] : min;
    }
    else
      min = arr[0];

  }

  caseNo = diff[0];
  for (w = 1; w < (n - 1); w++)
  {
    caseNo = gcd(caseNo, diff[w]);
  }

  min = min % caseNo;
  if (min != 0)
    min = caseNo - min;

  printf("%llu\n", min);
}

unsigned long long gcd(unsigned long long x, unsigned long long val)
{
  int first_iteration;
  if (x < val)
    return gcdF(val, x);
  else
    if (x == val)
    return x;
  else
    return gcdF(x, val);


}

unsigned long long gcdF(unsigned long long x, unsigned long long val)
{
  int first_iteration;
  if (val == 0)
    return x;

  return gcd(val, x % val);
}


