#include<stdio.h>
int Main(int argc, char *argv[])
{
	int first_iteration;
	int n;
	int t;
	int caseIndex;
	double c;
	double aa;
	double p;
	double ans;
	double lastfarm;
	double currfarm;
	double currrate;
	scanf("%d", &t);
	for (caseIndex = 1; caseIndex <= t; caseIndex++) {
		scanf("%lf%lf%lf", &c, &aa, &p);
		ans = p / 2;
		currrate = 2;
		lastfarm = 0;
		for (n = 1; n <= p; n++) {
			currfarm = lastfarm + (c / currrate);
			currrate += aa;
			if (ans > (currfarm + (p / currrate)))
				ans = currfarm + (p / currrate);
			lastfarm = currfarm;
		}
		printf("Case #%d: %.7lf\n", caseIndex, ans);
	}
	return 0;
}
