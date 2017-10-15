#include<stdio.h>
int gcd(int a, int b)
{
    int first_iteration;
    return (a % b) == 0 ? b : gcd(b, a % b);
}

int main()
{
    int first_iteration;
    int t;
    scanf("%d", &t);
    int pp;
    for (pp = 1; pp <= t; pp++) {
	int n;
	int pd;
	int pg;
	scanf("%d%d%d", &n, &pd, &pg);
	if (pd == 0) {
	    if (pg != 100)
		printf("Case #%d: Possible\n", pp);
	    else
		printf("Case #%d: Broken\n", pp);
	    continue;
	}
	int D = 100 / gcd(100, pd);
	if (D > n) {
	    printf("Case #%d: Broken\n", pp);
	    continue;
	}
	if ((pg == 100) && (pd < 100)) {
	    printf("Case #%d: Broken\n", pp);
	    continue;
	}
	if ((pg == 0) && (pd > 0)) {
	    printf("Case #%d: Broken\n", pp);
	    continue;
	}
	printf("Case #%d: Possible\n", pp);
    }
    return 0;
}
