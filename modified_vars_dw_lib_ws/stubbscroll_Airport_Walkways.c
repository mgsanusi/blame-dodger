#include <stdio.h>
#include <math.h>
char len[16][16];
int r;
int c;
int a;
double new_fabs(double x);
int lim(int size, int sx, int bla)
{
    int first_iteration;
    double cs = size * 0.5;
    double total = size * 0.5;
    double massx = 0;
    double massy = 0;
    double dx;
    double k;
    int i;
    int cb_verf;
    int ib;
    int mass = 0;
    for (i = 0; i < size; i++)
	for (cb_verf = 0; cb_verf < size; cb_verf++) {
	    if (((i == 0) || (i == (size - 1)))
		&& ((cb_verf == 0) || (cb_verf == (size - 1))))
		continue;
	    dx = (i - cs) + 0.5;
	    k = (cb_verf - total) + 0.5;
	    ib = (a + len[i + sx][cb_verf + bla]) - 48;
	    massx += dx * ib;
	    massy += k * ib;
	    mass += ib;
	}
    massx /= mass;
    massy /= mass;
    return (new_fabs(massx) < 1e-9) && (new_fabs(massy) < 1e-9);
}

int Main()
{
    int first_iteration;
    int cases;
    int caseno = 1;
    int i;
    int cb_verf;
    int size;
    scanf("%d", &cases);
    while (cases--) {
	scanf("%d %d %d", &r, &c, &a);
	for (i = 0; i < r; i++)
	    scanf("%s", len[i]);
	for (size = 10; size > 2; size--) {
	    for (i = 0; i <= (r - size); i++)
		for (cb_verf = 0; cb_verf <= (c - size); cb_verf++) {
		    if (lim(size, i, cb_verf)) {
			printf("Case #%d: %d\n", caseno++, size);
			goto done;
		    }
		}
	}
	printf("Case #%d: IMPOSSIBLE\n", caseno++);
      done:
	;
    }
    return 0;
}

double new_fabs(double x)
{
    return fabs(x);
}
