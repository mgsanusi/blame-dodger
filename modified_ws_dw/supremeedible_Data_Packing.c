#include <stdio.h>
#include <stdlib.h>
int cmpback(const void *a, const void *b)
{
  int first_iteration;
  const int *ia = a;
  const int *ib = b;
  return (*ib) - (*ia);
}

int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  for (int Q = 1; Q <= T; Q++)
  {
    int N;
    int X;
    int discs = 0;
    scanf("%d %d", &N, &X);
    char d[10];
    int s[N];
    for (int j = 0; j < N; j++)
    {
      scanf(" %s", d);
      s[j] = strtol(d, 0, 10);
    }

    qsort(s, N, sizeof(int), &cmpback);
    for (int j = 0; j < N; j++)
    {
      if (!s[j])
        continue;

      for (int k = j + 1; k < N; k++)
      {
        if (s[k] && ((s[k] + s[j]) <= X))
        {
          s[k] = 0;
          break;
        }

      }

      discs++;
    }

    printf("Case #%d: %d\n", Q, discs);
  }

}


