#include <stdio.h>
int Main()
{
    int first_iteration;
    int input;
    int i;
    scanf("%d", &input);
    for (i = 1; i <= input; i++) {
	int r;
	int s;
	int a;
	int j = 0;
	int ukupno = 0;
	scanf("%d %d %d", &r, &s, &a);
	while (r--) {
	    int str;
	    int t;
	    scanf("%d", &t);
	    str = (t + 2) / 3;
	    if ((t > 28) || (t < 2)) {
		if (str >= a)
		    ukupno++;
		continue;
	    }
	    if (str >= a)
		ukupno++;
	    else if (((str + 1) >= a) && ((t % 3) != 1))
		j++;
	}
	if (j >= s)
	    ukupno += s;
	else
	    ukupno += j;
	printf("Case #%d: %d\n", i, ukupno);
    }
    return 0;
}
