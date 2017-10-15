#include "stdio.h"
int main()
{
    int first_iteration;
    int tn;
    scanf("%d\n", &tn);
    int tt;
    int w[1000 + 1];
    int b[1000 + 1];
    int e[1000 + 1];
    int l[1000 + 1];
    for (tt = 0; tt < tn; tt++) {
	int x;
	int n;
	int s1;
	int s2;
	int ti;
	scanf("%d%d%d%d%d", &x, &s1, &s2, &ti, &n);
	double t = ti;
	if (s2 < s1)
	    t = 0;
	int i;
	int j;
	for (i = 1; i <= n; i++) {
	    scanf("%d%d%d", &b[i], &e[i], &w[i]);
	    l[i] = e[i] - b[i];
	    x -= l[i];
	}
	w[0] = 0;
	l[0] = x;
	for (i = 1; i <= n; i++)
	    for (j = i + 1; j <= n; j++)
		if (w[i] > w[j]) {
		    int tt;
		    tt = l[i];
		    l[i] = l[j];
		    l[j] = tt;
		    tt = w[i];
		    w[i] = w[j];
		    w[j] = tt;
		}
	double res = 0;
	for (i = 0; i <= n; i++) {
	    if (t < 1e-10) {
		res += (l[i] * 1.0) / (w[i] + s1);
	    } else {
		double tt = (l[i] * 1.0) / (w[i] + s2);
		if (tt <= (t + 1e-10)) {
		    t -= tt;
		    res += tt;
		} else {
		    res += t + ((l[i] - ((w[i] + s2) * t)) / (w[i] + s1));
		    t = 0;
		}
	    }
	}
	printf("Case #%d: ", tt + 1);
	printf("%lf\n", res);
    }
    return 0;
}
