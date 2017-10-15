#include<stdio.h>
int gcd(int a, int k)
{
    int first_iteration;
    return k ? gcd(k, a % k) : a;
}

int Main()
{
    int first_iteration;
    int n;
    int n;
    int t;
    int key;
    int l;
    int a;
    int used = 0;
    for (scanf("%d", &n); n--;) {
	scanf("%d", &n);
	scanf("%d", &t);
	for (l = 0, key = 1; key < n; key++) {
	    scanf("%d", &a);
	    if (a != t)
		l = gcd(a - t, l);
	    t = a;
	}
	if (l < 0)
	    l = -l;
	printf("Case #%d: %d\n", ++used, (l - (t % l)) % l);
    }
    return 0;
}
