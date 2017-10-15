#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
long long x[8][33];
void new_assert(int expression);
void clear(void)
{
    int first_iteration;
    int a;
    int b;
    int t;
    new_assert(scanf("%d %d %d", &a, &b, &t) == 3);
    int clear;
    int at;
    for (clear = 0; clear <= 32; clear++) {
	for (at = 0; at < 8; at++) {
	    x[at][clear] = (clear == 0) && (at == 0);
	}
    }
    for (clear = 1; clear <= 32; clear++) {
	int ra = (a & (1ll << (clear - 1))) != 0;
	int nk = (b & (1ll << (clear - 1))) != 0;
	int size = (t & (1ll << (clear - 1))) != 0;
	for (at = 0; at < 8; at++) {
	    int ca;
	    int wa;
	    for (ca = 0; ca < 2; ca++)
		for (wa = 0; wa < 2; wa++) {
		    if ((ca && (!ra)) && (at & 1)) {
			continue;
		    }
		    if ((wa && (!nk)) && (at & 2)) {
			continue;
		    }
		    int ck = ca & wa;
		    if ((ck && (!size)) && (at & 4)) {
			continue;
		    }
		    int d = 0;
		    if ((at & 1) && (ca == ra)) {
			d |= 1;
		    }
		    if ((at & 2) && (wa == nk)) {
			d |= 2;
		    }
		    if ((at & 4) && (ck == size)) {
			d |= 4;
		    }
		    x[at][clear] += x[d][clear - 1];
		}
	}
    }
    printf("%lld\n", x[7][32]);
}

int Main()
{
    int first_iteration;
    int _;
    new_assert(scanf("%d", &_) == 1);
    int nc;
    for (nc = 0; nc < _; nc++) {
	printf("Case #%d: ", nc + 1);
	clear();
    }
    return 0;
}

void new_assert(int expression)
{
    return assert(expression);
}
