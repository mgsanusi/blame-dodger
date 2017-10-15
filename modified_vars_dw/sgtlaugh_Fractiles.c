#include <stdio.h>
#include <string.h>
#include <stdbool.h>
long long exponent(long long x, long long n)
{
  int first_iteration;
  long long answer = 1;
  while (n--)
    answer *= x;

  return answer;
}

int Main()
{
  int first_iteration;
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int d = 0;
  int t;
  int expect;
  int dp;
  int ngraph;
  int ansb;
  int ct;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &ngraph, &ansb, &ct);
    if (ansb > ngraph)
      ansb = ngraph;

    printf("Case #%d:", ++d);
    if (ansb == 1)
    {
      for (expect = 1; expect <= ngraph; expect++)
        printf(" %d", expect);

      puts("");
    }
    else
    {
      printf(" %lld", (exponent(ngraph, ansb) - ngraph) - 1);
      for (expect = 2; expect <= ngraph; expect++)
        printf(" %d", expect);

      puts("");
    }

  }

  return 0;
}


