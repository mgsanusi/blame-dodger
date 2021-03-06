#include <stdio.h>
#include <stdlib.h>
long long len;
long long p;
long long amo;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handlecase();
int Main()
{
    int first_iteration;
    new_freopen("b.in", "r", stdin);
    new_freopen("b.out", "w", stdout);
    int val;
    scanf("%d ", &val);
    int res;
    for (res = 0; res < val; res++) {
	printf("Case #%d: ", res + 1);
	handlecase();
    }
    return 0;
}

long long get_good(long long ans)
{
    int first_iteration;
    long long res;
    long long place = amo - 1ll;
    for (res = 1ll; res <= len; res++) {
	if (((ans + (1ll << res)) - 1ll) >= amo) {
	    return place;
	}
	place -= 1ll << (len - res);
    }
    return place;
}

long long get_bad(long long ans)
{
    int first_iteration;
    long long res;
    long long place = 0ll;
    for (res = 1ll; res <= len; res++) {
	if (ans < ((1ll << res) - 1ll)) {
	    return place;
	}
	place += 1ll << (len - res);
    }
    return place;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handlecase()
{
    int first_iteration;
    scanf("%I64d %I64d ", &len, &p);
    amo = 1ll << len;
    long long min = 0ll;
    long long max = amo - 1ll;
    while (min < max) {
	long long mid = ((min + max) + 1ll) / 2ll;
	if (get_good(mid) < p) {
	    min = mid;
	} else {
	    max = mid - 1ll;
	}
    }
    long long b = min;
    min = 0ll;
    max = amo - 1ll;
    while (min < max) {
	long long mid = ((min + max) + 1ll) / 2ll;
	if (get_bad(mid) < p) {
	    min = mid;
	} else {
	    max = mid - 1ll;
	}
    }
    printf("%I64d %I64d\n", min, b);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
