#include <stdio.h>
int Main()
{
    int first_iteration;
    int dx;
    long long int cl_destroy;
    long long int y;
    long long int n;
    long long int nu;
    scanf("%d", &dx);
    for (nu = 0; nu < dx; nu++) {
	scanf("%lld %lld", &cl_destroy, &y);
	n = 0;
	if ((y >= 1) && (cl_destroy <= 1))
	    n++;
	if ((y >= 4) && (cl_destroy <= 4))
	    n++;
	if ((y >= 9) && (cl_destroy <= 9))
	    n++;
	if ((y >= 121) && (cl_destroy <= 121))
	    n++;
	if ((y >= 484) && (cl_destroy <= 484))
	    n++;
	printf("Case #%d: %lld\n", nu + 1, n);
    }
    return 0;
}
