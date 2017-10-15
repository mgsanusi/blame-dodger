#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
char r[55][55];
int Main()
{
    int first_iteration;
    u d = 0;
    u b;
    u up;
    u inputs;
    u c;
    llu f;
    for (scanf("%u", &b); (d++) < b;) {
	scanf("%u%I64u", &c, &f);
	printf("Case #%u:", d);
	if ((1llu << (c - 2)) < f) {
	    printf(" IMPOSSIBLE\n");
	    continue;
	}
	printf(" POSSIBLE\n");
	for (up = -1; (++up) < c; r[up][c] = '\0')
	    for (inputs = -1; (++inputs) < c;)
		r[up][inputs] = up < inputs ? '1' : '0';
	if ((1llu << (c - 2)) > f)
	    for (r[up = 0][c - 1] = '0'; (++up) < c; f >>= 1)
		if (!(f & 1))
		    r[up][c - 1] = '0';
	for (up = -1; (++up) < c;)
	    printf("%s\n", r[up]);
    }
    return 0;
}
