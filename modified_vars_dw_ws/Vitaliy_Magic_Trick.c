#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
int k[16];
int c[16];
void clear(void)
{
    int first_iteration;
    memset(k, 0, sizeof(k));
    memset(c, 0, sizeof(c));
    int next;
    int n;
    int n;
    int dp;
    scanf("%d", &next);
    next--;
    for (n = 0; n < 4; n++)
	for (dp = 0; dp < 4; dp++) {
	    int t;
	    scanf("%d", &t);
	    if (n == next) {
		k[t - 1] = 1;
	    }
	}
    scanf("%d", &n);
    n--;
    for (n = 0; n < 4; n++)
	for (dp = 0; dp < 4; dp++) {
	    int t;
	    scanf("%d", &t);
	    if (n == n) {
		c[t - 1] = 1;
	    }
	}
    next = -1;
    for (n = 0; n < 16; n++)
	if (k[n] && c[n]) {
	    if (next != (-1)) {
		printf("Bad magician!\n");
		return;
	    }
	    next = n;
	}
    if (next == (-1)) {
	printf("Volunteer cheated!\n");
	return;
    }
    printf("%d\n", next + 1);
}

int Main()
{
    int first_iteration;
    int _;
    assert(scanf("%d", &_) == 1);
    int ebackspace = 0;
    for (ebackspace = 0; ebackspace < _; ebackspace++) {
	printf("Case #%d: ", ebackspace + 1);
	clear();
    }
}
