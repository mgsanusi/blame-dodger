#include <stdio.h>
int main()
{
	int t, k, c, s, tc = 1, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &k, &c, &s);
		printf("Case #%d:", tc++);
		for (i = 1; i <= k; ++i) {
			printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}
