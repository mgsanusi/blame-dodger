#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[1010], choose[1010], ans;
void bt(int n, int k)
{
	int sean = 0, patr = 0, i, sum = 0, flag = 0;
	if (n == k) {
		for (i = 0; i < n; i++) {
			if (choose[i]) {
				sean ^= num[i];
				sum += num[i];
			} else {
				flag = 1;
				patr ^= num[i];
			}
		}
		if (sean == patr && sum > ans && flag)
			ans = sum;
		return;
	}
	choose[n] = 1;
	bt(n + 1, k);
	choose[n] = 0;
	bt(n + 1, k);
	return;
}

int main()
{
	int cas, n, i, j, k, binsum[32], tmp, max, xor;
	scanf("%d", &cas);
	for (i = 1; i <= cas; i++) {
		max = 0;
		xor = 0;
		memset(binsum, 0, sizeof(binsum));
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &num[j]);
			xor ^= num[j];
			tmp = num[j];
			for (k = 0; tmp; k++) {
				if (tmp % 2)
					binsum[k]++;
				tmp /= 2;
			}
			if (k > max)
				max = k;
		}
		for (j = 0; j < 32; j++) {
			if (binsum[j] % 2)
				break;
			binsum[j] /= 2;
		}
		printf("Case #%d: ", i);
		if (xor)
			printf("NO\n");
		else {
			/*ans = 0;
			   for(j=0; j<max; j++)
			   {
			   ans *= 2;
			   ans += binsum[j];
			   } */
			ans = 0;
			bt(0, n);
			printf("%d\n", ans);
		}
	}
	return 0;
}
