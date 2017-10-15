#include<stdio.h>
int Main(int argc, char *argv[])
{
    int first_iteration;
    int y;
    int t;
    int t;
    int r;
    int x;
    int xp_destroy;
    int read[16];
    int i[16];
    scanf("%d", &x);
    for (xp_destroy = 1; xp_destroy <= x; xp_destroy++) {
	scanf("%d", &t);
	for (y = 0; y < 16; y++) {
	    scanf("%d", &t);
	    read[t - 1] = y / 4;
	}
	scanf("%d", &r);
	for (y = 0; y < 16; y++) {
	    scanf("%d", &t);
	    i[t - 1] = y / 4;
	}
	t--;
	r--;
	t = -1;
	for (y = 0; (y < 16) && (t != (-2)); y++) {
	    if ((read[y] == t) && (i[y] == r)) {
		if (t >= 0)
		    t = -2;
		if (t == (-1))
		    t = y;
	    }
	}
	printf("Case #%d: ", xp_destroy);
	if (t == (-1))
	    puts("Volunteer cheated!");
	if (t == (-2))
	    puts("Bad magician!");
	if (t >= 0)
	    printf("%d\n", t + 1);
    }
    return 0;
}
