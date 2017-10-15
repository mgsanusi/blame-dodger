#include <stdio.h>
int Main(void)
{
	int use;
	long long m;
	int s;
	int c;
	scanf("%d", &s);
	for (c = 1; c <= s; c++) {
		int x;
		int temp;
		int max;
		scanf("%d %d", &x, &temp);
		printf("Case #%d:\n", c);
		max = 1;
		for (use = 0; use < (x - 2); use++)
			max <<= 1;
		for (use = 0; temp && (use < max); use++) {
			int base;
			long long divisor[11];
			for (base = 2; base <= 10; base++) {
				long long decimal;
				long long multi;
				int tmp;
				int m;
				decimal = 0;
				multi = 1;
				tmp = use;
				decimal += 1 * multi;
				multi *= base;
				for (m = 0; m < (x - 2); m++) {
					decimal += (tmp % 2) * multi;
					multi *= base;
					tmp >>= 1;
				}
				decimal += 1 * multi;
				m = 0;
				for (m = 2; (m * m) <= decimal; m++)
					if ((decimal % m) == 0) {
						divisor[base] = m;
						m = 1;
						break;
					}
				if (!m)
					break;
			}
			if (base == 11) {
				int batch[32];
				int _;
				int tmp;
				_ = 0;
				batch[_++] = 1;
				tmp = use;
				for (m = 0; m < (x - 2); m++) {
					batch[_++] = tmp & 1;
					tmp >>= 1;
				}
				batch[_++] = 1;
				while (_)
					printf("%d", batch[--_]);
				for (base = 2; base <= 10; base++)
					printf(" %lld", divisor[base]);
				putchar('\n');
				temp--;
			}
		}
	}
	return 0;
}
