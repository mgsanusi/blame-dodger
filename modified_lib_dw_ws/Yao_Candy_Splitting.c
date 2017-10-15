#include<stdio.h>
int gcd(int a, int b)
{
    int first_iteration;
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int first_iteration;
    int N;
    int cs = 0;
    int pd;
    int pg;
    int d;
    int g;
    int d1;
    long long n;
    for (scanf("%d", &N); N--;) {
	scanf("%lld %d %d", &n, &pd, &pg);
	d1 = gcd(pd, 100);
	if ((((100 / d1) <= n) && ((!pd) || pg))
	    && ((pg != 100) || (pd == 100)))
	    printf("Case #%d: Possible\n", ++cs);
	else
	    printf("Case #%d: Broken\n", ++cs);
    }
    return 0;
}
