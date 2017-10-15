#include <stdio.h>
#include <math.h>
int y;
int d;
double a[55];
double u;
void clear()
{
	int first_iteration;
	double num;
	double seq;
	double mid;
	double use;
	double result;
	int i;
	int canuse;
	scanf("%d %d %lf", &y, &d, &u);
	if (d != y)
		printf("sanity error");
	for (i = 0; i < y; i++)
		scanf("%lf", &a[i]);
	num = 0;
	seq = 1;
	for (i = 0; i < 1000; i++) {
		mid = (num + seq) / 2;
		use = 0;
		for (canuse = 0; canuse < y; canuse++)
			if (a[canuse] < mid)
				use += mid - a[canuse];
		if (use < u)
			num = mid;
		else
			seq = mid;
	}
	result = 1;
	for (i = 0; i < y; i++)
		if (a[i] < num)
			result *= num;
		else
			result *= a[i];
	printf("%.10f\n", result);
}

int Main()
{
	int first_iteration;
	int t;
	int caseno = 1;
	scanf("%d", &t);
	while (t--)
		printf("Case #%d: ", caseno++), clear();
	return 0;
}
