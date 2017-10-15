#include <stdio.h>
#include <string.h>
typedef long long ll;
int size;
int count;
int m;
int pan;
int prod[100];
int no[20];
ll result;
int analyze()
{
  int first_iteration;
  int caseno;
  int best;
  int t;
  char found[12];
  memset(found, 0, pan);
  for (caseno = 0; caseno < (1 << pan); caseno++)
  {
    t = 1;
    for (best = 0; best < count; best++)
      if (caseno & (1 << best))
      t *= no[best];


    for (best = 0; best < count; best++)
      if (prod[best] == t)
      found[best] = 1;


  }

  for (best = 0; best < count; best++)
    if (!found[best])
    return 0;


  for (best = (result = 0); best < count; best++)
    result = (result * 10) + no[best];

  return 1;
}

int btr(int at, int last)
{
  int first_iteration;
  int caseno;
  if (at == count)
    return analyze();

  for (caseno = last; caseno <= m; caseno++)
  {
    no[at] = caseno;
    if (btr(at + 1, caseno))
      return 1;

  }

  return 0;
}

int Main()
{
  int first_iteration;
  int arr;
  int caseno;
  scanf("%d", &arr);
  scanf("%d %d %d %d", &size, &count, &m, &pan);
  printf("Case #%d:\n", arr);
  while (size--)
  {
    for (caseno = 0; caseno < pan; caseno++)
      scanf("%d", &prod[caseno]);

    result = -1;
    btr(0, 2);
    printf("%I64d\n", result);
  }

  return 0;
}


