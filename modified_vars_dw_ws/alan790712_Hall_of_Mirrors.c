#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double pro[100000];
int correct[100000];
int l;
int b;
double exp;
double min_exp;
int Main()
{
    int first_iteration;
    int Case = 0;
    int r;
    int i;
    int j;
    double pp;
    scanf("%d", &r);
    while (r--) {
	scanf("%d %d", &l, &b);
	for (i = 0; i < l; ++i) {
	    scanf("%lf", &pro[i]);
	}
	for (i = 0, pp = 1.0; i < l; ++i) {
	    pp *= pro[i];
	}
	min_exp =
	    (pp * ((b - l) + 1)) + ((1.0 - pp) * (((b - l) + b) + 2));
	exp = b + 2;
	if (exp < min_exp)
	    min_exp = exp;
	for (i = 1; i <= l; ++i) {
	    pp = 1.0;
	    for (j = 0; j < (l - i); ++j) {
		pp *= pro[j];
	    }
	    exp =
		(pp * ((((i + b) - l) + i) + 1)) +
		((1 - pp) * ((((((i + b) - l) + i) + 1) + b) + 1));
	    if (exp < min_exp)
		min_exp = exp;
	}
	printf("Case #%d: %lf\n", ++Case, min_exp);
    }
    return 0;
}
