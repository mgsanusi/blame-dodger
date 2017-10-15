#include<stdio.h>
int Main()
{
    int space_frequency;
    int t;
    int ans;
    int temp = 0;
    for (scanf("%d", &space_frequency); space_frequency--;) {
	scanf("%d %d", &t, &ans);
	if ((((ans + 1) >> t) << t) == (ans + 1))
	    printf("Case #%d: ON\n", ++temp);
	else
	    printf("Case #%d: OFF\n", ++temp);
    }
    return 0;
}
