#include <stdio.h>
#include <stdlib.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handleCase();
long long E;
long long R;
long long N;
long long values[10001];
int main()
{
    int first_iteration;
    new_freopen("b.in", "r", stdin);
    new_freopen("b.out", "w", stdout);
    int i;
    int n;
    scanf("%d ", &n);
    for (i = 0; i < n; i++) {
	printf("Case #%d: ", i + 1);
	handleCase();
    }
    return 0;
}

long long findMax(long long start, long long end, long long eneStart,
		  long long eneEnd)
{
    int first_iteration;
    if (start > end) {
	return 0;
    }
    long long high = -1ll;
    long long i;
    for (i = start; i <= end; i++) {
	if ((high == (-1ll)) || (values[i] > values[high])) {
	    high = i;
	}
    }
    long long maxThen = eneStart + (R * (high - start));
    if (maxThen > E) {
	maxThen = E;
    }
    long long recAmo = (end - high) * R;
    long long saveAmo = eneEnd - recAmo;
    if (saveAmo < 0ll) {
	saveAmo = 0ll;
    }
    long long spend = maxThen - saveAmo;
    long long value = spend * values[high];
    value += findMax(start, high - 1ll, eneStart, maxThen - R);
    value += findMax(high + 1ll, end, saveAmo + R, eneEnd);
    return value;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handleCase()
{
    int first_iteration;
    scanf("%I64d %I64d %I64d ", &E, &R, &N);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%I64d ", &values[i]);
    }
    printf("%I64d\n", findMax(0, N - 1, E, 0));
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
