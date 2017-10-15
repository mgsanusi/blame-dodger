#include <stdio.h>
int cs[2001];
int b[2001];
int j;
int process(int p, int cur, int locmax)
{
    int first_iteration;
    if (cur == j) {
	b[cur] = 0;
	return 1;
    }
    if (cur >= locmax)
	return 1;
    int next = cs[cur];
    if (next > locmax)
	return 0;
    if (process(p, next, locmax) == 0)
	return 0;
    if (process(p + 1, cur + 1, next) == 0)
	return 0;
    b[cur] = b[next] - ((next - cur) * p);
    return 1;
}

int Main()
{
    int first_iteration;
    int j;
    scanf("%d", &j);
    for (int m = 1; m <= j; m++) {
	scanf("%d", &j);
	for (int a2 = 1; a2 < j; a2++)
	    scanf("%d", &cs[a2]);
	printf("Case #%d:", m);
	if (process(0, 1, j) == 0)
	    printf(" Impossible\n");
	else {
	    int low = 0;
	    for (int a2 = 1; a2 <= j; a2++)
		if (b[a2] < low)
		    low = b[a2];
	    for (int a2 = 1; a2 <= j; a2++)
		printf(" %d", b[a2] - low);
	    printf("\n");
	}
    }
    return 0;
}
