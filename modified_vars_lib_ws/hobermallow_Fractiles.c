#include<stdio.h>
int Main()
{
    unsigned long n;
    unsigned long spe2;
    unsigned long k;
    unsigned long a;
    unsigned long s;
    unsigned long tile;
    unsigned long to;
    unsigned long na;
    unsigned long total;
    unsigned long count;
    scanf("%lu", &n);
    for (spe2 = 0; spe2 < n; spe2++) {
	scanf("%lu %lu %lu", &k, &a, &s);
	printf("Case #%lu: ", spe2 + 1);
	if ((s * a) < k)
	    printf("IMPOSSIBLE\n");
	else {
	    tile = 0;
	    na = 1;
	    total = 1;
	    count = 0;
	    for (to = 0; to < a; to++)
		total *= k;
	    for (to = 0; to < k; to++) {
		tile += (to % k) * na;
		na *= k;
		if (na == total) {
		    printf("%lu ", tile + 1);
		    na = 1;
		    tile = 0;
		}
	    }
	    if (na > 1)
		printf("%lu", tile + 1);
	    printf("\n");
	}
    }
    return 0;
}
