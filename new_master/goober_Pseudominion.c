#include <stdio.h>

char iprime[1000000];
int prime[100000];
int cnt = 0;

int main()
{
  iprime[0] = 1;
  iprime[1] = 1;
  for (int i=2; i<1000000; i++)
    if (iprime[i])
      continue;
    else
    {
      prime[cnt++] = i;
      for (int j=i; j<1000000; j += i)
        iprime[j] = 1;
    }
    
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int n;
    scanf("%d", &n);
    int res = 0;
    for (int i=0; prime[i]*prime[i]<=n; i++)
    {
      int p = prime[i];
      int nn = n/p;
      while(nn >= p)
      {
        res++;
        nn /= p;
      }
    }
    printf("Case #%d: %d\n", t, res + (n > 1));
  }
  return 0;
}
