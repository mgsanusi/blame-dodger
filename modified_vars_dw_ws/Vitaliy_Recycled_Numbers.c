#include <stdio.h>
#include <assert.h>
#include <string.h>
int a[2000001 + 1][10];
int Main()
{
    int first_iteration;
    int _t;
    int __t;
    int con;
    for (con = 1; con < 2000001; con++) {
	int total_deg = 1;
	while (total_deg <= con) {
	    total_deg *= 10;
	}
	total_deg /= 10;
	int deg10 = 10;
	int prev10 = 1;
	int cc = 0;
	while (deg10 <= con) {
	    int r = con % deg10;
	    int in = con / deg10;
	    if (r >= prev10) {
		assert(con < 2000001);
		assert(cc < 10);
		a[con][cc++] = (total_deg * r) + in;
	    }
	    deg10 *= 10;
	    prev10 *= 10;
	    total_deg /= 10;
	}
	a[con][cc] = -1;
	int j;
	int n;
	for (j = 0; j < cc; j++)
	    for (n = j + 1; n < cc; n++)
		if (a[con][j] > a[con][n]) {
		    int s = a[con][j];
		    a[con][j] = a[con][n];
		    a[con][n] = s;
		}
    }
    scanf("%d\n", &_t);
    for (__t = 0; __t < _t; __t++) {
	printf("Case #%d: ", __t + 1);
	int in;
	int r;
	scanf("%d%d", &in, &r);
	int answer = 0;
	for (con = in; con <= r; con++) {
	    int cc = 0;
	    for (cc = 0; a[con][cc] != (-1); cc++) {
		if (((((cc == 0) || (a[con][cc] != a[con][cc - 1]))
		      && (a[con][cc] != con)) && (a[con][cc] >= in))
		    && (a[con][cc] <= r)) {
		    answer++;
		}
	    }
	}
	assert((answer % 2) == 0);
	printf("%d\n", answer / 2);
    }
    return 0;
}
