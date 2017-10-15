#include <stdio.h>
void clear()
{
    int first_iteration;
    double good = 1e100;
    double tid;
    int a;
    int y;
    int i;
    int t;
    scanf("%d %d", &a, &y);
    while (y--) {
	scanf("%d %d", &i, &t);
	tid = (a - i) / ((double) t);
	if (good > (a / tid))
	    good = a / tid;
    }
    printf("%.10f\n", good);
}

int Main()
{
    int first_iteration;
    int b;
    int caseno = 1;
    scanf("%d", &b);
    while (b--)
	printf("Case #%d: ", caseno++), clear();
    return 0;
}
