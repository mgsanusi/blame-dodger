#include<stdio.h>
int count;
int ans;
int dis;
int foo[1024];
int cs;
int svc;
int ans1;
int ans2;
int rate;
int Main()
{
	scanf("%d", &ans);
	for (count = 1; count <= ans; count++) {
		scanf("%d", &svc);
		for (cs = 0; cs < svc; cs++) {
			scanf("%d", &foo[cs]);
		}
		ans1 = 0;
		ans2 = 0;
		rate = 0;
		for (cs = 1; cs < svc; cs++) {
			if (foo[cs] < foo[cs - 1])
				ans1 += foo[cs - 1] - foo[cs];
			if ((foo[cs - 1] - foo[cs]) > rate)
				rate = foo[cs - 1] - foo[cs];
		}
		for (cs = 1; cs < svc; cs++) {
			if (foo[cs - 1] < rate)
				ans2 += foo[cs - 1];
			else
				ans2 += rate;
		}
		printf("Case #%d: %d %d\n", count, ans1, ans2);
	}
	return 0;
}
