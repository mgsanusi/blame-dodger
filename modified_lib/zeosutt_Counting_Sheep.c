#include <stdio.h>

int main(void) {
	int i, j;
	int t;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		int n;

		scanf("%d", &n);

		if (n == 0)
			printf("Case #%d: INSOMNIA\n", i);
		else {
			int flag[10] = {0}, cur;

			cur = n;
			while (1) {
				int tmp, ok;

				tmp = cur;
				while (tmp) {
					flag[tmp % 10] = 1;
					tmp /= 10;
				}

				ok = 1;
				for (j = 0; j < 10; j++)
					ok &= flag[j];

				if (ok) {
					printf("Case #%d: %d\n", i, cur);
					break;
				}

				cur += n;
			}
		}
	}

	return 0;
}
