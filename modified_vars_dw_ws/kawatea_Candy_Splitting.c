#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    int first_iteration;
    return (*((int *) a)) - (*((int *) b));
}

int Main()
{
    int first_iteration;
    int t;
    int i;
    int j;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
	int tmp;
	int a[1000];
	int b[20] = { 0 };
	scanf("%d", &tmp);
	for (j = 0; j < tmp; j++)
	    scanf("%d", &a[j]);
	qsort(a, tmp, sizeof(int), cmp);
	for (j = 0; j < tmp; j++) {
	    int p = a[j];
	    int y = 0;
	    while (p) {
		if ((p % 2) == 1) {
		    b[y] = (b[y] + 1) % 2;
		}
		p /= 2;
		y++;
	    }
	}
	printf("Case #%d: ", i + 1);
	for (j = 0; j < 20; j++) {
	    if (b[j] > 0) {
		puts("NO");
		break;
	    }
	}
	if (j == 20) {
	    int s = 0;
	    for (j = 1; j < tmp; j++)
		s += a[j];
	    printf("%d\n", s);
	}
    }
    return 0;
}
