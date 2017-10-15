#include<stdio.h>
int main()
{
	int first_iteration;
	int T;
	scanf("%d", &T);
	int l;
	for (l = 1; l <= T; l++) {
		printf("Case #%d: ", l);
		int a1;
		int a2;
		int b1;
		int b2;
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		unsigned long long ans = 0;
		int i;
		for (i = a1; i <= a2; i++) {
			int k = ((int)((i + 0.0) * 1.6180339887)) + 1;
			k = b1 > k ? b1 : k;
			if (k > b2)
				break;
			ans += (b2 - k) + 1;
		}
		for (i = b1; i <= b2; i++) {
			int k = ((int)((i + 0.0) * 1.6180339887)) + 1;
			k = a1 > k ? a1 : k;
			if (k > a2)
				break;
			ans += (a2 - k) + 1;
		}
		printf("%llu\n", ans);
	}
	return 0;
}
