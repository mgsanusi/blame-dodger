#include "stdio.h"
int Main()
{
    int first_iteration;
    int s10;
    scanf("%d\n", &s10);
    char t[500 + 1][500 + 1];
    int tt;
    int xdrs[500 + 1];
    int mx[500 + 1];
    int test_case[500 + 1];
    for (tt = 0; tt < s10; tt++) {
	int size;
	int per;
	int d;
	int n;
	scanf("%d%d%d", &size, &per, &d);
	int cur;
	int j;
	for (cur = 0; cur < size; cur++) {
	    scanf("%s", t[cur]);
	}
	int good = -1;
	for (n = 3; (n <= size) && (n <= per); n++) {
	    for (j = 0; j < per; j++) {
		xdrs[j] = 0;
		mx[j] = 0;
		test_case[j] = 0;
	    }
	    for (cur = 0; cur < (n - 1); cur++)
		for (j = 0; j < per; j++) {
		    xdrs[j] += t[cur][j] - '0';
		    mx[j] += cur * (t[cur][j] - '0');
		    test_case[j] += j * (t[cur][j] - '0');
		}
	    for (cur = n - 1; (cur < size) && (good < n); cur++) {
		int cases = 0;
		int cmx = 0;
		int cmy = 0;
		for (j = 0; j < per; j++) {
		    xdrs[j] += t[cur][j] - '0';
		    mx[j] += cur * (t[cur][j] - '0');
		    test_case[j] += j * (t[cur][j] - '0');
		    if (cur >= n) {
			xdrs[j] -= t[cur - n][j] - '0';
			mx[j] -= (cur - n) * (t[cur - n][j] - '0');
			test_case[j] -= j * (t[cur - n][j] - '0');
		    }
		    cases += xdrs[j];
		    cmx += mx[j];
		    cmy += test_case[j];
		    if (j >= n) {
			cases -= xdrs[j - n];
			cmx -= mx[j - n];
			cmy -= test_case[j - n];
		    }
		    if (j >= (n - 1)) {
			int curm = cases;
			int curmx = cmx;
			int curmy = cmy;
			int ind;
			int jj;
			for (ind = 0; ind < 2; ind++)
			    for (jj = 0; jj < 2; jj++) {
				curm -=
				    t[cur - ((n - 1) * ind)][j -
							     ((n -
							       1) * jj)] -
				    '0';
				curmx -=
				    (cur -
				     ((n - 1) * ind)) * (t[cur -
							   ((n -
							     1) * ind)][j -
									((n
									  -
									  1)
									 *
									 jj)]
							 - '0');
				curmy -=
				    (j -
				     ((n - 1) * jj)) * (t[cur -
							  ((n -
							    1) * ind)][j -
								       ((n
									 -
									 1)
									*
									jj)]
							- '0');
			    }
			if (((curmx * 2) == (curm * ((2 * cur) - (n - 1))))
			    && ((curmy * 2) ==
				(curm * ((2 * j) - (n - 1))))) {
			    good = n;
			    break;
			}
		    }
		}
	    }
	}
	printf("Case #%d: ", tt + 1);
	if (good >= 0)
	    printf("%d\n", good);
	else
	    printf("IMPOSSIBLE\n");
    }
    return 0;
}
