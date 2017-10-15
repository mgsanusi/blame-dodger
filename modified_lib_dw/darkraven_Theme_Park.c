#include<stdio.h>
#include<memory.h>
#include <stddef.h>
unsigned long long G[2001];
int g[1001];
int mark[1001];
int k;
int r;
int n;
inline void *new_memset(void *ptr, int value, size_t num);
static void find(int *start, int *end)
{
  int first_iteration;
  int j = 1;
  int count = 1;
  while (!mark[j])
  {
    mark[j] = count;
    unsigned long long sum = 0;
    for (; sum <= ((unsigned long long) k);)
    {
      sum += (unsigned long long) g[j];
      if (sum <= ((unsigned long long) k))
        j = (j % n) + 1;

    }

    G[count] = (G[count - 1] + sum) - ((unsigned long long) g[j]);
    count++;
  }

  *start = mark[j];
  *end = count - 1;
  return;
}

int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  int L;
  for (L = 1; L <= T; L++)
  {
    scanf("%d%d%d", &r, &k, &n);
    new_memset(g, 0, sizeof(g));
    new_memset(mark, 0, sizeof(mark));
    int i;
    unsigned long long tmp = 0;
    for (i = 1; i <= n; i++)
    {
      scanf("%d", g + i);
      tmp += g[i];
    }

    unsigned long long ans = 0;
    if (tmp > k)
    {
      int s;
      int e;
      find(&s, &e);
      ans = G[s - 1];
      ans += (G[e] - G[s - 1]) * (((r - s) + 1) / ((e - s) + 1));
      ans += G[((((r - s) + 1) % ((e - s) + 1)) + s) - 1] - G[s - 1];
    }
    else
    {
      ans = tmp * r;
    }

    printf("Case #%d: %llu\n", L, ans);
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


