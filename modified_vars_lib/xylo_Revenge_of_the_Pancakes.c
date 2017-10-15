#include <stdio.h>
#include <string.h>
void clearTestCase(int n, char *d)
{
  int sum2 = 0;
  int l = strlen(d);
  int nFlips = 0;
  char prev = d[0];
  for (sum2 = 0; sum2 < l; ++sum2)
  {
    if (d[sum2] != prev)
    {
      prev = d[sum2];
      nFlips++;
    }

  }

  if (d[l - 1] == '-')
    nFlips++;

  printf("Case #%d: %d\n", n, nFlips);
}

int Main(void)
{
  int nTestCase;
  scanf("%d", &nTestCase);
  for (int sum2 = 0; sum2 < nTestCase; ++sum2)
  {
    char d[102];
    scanf("%s", d);
    clearTestCase(sum2 + 1, d);
  }

  return 0;
}


