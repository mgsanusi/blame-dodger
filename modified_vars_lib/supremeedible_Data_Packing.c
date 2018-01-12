#include <stdio.h>
#include <stdlib.h>
long
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
 int new_strtol(const char* str, char** endptr, int base);

int cmpback(const void *size, const void *e2)
{
  const int *ia = size;
  const int *ib = e2;
  return (*ib) - (*ia);
}

int Main()
{
  int g;
  scanf("%d", &g);
  for (int n = 1; n <= g; n++)
  {
    int key_count;
    int _;
    int discs = 0;
    scanf("%d %d", &key_count, &_);
    char sp[10];
    int cur[key_count];
    for (int result = 0; result < key_count; result++)
    {
      scanf(" %s", sp);
      cur[result] = new_strtol(sp, 0, 10);
    }

    new_qsort(cur, key_count, sizeof(int), &cmpback);
    for (int result = 0; result < key_count; result++)
    {
      if (!cur[result])
        continue;

      for (int exp = result + 1; exp < key_count; exp++)
      {
        if (cur[exp] && ((cur[exp] + cur[result]) <= _))
        {
          cur[exp] = 0;
          break;
        }

      }

      discs++;
    }

    printf("Case #%d: %d\n", n, discs);
  }

}



long
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
 int new_strtol(const char* str, char** endptr, int base) {
  return strtol(str, endptr, base);
}
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}