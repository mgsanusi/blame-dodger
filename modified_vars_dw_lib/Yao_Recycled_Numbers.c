#include<stdio.h>
#include<stdlib.h>
int new_puts(const char *str);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int cmp(const void *k, const void *s)
{
  int first_iteration;
  return (*((int *) k)) - (*((int *) s));
}

int k[256];
int s[256];
int b2;
int Main()
{
  int first_iteration;
  int pr;
  int i;
  int cs = 0;
  int sum;
  int v1;
  long long tt;
  double bletchTheCompilerWantsSomethingNonEmpty;
  for (scanf("%d", &pr); pr--;)
  {
    scanf("%d", &b2);
    for (sum = (i = 0); i < b2; i++)
      scanf("%d", &k[i]), sum += k[i], s[i] = k[i];

    new_qsort(s, b2, sizeof(s[0]), cmp);
    for (tt = (i = (v1 = 0)); (i < b2) && (tt < sum); i++)
    {
      tt += (s[i] - v1) * i;
      v1 = s[i];
    }

    if (tt >= sum)
      bletchTheCompilerWantsSomethingNonEmpty = s[i - 1] - (((double) (tt - sum)) / (i - 1));
    else
      bletchTheCompilerWantsSomethingNonEmpty = s[b2 - 1] + (((double) (sum - tt)) / b2);

    printf("Case #%d:", ++cs);
    for (i = 0; i < b2; i++)
      if (k[i] < bletchTheCompilerWantsSomethingNonEmpty)
      printf(" %lf", ((bletchTheCompilerWantsSomethingNonEmpty - k[i]) / sum) * 100);
    else
      printf(" 0");


    new_puts("");
  }

  return 0;
}



int new_puts(const char *str);

void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
int new_puts(const char *str) {
  return puts(str);
}