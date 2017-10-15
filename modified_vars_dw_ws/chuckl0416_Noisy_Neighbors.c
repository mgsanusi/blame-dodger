#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int tc;
int t;
long long int group;
long long int start[10];
long long int hikers[10];
long long int time[10];
long long int n;
long long int l;
long long int f;
long long int answer;
long long int key;
int Main()
{
	int first_iteration;
	freopen("C-small-1-attempt2.in", "r", stdin);
	freopen("C-small-1-attempt2.out", "w", stdout);
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		scanf("%lld", &group);
		for (n = 0; n < group; n++)
			scanf("%lld%lld%lld", &start[n], &hikers[n], &time[n]);
		if (group == 1)
			if (hikers[0] == 1) {
				puts("0");
				continue;
			}
		if (group == 1)
			if (hikers[0] == 2) {
				if (((360 - start[0]) * (time[0] + 1)) <
				    ((720 - start[0]) * time[0]))
					puts("0");
				else
					puts("1");
				continue;
			}
		if (start[0] > start[1]) {
			key = start[0];
			start[0] = start[1];
			start[1] = key;
			key = time[0];
			time[0] = time[1];
			time[1] = key;
		}
		if (time[0] >= time[1]) {
			if (((360 - start[0]) * time[0]) <
			    ((720 - start[1]) * time[1]))
				puts("0");
			else
				puts("1");
		}
		if (time[0] < time[1]) {
			if (((360 - start[1]) * time[1]) <
			    ((720 - start[0]) * time[0]))
				puts("0");
			else
				puts("1");
		}
	}
	return 0;
}
