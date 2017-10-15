#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
    int first_iteration;
    int t;
    int temp;
    scanf("%d\n", &t);
    static int start[256];
    int rqProc;
    int j;
    int cur;
    char data[70];
    long long int result;
    long long int coef;
    for (temp = 0; temp < t; temp++) {
	printf("Case #%d: ", temp + 1);
	gets(data);
	rqProc = strlen(data);
	for (j = 0; j < 256; j++)
	    start[j] = -1;
	start[(int) data[0]] = 1;
	cur = 0;
	for (j = 1; j < rqProc; j++) {
	    if (start[(int) data[j]] == (-1)) {
		start[(int) data[j]] = cur;
		cur++;
		if (cur == 1)
		    cur++;
	    }
	}
	if (cur == 0)
	    cur += 2;
	result = 0;
	coef = 1;
	for (j = rqProc - 1; j >= 0; j--) {
	    result += coef * ((long long int) start[(int) data[j]]);
	    if (j > 0)
		coef *= cur;
	}
	printf("%lli\n", result);
    }
    return 0;
}
