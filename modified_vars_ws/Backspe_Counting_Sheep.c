#include <stdio.h>
int Main()
{
    int b;
    int h;
    int r;
    int numTestCases;
    int y;
    int d[10];
    scanf("%d", &h);
    for (b = 1; b <= h; b++) {
	scanf("%d", &r);
	printf("Case #%d: ", b);
	if (r == 0) {
	    printf("INSOMNIA\n");
	} else {
	    for (numTestCases = 0; numTestCases < 10; numTestCases++)
		d[numTestCases] = 0;
	    numTestCases = 0;
	    while ((((((((((d[0] * d[1]) * d[2]) * d[3]) * d[4]) * d[5]) *
		       d[6]) * d[7]) * d[8]) * d[9]) == 0) {
		numTestCases++;
		y = numTestCases * r;
		while (y > 0) {
		    d[y % 10] = 1;
		    y /= 10;
		}
	    }
	    printf("%d\n", numTestCases * r);
	}
    }
}
