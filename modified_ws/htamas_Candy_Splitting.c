#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int T, N, tc, i;
    unsigned long long c, x, m, s;
    scanf("%d", &T);
    for (tc = 1; tc <= T; ++tc) {
	scanf("%d", &N);
	x = 0;
	s = 0;
	m = ~(unsigned long long) 0;
	for (i = 0; i < N; ++i) {
	    scanf("%llu", &c);
	    x ^= c;
	    s += c;
	    if (c < m)
		m = c;
	}
	if (x) {
	    printf("Case #%d: NO\n", tc);
	} else {
	    printf("Case #%d: %llu\n", tc, s - m);
	}
    }
    return 0;
}
