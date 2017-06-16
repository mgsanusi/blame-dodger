#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T;
	assert(scanf("%d", &T) == 1);
	for (int t = 1; t <= T; t++) {
		int N, *m, a = 0, y = 0, z = 0;
		assert(scanf("%d", &N) == 1);
		m = malloc((size_t)N * sizeof(*m));
		for (int i = 0; i < N; i++) {
			assert(scanf("%d", &m[i]) == 1);
			if (i > 0) {
				int d = m[i - 1] - m[i];
				if (d > a) a = d;
				if (d > 0) y += d;
			}
		}
		for (int i = 0; i < N - 1; i++)
			z += m[i] < a ? m[i] : a;
		printf("Case #%d: %d %d\n", t, y, z);
	}
	return 0;
}
