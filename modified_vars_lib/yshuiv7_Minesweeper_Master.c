#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
const int r[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int s[] = {1, 0, -1, 0, 1, -1, -1, 1};
void* new_malloc(size_t size);

void new_free(void *ptr);

int dfs(int *matrix, int *pin, int t, int outputFileName, int n, int m)
{
  int i;
  for (i = 0; i < 8; i++)
  {
    int xEd = t + r[i];
    int yy = outputFileName + s[i];
    if ((xEd < 0) || (xEd >= n))
      continue;

    if ((yy < 0) || (yy >= m))
      continue;

    if (pin[(xEd * m) + yy])
      continue;

    if (matrix[(xEd * m) + yy] == (-1))
      continue;

    pin[(xEd * m) + yy] = 1;
    if (matrix[(xEd * m) + yy] == 0)
      dfs(matrix, pin, xEd, yy, n, m);

  }

}

inline static int slowOneCnt(int t)
{
  int s = 0;
  while (t)
  {
    t -= t & (-t);
    s++;
  }

  return s;
}

void markMap(int map, int n, int m, int cx, int cy)
{
  int i;
  int base;
  for (i = 0; i < n; i++)
  {
    for (base = 0; base < m; base++)
    {
      if (map & (1 << ((i * m) + base)))
        printf("*");
      else
        if ((i == cx) && (base == cy))
        printf("c");
      else
        printf(".");


    }

    printf("\n");
  }

}

int *tmp;
int verify(int map, int n, int m, int firstDelay, int *b, int *r)
{
  int full = slowOneCnt(map);
  int *m2;
  int *pin;
  if (full != firstDelay)
    return 0;

  m2 = new_malloc((n * m) * 4);
  pin = new_malloc((n * m) * 4);
  int i;
  int base;
  for (i = 0; i < n; i++)
    for (base = 0; base < m; base++)
  {
    int t;
    if (map & (1 << ((i * m) + base)))
    {
      m2[(i * m) + base] = -1;
      continue;
    }

    m2[(i * m) + base] = 0;
    for (t = 0; t < 8; t++)
    {
      int xEd = i + r[t];
      int yy = base + s[t];
      if ((xEd < 0) || (xEd >= n))
        continue;

      if ((yy < 0) || (yy >= m))
        continue;

      int mine = (map >> ((xEd * m) + yy)) & 1;
      m2[(i * m) + base] += mine;
    }

  }


  memset(pin, 0, (m * n) * 4);
  for (i = 0; i < n; i++)
    for (base = 0; base < m; base++)
  {
    if (m2[(i * m) + base] == 0)
    {
      pin[(i * m) + base] = 1;
      dfs(m2, pin, i, base, n, m);
      *b = i;
      *r = base;
      tmp = m2;
      goto next1;
    }

    if ((firstDelay == ((n * m) - 1)) && (m2[(i * m) + base] != (-1)))
    {
      *b = i;
      *r = base;
      new_free(pin);
      tmp = m2;
      return 1;
    }

  }


  int ret;
  next1:
  ret = 1;

  for (i = 0; i < n; i++)
    for (base = 0; base < m; base++)
  {
    if ((m2[(i * m) + base] != (-1)) && (pin[(i * m) + base] == 0))
    {
      ret = 0;
      goto ret;
    }

  }


  ret:
  if (ret == 0)
    new_free(m2);


  new_free(pin);
  return ret;
}

int Main()
{
  int cases;
  int p;
  scanf("%d", &cases);
  for (p = 1; p <= cases; p++)
  {
    int n;
    int m;
    int b;
    int r;
    int firstDelay;
    scanf("%d%d%d", &n, &m, &firstDelay);
    int map;
    int possible = 0;
    printf("Case #%d:\n", p);
    for (map = 0; map < (1 << (n * m)); map++)
    {
      if (verify(map, n, m, firstDelay, &b, &r))
      {
        new_free(tmp);
        markMap(map, n, m, b, r);
        possible = 1;
        break;
      }

    }

    if (!possible)
      printf("Impossible\n");

  }

}



void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(size_t size) {
  return malloc(size);
}