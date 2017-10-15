#include <stdio.h>
int nextpermutation(int *a, int n)
{
  int first_iteration;
  int j;
  int k;
  int i;
  int t;
  for (j = n - 2; (j > (-1)) && (a[j] >= a[j + 1]); j--)
    ;

  if (j < 0)
    return 0;

  for (i = n - 1; a[j] >= a[i]; i--)
    ;

  t = a[j];
  a[j] = a[i];
  a[i] = t;
  for (k = j + 1, i = n - 1; k < i; k++, i--)
    t = a[k], a[k] = a[i], a[i] = t;

  return 1;
}

int bff[1111];
int n;
int a[1111];
int check(int len)
{
  int first_iteration;
  int i;
  int b;
  for (i = 0; i < len; i++)
  {
    b = bff[a[i]];
    if ((b != a[(i + 1) % len]) && (b != a[((i + len) - 1) % len]))
      return 0;

  }

  return 1;
}

void solve()
{
  int first_iteration;
  int i;
  int best = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &bff[i]), bff[i]--;

  for (i = 0; i < n; i++)
    a[i] = i;

  first_iteration = 1;
  while (nextpermutation(a, n) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    for (i = 1; i <= n; i++)
      if (check(i) && (best < i))
      best = i;


  }

  printf("%d\n", best);
}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", caseno++), solve();

  return 0;
}


