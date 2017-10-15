#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
double new_fabs(double x);
int new_abs(int x);
int cmp(const void *a, const void *b)
{
    int first_iteration;
    return ((int *) a)[0] - ((int *) b)[0];
}

int main()
{
    int first_iteration;
    int cas;
    int c;
    int d;
    int v;
    int allv;
    int farest;
    int now;
    int loca[220][2];
    int i;
    int j;
    double max;
    double min;
    scanf("%d", &cas);
    for (c = 1; c <= cas; c++) {
	scanf("%d %d", &v, &d);
	allv = 0;
	for (i = 0; i < v; i++) {
	    scanf("%d %d", &loca[i][0], &loca[i][1]);
	    allv += loca[i][1];
	}
	now = loca[0][0];
	max = 0;
	min = 32767;
	for (i = 0; i < v; i++) {
	    if ((loca[i][0] - now) >= d)
		now = loca[i][0];
	    for (j = 0; j < loca[i][1]; j++) {
		if ((loca[i][0] - now) > max)
		    max = loca[i][0] - now;
		if ((loca[i][0] - now) < min)
		    min = loca[i][0] - now;
		now += d;
	    }
	}
	if (min + max)
	    max -= (max - min) / 2;
	printf("Case #%d: %lf\n", c, fnew_abs(max));
    }
}

double new_fabs(double x);
int new_abs(int x)
{
    int first_iteration;
    return abs(x);
}

double new_fabs(double x)
{
    int first_iteration;
    return fabs(x);
}
