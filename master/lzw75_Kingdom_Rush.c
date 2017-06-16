#include <stdio.h>
#include <stdlib.h>

int main() {
   double *x, *y;
   int num, i;

   x = (double*)malloc(sizeof(double) * 120000);
   y = (double*)malloc(sizeof(double) * 120000);

   scanf("%d", &num);

   for(i=0; i<num; i++) {
      int a, b, j;

      scanf("%d %d", &a, &b);
      for(j=0; j<a; j++)
         scanf("%lf", &x[j]);

      // Prob of no wrong character _before_ j.

      y[0] = 1.0;
      for(j=1; j<=a; j++) {
         y[j] = y[j-1] * x[j-1];
      }

      double best, tmp;

      // Case 1.

      tmp = (b-a+1);
      tmp += (1-y[a]) * (b+1);
      best = tmp;

      // Case 2.

      for(j=1; j<=a; j++) {
         tmp = (y[a-j] * (j + b-a+1 + j));
         tmp += (1-y[a-j]) * (j + b-a+1 + j + b+1);
         if (best > tmp) best = tmp;
      }

      // Case 3.

      if (best > b+2) best = b+2;

      printf("Case #%d: %.10lf\n", i+1, best);
   }

   free(y); free(x);
   return 0;
}
