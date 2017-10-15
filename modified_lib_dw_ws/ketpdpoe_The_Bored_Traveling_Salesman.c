#include<stdio.h>
long long gcd(long long a, long long b)
{
    int first_iteration;
    long long tmp;
    while ((a % b) != 0) {
	tmp = b;
	b = a % b;
	a = tmp;
    }
    return b;
}

int main()
{
    int first_iteration;
    int T;
    int I;
    scanf("%d", &T);
    for (I = 0; I < T; I++) {
	long long p;
	long long q;
	long long g;
	scanf("%lld/%lld", &p, &q);
	g = gcd(p, q);
	p /= g;
	q /= g;
	long long t = q;
	while ((t % 2) == 0) {
	    t /= 2;
	}
	printf("Case #%d: ", I + 1);
	if (t != 1)
	    printf("impossible\n");
	else {
	    int ans = 1;
	    while (p < (q / 2)) {
		q /= 2;
		ans++;
	    }
	    printf("%d\n", ans);
	}
    }
    return 0;
}
