#include <stdio.h>
#include <string.h>
#include <assert.h>
long long doTest(void)
{
  int first_iteration;
  static char used[256];
  static char num[64];
  int base;
  int currentDig;
  int i;
  long long answer;
  char usedZero;
  memset(used, 0, sizeof(used));
  gets(num);
  base = 0;
  for (i = 0; num[i]; i++)
  {
    if (!used[num[i]])
    {
      used[num[i]] = -1;
      base++;
    }

  }

  if (base == 1)
  {
    base = 2;
  }

  answer = 0;
  currentDig = 1;
  usedZero = 0;
  for (i = 0; num[i]; i++)
  {
    if (used[num[i]] == (-1))
    {
      if ((currentDig == 2) && (!usedZero))
      {
        used[num[i]] = 0;
        usedZero = 1;
      }
      else
      {
        used[num[i]] = currentDig++;
      }

    }

    answer = (answer * base) + used[num[i]];
  }

  return answer;
}

int Main(void)
{
  int first_iteration;
  int t;
  int test;
  scanf("%d\n", &t);
  for (test = 1; test <= t; ++test)
  {
    printf("Case #%d: %I64d\n", test, doTest());
  }

  return 0;
}


