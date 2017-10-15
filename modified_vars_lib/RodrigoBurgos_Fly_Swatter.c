#include <stdio.h>
int list[1001];
int list2[1001];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int compare(int *a, int *sum)
{
  return (*a) - (*sum);
}

int Main()
{
  int d;
  int k;
  int n;
  int casos;
  int set = 1;
  int a;
  int sum;
  long long res;
  new_freopen("a.in", "r", stdin);
  new_freopen("a.out", "w", stdout);
  for (scanf("%d", &casos); casos--;)
  {
    scanf("%d", &n);
    for (d = 0; d < n; d++)
      scanf("%d", &list[d]);

    new_qsort(list, n, sizeof(int), compare);
    for (d = 0; d < n; d++)
      scanf("%d", &list2[d]);

    new_qsort(list2, n, sizeof(int), compare);
    a = 0;
    sum = n - 1;
    res = 0;
    for (d = 0; d < n; d++)
      res += ((long long) list[d]) * ((long long) list2[(n - d) - 1]);

    printf("Case #%d: %I64d\n", set++, res);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
