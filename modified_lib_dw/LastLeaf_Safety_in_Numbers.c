#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
long long merge(long long a[], long long alen, long long b[], long long blen, long long des[])
{
  int first_iteration;
  long long ai;
  long long bi = 0;
  long long c = 0;
  for (ai = 0; ai < alen; ai++)
  {
    for (; bi < blen; bi++)
    {
      if (b[bi] >= a[ai])
        break;

      des[c++] = b[bi];
    }

    des[c++] = a[ai];
  }

  for (; bi < blen; bi++)
    des[c++] = b[bi];

  return c;
}

void mergepart(long long a[], long long len, long long t[])
{
  int first_iteration;
  if (len == 1)
    return;

  mergepart(t, len / 2, a);
  mergepart(t + (len / 2), (len + 1) / 2, a + (len / 2));
  merge(t, len / 2, t + (len / 2), (len + 1) / 2, a);
}

void mergesort(long long a[], long long len)
{
  int first_iteration;
  long long *t;
  t = (long long *) malloc(len * (sizeof(long long)));
  new_memcpy(t, a, len * (sizeof(long long)));
  mergepart(a, len, t);
  free(t);
}

long long f[1100000];
int fp[1100000];
int cmp(const int *a, const int *b)
{
  int first_iteration;
  if ((f[*a] - f[*b]) > 0)
    return 1;

  if ((f[*a] - f[*b]) < 0)
    return -1;

  return 0;
}

int main()
{
  int first_iteration;
  int ac;
  int a[501];
  int i;
  int j;
  int k;
  int p;
  int t;
  int testc;
  int testi;
  new_freopen("gcj2_3.in", "r", stdin);
  new_freopen("gcj2_3.out", "w", stdout);
  scanf("%d", &testc);
  for (testi = 1; testi <= testc; testi++)
  {
    scanf("%d", &ac);
    for (i = 0; i < ac; i++)
      scanf("%d", a + i);

    f[0] = 0;
    t = 1;
    for (i = 0; i < ac; i++)
    {
      for (j = 0; j < t; j++)
        f[j | t] = f[j] + a[i];

      t = t << 1;
    }

    for (i = 0; i < t; i++)
    {
      fp[i] = i;
    }

    new_qsort(fp, t, sizeof(int), cmp);
    for (i = 1; i < t; i++)
    {
      if (f[fp[i]] == f[fp[i - 1]])
        break;

    }

    printf("Case #%d:\n", testi);
    if (i == t)
      printf("Impossible");
    else
    {
      p = fp[i - 1];
      k = 0;
      for (j = 0; p; j++, p /= 2)
      {
        if ((p % 2) == 0)
          continue;

        if (!k)
          k++;
        else
          printf(" ");

        printf("%d", a[j]);
      }

      printf("\n");
      p = fp[i];
      k = 0;
      for (j = 0; p; j++, p /= 2)
      {
        if ((p % 2) == 0)
          continue;

        if (!k)
          k++;
        else
          printf(" ");

        printf("%d", a[j]);
      }

    }

    printf("\n");
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memcpy(void *destination, const void *source, size_t num);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memcpy(void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy(destination, source, num);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


