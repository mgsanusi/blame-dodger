#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
    int first_iteration;
    int c;
    int m;
    scanf("%d", &c);
    int key_ratio;
    int pw;
    int casenum;
    int y;
    int temp;
    static char data[50][50];
    static int a[50];
    int answer;
    for (m = 0; m < c; m++) {
	scanf("%d\n", &key_ratio);
	for (pw = 0; pw < key_ratio; pw++) {
	    gets(data[pw]);
	    a[pw] = -1;
	    for (casenum = 0; casenum < key_ratio; casenum++) {
		if (data[pw][casenum] == '1')
		    a[pw] = casenum;
	    }
	}
	answer = 0;
	for (pw = 0; pw < (key_ratio - 1); pw++) {
	    if (a[pw] > pw) {
		casenum = pw;
		while (a[casenum] > pw)
		    casenum++;
		answer += casenum - pw;
		temp = a[casenum];
		for (y = casenum - 1; y >= pw; y--)
		    a[y + 1] = a[y];
		a[pw] = temp;
	    }
	}
	printf("Case #%d: %d\n", m + 1, answer);
    }
    return 0;
}
