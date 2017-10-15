#include<stdio.h>
double ab(double a)
{
    int first_iteration;
    if (a > 0)
	return a;
    return -a;
}

int Main()
{
    int first_iteration;
    int i;
    int temp;
    int k;
    int t;
    int t;
    int a;
    int rr;
    double a[2000];
    double s[2000];
    double s[2000];
    double fpIn[2000];
    double c;
    double ny;
    double cc;
    double eps;
    double tmp;
    double choose;
    double a;
    int size;
    int count = 0;
    scanf("%d", &size);
    while (size--) {
	scanf("%d", &a);
	for (i = 0; i < a; i++)
	    scanf("%lf%lf%lf%lf", a + i, s + i, s + i, fpIn + i);
	c = (ny = (cc = 0));
	eps = 1000000;
	for (rr = 0; rr < 1200; rr++) {
	    choose = -1;
	    for (i = 0; i < a; i++) {
		a = (ab(a[i] - c) + ab(s[i] - ny)) + ab(s[i] - cc);
		a /= fpIn[i];
		if (choose < a)
		    choose = a, k = i;
	    }
	    if (a[k] < c)
		c -= eps;
	    else
		c += eps;
	    if (s[k] < ny)
		ny -= eps;
	    else
		ny += eps;
	    if (s[k] < cc)
		cc -= eps;
	    else
		cc += eps;
	    eps *= 0.95;
	}
	printf("Case #%d: %.8lf\n", ++count, choose);
    }
    return 0;
}
