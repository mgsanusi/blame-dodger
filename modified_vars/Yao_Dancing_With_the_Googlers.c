#include<stdio.h>
int pd[10];
int pp[10000001];
int pv[10000001];
void init()
{
  int i;
  int scores;
  int k;
  int t;
  for (pd[0] = (i = 1); i < 10; i++)
    pd[i] = pd[i - 1] * 10;

  for (i = 0; i < 7; i++)
    for (scores = pd[i]; scores <= pd[i + 1]; scores++)
  {
    pp[scores] = scores;
    for (k = 0, t = scores; k < i; k++)
    {
      t = ((t % 10) * pd[i]) + (t / 10);
      if (t < pp[scores])
        pp[scores] = t;

    }

  }


}

int Main()
{
  int cases;
  int a;
  int kk;
  int i;
  int cases = 0;
  long long ret;
  init();
  for (scanf("%d", &cases); cases--;)
  {
    scanf("%d %d", &a, &kk);
    ret = 0;
    for (i = a; i <= kk; i++)
    {
      ret += pv[pp[i]];
      pv[pp[i]]++;
    }

    printf("Case #%d: %lld\n", ++cases, ret);
    for (i = a; i <= kk; i++)
      pv[pp[i]] = 0;

  }

  return 0;
}


