#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int Main()
{
  int first_iteration;
  long long int x;
  long long int n;
  long long int k;
  long long int pos;
  long long int sum2;
  long long int sum;
  long long int s;
  long long int target;
  long long int i;
  long long int powa;
  long long int u;
  FILE *b;
  FILE *fo;
  fo = fopen("outputa.txt", "w");
  b = fopen("inputa.txt", "r");
  fscanf(b, "%lld", &x);
  for (u = 1; u <= x; u++)
  {
    fscanf(b, "%lld", &k);
    fscanf(b, "%lld", &n);
    fscanf(b, "%lld", &s);
    fprintf(fo, "Case #");
    fprintf(fo, "%lld", u);
    fprintf(fo, ":");
    fprintf(fo, " ");
    pos = k / n;
    if ((k % n) != 0)
      pos = pos + 1;

    if (s < pos)
    {
      fprintf(fo, "IMPOSSIBLE");
    }
    else
    {
      sum = 0;
      for (target = 1; target <= (k % n); target++)
      {
        sum2 = (target - 1) * n;
        for (i = 1; i <= n; i++)
        {
          powa = (long long int) (pow(k, n - i) + 0.5);
          sum = sum + (((sum2 + i) - 1) * powa);
        }

        fprintf(fo, "%lld", sum + 1);
        fprintf(fo, " ");
      }

    }

    fprintf(fo, "\n");
  }

}


