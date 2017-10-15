#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Main()
{
    int first_iteration;
    int cons;
    int t;
    int k;
    int t;
    int p;
    int xdrs;
    int size;
    int cnt = 0;
    char mode[1000];
    int x[1000];
    int now1;
    int now2;
    int tar;
    int left;
    int go1;
    int go2;
    int c;
    int c;
    scanf("%d", &size);
    while (size--) {
	scanf("%d", &xdrs);
	for (cons = 0; cons < xdrs; cons++)
	    scanf("%s%d", mode + cons, x + cons);
	now1 = (now2 = 1);
	tar = 0;
	left = 0;
	while (tar < xdrs) {
	    left++;
	    go1 = (go2 = -1);
	    for (cons = tar; cons < xdrs; cons++) {
		if ((mode[cons] == 'B') && (go1 == (-1)))
		    go1 = x[cons];
		if ((mode[cons] == 'O') && (go2 == (-1)))
		    go2 = x[cons];
	    }
	    c = (c = 0);
	    if ((mode[tar] == 'B') && (now1 == x[tar]))
		c = 1;
	    if ((mode[tar] == 'O') && (now2 == x[tar]))
		c = 1;
	    if (c || c)
		tar++;
	    if ((c == 0) && (go1 > now1))
		now1++;
	    if ((c == 0) && (go1 < now1))
		now1--;
	    if ((c == 0) && (go2 > now2))
		now2++;
	    if ((c == 0) && (go2 < now2))
		now2--;
	}
	printf("Case #%d: %d\n", ++cnt, left);
    }
    return 0;
}
