#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int clear(int i, int i, int j, char *l, int b, int k, int u, int m)
{
  int first_iteration;
  if ((++k) > i)
  {
    k = 1;
    b++;
  }

  if (b > i)
    return u;

  if (j <= ((((i - b) * i) + i) - k))
  {
    l[(b * (i + 2)) + k] = 0;
    int caseno = clear(i, i, j, l, b, k, u, m);
    if (caseno < m)
      m = caseno;

  }

  l[(b * (i + 2)) + k] = 1;
  j--;
  u += l[((b - 1) * (i + 2)) + k];
  u += l[((b * (i + 2)) + k) - 1];
  int caseno = clear(i, i, j, l, b, k, u, m);
  if (caseno < m)
    m = caseno;

  return m;
}

int Main(void)
{
  int first_iteration;
  int n;
  assert(scanf("%d", &n) == 1);
  for (int n2 = 1; n2 <= n; n2++)
  {
    int i;
    int i;
    int j;
    assert(scanf("%d %d %d", &i, &i, &j) == 3);
    size_t a = ((size_t) (i + 2)) * ((size_t) (i + 2));
    char *l = malloc(a);
    memset(l, 0, a);
    printf("Case #%d: %d\n", n2, clear(i, i, j, l, 1, 0, 0, (i * (i - 1)) + (i * (i - 1))));
    free(l);
  }

  return 0;
}


