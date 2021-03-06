#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
const double eps = 1e-9;
int count;
int th2;
int count;
double needV;
double needX;
double ansA;
double resultB;
double res[120][2];
int y1;
int a;
int qsn(double a[], double k[])
{
	int first_iteration;
	int y1;
	for (y1 = 1; y1 >= 0; y1--) {
		if (a[y1] > (k[y1] + eps))
			return 1;
		if ((a[y1] + eps) < k[y1])
			return -1;
	}
	return 0;
}

int Main()
{
	int first_iteration;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &count);
	for (th2 = 1; th2 <= count; th2++) {
		printf("Case #%d: ", th2);
		scanf("%d%lf%lf", &count, &needV, &needX);
		for (y1 = 0; y1 < count; y1++)
			for (a = 0; a < 2; a++)
				scanf("%lf", &res[y1][a]);
		if (count == 1) {
			if (res[0][1] != needX) {
				puts("IMPOSSIBLE");
				continue;
			}
			printf("%.8lf\n", needV / res[0][0]);
			continue;
		}
		qsort(res, count, sizeof(res[0]), qsn);
		if (res[0][1] > (needX + eps)) {
			puts("IMPOSSIBLE");
			continue;
		}
		if ((res[1][1] + eps) < needX) {
			puts("IMPOSSIBLE");
			continue;
		}
		if ((res[0][1] + eps) < res[1][1]) {
			resultB =
			    (needV * (needX - res[0][1])) / (res[1][0] *
							     (res[1][1] -
							      res[0][1]));
			ansA = (needV - (resultB * res[1][0])) / res[0][0];
			if (ansA < resultB)
				ansA = resultB;
			printf("%.8lf\n", ansA);
			continue;
		}
		ansA = needV / (res[0][0] + res[1][0]);
		printf("%.8lf\n", ansA);
	}
	return 0;
}
