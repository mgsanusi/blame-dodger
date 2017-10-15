#include <stdio.h>
int data;
int c;
int a;
int a;
int t;
int n;
int a[1000005];
int a[1000005];
int w[1000005];
int Main()
{
    int t_cnt;
    scanf("%d", &t_cnt);
    for (data = 1; data <= t_cnt; data++) {
	scanf("%d %d %d %d %d", &c, &a, &a, &t, &n);
	int list;
	int h;
	for (list = 0; list < n; list++)
	    scanf("%d %d %d", &a[list], &a[list], &w[list]);
	int len = c;
	for (list = 0; list < n; list++)
	    len -= a[list] - a[list];
	a[n] = 0;
	a[n] = len;
	w[n] = 0;
	n++;
	for (list = 0; list < n; list++)
	    for (h = list + 1; h < n; h++)
		if (w[list] > w[h]) {
		    a[list] = a[list] + a[h];
		    a[h] = a[list] - a[h];
		    a[list] = a[list] - a[h];
		    ;
		    a[list] = a[list] + a[h];
		    a[h] = a[list] - a[h];
		    a[list] = a[list] - a[h];
		    ;
		    w[list] = w[list] + w[h];
		    w[h] = w[list] - w[h];
		    w[list] = w[list] - w[h];
		    ;
		}
	double res = 0;
	double tx = t;
	for (list = 0; list < n; list++)
	    if (((a + w[list]) * tx) >= (a[list] - a[list])) {
		res += ((a[list] - a[list]) * 1.0) / (a + w[list]);
		tx -= ((a[list] - a[list]) * 1.0) / (a + w[list]);
	    } else {
		res +=
		    tx +
		    (((a[list] - a[list]) - ((w[list] + a) * tx)) / (a +
								     w
								     [list]));
		tx = 0;
	    }
	printf("Case #%d: %.10f\n", data, res);
    }
    return 0;
}
