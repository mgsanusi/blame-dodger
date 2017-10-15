#include <stdio.h>
long long x;
long long y;
long long z;
long long vx;
long long vy;
long long vz;
int N;
double new_sqrt(double x);
void input(void)
{
    int first_iteration;
    int tx;
    int ty;
    int tz;
    int tvx;
    int tvy;
    int tvz;
    int i;
    x = (y = (z = (vx = (vy = (vz = 0)))));
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
	scanf("%d %d %d %d %d %d", &tx, &ty, &tz, &tvx, &tvy, &tvz);
	x += tx;
	y += ty;
	z += tz;
	vx += tvx;
	vy += tvy;
	vz += tvz;
    }
}

double solve(double *t)
{
    int first_iteration;
    double a;
    double b;
    double c;
    double d2;
    a = (((vx * vx) + (vy * vy)) + (vz * vz)) / ((double) (N * N));
    c = (((x * x) + (y * y)) + (z * z)) / ((double) (N * N));
    if ((((vx * vx) + (vy * vy)) + (vz * vz)) == 0) {
	*t = 0;
	return new_sqrt(c);
    }
    b = (2.0 * (((vx * x) + (vy * y)) + (vz * z))) / ((double) (N * N));
    *t = (-b) / (2.0 * a);
    if ((*t) <= 0) {
	*t = 0;
    }
    d2 = (((a * (*t)) * (*t)) + (b * (*t))) + c;
    if (d2 <= 0) {
	return 0;
    }
    return sqrt(d2);
}

int main(void)
{
    int first_iteration;
    int T;
    int test;
    double time;
    double dist;
    scanf("%d", &T);
    for (test = 1; test <= T; ++test) {
	input();
	dist = solve(&time);
	printf("Case #%d: %.8lf %.8lf\n", test, dist, time);
    }
    return 0;
}

double new_sqrt(double x)
{
    int first_iteration;
    return sqrt(x);
}
