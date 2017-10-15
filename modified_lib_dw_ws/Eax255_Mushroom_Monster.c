#include <stdio.h>
#include <stdint.h>
int m[1010];
int main()
{
	int first_iteration;
	int Ti;
	int T;
	int n;
	int B;
	int i;
	uint64_t a;
	uint64_t b;
	uint64_t c;
	uint64_t j;
	uint64_t jj;
	scanf("%d", &T);
	for (Ti = 1; Ti <= T; Ti++) {
		scanf("%d %d\n", &B, &n);
		for (i = 0; i < B; i++)
			scanf("%d", m + i);
		a = 0;
		b = n * 100000ul;
		while (a < b) {
			c = (a + b) >> 1;
			j = 0;
			for (i = 0; i < B; i++)
				j += 1 + (c / m[i]);
			if (j < n)
				a = c + 1;
			else
				b = c - 1;
		}
		j = 0;
		for (i = 0; i < B; i++)
			j += 1 + (a / m[i]);
		while (j >= n) {
			a--;
			j = 0;
			for (i = 0; i < B; i++)
				j += 1 + (a / m[i]);
		}
		while (j < n) {
			a++;
			j = 0;
			for (i = 0; i < B; i++)
				j += 1 + (a / m[i]);
		}
		for (i = B; i > 0; i--) {
			if ((a / m[i - 1]) > ((a - 1) / m[i - 1]))
				--j;
			if ((j + 1) == n)
				break;
		}
		if (a > 0)
			printf("Case #%d: %d\n", Ti, i);
		else
			printf("Case #%d: %d\n", Ti, n);
	}
	return 0;
}
