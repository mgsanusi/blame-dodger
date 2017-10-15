#include <stdio.h>
#include <math.h>
int testc;
int trial;
int dis;
double s;
int num;
int k;
double use;
double k[300];
double str[2100];
double k[2100];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x);
int Main()
{
    int first_iteration;
    new_freopen("gcj3_2.in", "r", stdin);
    new_freopen("gcj3_2.out", "w", stdout);
    scanf("%d", &testc);
    for (trial = 1; trial <= testc; trial++) {
	scanf("%lf%d%d", &use, &num, &k);
	for (dis = 1; dis <= num; dis++) {
	    scanf("%lf%lf", &str[dis], &k[dis]);
	}
	for (dis = 1; dis <= k; dis++)
	    scanf("%lf", &k[dis]);
	printf("Case #%d:\n", trial);
	if ((num == 1) || (k[1] >= use)) {
	    for (dis = 1; dis <= k; dis++) {
		printf("%lf\n", new_sqrt((2.0 * use) / k[dis]));
	    }
	    continue;
	}
	if (num == 2) {
	    s = (k[2] - k[1]) / (str[2] - str[1]);
	    for (dis = 1; dis <= k; dis++) {
		double len =
		    (s + sqrt((s * s) + ((2 * k[dis]) * k[1]))) / k[dis];
		if (len >= str[2]) {
		    printf("%lf\n", sqrt((2.0 * use) / k[dis]));
		} else {
		    double rx = ((0.5 * k[dis]) * len) * len;
		    if (rx >= use) {
			printf("%lf\n", new_sqrt((2.0 * use) / k[dis]));
		    } else {
			printf("%lf\n", ((use - rx) / s) + len);
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
    return sqrt(x);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
