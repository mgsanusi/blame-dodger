#include <stdio.h>
#include <math.h>
int testc;
int test;
int i;
double s;
int N;
int A;
double H;
double a[300];
double t[2100];
double x[2100];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x);
int main()
{
	int first_iteration;
	new_freopen("gcj3_2.in", "r", stdin);
	new_freopen("gcj3_2.out", "w", stdout);
	scanf("%d", &testc);
	for (test = 1; test <= testc; test++) {
		scanf("%lf%d%d", &H, &N, &A);
		for (i = 1; i <= N; i++) {
			scanf("%lf%lf", &t[i], &x[i]);
		}
		for (i = 1; i <= A; i++)
			scanf("%lf", &a[i]);
		printf("Case #%d:\n", test);
		if ((N == 1) || (x[1] >= H)) {
			for (i = 1; i <= A; i++) {
				printf("%lf\n", new_sqrt((2.0 * H) / a[i]));
			}
			continue;
		}
		if (N == 2) {
			s = (x[2] - x[1]) / (t[2] - t[1]);
			for (i = 1; i <= A; i++) {
				double rt =
				    (s +
				     sqrt((s * s) +
					  ((2 * a[i]) * x[1]))) / a[i];
				if (rt >= t[2]) {
					printf("%lf\n", sqrt((2.0 * H) / a[i]));
				} else {
					double rx = ((0.5 * a[i]) * rt) * rt;
					if (rx >= H) {
						printf("%lf\n",
						       new_sqrt((2.0 * H) /
								a[i]));
					} else {
						printf("%lf\n",
						       ((H - rx) / s) + rt);
					}
				}
			}
		}
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x)
{
	int first_iteration;
	return sqrt(x);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	int first_iteration;
	return freopen(filename, mode, stream);
}
