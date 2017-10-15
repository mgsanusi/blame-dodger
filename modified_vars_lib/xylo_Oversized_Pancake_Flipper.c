#include <stdio.h>
#include <string.h>
int clearForward(char *val, int f, int r)
{
  int ii = 0;
  if (f < r)
    return 9999;

  for (int i = 0; i <= (f - r); ++i)
  {
    if (val[i] != '+')
    {
      ii++;
      for (int ans = i; ans < (i + r); ++ans)
        val[ans] = val[ans] == '+' ? '-' : '+';

    }

  }

  for (int i = (f - r) + 1; i < f; ++i)
  {
    if (val[i] != '+')
      return 9999;

  }

  return ii;
}

void clearTestCase(int l, char *val, int r)
{
  int f = strlen(val);
  int nFlips;
  int nFlips1;
  int nFlips2;
  char sReversed[1001];
  for (int i = 0; i < f; ++i)
  {
    sReversed[i] = val[(f - 1) - i];
  }

  sReversed[f] = '\0';
  nFlips1 = clearForward(val, f, r);
  nFlips2 = clearForward(sReversed, f, r);
  nFlips = nFlips1 < nFlips2 ? nFlips1 : nFlips2;
  if (nFlips == 9999)
    printf("Case #%d: IMPOSSIBLE\n", l);
  else
    printf("Case #%d: %d\n", l, nFlips);

}

int Main(void)
{
  int nTrialCase;
  scanf("%d", &nTrialCase);
  for (int i = 0; i < nTrialCase; ++i)
  {
    char val[102];
    int r;
    scanf("%s %d", val, &r);
    clearTestCase(i + 1, val, r);
  }

  return 0;
}


