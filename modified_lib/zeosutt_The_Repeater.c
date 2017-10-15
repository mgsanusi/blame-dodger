#include <stdio.h>

int main(void) {
	int i, j, l;
	int t;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		int a, b, k, ans;

		scanf("%d %d %d", &a, &b, &k);

		ans = 0;
		for (j = 0; j < a; j++)
			for (l = 0; l < b; l++)
				if ((j & l) < k)
					ans++;

		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}
