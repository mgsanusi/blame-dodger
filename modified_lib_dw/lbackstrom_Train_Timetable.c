int cmp(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

void new_qsort(void *base, int num, int size, int (*compar)(const void *, const void *));
int main()
{
  int first_iteration;
  int N;
  int NA;
  int NB;
  int T;
  int i;
  int j;
  int k;
  int pa;
  int pb;
  int h1;
  int m1;
  int h2;
  int m2;
  int na;
  int nb;
  int ra;
  int rb;
  int A[1000];
  int B[1000];
  scanf("%d", &N);
  for (i = 1; i <= N; i++)
  {
    pa = (pb = (na = (nb = (ra = (rb = 0)))));
    scanf("%d%d%d", &T, &NA, &NB);
    for (j = 0; j < NA; j++)
    {
      scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
      A[pa++] = (((h1 * 60) + m1) * 2) + 1;
      B[pb++] = (((h2 * 60) + m2) + T) * 2;
    }

    for (j = 0; j < NB; j++)
    {
      scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
      B[pb++] = (((h1 * 60) + m1) * 2) + 1;
      A[pa++] = (((h2 * 60) + m2) + T) * 2;
    }

    new_qsort(A, pa, sizeof(int), cmp);
    new_qsort(B, pb, sizeof(int), cmp);
    for (j = 0; j < pa; j++)
    {
      if ((A[j] % 2) == 0)
        na++;
      else
        na--;

      if ((-na) > ra)
        ra = -na;

    }

    for (j = 0; j < pb; j++)
    {
      if ((B[j] % 2) == 0)
        nb++;
      else
        nb--;

      if ((-nb) > rb)
        rb = -nb;

    }

    printf("Case #%d: %d %d\n", i, ra, rb);
  }

}

void new_qsort(void *base, int num, int size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}


