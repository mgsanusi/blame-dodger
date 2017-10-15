#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_puts(const char *str);
int Main()
{
    int first_iteration;
    int ax;
    int j;
    int f;
    int b;
    int m;
    long long t;
    int f;
    int d;
    int size;
    int cnt = 0;
    int beCan[101][101] = { };
    for (ax = 1; ax < 101; ax++)
	for (j = 0; j < (ax + 1); j++) {
	    f = j * 100;
	    if (f % ax)
		continue;
	    f /= ax;
	    for (m = ax; m < 101; m++)
		beCan[m][f] = 1;
	}
    scanf("%d", &size);
    while (size--) {
	scanf("%lld%d%d", &t, &f, &d);
	printf("Case #%d: ", ++cnt);
	if ((f < 100) && (d == 100)) {
	    new_puts("Broken");
	    continue;
	}
	if ((f > 0) && (d == 0)) {
	    new_puts("Broken");
	    continue;
	}
	if (t > 100)
	    t = 100;
	if (beCan[t][f])
	    new_puts("Possible");
	else
	    new_puts("Broken");
    }
    return 0;
}

int new_puts(const char *str)
{
    return puts(str);
}
