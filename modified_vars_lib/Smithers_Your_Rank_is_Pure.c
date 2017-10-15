#include <stdio.h>
int Main()
{
  int c;
  int n;
  int z;
  int b;
  int t;
  int e[50];
  int v[50];
  int casenum;
  int save;
  int unsaved;
  int swaps;
  int i;
  scanf("%d", &c);
  for (casenum = 1; casenum <= c; casenum++)
  {
    scanf("%d%d%d%d", &n, &z, &b, &t);
    for (i = 0; i < n; i++)
      scanf("%d", &e[i]);

    for (i = 0; i < n; i++)
      scanf("%d", &v[i]);

    save = (unsaved = (swaps = 0));
    for (i = n - 1; (i >= 0) && (save < z); i--)
      if ((t * v[i]) >= (b - e[i]))
      save++, swaps += unsaved;
    else
      unsaved++;


    if (save == z)
      printf("Case #%d: %d\n", casenum, swaps);
    else
      printf("Case #%d: IMPOSSIBLE\n", casenum);

  }

  return 0;
}


