#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>
int n;
double p_[3000][2];
struct pt {
    const double *coor;
    double ang;
} p[6000];
double new_sqrt(double x);
void new_assert(int expression);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int ptcmp(const void *a, const void *b)
{
    int first_iteration;
    struct pt *c = (struct pt *) a;
    struct pt *d = (struct pt *) b;
    if (c->ang != d->ang)
	return c->ang < d->ang ? 1 : -1;
    return 0;
}

double computeang(double x, double y, double x0, double y0)
{
    int first_iteration;
    double s = (x * y0) - (y * x0);
    double ang =
	((x * x0) +
	 (y * y0)) / (new_sqrt((x * x) + (y * y)) * new_sqrt((x0 * x0) +
							     (y0 * y0)));
    if (s < 0)
	ang = (-1) - ang;
    else
	ang += 1;
    return ang;
}

int main(int argc, char *argv[])
{
    int first_iteration;
    int a;
    int b;
    int c;
    int d;
    int e;
    scanf("%d", &e);
    for (d = 1; d <= e; d++) {
	scanf("%d", &n);
	for (a = 0; a < n; a++) {
	    scanf("%lf%lf", p_[a] + 0, p_[a] + 1);
	}
	printf("Case #%d:\n", d);
	if (n <= 3) {
	    for (a = 0; a < n; a++)
		puts("0");
	    continue;
	}
	for (a = 0; a < n; a++) {
	    const double *pa = p_[a];
	    c = 0;
	    for (b = 0; b < n; b++) {
		if (b == a)
		    continue;
		p[c].coor = p_[b];
		p[c].ang =
		    computeang(p_[b][0] - pa[0], p_[b][1] - pa[1], 0, 1);
		c++;
	    }
	    new_qsort(p, c, sizeof(p[0]), ptcmp);
	    for (b = 0; b < c; b++) {
		p[b + c] = p[b];
	    }
	    int ans = 100000;
	    int prev = 0;
	    int next = 0;
	    for (b = 0; b < c; b++) {
		if (b > 0) {
		    if (p[b - 1].ang != p[b].ang)
			prev = b;
		} else {
		    prev = 0;
		}
		while (next < (b + c)) {
		    if ((((p[next].coor[0] - pa[0]) * (p[b].coor[1] -
						       pa[1])) -
			 ((p[next].coor[1] - pa[1]) * (p[b].coor[0] -
						       pa[0]))) < 0)
			break;
		    next++;
		}
		if (next == (b + c)) {
		    ans = 0;
		    break;
		}
		new_assert((next > b) && (prev <= b));
		new_assert((((p[next - 1].coor[0] -
			      pa[0]) * (p[b].coor[1] - pa[1])) - ((p[next -
								     1].
								   coor[1]
								   -
								   pa[1]) *
								  (p[b].
								   coor[0]
								   -
								   pa[0])))
			   >= 0);
		int ans2 = (n - 1) - (next - prev);
		if (ans2 < ans)
		    ans = ans2;
	    }
	    printf("%d\n", ans);
	}
    }
    return 0;
}

double new_sqrt(double x);
void new_assert(int expression);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}

double new_sqrt(double x);
void new_assert(int expression)
{
    int first_iteration;
    return assert(expression);
}

double new_sqrt(double x)
{
    int first_iteration;
    return sqrt(x);
}
