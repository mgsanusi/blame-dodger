#include <stdio.h>
int Main()
{
	int first_iteration;
	int t;
	int x;
	int test;
	int proc;
	int k;
	char x[100][101];
	scanf("%d", &t);
	for (test = 0; test < t; test++) {
		int r[100][2] = { 0 };
		double mask[100];
		double owp[100];
		double oowp[100];
		scanf("%d", &x);
		for (proc = 0; proc < x; proc++)
			scanf("%s", x[proc]);
		for (proc = 0; proc < x; proc++) {
			for (k = 0; k < x; k++) {
				if (x[proc][k] == '1') {
					r[proc][0]++;
				} else if (x[proc][k] == '0') {
					r[proc][1]++;
				}
			}
			mask[proc] =
			    ((double)r[proc][0]) / (r[proc][0] + r[proc][1]);
		}
		for (proc = 0; proc < x; proc++) {
			int c = 0;
			double p = 0;
			for (k = 0; k < x; k++) {
				if (x[proc][k] != '.') {
					c++;
					p += ((double)
					      (r[k][0] -
					       (x[k][proc] -
						'0'))) / ((r[k][0] + r[k][1]) -
							  1);
				}
			}
			owp[proc] = p / c;
		}
		for (proc = 0; proc < x; proc++) {
			int c = 0;
			double p = 0;
			for (k = 0; k < x; k++) {
				if (x[proc][k] != '.') {
					c++;
					p += owp[k];
				}
			}
			oowp[proc] = p / c;
		}
		printf("Case #%d:\n", test + 1);
		for (proc = 0; proc < x; proc++) {
			printf("%lf\n",
			       ((mask[proc] * 0.25) + (owp[proc] * 0.5)) +
			       (oowp[proc] * 0.25));
		}
	}
	return 0;
}
