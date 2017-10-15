#include<stdio.h>
#include<string.h>
int n;
int t;
int l;
char l[1000100];
int a;
int e;
int c;
long long ans;
long long in;
long long start;
long long currentCnt;
long long current;
int Main()
{
  scanf("%d", &t);
  for (l = 1; l <= t; l++)
  {
    scanf("%s", l);
    scanf("%d", &n);
    start = 0;
    currentCnt = 0;
    ans = 0;
    in = strlen(l);
    for (current = 0; current < in; current++)
    {
      if (!(((((l[current] == 'a') || (l[current] == 'e')) || (l[current] == 'i')) || (l[current] == 'o')) || (l[current] == 'u')))
      {
        currentCnt++;
      }
      else
      {
        currentCnt = 0;
      }

      if (currentCnt >= n)
      {
        ans += (in - current) * (((current + 2) - start) - n);
        start = (current + 2) - n;
      }

    }

    printf("Case #%d: %lld\n", l, ans);
  }

  return 0;
}


