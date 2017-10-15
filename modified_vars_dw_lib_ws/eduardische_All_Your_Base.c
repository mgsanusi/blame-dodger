#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct point {
    int b;
    int n;
    int z;
    int px;
    int largest_x;
    int cases;
};
struct vec {
    double dh;
    double px;
    double d;
    double largest_x;
    double ri;
    double cases;
};
struct vec draw_vec(struct point a[505], int desks)
{
    int first_iteration;
    struct vec ans;
    int i;
    int sumx = 0;
    int sumy = 0;
    int sumz = 0;
    for (i = 0; i < desks; i++) {
	sumx += a[i].b;
	sumy += a[i].n;
	sumz += a[i].z;
    }
    ans.dh = ((double) sumx) / ((double) desks);
    ans.d = ((double) sumy) / ((double) desks);
    ans.ri = ((double) sumz) / ((double) desks);
    sumx = 0;
    sumy = 0;
    sumz = 0;
    for (i = 0; i < desks; i++) {
	sumx += a[i].b + a[i].px;
	sumy += a[i].n + a[i].largest_x;
	sumz += a[i].z + a[i].cases;
    }
    ans.px = ((double) sumx) / ((double) desks);
    ans.largest_x = ((double) sumy) / ((double) desks);
    ans.cases = ((double) sumz) / ((double) desks);
    ans.px -= ans.dh;
    ans.largest_x -= ans.d;
    ans.cases -= ans.ri;
    return ans;
}

double new_sqrt(double x);
double get_dist(struct vec a, double t)
{
    int first_iteration;
    double b;
    double n;
    double z;
    b = a.dh + (a.px * t);
    n = a.d + (a.largest_x * t);
    z = a.ri + (a.cases * t);
    if (b < 0)
	b *= -1;
    if (n < 0)
	n *= -1;
    if (z < 0)
	z *= -1;
    double ans = new_sqrt(((b * b) + (n * n)) + (z * z));
    return ans;
}

int Main()
{
    int first_iteration;
    int x2;
    int n;
    scanf("%d", &x2);
    int desks;
    int i;
    static struct point a[505];
    struct vec saved;
    double p1;
    double sum;
    double cost1;
    double case_idx;
    double lv;
    double ti;
    double c1v;
    double c2v;
    char j;
    char tb;
    char file;
    for (n = 0; n < x2; n++) {
	scanf("%d", &desks);
	for (i = 0; i < desks; i++)
	    scanf("%d %d %d %d %d %d", &a[i].b, &a[i].n, &a[i].z, &a[i].px,
		  &a[i].largest_x, &a[i].cases);
	saved = draw_vec(a, desks);
	p1 = 0.0;
	sum = 2500020.0;
	lv = get_dist(saved, p1);
	ti = get_dist(saved, sum);
	while ((sum - p1) > 1E-9) {
	    cost1 = p1 + ((sum - p1) / 3);
	    case_idx = sum - ((sum - p1) / 3);
	    c1v = get_dist(saved, cost1);
	    c2v = get_dist(saved, case_idx);
	    if (c1v < lv)
		j = 0;
	    else
		j = 1;
	    if (c2v < c1v)
		tb = 0;
	    else
		tb = 1;
	    if (ti < c2v)
		file = 0;
	    else
		file = 1;
	    if (j) {
		sum = cost1;
		ti = c1v;
	    } else if (tb) {
		sum = case_idx;
		ti = c2v;
	    } else if (file) {
		p1 = cost1;
		lv = c1v;
	    } else {
		p1 = case_idx;
		lv = c2v;
	    }
	}
	cost1 = (p1 + sum) / 2;
	c1v = get_dist(saved, cost1);
	printf("Case #%d: %.8f %.8f\n", n + 1, c1v, cost1);
    }
    return 0;
}

double new_sqrt(double x)
{
    return sqrt(x);
}
