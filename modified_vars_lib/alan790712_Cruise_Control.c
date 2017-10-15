#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stddef.h>
int no[12340];
int dx;
char use[114];
int s[3234567];
int sNo;
void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *in, const void *b)
{
  return (*((int *) in)) - (*((int *) b));
}

void dfs(int now, int sum)
{
  if (now == dx)
  {
    s[sNo++] = sum;
    return;
  }

  dfs(now + 1, sum + no[now]);
  dfs(now + 1, sum);
}

int ans;
int aaaa;
void dfs2(int now, int sum)
{
  if (sum == ans)
  {
    int t1;
    int s;
    for (t1 = (s = 0); t1 < now; ++t1)
    {
      if (use[t1])
      {
        if (s == 1)
          printf(" %d", no[t1]);
        else
          printf("%d", no[t1]);

        s = 1;
      }

    }

    new_puts("");
    ++aaaa;
    return;
  }

  if ((now == dx) || (aaaa == 2))
  {
    return;
  }

  use[now] = 1;
  dfs2(now + 1, sum + no[now]);
  use[now] = 0;
  dfs2(now + 1, sum);
}

int Main()
{
  int Case = 0;
  int l;
  int t1;
  scanf("%d", &l);
  while (l--)
  {
    scanf("%d", &dx);
    for (t1 = 0; t1 < dx; ++t1)
    {
      scanf("%d", &no[t1]);
    }

    new_memset(s, 0, sizeof(s));
    sNo = 0;
    dfs(0, 0);
    new_qsort(s, sNo, sizeof(int), cmp);
    for (t1 = 1; (t1 < sNo) && (s[t1] != s[t1 - 1]); ++t1)
      ;

    printf("Case #%d:\n", ++Case);
    if (t1 >= sNo)
    {
      new_puts("Impossible");
    }
    else
    {
      ans = s[t1];
      aaaa = 0;
      new_memset(use, 0, sizeof(use));
      dfs2(0, 0);
    }

  }

  return 0;
}



void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str) {
  return puts(str);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}