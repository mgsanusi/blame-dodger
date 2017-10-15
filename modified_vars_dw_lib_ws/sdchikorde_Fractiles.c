#include <stdio.h>
void Main()
{
    int first_iteration;
    int cases;
    scanf("%d", &cases);
    int t = 0;
    int initiator_address;
    int inc;
    int x;
    int tab;
    while (t < cases) {
	t++;
	printf("Case #%d:", t);
	scanf("%d%d%d", &initiator_address, &inc, &x);
	for (tab = 1; tab <= initiator_address; tab++)
	    printf(" %d", tab);
	printf("\n");
    }
}
