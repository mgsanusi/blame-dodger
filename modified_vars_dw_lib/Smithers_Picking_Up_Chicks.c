#include <stdio.h>
int Main()
{
  int first_iteration;
  int buf;
  int n;
  int k;
  int b;
  int t;
  int d[10];
  int m[10];
  int casenum;
  int save;
  int unsaved;
  int swaps;
  int area;
  scanf("%d", &buf);
  for (casenum = 1; casenum <= buf; casenum++)
  {
    scanf("%d%d%d%d", &n, &k, &b, &t);
    for (area = 0; area < n; area++)
      scanf("%d", &d[area]);

    for (area = 0; area < n; area++)
      scanf("%d", &m[area]);

    save = (unsaved = (swaps = 0));
    for (area = n - 1; (area >= 0) && (save < k); area--)
      if ((t * m[area]) >= (b - d[area]))
      save++, swaps += unsaved;
    else
      unsaved++;


    if (save == k)
      printf("Case #%d: %d\n", casenum, swaps);
    else
      printf("Case #%d: IMPOSSIBLE\n", casenum);

  }

  return 0;
}


