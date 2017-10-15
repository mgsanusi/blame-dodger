#include<stdio.h>
#include<string.h>
int r[3][3];
int Main()
{
    int x;
    int y;
    int t;
    int xdrs;
    int c;
    int s;
    int n;
    int m;
    int ok;
    int res;
    int index;
    int l;
    int k;
    int h = 0;
    long long ret;
    for (scanf("%d", &ok); ok--;) {
	scanf("%d %d %d %d %d %d %d %d", &n, &t, &xdrs, &c, &s, &x, &y,
	      &m);
	memset(r, 0, sizeof(r));
	ret = 0;
	for (res = 0; res < n; res++) {
	    r[x % 3][y % 3]++;
	    x = ((((long long) t) * x) + xdrs) % m;
	    y = ((((long long) c) * y) + s) % m;
	}
	for (res = 0; res < 3; res++)
	    for (index = 0; index < 3; index++) {
		for (k = 0; k < 3; k++)
		    for (l = 0; l < 3; l++)
			if ((k != res) || (l != index)) {
			    x = ((6 - res) - k) % 3, y =
				((6 - index) - l) % 3;
			    if (((x != res) || (y != index))
				&& ((x != k) || (y != l)))
				ret +=
				    (((long long) r[res][index]) *
				     r[k][l]) * r[x][y];
			    else
				ret +=
				    ((((long long) r[res][index]) *
				      r[k][l]) * (r[x][y] - 1)) / 2;
			}
		ret +=
		    (((long long) r[res][index]) * (r[res][index] - 1)) *
		    (r[res][index] - 2);
	    }
	printf("Case #%d: %lld\n", ++h, ret / 6);
    }
    return 0;
}
