#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int seq;
int num[123456];
int sum;
int avg;
int sss;
double rslt[123456];
double e1;
double c;
int n;
int Main()
{
	int first_iteration;
	int Case = 0;
	int d;
	int d;
	scanf("%d", &d);
	while (d--) {
		scanf("%d", &seq);
		for (d = 0, sum = 0; d < seq; ++d) {
			scanf("%d", &num[d]);
			sum += num[d];
		}
		sss = sum;
		avg = (sum * 2) / seq;
		for (d = (n = 0); d < seq; ++d) {
			if (num[d] > avg) {
				rslt[d] = 0;
				sum -= num[d];
			} else {
				++n;
				rslt[d] = -1;
			}
		}
		printf("Case #%d:", ++Case);
		for (d = 0; d < seq; ++d) {
			if (rslt[d] == 0) {
				printf(" %lf", rslt[d]);
			} else {
				printf(" %lf",
				       ((double)
					(100 *
					 (((sss +
					    ((double)sum)) / ((double)n)) -
					  num[d]))) / sss);
			}
		}
		puts("");
	}
	return 0;
}
