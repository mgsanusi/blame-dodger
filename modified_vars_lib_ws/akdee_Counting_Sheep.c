#include <stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
long long last(long long n)
{
    if (n == 0)
	return -1;
    int j = 0;
    int mask = 0;
    while (mask != 0x3ff) {
	long long t = n * (++j);
	while (t != 0) {
	    mask |= 1 << (t % 10);
	    t /= 10;
	}
	if (j > 72)
	    fprintf(stderr, "ERROR: %lld\n", n);
    }
    return n * j;
}

int Main()
{
    new_freopen("A-small-attempt0.in", "rb", stdin);
    new_freopen("output.txt", "wb", stdout);
    int cases;
    scanf("%d", &cases);
    for (int dir = 1; dir <= cases; dir++) {
	long long n;
	scanf("%lld", &n);
	if ((n = last(n)) == (-1))
	    printf("Case #%d: INSOMNIA\n", dir);
	else
	    printf("Case #%d: %lld\n", dir, n);
    }
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
