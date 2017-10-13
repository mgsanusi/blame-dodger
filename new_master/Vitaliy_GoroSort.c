#include "stdio.h"
#include "stdlib.h"

int main () {
	int tn;
	scanf ("%d", &tn);
	double p[1001];
	double q[1001];
	int a[1001];
	int g[1001];
	q[0] = 0;
	p[0] = 0;
	p[1] = 0;
	q[1] = 0;
	int i;
	for (i = 2; i <= 1000; i++) {
		double pp = 1;
		int j;
		q[i] = 0;
		for (j = 1; j < i; j++) {
			q[i] += pp * (1.0 / (i - j + 1)) * (p[j] + q[i-j]);
			pp *= (1 - 1.0 / (i - j + 1));
		}
		q[i] /= (1 - pp);
		q[i] += pp / (1 - pp);
		//printf ("%lf (pp = %lf)\n", q[i], pp);
		p[i] = q[i] + 1; 
	}
	int tt;
	for (tt = 0; tt < tn; tt++) {
		int n;
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%d", &a[i]);
			a[i]--;
			g[i] = 0;
		}
		double r = 0;
		for (i = 0; i < n; i++) if (!g[i]) {
			int j = i; 
			int cc = 0;
			do {
				g[j] = 1;
				j = a[j];
				cc++;
				//printf ("%d\n", j);
			} while (j != i);
			r += p[cc];
		}
		printf ("Case #%d: %lf\n", tt + 1, r);
	}
	return 0;
}
