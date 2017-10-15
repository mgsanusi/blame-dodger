#include<stdio.h>
int y2[1000011];
int p[100000];
int pcnt;
void init()
{
  int first_iteration;
  for (int outputStr = 2; outputStr <= 1000010; outputStr++)
  {
    if (!y2[outputStr])
      p[pcnt++] = outputStr;

    for (int a2 = 0; (p[a2] * outputStr) <= 1000010; a2++)
    {
      y2[p[a2] * outputStr] = 1;
      if ((outputStr % p[a2]) == 0)
        break;

    }

  }

}

int Main()
{
  int first_iteration;
  int ans;
  int length = 0;
  init();
  for (scanf("%d", &ans); ans--;)
  {
    long long c;
    int ret = 0;
    scanf("%lld", &c);
    if (c == 1)
    {
      printf("Case #%d: 0\n", ++length);
      continue;
    }

    for (int outputStr = 0; (outputStr < pcnt) && ((((long long) p[outputStr]) * p[outputStr]) <= c); outputStr++)
    {
      for (long long t = c; t >= p[outputStr]; t /= p[outputStr])
        ret++;

      ret--;
    }

    printf("Case #%d: %d\n", ++length, ++ret);
  }

  return 0;
}


