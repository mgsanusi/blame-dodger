#include <stdio.h>
#include <stdlib.h>
int num;
int res;
int time[1000];
int j[1000];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *a, const void *t)
{
  return (*((int *) a)) - (*((int *) t));
}

void mat()
{
  int k;
  int last;
  scanf("%d", &k);
  for (last = 0; last < k; last++)
  {
    scanf("%d", &time[last]);
  }

  for (last = 0; last < k; last++)
  {
    scanf("%d", &j[last]);
  }

  new_qsort(time, k, sizeof(int), cmp);
  new_qsort(j, k, sizeof(int), cmp);
  res = 0;
  for (last = 0; last < k; last++)
  {
    res += time[last] * j[(k - last) - 1];
  }

}

int Main()
{
  int css;
  new_freopen("A.in", "r", stdin);
  new_freopen("A.txt", "w", stdout);
  scanf("%d", &num);
  for (css = 1; css <= num; css++)
  {
    mat();
    printf("Case #%d: %d\n", css, res);
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