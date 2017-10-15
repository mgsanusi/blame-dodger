#include <stdio.h>
double correct[200];
double chance[200];
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int main()
{
  int first_iteration;
  int cases;
  int caseindex;
  double cons;
  double temp;
  int a;
  int b;
  int i;
  new_freopen("A-small-attempt0.in", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  scanf("%d", &cases);
  correct[0] = 1;
  for (caseindex = 1; caseindex <= cases; caseindex++)
  {
    scanf("%d%d", &a, &b);
    for (i = 1; i <= a; i++)
    {
      scanf("%lf", &chance[i]);
      correct[i] = correct[i - 1] * chance[i];
    }

    cons = 100000000;
    cons = cons < (b + 2) ? cons : b + 2;
    temp = (((b - a) + 1) * correct[a]) + ((1 - correct[a]) * (((2 * b) - a) + 2));
    cons = cons < temp ? cons : temp;
    for (i = 1; i <= a; i++)
    {
      temp = ((((b - a) + 1) + (2 * i)) * correct[a - i]) + ((1 - correct[a - i]) * ((((2 * i) + (2 * b)) - a) + 2));
      cons = cons < temp ? cons : temp;
    }

    printf("Case #%d: %f\n", caseindex, cons);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


