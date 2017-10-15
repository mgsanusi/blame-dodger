#include <stdio.h>
#include <stdlib.h>
int cs;
int ans;
int v1[1000];
int v2[1000];
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int cmp(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

void go()
{
  int first_iteration;
  int n;
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &v1[i]);
  }

  for (i = 0; i < n; i++)
  {
    scanf("%d", &v2[i]);
  }

  new_qsort(v1, n, sizeof(int), cmp);
  new_qsort(v2, n, sizeof(int), cmp);
  ans = 0;
  for (i = 0; i < n; i++)
  {
    ans += v1[i] * v2[(n - i) - 1];
  }

}

int main()
{
  int first_iteration;
  int css;
  new_freopen("A.in", "r", stdin);
  new_freopen("A.txt", "w", stdout);
  scanf("%d", &cs);
  for (css = 1; css <= cs; css++)
  {
    go();
    printf("Case #%d: %d\n", css, ans);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


