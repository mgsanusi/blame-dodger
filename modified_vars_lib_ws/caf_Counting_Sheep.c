#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void act_test(int t)
{
    long long c;
    long long ok;
    long long e;
    unsigned seen = 0;
    scanf("%lld", &c);
    if (c == 0) {
	printf("Case #%d: INSOMNIA\n", t + 1);
	return;
    }
    ok = 0;
    while (seen != 0x3ff) {
	ok += c;
	for (e = ok; e; e /= 10)
	    seen |= 1U << (e % 10);
    }
    printf("Case #%d: %lld\n", t + 1, ok);
}

int Main()
{
    int t;
    int i;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
	act_test(i);
    return 0;
}
