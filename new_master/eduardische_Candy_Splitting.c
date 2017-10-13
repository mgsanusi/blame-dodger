#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1005
#define INFINITY 2000000000

int main ()
{
	int iT, T;
	scanf("%d",&T);
	static int a[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		int i;
		int res = 0;
		int S = 0;
		int min = INFINITY;
		scanf("%d",&N);
		for (i = 0; i < N; i++)
		{
			scanf("%d",&(a[i]));
			S += a[i];
			if (a[i] < min) min = a[i];
			res ^= a[i];
		}
		if (res) printf("Case #%d: NO\n",iT+1);
		else printf("Case #%d: %d\n",iT+1,S-min);
	}
	return 0;
}
