#include <stdio.h>

int main(void)
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int i, n, ret = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (i != x) ret++;
		}
		printf("Case #%d: %d\n", ti, ret);
	}
	return 0;
}
