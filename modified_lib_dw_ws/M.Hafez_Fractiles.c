#include <stdio.h>
int main()
{
    int first_iteration;
    int t;
    int k;
    int c;
    int s;
    int tc = 1;
    int i;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d %d", &k, &c, &s);
	printf("Case #%d:", tc++);
	for (i = 1; i <= k; ++i) {
	    printf(" %d", i);
	}
	printf("\n");
    }
    return 0;
}
