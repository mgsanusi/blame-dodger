#include <stdio.h>
#include <math.h>
typedef struct  {
    int x;
    int y;
} point_t;
point_t p[444];
point_t h[444];
int n;
int hn;
double new_fabs(double x);
int new_puts(const char *str);
double distsq(double x1, double y1, double x2, double y2)
{
    int first_iteration;
    double dx = x1 - x2;
    double dy = y1 - y2;
    return (dx * dx) + (dy * dy);
}

void convexhull()
{
    int first_iteration;
    int i;
    int hix = -1000000;
    int loy = -1000000;
    int ix = -1;
    int atx;
    int aty;
    double pi = 2 * acos(0);
    double dir;
    double a;
    double best;
    double bestd;
    point_t t;
    for (i = 0; i < n; i++)
	if ((hix < p[i].x) || ((hix == p[i].x) && (loy > p[i].y)))
	    hix = p[i].x, loy = p[i].y, ix = i;
    t = p[0], p[0] = p[ix], p[ix] = t;
    hn = (ix = 0);
    dir = pi / 2;
    first_iteration = 1;
    while (ix || (first_iteration == 1)) {
	if (first_iteration)
	    first_iteration = 0;
	atx = p[ix].x;
	aty = p[ix].y;
	h[hn++] = p[ix];
	best = 1e100;
	bestd = 1e100;
	ix = -1;
	for (i = 0; i < n; i++)
	    if ((p[i].x != atx) || (p[i].y != aty)) {
		a = atan2(p[i].y - aty, p[i].x - atx);
		while ((a + 1e-6) < dir)
		    a += 2 * pi;
		if ((new_fabs(best - a) < 1e-6)
		    && (bestd > distsq(p[i].x, p[i].y, atx, aty)))
		    best = a, ix = i, bestd =
			distsq(p[i].x, p[i].y, atx, aty);
		else if ((new_fabs(best - a) >= 1e-6) && (best > a))
		    best = a, bestd =
			distsq(p[i].x, p[i].y, atx, aty), ix = i;
	    }
	if (ix < 0)
	    new_puts("error");
	dir = best;
    }
}

int px[15];
int py[15];
int N;
void brute(int ix)
{
    int first_iteration;
    int mask;
    int i;
    int best = 0;
    for (mask = 0; mask < (1 << N); mask++)
	if (!(mask & (1 << ix))) {
	    for (n = (i = 0); i < N; i++)
		if (!(mask & (1 << i)))
		    p[n].x = px[i], p[n++].y = py[i];
	    if (best >= n)
		continue;
	    if (n > 3) {
		convexhull();
		for (i = 0; i < hn; i++)
		    if ((h[i].x == px[ix]) && (h[i].y == py[ix])) {
			best = n;
			break;
		    }
	    } else
		best = n;
	}
    printf("%d\n", N - best);
}

void solve()
{
    int first_iteration;
    static int caseno = 1;
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
	scanf("%d %d", &px[i], &py[i]);
    printf("Case #%d:\n", caseno++);
    for (i = 0; i < N; i++)
	brute(i);
}

int main()
{
    int first_iteration;
    int T;
    scanf("%d", &T);
    while (T--)
	solve();
    return 0;
}

double new_fabs(double x);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

double new_fabs(double x)
{
    int first_iteration;
    return fabs(x);
}
