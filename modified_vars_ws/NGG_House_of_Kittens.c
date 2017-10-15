#include <stdio.h>
double mintime[210];
double right[210];
int Main(void)
{
	int res;
	int count;
	scanf("%d", &count);
	for (res = 1; res <= count; res++) {
		int k;
		int d;
		int j;
		int k = 0;
		fprintf(stderr, "ti %d\n", res);
		scanf("%d %d", &k, &d);
		for (j = 0; j < k; j++) {
			int p;
			int v;
			double exit;
			scanf("%d %d", &p, &v);
			mintime[j] = (((double)(v - 1)) * ((double)d)) * 0.5;
			exit = (p - mintime[j]) - (d * 0.5);
			right[j] = (p + mintime[j]) + (d * 0.5);
			if (j > 0) {
				if (exit < right[j - 1]) {
					double dist = right[j - 1] - exit;
					if (mintime[j - 1] > mintime[j]) {
						if ((mintime[j - 1] -
						     mintime[j]) > dist) {
							mintime[j] =
							    mintime[j - 1];
							right[j] += dist;
						} else {
							right[j] +=
							    mintime[j - 1] -
							    mintime[j];
							exit +=
							    mintime[j - 1] -
							    mintime[j];
							mintime[j] =
							    mintime[j - 1];
							dist =
							    right[j - 1] - exit;
							mintime[j] +=
							    dist * 0.5;
							right[j] += dist * 0.5;
						}
					} else {
						if ((mintime[j] -
						     mintime[j - 1]) < dist) {
							dist -=
							    mintime[j] -
							    mintime[j - 1];
							mintime[j] +=
							    dist * 0.5;
							right[j] += dist * 0.5;
						}
					}
				} else {
					if (mintime[j - 1] > mintime[j]) {
						right[j] -=
						    mintime[j - 1] - mintime[j];
						mintime[j] = mintime[j - 1];
					}
				}
			}
		}
		printf("Case #%d: %.8lf\n", res, mintime[k - 1]);
	}
	return 0;
}
