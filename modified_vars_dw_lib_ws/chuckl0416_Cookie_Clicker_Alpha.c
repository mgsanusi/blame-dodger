#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int case_num;
int t;
double t2;
double m;
double j;
double smtp_rcpt_to;
double ah_private;
double t;
double produce;
double time;
double rslt;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Main()
{
	int first_iteration;
	new_freopen("B-small-attempt0.in", "r", stdin);
	new_freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &case_num);
	for (t = 1; t <= case_num; t++) {
		printf("Case #%d: ", t);
		scanf("%lf%lf%lf", &t2, &m, &j);
		produce = 2;
		rslt = j / produce;
		time = 0;
		while (1) {
			if (((time + (t2 / produce)) + (j / (produce + m))) >=
			    rslt)
				break;
			rslt = (time + (t2 / produce)) + (j / (produce + m));
			time += t2 / produce;
			produce += m;
		}
		printf("%.7lf\n", rslt);
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
