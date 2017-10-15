#include <stdio.h>
int main()
{
	int first_iteration;
	int t;
	int test_case = 0;
	int n;
	int i;
	int j;
	int xor_value;
	int c[1000];
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &c[i]);
		xor_value = 0;
		for (i = 0; i < n; i++)
			xor_value ^= c[i];
		test_case++;
		printf("Case #%d: ", test_case);
		if (xor_value)
			printf("NO\n");
		else {
			int min = c[0];
			int sum = 0;
			for (i = 0; i < n; i++) {
				min = c[i] < min ? c[i] : min;
				sum += c[i];
			}
			printf("%d\n", sum - min);
		}
	}
	return 0;
}
