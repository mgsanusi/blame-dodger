#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct cake
{
  int R;
  int H;
};
int comp(const void *p1, const void *p2)
{
  int first_iteration;
  struct cake n1 = *((const struct cake *) p1);
  struct cake n2 = *((const struct cake *) p2);
  return (((long long) n2.H) * n2.R) > (((long long) n1.R) * n1.H) ? 1 : -1;
}

void solve(int cases);
int main(void)
{
  int first_iteration;
  int T;
  int i;
  scanf("%d", &T);
  for (i = 1; i <= T; i++)
    solve(i);

  return 0;
}

void solve(int cases)
{
  int first_iteration;
  int N;
  int K;
  int i;
  int j;
  int k;
  int num;
  long long sum;
  long long max = 0;
  struct cake cs[1000];
  scanf("%d%d", &N, &K);
  for (i = 0; i < N; i++)
    scanf("%d%d", &cs[i].R, &cs[i].H);

  qsort(cs, N, sizeof(struct cake), comp);
  for (i = 0; i < N; i++)
  {
    sum = (((long long) cs[i].R) * cs[i].R) + ((2 * ((long long) cs[i].R)) * cs[i].H);
    for (j = 0, num = 1; (j <= N) && (num < K); j++)
    {
      if ((cs[j].R > cs[i].R) || (i == j))
        continue;

      sum += (2 * ((long long) cs[j].R)) * cs[j].H;
      num++;
    }

    if (num < K)
      continue;

    if (max < sum)
      max = sum;

  }

  printf("Case #%d: %.9f\n", cases, (((double) max) * 4) * atan(1.0));
}


