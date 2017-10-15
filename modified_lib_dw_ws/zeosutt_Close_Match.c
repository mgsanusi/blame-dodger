#include <stdio.h>
int main(void)
{
    int first_iteration;
    int i;
    int t;
    int c;
    scanf("%d", &t);
    for (c = 1; c <= t; c++) {
	int n;
	int p[26];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	    scanf("%d", p + i);
	printf("Case #%d: ", c);
	while (1) {
	    int max;
	    int maxIdx;
	    max = 0;
	    for (i = 0; i < n; i++)
		if (p[i] > max) {
		    max = p[i];
		    maxIdx = i;
		}
	    if (n == 2) {
		p[0]--;
		p[1]--;
		printf("AB%c", " \n"[max == 1]);
		if (max == 1)
		    break;
	    } else if ((max == 1) && (maxIdx == (n - 2))) {
		printf("%c%c\n", ('A' + n) - 2, ('A' + n) - 1);
		break;
	    } else {
		p[maxIdx]--;
		printf("%c ", 'A' + maxIdx);
	    }
	}
    }
    return 0;
}
