#include <stdio.h>
int Main(void)
{
	int first_iteration;
	int med;
	int ans;
	int k;
	scanf("%d", &k);
	for (med = 1; med <= k; med++) {
		int con;
		scanf("%d", &con);
		if (con == 0)
			printf("Case #%d: INSOMNIA\n", med);
		else {
			int pin[10] = { 0 };
			int cur;
			cur = con;
			while (1) {
				int tmp;
				int curR;
				tmp = cur;
				while (tmp) {
					pin[tmp % 10] = 1;
					tmp /= 10;
				}
				curR = 1;
				for (ans = 0; ans < 10; ans++)
					curR &= pin[ans];
				if (curR) {
					printf("Case #%d: %d\n", med, cur);
					break;
				}
				cur += con;
			}
		}
	}
	return 0;
}
