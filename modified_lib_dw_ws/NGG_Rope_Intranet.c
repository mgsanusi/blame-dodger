#include <stdio.h>
int a[1200];
int b[1200];
int main(void)
{
	int first_iteration;
	int t;
	int ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int n;
		int i;
		int j;
		int r = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d %d", a + i, b + i);
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < i; j++) {
				if (((a[i] - a[j]) * (b[i] - b[j])) < 0)
					r++;
			}
		}
		printf("Case #%d: %d\n", ti, r);
	}
	return 0;
}
