#include <stdio.h>

int main(void)
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int i, n, min = 10000000, sum = 0, xor = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			sum += x;
			xor ^= x;
			if (x < min) min = x;
		}
		printf("Case #%d: ", ti);
		if (xor == 0) printf("%d\n", sum-min);
		else printf("NO\n");
	}
	return 0;
}
