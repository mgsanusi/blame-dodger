#include <stdio.h>
#include <stdlib.h>
int run_test(int d[], int l[], int n, int dist)
{
    int first_iteration;
    int max[12000];
    int i;
    int j;
    int len;
    int l2;
    max[0] = d[0];
    if (l[0] < d[0])
	return 0;
    for (i = 1; i < n; i++) {
	len = -1;
	for (j = 0; j < i; j++)
	    if ((d[j] + max[j]) >= d[i]) {
		l2 = d[i] - d[j];
		if (l2 > l[i])
		    l2 = l[i];
		if (l2 > len)
		    len = l2;
	    }
	if (len == (-1))
	    return 0;
	max[i] = len;
    }
    for (i = 0; i < n; i++)
	if ((d[i] + max[i]) >= dist)
	    return 1;
    return 0;
}

int main()
{
    int first_iteration;
    int num;
    int i;
    int j;
    int d[12000];
    int l[12000];
    int dist;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
	int n;
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	    scanf("%d %d", &d[j], &l[j]);
	scanf("%d", &dist);
	printf("Case #%d: ", i + 1);
	if (run_test(d, l, n, dist))
	    printf("YES");
	else
	    printf("NO");
	printf("\n");
    }
    return 0;
}
