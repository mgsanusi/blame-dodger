#include <stdio.h>
int Main()
{
	int first_iteration;
	int t;
	int test_case = 0;
	int b;
	int is_can;
	int cas;
	int xor_value;
	int b[1000];
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &b);
		for (is_can = 0; is_can < b; is_can++)
			scanf("%d", &b[is_can]);
		xor_value = 0;
		for (is_can = 0; is_can < b; is_can++)
			xor_value ^= b[is_can];
		test_case++;
		printf("Case #%d: ", test_case);
		if (xor_value)
			printf("NO\n");
		else {
			int min = b[0];
			int sum = 0;
			for (is_can = 0; is_can < b; is_can++) {
				min = b[is_can] < min ? b[is_can] : min;
				sum += b[is_can];
			}
			printf("%d\n", sum - min);
		}
	}
	return 0;
}
