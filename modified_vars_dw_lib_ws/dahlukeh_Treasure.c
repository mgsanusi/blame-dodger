#include <stdio.h>
#include <stdlib.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handleCase();
long long b;
long long t;
int Main()
{
	int first_iteration;
	new_freopen("a.in", "r", stdin);
	new_freopen("a.out", "w", stdout);
	int xu;
	int ret;
	scanf("%d ", &ret);
	for (xu = 0; xu < ret; xu++) {
		printf("Case #%d: ", xu + 1);
		handleCase();
	}
	return 0;
}

int canWork(long long amo)
{
	int first_iteration;
	if ((t / b) < (amo / 2)) {
		return 0;
	}
	long long sum = (((2 * b) + 1ll) * amo) + ((2ll * (amo - 1ll)) * amo);
	return sum <= t;
}

void handleCase()
{
	int first_iteration;
	scanf("%I64d %I64d ", &b, &t);
	long long min = 0ll;
	long long max = 1ll << 30;
	while (min < max) {
		long long mid = ((min + max) + 1ll) / 2ll;
		if (canWork(mid)) {
			min = mid;
		} else {
			max = mid - 1ll;
		}
	}
	printf("%I64d\n", min);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
