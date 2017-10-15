#include <stdio.h>
#include <assert.h>
#include <string.h>
int strStart[1000][1000];
int h[1000];
int x[1000];
void new_assert(int expression);

void clear(void)
{
  int b;
  int t;
  int i;
  int isOk;
  new_assert(scanf("%d%d", &b, &t) == 2);
  for (i = 0; i < b; i++)
    h[i] = 0;

  for (isOk = 0; isOk < t; isOk++)
    x[isOk] = 0;

  for (i = 0; i < b; i++)
    for (isOk = 0; isOk < t; isOk++)
  {
    new_assert(scanf("%d", &strStart[i][isOk]) == 1);
    if (strStart[i][isOk] > h[i])
    {
      h[i] = strStart[i][isOk];
    }

    if (strStart[i][isOk] > x[isOk])
    {
      x[isOk] = strStart[i][isOk];
    }

  }


  for (i = 0; i < b; i++)
    for (isOk = 0; isOk < t; isOk++)
    if ((strStart[i][isOk] != h[i]) && (strStart[i][isOk] != x[isOk]))
  {
    printf("NO\n");
    return;
  }



  printf("YES\n");
}

int Main()
{
  int _;
  new_assert(scanf("%d\n", &_) > 0);
  int row;
  for (row = 0; row < _; row++)
  {
    printf("Case #%d: ", row + 1);
    clear();
  }

  return 0;
}



void new_assert(int expression) {
  return assert(expression);
}