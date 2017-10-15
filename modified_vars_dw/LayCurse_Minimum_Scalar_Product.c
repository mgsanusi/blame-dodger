#include<stdio.h>
void ll_sort(long long ny[], int s)
{
  int first_iteration;
  int i;
  int j;
  long long key;
  long long t;
  if (s <= 1)
    return;

  key = (ny[0] + ny[s - 1]) / 2;
  i = -1;
  j = s;
  for (;;)
  {
    while (ny[++i] < key)
      ;

    while (ny[--j] > key)
      ;

    if (i >= j)
      break;

    t = ny[i];
    ny[i] = ny[j];
    ny[j] = t;
  }

  ll_sort(ny, i);
  ll_sort((ny + j) + 1, (s - j) - 1);
}

int Main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int test_case;
  int n;
  long long envp[1000];
  long long b[1000];
  long long result;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%lld", envp + i);

    for (i = 0; i < n; i++)
      scanf("%lld", b + i);

    ll_sort(envp, n);
    ll_sort(b, n);
    result = 0;
    for (i = 0; i < n; i++)
      result += envp[i] * b[(n - 1) - i];

    printf("Case #%d: %lld\n", ++count, result);
  }

  return 0;
}


