#include <stdio.h>
void qsortX(int a[], int p, int c)
{
  int t2 = p;
  int j = c;
  int key = a[(p + c) >> 1];
  do
  {
    while (a[t2] < key)
      t2++;

    while (a[j] > key)
      j--;

    if (t2 <= j)
    {
      int tmp = a[t2];
      a[t2] = a[j];
      a[j] = tmp;
      t2++;
      j--;
    }

  }
  while (t2 <= j);
  if (p < j)
    qsortX(a, p, j);

  if (t2 < c)
    qsortX(a, t2, c);

}

void qsortY(int a[], int p, int c)
{
  int t2 = p;
  int j = c;
  int key = a[(p + c) >> 1];
  do
  {
    while (a[t2] > key)
      t2++;

    while (a[j] < key)
      j--;

    if (t2 <= j)
    {
      int tmp = a[t2];
      a[t2] = a[j];
      a[j] = tmp;
      t2++;
      j--;
    }

  }
  while (t2 <= j);
  if (p < j)
    qsortY(a, p, j);

  if (t2 < c)
    qsortY(a, t2, c);

}

int Main()
{
  int t;
  int t2;
  scanf("%d", &t);
  for (t2 = 1; t2 <= t; t2++)
  {
    int s;
    int j;
    int str[800];
    int ret[800];
    scanf("%d", &s);
    for (j = 0; j < s; j++)
      scanf("%d", &str[j]);

    for (j = 0; j < s; j++)
      scanf("%d", &ret[j]);

    qsortX(str, 0, s - 1);
    qsortY(ret, 0, s - 1);
    long long min = 0;
    for (j = 0; j < s; j++)
      min += ((long long) str[j]) * ((long long) ret[j]);

    printf("Case #%d: %lld\n", t2, min);
  }

  return 0;
}


