#include <stdio.h>
#include <stdlib.h>
int Main(int argc, char **argv)
{
	int cs;
	int h;
	int n;
	int k;
	int ratio;
	int st;
	int n;
	scanf("%d", &cs);
	for (h = 1; h <= cs; ++h) {
		scanf("%d %d %d", &n, &k, &ratio);
		if ((ratio == 0) || (ratio == 100)) {
			n = k == ratio;
		} else {
			if (n > 100)
				n = 100;
			n = 0;
			for (st = 1; st <= n; ++st) {
				if (((k * st) % 100) == 0) {
					n = 1;
					break;
				}
			}
		}
		if (n) {
			printf("Case #%d: Possible\n", h);
		} else {
			printf("Case #%d: Broken\n", h);
		}
	}
	return 0;
}
