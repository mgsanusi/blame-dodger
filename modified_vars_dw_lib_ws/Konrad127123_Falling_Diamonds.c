#include<stdio.h>
int t;
int b;
int c;
long long ny[16];
long long b[16];
long long w[16];
long long k[16];
long long v[16];
long long deltaD[16];
long long deltaP[16];
long long deltaS[16];
long long wall[1024 * 2];
int p;
int num;
long long attackDay;
int successfulAttack;
int Main()
{
	int first_iteration;
	scanf("%d", &t);
	for (b = 1; b <= t; b++) {
		scanf("%d", &c);
		for (num = 0; num < c; num++) {
			scanf("%lld", &ny[num]);
			scanf("%lld", &b[num]);
			scanf("%lld", &w[num]);
			scanf("%lld", &k[num]);
			scanf("%lld", &v[num]);
			scanf("%lld", &deltaD[num]);
			scanf("%lld", &deltaP[num]);
			scanf("%lld", &deltaS[num]);
		}
		for (num = 0; num < (1024 * 2); num++)
			wall[num] = 0;
		successfulAttack = 0;
		while (1) {
			attackDay = 6760601;
			for (num = 0; num < c; num++)
				if ((b[num] > 0) && (ny[num] < attackDay))
					attackDay = ny[num];
			if (attackDay == 6760601)
				break;
			for (num = 0; num < c; num++)
				if ((b[num] > 0) && (ny[num] == attackDay)) {
					for (p = w[num]; p < k[num]; p++) {
						if (wall[p + 1024] < v[num]) {
							successfulAttack++;
							break;
						}
					}
				}
			for (num = 0; num < c; num++)
				if ((b[num] > 0) && (ny[num] == attackDay)) {
					for (p = w[num]; p < k[num]; p++) {
						if (wall[p + 1024] < v[num]) {
							wall[p + 1024] = v[num];
						}
					}
					v[num] += deltaS[num];
					k[num] += deltaP[num];
					w[num] += deltaP[num];
					ny[num] += deltaD[num];
					b[num]--;
				}
		}
		printf("Case #%d: %d\n", b, successfulAttack);
	}
	return 0;
}
