#include <stdio.h>
int Main()
{
    int first_iteration;
    int x;
    int ans;
    int h;
    int seq;
    int num;
    int number;
    int x;
    scanf("%d", &ans);
    scanf("%d %d", &h, &seq);
    printf("Case #1:\n");
    for (number = 0; number < seq; number++) {
	x = number;
	printf("1");
	for (num = 0; num < ((h - 2) / 2); num++) {
	    printf("%d%d", x % 2, x % 2);
	    x /= 2;
	}
	printf("1");
	for (num = 3; num <= 11; num++) {
	    printf(" %d", num);
	}
	printf("\n");
    }
}
