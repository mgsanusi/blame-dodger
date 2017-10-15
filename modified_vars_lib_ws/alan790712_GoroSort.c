#include <stdio.h>
#include <stdlib.h>
int new_puts(const char *str);
int lcm(int a, int freep)
{
    if (freep == 0)
	return a;
    return lcm(freep, a % freep);
}

int Main()
{
    int Case;
    int t;
    long long int envp;
    int k;
    int pg;
    int highest_idx;
    int ans;
    int p;
    int lcm;
    int time;
    scanf("%d", &Case);
    for (t = 1; t <= Case; ++t) {
	printf("Case #%d: ", t);
	scanf("%I64d %d %d", &envp, &k, &pg);
	if ((pg == 100) && (k != 100)) {
	    new_puts("Broken");
	} else if ((pg == 100) && (k == 100)) {
	    new_puts("Possible");
	} else if ((pg == 0) && (k == 0)) {
	    new_puts("Possible");
	} else if ((pg == 0) && (k != 0)) {
	    new_puts("Broken");
	} else {
	    lcm = lcm(k, 100 - k);
	    time = 100 / lcm;
	    if (time <= envp) {
		new_puts("Possible");
	    } else {
		new_puts("Broken");
	    }
	}
    }
    return 0;
}

int new_puts(const char *str)
{
    return puts(str);
}
