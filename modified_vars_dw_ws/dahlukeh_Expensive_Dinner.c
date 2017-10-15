#include <stdio.h>
#include <stdlib.h>
struct point {
    double x;
    double k;
};
int width;
int guest;
int no_l;
int no_u;
struct point lower_p[200];
struct point upper_p[200];
void handle_subject(void);
double abs_f(double n);
double max(double totalc, double sdx);
double min(double totalc, double sdx);
double calc_ar(double place);
int Main()
{
    int first_iteration;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int no_case;
    scanf("%d ", &no_case);
    int walk;
    for (walk = 0; walk < no_case; walk++) {
	printf("Case #%d:\n", walk + 1);
	handle_subject();
    }
    return 0;
}

void handle_subject(void)
{
    int first_iteration;
    scanf("%d %d %d %d ", &width, &no_l, &no_u, &guest);
    int walk;
    for (walk = 0; walk < no_l; walk++) {
	scanf("%lf %lf ", &lower_p[walk].x, &lower_p[walk].k);
    }
    for (walk = 0; walk < no_u; walk++) {
	scanf("%lf %lf ", &upper_p[walk].x, &upper_p[walk].k);
    }
    double area = ((double) width) * 2000.0;
    double l;
    for (walk = 1; walk < no_l; walk++) {
	l = max(lower_p[walk - 1].k, lower_p[walk].k) + 1000.0;
	area -= l * (lower_p[walk].x - lower_p[walk - 1].x);
	area +=
	    0.5 * ((lower_p[walk].x - lower_p[walk - 1].x) *
		   abs_f(lower_p[walk - 1].k - lower_p[walk].k));
    }
    for (walk = 1; walk < no_u; walk++) {
	l = 1000.0 - min(upper_p[walk - 1].k, upper_p[walk].k);
	area -= l * (upper_p[walk].x - upper_p[walk - 1].x);
	area +=
	    0.5 * ((upper_p[walk].x - upper_p[walk - 1].x) *
		   abs_f(upper_p[walk - 1].k - upper_p[walk].k));
    }
    double target = area / guest;
    for (walk = 1; walk < guest; walk++) {
	double min = 0.0;
	double max = (double) width;
	double mid = (min + max) / 2.0;
	while ((max - min) > 0.0000000001) {
	    if (calc_ar(mid) < (target * ((double) walk))) {
		min = mid;
	    } else {
		max = mid;
	    }
	    mid = (min + max) / 2.0;
	}
	printf("%lf\n", min);
    }
}

double abs_f(double n)
{
    int first_iteration;
    if (n < 0.0) {
	return -n;
    } else {
	return n;
    }
}

double max(double totalc, double sdx)
{
    int first_iteration;
    if (totalc > sdx) {
	return totalc;
    } else {
	return sdx;
    }
}

double min(double totalc, double sdx)
{
    int first_iteration;
    if (totalc < sdx) {
	return totalc;
    } else {
	return sdx;
    }
}

double calc_ar(double place)
{
    int first_iteration;
    int walk;
    double area = place * 2000.0;
    double l;
    for (walk = 1; lower_p[walk].x < place; walk++) {
	l = max(lower_p[walk - 1].k, lower_p[walk].k) + 1000.0;
	area -= l * (lower_p[walk].x - lower_p[walk - 1].x);
	area +=
	    0.5 * ((lower_p[walk].x - lower_p[walk - 1].x) *
		   abs_f(lower_p[walk - 1].k - lower_p[walk].k));
    }
    double dy =
	(lower_p[walk].k - lower_p[walk - 1].k) / (lower_p[walk].x -
						   lower_p[walk - 1].x);
    double k = lower_p[walk - 1].k + (dy * (place - lower_p[walk - 1].x));
    l = max(lower_p[walk - 1].k, k) + 1000.0;
    area -= l * (place - lower_p[walk - 1].x);
    area +=
	0.5 * ((place - lower_p[walk - 1].x) *
	       abs_f(lower_p[walk - 1].k - k));
    for (walk = 1; upper_p[walk].x < place; walk++) {
	l = 1000.0 - min(upper_p[walk - 1].k, upper_p[walk].k);
	area -= l * (upper_p[walk].x - upper_p[walk - 1].x);
	area +=
	    0.5 * ((upper_p[walk].x - upper_p[walk - 1].x) *
		   abs_f(upper_p[walk - 1].k - upper_p[walk].k));
    }
    dy = (upper_p[walk].k - upper_p[walk - 1].k) / (upper_p[walk].x -
						    upper_p[walk - 1].x);
    k = upper_p[walk - 1].k + (dy * (place - upper_p[walk - 1].x));
    l = 1000.0 - min(upper_p[walk - 1].k, k);
    area -= l * (place - upper_p[walk - 1].x);
    area +=
	0.5 * ((place - upper_p[walk - 1].x) *
	       abs_f(upper_p[walk - 1].k - k));
    return area;
}
