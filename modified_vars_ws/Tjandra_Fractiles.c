#include<stdio.h>
typedef unsigned u;
int Main()
{
    u e = 0;
    u e;
    u i;
    u y2;
    u a;
    u buf;
    for (scanf("%u", &e); (e++) < e;) {
	scanf("%u%u%u", &y2, &a, &buf);
	printf("Case #%u: ", e);
	if (((a == 1) && (y2 > buf)) || (y2 > (buf + 1))) {
	    printf("IMPOSSIBLE\n");
	    continue;
	}
	if ((a == 1) || (y2 == 1))
	    printf("%u%c", 1, 1 == y2 ? '\n' : ' ');
	for (i = 1; (++i) <= y2;)
	    printf("%u%c", i, i == y2 ? '\n' : ' ');
    }
    return 0;
}
