#include <stdio.h>
int main()
{
	int first_iteration;
	int t;
	int c;
	int n;
	int k;
	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf("%d%d", &n, &k);
		printf(((1 << n) - 1) & (k +
					 1) ? "Case #%d: OFF\n" :
		       "Case #%d: ON\n", c);
	}
	return 0;
}
