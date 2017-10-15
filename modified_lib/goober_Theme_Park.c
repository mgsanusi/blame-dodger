#include <stdio.h>

int main() {
	int t, c;

	scanf("%d", &t);
	for (c = 1; c <= t; c++)
	{
		int r, k, n, i;
		long long lastval[1000];
		int lastride[1000];
		int g[1000];
		int gin, gi;
		int rides;
		int firstgr;
		char timejump;
		long long total;

		scanf("%d %d %d", &r, &k, &n);
		for (i=0; i < n; i++)
		{
			lastval[i] = -1;
			lastride[i] = -1;
			scanf("%d", &g[i]);
		}
		total = 0;
		rides = -1;
		gin = 0;
		gi = 0;
		firstgr = 0;
		timejump = 0;
		while(rides < r)
		{
			if (gin + g[gi] > k || gi == firstgr)
			{
				total += gin;
				gin = 0;
				rides++;
				if (!timejump && lastval[gi] != -1)
				{
					long long skipper = rides - lastride[gi];
					long long skipval = total - lastval[gi];
					long long skipcount = (r - rides)/skipper;
					total += skipcount*skipval;
					rides += skipcount*skipper;
					timejump = 1;
				}
				lastride[gi] = rides;
				lastval[gi] = total;
				firstgr = gi;
			}
			gin += g[gi];
			if (++gi >= n)
				gi = 0;
			
		}
		printf("Case #%d: %lld\n", c, total);
	}
	return 0;
}
