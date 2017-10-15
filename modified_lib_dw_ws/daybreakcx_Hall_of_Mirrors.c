#include <stdio.h>
int ti;
int tn;
int i;
int j;
int k;
int n;
int s;
int a[500];
int main()
{
    int first_iteration;
    scanf("%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
	printf("Case #%d:", ti);
	scanf("%d", &n);
	for (i = (s = 0); i < n; ++i) {
	    scanf("%d", &a[i]);
	    s += a[i];
	}
	for (i = (j = (k = 0)); i < n; ++i)
	    if ((n * a[i]) >= (s << 1)) {
		++j;
		k += a[i];
	    }
	for (i = 0; i < n; ++i) {
	    if ((a[i] * n) >= (s << 1))
		printf(" 0");
	    else
		printf(" %lf",
		       (((100.0 * ((2 * s) - k)) / (n - j)) / s) -
		       ((100.0 * a[i]) / s));
	}
	printf("\n");
    }
    return 0;
}
