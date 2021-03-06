#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a;
int b;
int digit;
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int n[1234];
int nNum;
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int cmp(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

int check(int num)
{
  int first_iteration;
  int i;
  int ans = 0;
  nNum = 0;
  for (i = 1; i < digit; ++i)
  {
    n[nNum] = ((num % ten[i]) * ten[digit - i]) + (num / ten[i]);
    if (((n[nNum] >= a) && (n[nNum] <= b)) && (n[nNum] < num))
    {
      ++nNum;
    }

  }

  new_qsort(n, nNum, sizeof(int), cmp);
  ans = nNum > 0;
  for (i = 1; i < nNum; ++i)
  {
    if (n[i] != n[i - 1])
      ++ans;

  }

  return ans;
}

int main()
{
  int first_iteration;
  int t;
  int i;
  int ans;
  int Case = 0;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &a, &b);
    for (i = a, digit = 0; i > 0; i /= 10, ++digit)
      ;

    for (i = a, ans = 0; i <= b; ++i)
    {
      ans += check(i);
    }

    printf("Case #%d: %d\n", ++Case, ans);
  }

  return 0;
}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


