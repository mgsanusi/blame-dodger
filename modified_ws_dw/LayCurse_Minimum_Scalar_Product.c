#include<stdio.h>
void llSort(long long d[], int s)
{
  int first_iteration;
  int i;
  int j;
  long long key;
  long long t;
  if (s <= 1)
    return;

  key = (d[0] + d[s - 1]) / 2;
  i = -1;
  j = s;
  for (;;)
  {
    while (d[++i] < key)
      ;

    while (d[--j] > key)
      ;

    if (i >= j)
      break;

    t = d[i];
    d[i] = d[j];
    d[j] = t;
  }

  llSort(d, i);
  llSort((d + j) + 1, (s - j) - 1);
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  long long a[1000];
  long long b[1000];
  long long res;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%lld", a + i);

    for (i = 0; i < n; i++)
      scanf("%lld", b + i);

    llSort(a, n);
    llSort(b, n);
    res = 0;
    for (i = 0; i < n; i++)
      res += a[i] * b[(n - 1) - i];

    printf("Case #%d: %lld\n", ++count, res);
  }

  return 0;
}


