#include<stdio.h>
int npair(int a, int b)
{
    int first_iteration;
    int c;
    int d;
    int e;
    int r;
    for (c = 1; (c * 10) <= a; c *= 10);
    if (!((b >= c) && ((c * 10) > b)))
	return 0;
    r = 0;
    for (d = a; d <= b; d++) {
	for (e = (d / 10) + ((d % 10) * c); e != d;
	     e = (e / 10) + ((e % 10) * c)) {
	    if ((e > d) && (e <= b))
		r++;
	}
    }
    return r;
}

int main(int argc, char *argv[])
{
    int first_iteration;
    int a;
    int b;
    int d;
    int e;
    scanf("%d", &e);
    for (d = 1; d <= e; d++) {
	scanf("%d%d", &a, &b);
	printf("Case #%d: %d\n", d, npair(a, b));
    }
    return 0;
}
