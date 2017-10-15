#include <stdio.h>
#include <stdlib.h>
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int cmp(const void *a, const void *b)
{
  int first_iteration;
  const double *ad = a;
  const double *bd = b;
  return (*ad) < (*bd) ? -1 : (*ad) > (*bd);
}

int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  for (int Q = 1; Q <= T; Q++)
  {
    int N;
    scanf("%d", &N);
    double k[N];
    double n[N];
    for (int i = 0; i < N; i++)
    {
      scanf("%lf", &n[i]);
    }

    for (int i = 0; i < N; i++)
    {
      scanf("%lf", &k[i]);
    }

    new_qsort(k, N, sizeof(double), &cmp);
    new_qsort(n, N, sizeof(double), &cmp);
    printf("Case #%d: ", Q);
    int i;
    int j;
    for (i = (j = 0); i < N; i++)
    {
      if (n[i] > k[j])
      {
        j++;
      }

    }

    printf("%d ", j);
    int w = 0;
    for (i = (j = 0); i < N, j < N; i++)
    {
      while (n[i] > k[j])
      {
        j++;
        if (j == N)
        {
          goto done;
        }

      }

      j++;
      w++;
    }

    done:
    printf("%d\n", N - w);

  }

}

void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


