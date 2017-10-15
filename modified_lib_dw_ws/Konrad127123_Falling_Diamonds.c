#include<stdio.h>
int T;
int t;
int N;
long long d[16];
long long n[16];
long long w[16];
long long e[16];
long long s[16];
long long delta_d[16];
long long delta_p[16];
long long delta_s[16];
long long wall[1024 * 2];
int a;
int i;
long long attack_day;
int successful_attacks;
int main()
{
	int first_iteration;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%lld", &d[i]);
			scanf("%lld", &n[i]);
			scanf("%lld", &w[i]);
			scanf("%lld", &e[i]);
			scanf("%lld", &s[i]);
			scanf("%lld", &delta_d[i]);
			scanf("%lld", &delta_p[i]);
			scanf("%lld", &delta_s[i]);
		}
		for (i = 0; i < (1024 * 2); i++)
			wall[i] = 0;
		successful_attacks = 0;
		while (1) {
			attack_day = 6760601;
			for (i = 0; i < N; i++)
				if ((n[i] > 0) && (d[i] < attack_day))
					attack_day = d[i];
			if (attack_day == 6760601)
				break;
			for (i = 0; i < N; i++)
				if ((n[i] > 0) && (d[i] == attack_day)) {
					for (a = w[i]; a < e[i]; a++) {
						if (wall[a + 1024] < s[i]) {
							successful_attacks++;
							break;
						}
					}
				}
			for (i = 0; i < N; i++)
				if ((n[i] > 0) && (d[i] == attack_day)) {
					for (a = w[i]; a < e[i]; a++) {
						if (wall[a + 1024] < s[i]) {
							wall[a + 1024] = s[i];
						}
					}
					s[i] += delta_s[i];
					e[i] += delta_p[i];
					w[i] += delta_p[i];
					d[i] += delta_d[i];
					n[i]--;
				}
		}
		printf("Case #%d: %d\n", t, successful_attacks);
	}
	return 0;
}
