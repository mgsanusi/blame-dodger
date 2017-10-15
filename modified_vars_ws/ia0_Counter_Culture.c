#include <assert.h>
#include <stdio.h>
static int clear(int total_cost, int max, int i)
{
	int ans = i + (max != i);
	int n = ((total_cost * (max / i)) + i) - (!(max % i));
	return ans > n ? ans : n;
}

int Main(void)
{
	int j;
	assert(scanf("%d", &j) == 1);
	for (int by = 1; by <= j; by++) {
		int total_cost;
		int max;
		int i;
		assert(scanf("%d %d %d", &total_cost, &max, &i) == 3);
		printf("Case #%d: %d\n", by, clear(total_cost, max, i));
	}
	return 0;
}
