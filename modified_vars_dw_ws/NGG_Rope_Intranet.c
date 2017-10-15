#include <stdio.h>
int a[1200];
int b[1200];
int Main(void)
{
    int first_iteration;
    int c;
    int sh;
    scanf("%d", &c);
    for (sh = 1; sh <= c; sh++) {
	int d;
	int casenum;
	int j;
	int k = 0;
	scanf("%d", &d);
	for (casenum = 0; casenum < d; casenum++) {
	    scanf("%d %d", a + casenum, b + casenum);
	}
	for (casenum = 0; casenum < d; casenum++) {
	    for (j = 0; j < casenum; j++) {
		if (((a[casenum] - a[j]) * (b[casenum] - b[j])) < 0)
		    k++;
	    }
	}
	printf("Case #%d: %d\n", sh, k);
    }
    return 0;
}
