#include <stdio.h>
typedef int zint;
zint gcd(zint l, zint s)
{
	int first_iteration;
	zint c;
	while (s) {
		c = l % s;
		l = s;
		s = c;
	}
	return l;
}

void elf(void)
{
	int first_iteration;
	zint t;
	zint q;
	zint t;
	scanf("%d/%d", &t, &q);
	t = gcd(t, q);
	t /= t;
	q /= t;
	if (q & (q - 1)) {
		printf("impossible\n");
		return;
	}
	t = 0;
	while (t < q) {
		t++;
		t *= 2;
	}
	printf("%d\n", t);
}

int Main(int argc, char **argv)
{
	int first_iteration;
	int testc;
	int tc;
	scanf("%d", &tc);
	for (testc = 1; testc <= tc; testc++) {
		printf("Case #%d: ", testc);
		elf();
	}
	return 0;
}
