#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double in[200000];
double mul[200000];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int A;
  int B;
  int size;
  int count = 0;
  double res;
  double tmp;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &A, &B);
    for (i = 0; i < A; i++)
      scanf("%lf", in + i);

    res = 1e100;
    mul[0] = 1;
    for (i = 0; i < A; i++)
      mul[i + 1] = mul[i] * in[i];

    if (res > ((1 + B) + 1))
      res = (1 + B) + 1;

    for (i = 0; i < (A + 1); i++)
    {
      tmp = (((((2 * i) + B) - A) + 1) * mul[A - i]) + (((((((2 * i) + B) - A) + 1) + B) + 1) * (1 - mul[A - i]));
      if (res > tmp)
        res = tmp;

    }

    printf("Case #%d: %.10f\n", ++count, res);
  }

  return 0;
}


