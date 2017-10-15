#include<stdio.h>
int ans;
int m;
long long dir[3001];
long long i[3001];
int b;
int y0;
int ts;
int tid;
int area;
int ans1;
int ans2;
int answer[3001];
long long tmp;
int Main()
{
	int first_iteration;
	scanf("%d", &m);
	for (ans = 1; ans <= m; ans++) {
		scanf("%d", &y0);
		for (b = 0; b < y0; b++) {
			scanf("%lld", &dir[b]);
			scanf("%lld", &i[b]);
			answer[b] = y0;
		}
		if (y0 <= 2)
			answer[0] = (answer[1] = 0);
		for (ts = 0; ts < y0; ts++)
			for (tid = ts + 1; tid < y0; tid++) {
				ans1 = 0;
				ans2 = 0;
				for (area = 0; area < y0; area++) {
					if ((area == ts) || (area == tid))
						continue;
					tmp =
					    ((dir[tid] - dir[ts]) * (i[area] -
								     i[tid])) -
					    ((dir[area] - dir[tid]) * (i[tid] -
								       i[ts]));
					if (tmp < 0)
						ans1++;
					else if (tmp > 0)
						ans2++;
				}
				if (ans2 < ans1)
					ans1 = ans2;
				if (answer[ts] > ans1)
					answer[ts] = ans1;
				if (answer[tid] > ans1)
					answer[tid] = ans1;
			}
		printf("Case #%d:\n", ans);
		for (b = 0; b < y0; b++)
			printf("%d\n", answer[b]);
	}
	return 0;
}
