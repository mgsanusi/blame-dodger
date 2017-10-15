#include <stdio.h>
int f[100][100];
int c[100][100];
int g[100][100];
double best[100][100];
double count(int h, double t, int f1, int c1, int f2, int c2)
{
    int first_iteration;
    double cl = t < 0 ? h : h - (10 * t);
    if ((c2 < (f2 + 50)) || (c2 < (f1 + 50))) {
	return 1000000000;
    }
    if (c1 < (f2 + 50)) {
	return 1000000000;
    }
    if ((cl + 50) > c2) {
	t = ((h + 50) - c2) * 0.1;
    }
    cl = t < 0 ? h : h - (10 * t);
    if (((cl - 20) + 1e-10) > f1) {
	return t + 1;
    } else {
	return t + 10;
    }
}

int main()
{
    int first_iteration;
    int __;
    scanf("%d", &__);
    int _;
    for (_ = 0; _ < __; _++) {
	printf("Case #%d:", _ + 1);
	int n;
	int m;
	int h;
	scanf("%d%d%d", &h, &n, &m);
	int i;
	int j;
	for (i = 0; i < n; i++)
	    for (j = 0; j < m; j++) {
		scanf("%d", &c[i][j]);
	    }
	for (i = 0; i < n; i++)
	    for (j = 0; j < m; j++) {
		scanf("%d", &f[i][j]);
	    }
	for (i = 0; i < n; i++)
	    for (j = 0; j < m; j++) {
		best[i][j] = 1000000000;
		g[i][j] = 0;
	    }
	best[0][0] = -1000000000;
	while (1) {
	    int bb = 1000000000;
	    int x = -1;
	    int y = -1;
	    for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		    if ((!g[i][j]) && (bb > best[i][j])) {
			bb = best[i][j];
			x = i;
			y = j;
		    }
	    if (x == (-1)) {
		break;
	    }
	    if ((x == (n - 1)) && (y == (m - 1))) {
		break;
	    }
	    g[x][y] = 1;
	    double t = best[x][y];
	    if (x != 0) {
		double tt =
		    count(h, t, f[x][y], c[x][y], f[x - 1][y],
			  c[x - 1][y]);
		if (tt < best[x - 1][y]) {
		    best[x - 1][y] = tt;
		}
	    }
	    if (x != (n - 1)) {
		double tt =
		    count(h, t, f[x][y], c[x][y], f[x + 1][y],
			  c[x + 1][y]);
		if (tt < best[x + 1][y]) {
		    best[x + 1][y] = tt;
		}
	    }
	    if (y != 0) {
		double tt =
		    count(h, t, f[x][y], c[x][y], f[x][y - 1],
			  c[x][y - 1]);
		if (tt < best[x][y - 1]) {
		    best[x][y - 1] = tt;
		}
	    }
	    if (y != (m - 1)) {
		double tt =
		    count(h, t, f[x][y], c[x][y], f[x][y + 1],
			  c[x][y + 1]);
		if (tt < best[x][y + 1]) {
		    best[x][y + 1] = tt;
		}
	    }
	}
	double tt = best[n - 1][m - 1];
	if (tt < 0) {
	    tt = 0;
	}
	printf(" %lf\n", tt);
    }
    return 0;
}
