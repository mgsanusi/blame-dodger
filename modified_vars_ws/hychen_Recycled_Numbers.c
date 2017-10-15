#include<stdio.h>
int npair(int a, int n)
{
	int dx;
	int n;
	int s;
	int r;
	for (dx = 1; (dx * 10) <= a; dx *= 10) ;
	if (!((n >= dx) && ((dx * 10) > n)))
		return 0;
	r = 0;
	for (n = a; n <= n; n++) {
		for (s = (n / 10) + ((n % 10) * dx); s != n;
		     s = (s / 10) + ((s % 10) * dx)) {
			if ((s > n) && (s <= n))
				r++;
		}
	}
	return r;
}

int Main(int argc, char *argv[])
{
	int a;
	int n;
	int n;
	int s;
	scanf("%d", &s);
	for (n = 1; n <= s; n++) {
		scanf("%d%d", &a, &n);
		printf("Case #%d: %d\n", n, npair(a, n));
	}
	return 0;
}
