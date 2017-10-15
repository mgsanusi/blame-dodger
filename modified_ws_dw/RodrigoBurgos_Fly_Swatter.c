#include <stdio.h>
#include <string.h>
int list[1001];
int list2[1001];
int compare(int *a, int *b)
{
  int first_iteration;
  return (*a) - (*b);
}

int main()
{
  int first_iteration;
  int x;
  int y;
  int n;
  int casos;
  int set = 1;
  int a;
  int b;
  long long res;
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  for (scanf("%d", &casos); casos--;)
  {
    scanf("%d", &n);
    for (x = 0; x < n; x++)
      scanf("%d", &list[x]);

    qsort(list, n, sizeof(int), compare);
    for (x = 0; x < n; x++)
      scanf("%d", &list2[x]);

    qsort(list2, n, sizeof(int), compare);
    a = 0;
    b = n - 1;
    res = 0;
    for (x = 0; x < n; x++)
      res += ((long long) list[x]) * ((long long) list2[(n - x) - 1]);

    printf("Case #%d: %I64d\n", set++, res);
  }

  return 0;
}


