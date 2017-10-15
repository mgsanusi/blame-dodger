#include<stdio.h>
char getsmallest(int *t, int len2)
{
    int now;
    int c = 0;
    for (now = 1; now < len2; now++)
	if (t[c] < t[now])
	    c = now;
    t[c]--;
    return (char) c;
}

int Main()
{
    int x;
    int a;
    int now;
    int sum;
    int len2;
    char ddel;
    char p;
    int t[1000];
    scanf("%d", &a);
    for (x = 1; x <= a; x++) {
	scanf("%d", &len2);
	for (sum = 0, now = 0; now < len2; now++) {
	    scanf("%d", t + now);
	    sum += t[now];
	}
	printf("Case #%d:", x);
	while (1) {
	    ddel = getsmallest(t, len2);
	    if ((sum == len2) && (len2 & 1)) {
		sum--;
		printf(" %c", 'A' + ddel);
		continue;
	    }
	    if ((--sum) == 0) {
		printf(" %c\n", 'A' + ddel);
		break;
	    }
	    p = getsmallest(t, len2);
	    printf(" %c%c", 'A' + ddel, 'A' + p);
	    if ((--sum) == 0) {
		printf("\n");
		break;
	    }
	}
    }
}
