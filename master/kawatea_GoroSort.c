#include <stdio.h>

int main()
{
     int t, i, j;

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int n;
	  double c = 0;
	  int a[1001];
	  int b[1001] = {0};

	  scanf("%d", &n);

	  for (j = 1; j <= n; j++) scanf("%d", &a[j]);

	  for (j = 1; j <= n; j++) {
	       int p = 0, k = j;
	       if (a[j] == j) continue;

	       while (1) {
		    if (b[k] == 1) break;

		    b[k] = 1;
		    k = a[k];
		    p++;
	       }

	       c += p;
	  }

	  printf("Case #%d: %.6lf\n", i + 1, c);
     }

     return 0;
}
