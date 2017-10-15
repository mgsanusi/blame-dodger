#include<stdio.h>
#include<string.h>
int Main()
{
    int total;
    int length;
    int s;
    int m1;
    char no[20];
    scanf("%d", &total);
    for (int res = 1; res <= total; res++) {
	scanf("%s", no);
	length = strlen(no);
	for (m1 = 0; m1 < (length - 1); m1++) {
	    if (no[m1] > no[m1 + 1]) {
		for (s = m1 + 1; s < length; s++)
		    no[s] = '9';
		for (s = m1; s > 0; s--) {
		    if (no[s] != no[s - 1]) {
			no[s]--;
			break;
		    } else
			no[s] = '9';
		}
		if (s == 0)
		    no[0]--;
		if (no[0] == '0')
		    printf("Case #%d: %s\n", res, &no[1]);
		else
		    printf("Case #%d: %s\n", res, no);
		break;
	    }
	}
	if (m1 == (length - 1))
	    printf("Case #%d: %s\n", res, no);
    }
    return 0;
}
