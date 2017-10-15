#include <stdio.h>
double correct[200];
double chance[200];
int Main()
{
    int cases;
    int caseindex;
    double con;
    double temp;
    int s;
    int t;
    int i;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &cases);
    correct[0] = 1;
    for (caseindex = 1; caseindex <= cases; caseindex++) {
	scanf("%d%d", &s, &t);
	for (i = 1; i <= s; i++) {
	    scanf("%lf", &chance[i]);
	    correct[i] = correct[i - 1] * chance[i];
	}
	con = 100000000;
	con = con < (t + 2) ? con : t + 2;
	temp =
	    (((t - s) + 1) * correct[s]) +
	    ((1 - correct[s]) * (((2 * t) - s) + 2));
	con = con < temp ? con : temp;
	for (i = 1; i <= s; i++) {
	    temp =
		((((t - s) + 1) + (2 * i)) * correct[s - i]) +
		((1 - correct[s - i]) * ((((2 * i) + (2 * t)) - s) + 2));
	    con = con < temp ? con : temp;
	}
	printf("Case #%d: %f\n", caseindex, con);
    }
    return 0;
}
