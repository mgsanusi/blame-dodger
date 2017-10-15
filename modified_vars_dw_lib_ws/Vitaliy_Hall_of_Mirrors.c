#include <stdio.h>
int a[1000];
int b[1000];
int Main()
{
    int first_iteration;
    int __;
    scanf("%d", &__);
    int a[1000];
    int dh;
    for (dh = 0; dh < __; dh++) {
	printf("Case #%d:", dh + 1);
	int n;
	scanf("%d", &n);
	int unhappy;
	int s = 0;
	for (unhappy = 0; unhappy < n; unhappy++) {
	    scanf("%d", &a[unhappy]);
	    b[unhappy] = a[unhappy];
	    s += a[unhappy];
	}
	int qq;
	for (unhappy = 0; unhappy < n; unhappy++)
	    for (qq = unhappy + 1; qq < n; qq++)
		if (b[unhappy] > b[qq]) {
		    int w = b[unhappy];
		    b[unhappy] = b[qq];
		    b[qq] = w;
		}
	for (unhappy = 0; unhappy < n; unhappy++) {
	    double l = 0;
	    double r = 1;
	    while ((r - l) > 1e-10) {
		double p = (r + l) / 2;
		double z = p;
		for (qq = 0; qq < n; qq++)
		    if (unhappy != qq) {
			double w =
			    (((a[unhappy] - a[qq]) * 1.0) + (s * p)) / s;
			if (w < 0) {
			    w = 0;
			}
			z += w;
			if (z >= 1) {
			    break;
			}
		    }
		if (z < 1) {
		    l = p;
		} else {
		    r = p;
		}
	    }
	    printf(" %lf", l * 100);
	}
	printf("\n");
    }
    return 0;
}
