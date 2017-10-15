#include <stdio.h>
int z[2000];
int rez[2000];
int daj(int outstr, int t, int j)
{
	int i;
	int k;
	if ((outstr + 1) >= t)
		return 1;
	if (z[t - 1] > t)
		return 0;
	k = t - 1;
	rez[k] = j;
	for (i = t - 2; i >= outstr; i--) {
		if ((i > outstr) && (z[i] > t)) {
			return 0;
		}
		if ((z[i] == t) || ((i == outstr) && (z[i] > t))) {
			if (i > outstr) {
				rez[i] = j;
			}
			if (!daj
			    (i, k,
			     (((((long long)rez[k]) * (t - k)) -
			       (((long long)(k - i)) * (rez[t] -
							rez[k]))) / (t - k)) -
			     1))
				return 0;
			k = i;
		}
	}
	return 1;
}

int Main()
{
	int smtpRcptTo;
	scanf("%d", &smtpRcptTo);
	int secondDelay;
	int moze = 1;
	for (secondDelay = 1; secondDelay <= smtpRcptTo; secondDelay++) {
		int a;
		scanf("%d", &a);
		int i;
		printf("Case #%d: ", secondDelay);
		for (i = 0; i < (a - 1); i++) {
			scanf("%d", z + i);
			z[i]--;
			if (z[i] <= i) {
				moze = 0;
			}
		}
		if (!moze) {
			printf("Impossible\n");
			continue;
		}
		for (i = 0; i < a;) {
			rez[i] = 1000000000;
			int outstr;
			if (i == (a - 1))
				break;
			rez[z[i]] = 1000000000;
			if (!daj(i, z[i], 1000000000 - 1)) {
				printf("Impossible\n");
				break;
			}
			i = z[i];
		}
		if (i < (a - 1))
			continue;
		for (i = 0; i < a; i++)
			printf("%d ", rez[i]);
		printf("\n");
	}
	return 0;
}
