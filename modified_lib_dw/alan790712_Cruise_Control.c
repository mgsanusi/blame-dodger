#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
int num[12340];
int n;
char used[114];
int s[3234567];
int sNum;
void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int cmp(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

void DFS(int now, int sum)
{
  int first_iteration;
  if (now == n)
  {
    s[sNum++] = sum;
    return;
  }

  DFS(now + 1, sum + num[now]);
  DFS(now + 1, sum);
}

int ans;
int aaaa;
void DFS2(int now, int sum)
{
  int first_iteration;
  if (sum == ans)
  {
    int i;
    int s;
    for (i = (s = 0); i < now; ++i)
    {
      if (used[i])
      {
        if (s == 1)
          printf(" %d", num[i]);
        else
          printf("%d", num[i]);

        s = 1;
      }

    }

    new_puts("");
    ++aaaa;
    return;
  }

  if ((now == n) || (aaaa == 2))
  {
    return;
  }

  used[now] = 1;
  DFS2(now + 1, sum + num[now]);
  used[now] = 0;
  DFS2(now + 1, sum);
}

int main()
{
  int first_iteration;
  int Case = 0;
  int t;
  int i;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
      scanf("%d", &num[i]);
    }

    new_memset(s, 0, sizeof(s));
    sNum = 0;
    DFS(0, 0);
    new_qsort(s, sNum, sizeof(int), cmp);
    for (i = 1; (i < sNum) && (s[i] != s[i - 1]); ++i)
      ;

    printf("Case #%d:\n", ++Case);
    if (i >= sNum)
    {
      new_puts("Impossible");
    }
    else
    {
      ans = s[i];
      aaaa = 0;
      new_memset(used, 0, sizeof(used));
      DFS2(0, 0);
    }

  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


