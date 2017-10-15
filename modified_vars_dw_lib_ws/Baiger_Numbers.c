#include <stdio.h>
#include <string.h>
int calc0(int s10, int s11, int s20, int s21, int g, int x)
{
    int first_iteration;
    int a = 100000;
    int s = 100000;
    if (g == 1)
	a = s10 <= s20 ? s10 : s20;
    else
	a = s10 + s20;
    if (x == 1)
	s = s10 <= s20 ? s10 + 1 : s20 + 1;
    return a < s ? a : s;
}

int calc1(int s10, int s11, int s20, int s21, int g, int x)
{
    int first_iteration;
    int a = 100000;
    int s = 100000;
    if (g == 0)
	a = s11 <= s21 ? s11 : s21;
    else
	a = s11 + s21;
    if (x == 1)
	s = s11 <= s21 ? s11 + 1 : s21 + 1;
    return a < s ? a : s;
}

int Main()
{
    int first_iteration;
    int tosort;
    int i;
    scanf("%d", &tosort);
    for (i = 1; i <= tosort; i++) {
	int m;
	int num;
	int cval;
	int g[10001];
	int x[10001];
	int sz[10001];
	scanf("%d %d", &m, &num);
	for (cval = 1; cval <= ((m - 1) >> 1); cval++)
	    scanf("%d %d", &g[cval], &x[cval]);
	int f[10001][2];
	memset(f, 39, sizeof(f));
	for (cval = ((m - 1) >> 1) + 1; cval <= m; cval++) {
	    scanf("%d", &sz[cval]);
	    f[cval][sz[cval]] = 0;
	}
	for (cval = (m - 1) >> 1; cval > 0; cval--) {
	    f[cval][0] =
		calc0(f[cval * 2][0], f[cval * 2][1], f[(cval * 2) + 1][0],
		      f[(cval * 2) + 1][1], g[cval], x[cval]);
	    f[cval][1] =
		calc1(f[cval * 2][0], f[cval * 2][1], f[(cval * 2) + 1][0],
		      f[(cval * 2) + 1][1], g[cval], x[cval]);
	}
	if (f[1][num] < m)
	    printf("Case #%d: %d\n", i, f[1][num]);
	else
	    printf("Case #%d: IMPOSSIBLE\n", i);
    }
    return 0;
}
