#include <stdio.h>
void solve()
{
  int first_iteration;
  double C;
  double F;
  double X;
  double best = 1e100;
  double tid;
  double produce = 2;
  int z;
  scanf("%lf %lf %lf", &C, &F, &X);
  tid = 0;
  best = X / produce;
  for (z = 1; z < 2000000000; z++)
  {
    tid += C / produce;
    produce += F;
    if (best <= (tid + (X / produce)))
      break;

    best = tid + (X / produce);
  }

  printf("%.10f\n", best);
  return;
}

int main()
{
  int first_iteration;
  int T;
  int no = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", no++), solve();

  return 0;
}


