#include <stdio.h>
#include <stdlib.h>
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int compare(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

int main(void)
{
  int first_iteration;
  int i;
  int j;
  int t;
  scanf("%d", &t);
  for (i = 1; i <= t; i++)
  {
    int n;
    int x;
    int s[10000];
    int l;
    int r;
    int ans;
    scanf("%d %d", &n, &x);
    for (j = 0; j < n; j++)
      scanf("%d", s + j);

    new_qsort(s, n, sizeof(int), &compare);
    l = 0;
    r = n - 1;
    ans = 0;
    while (l <= r)
      if ((s[l] + s[r]) <= x)
    {
      l++;
      r--;
      ans++;
    }
    else
    {
      r--;
      ans++;
    }


    printf("Case #%d: %d\n", i, ans);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


