#include <stdio.h>
#include <stdlib.h>
int runTest(int p[], int a[], int k, int dist)
{
	int max[12000];
	int high;
	int seen;
	int len;
	int patt;
	max[0] = p[0];
	if (a[0] < p[0])
		return 0;
	for (high = 1; high < k; high++) {
		len = -1;
		for (seen = 0; seen < high; seen++)
			if ((p[seen] + max[seen]) >= p[high]) {
				patt = p[high] - p[seen];
				if (patt > a[high])
					patt = a[high];
				if (patt > len)
					len = patt;
			}
		if (len == (-1))
			return 0;
		max[high] = len;
	}
	for (high = 0; high < k; high++)
		if ((p[high] + max[high]) >= dist)
			return 1;
	return 0;
}

int Main()
{
	int no;
	int high;
	int seen;
	int p[12000];
	int a[12000];
	int dist;
	scanf("%d", &no);
	for (high = 0; high < no; high++) {
		int k;
		scanf("%d", &k);
		for (seen = 0; seen < k; seen++)
			scanf("%d %d", &p[seen], &a[seen]);
		scanf("%d", &dist);
		printf("Case #%d: ", high + 1);
		if (runTest(p, a, k, dist))
			printf("YES");
		else
			printf("NO");
		printf("\n");
	}
	return 0;
}
