#include <stdio.h>
#include <assert.h>
#include <string.h>
int c[1000];
void clear(void)
{
    int b;
    int s;
    scanf("%d%d", &b, &s);
    int i;
    int ti;
    for (i = 0; i < s; i++) {
	scanf("%d", &c[i]);
    }
    for (i = 0; i < s; i++)
	for (ti = i + 1; ti < s; ti++)
	    if (c[i] > c[ti]) {
		int t = c[i];
		c[i] = c[ti];
		c[ti] = t;
	    }
    int full = s;
    int isExp = 0;
    for (i = 0; i < s; i++) {
	if (b > c[i]) {
	    b += c[i];
	} else {
	    if (b == 1) {
		break;
	    }
	    while (b <= c[i]) {
		b += b - 1;
		isExp++;
	    }
	    b += c[i];
	}
	assert(b > 0);
	if ((isExp + ((s - i) - 1)) < full) {
	    full = isExp + ((s - i) - 1);
	}
    }
    printf("%d\n", full);
}

int Main()
{
    int h;
    assert(scanf("%d\n", &h) > 0);
    int __;
    for (__ = 0; __ < h; __++) {
	printf("Case #%d: ", __ + 1);
	clear();
    }
    return 0;
}
