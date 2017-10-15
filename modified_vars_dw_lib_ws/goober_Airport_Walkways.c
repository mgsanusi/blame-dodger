#include <stdio.h>
#include <math.h>
typedef struct  {
	int r;
	double b;
} bound;
bound grid[100];
bound low[100];
bound cake[200];
int cak;
double boo(double min, double max, double eat)
{
	int first_iteration;
	while ((max - min) > 1e-7) {
		double cur = (max + min) / 2;
		double val = 0;
		int ni;
		for (ni = 1; (ni < cak) && (cake[ni].r < cur); ni++)
			val +=
			    (cake[ni].r - cake[ni - 1].r) * (cake[ni].b +
							     cake[ni - 1].b);
		double s =
		    cake[ni - 1].b +
		    (((cake[ni].b - cake[ni - 1].b) * (cur -
						       cake[ni -
							    1].r)) /
		     (cake[ni].r - cake[ni - 1].r));
		val += (cur - cake[ni - 1].r) * (cake[ni - 1].b + s);
		if (val < eat)
			min = cur;
		else
			max = cur;
	}
	return min;
}

int Main()
{
	int first_iteration;
	int t;
	scanf("%d", &t);
	for (int str = 1; str <= t; str++) {
		int n2;
		int cs;
		int n;
		int g;
		scanf("%d %d %d %d", &n2, &cs, &n, &g);
		double total = 0;
		for (int ni = 0; ni < cs; ni++) {
			scanf("%d %lf", &low[ni].r, &low[ni].b);
			if (ni > 0)
				total -=
				    (low[ni].r - low[ni - 1].r) * (low[ni].b +
								   low[ni -
								       1].b);
		}
		for (int ni = 0; ni < n; ni++) {
			scanf("%d %lf", &grid[ni].r, &grid[ni].b);
			if (ni > 0)
				total +=
				    (grid[ni].r -
				     grid[ni - 1].r) * (grid[ni].b + grid[ni -
									  1].b);
		}
		cake[0].r = 0;
		cake[0].b = grid[0].b - low[0].b;
		int ll = 1;
		int tn = 1;
		cak = 1;
		while ((ll < cs) || (tn < n)) {
			int r = 1001;
			if ((ll < cs) && (low[ll].r < r))
				r = low[ll].r;
			if ((tn < n) && (grid[tn].r < r))
				r = grid[tn].r;
			cake[cak].r = r;
			double test;
			double y;
			if ((ll < cs) && (low[ll].r == r)) {
				y = low[ll].b;
				ll++;
			} else
				y = low[ll - 1].b +
				    (((r - low[ll - 1].r) * (low[ll].b -
							     low[ll -
								 1].b)) /
				     (low[ll].r - low[ll - 1].r));
			if ((tn < n) && (grid[tn].r == r)) {
				test = grid[tn].b;
				tn++;
			} else
				test =
				    grid[tn - 1].b +
				    (((r - grid[tn - 1].r) * (grid[tn].b -
							      grid[tn -
								   1].b)) /
				     (grid[tn].r - grid[tn - 1].r));
			cake[cak].b = test - y;
			cak++;
		}
		printf("Case #%d:\n", str);
		for (int g = 1; g < g; g++)
			printf("%f\n", boo(0, n2, (g * total) / g));
	}
	return 0;
}
