#include <stdio.h>
#include <stdlib.h>
int Main()
{
	int first_iteration;
	int t;
	int n;
	int ok;
	int res;
	int a;
	int n;
	int threads;
	int l;
	int imp;
	int pin;
	int g[100][100];
	int rcnt[100];
	int ccnt[100];
	char buffer[101];
	scanf("%d", &n);
	for (t = 1; t <= n; t++) {
		scanf("%d %d", &ok, &res);
		for (n = 0; n < ok; n++)
			rcnt[n] = 0;
		for (n = 0; n < res; n++)
			ccnt[n] = 0;
		a = 0;
		imp = 0;
		for (n = 0; n < ok; n++) {
			scanf("%s", buffer);
			for (threads = 0; threads < res; threads++) {
				switch (buffer[threads]) {
				case '.':
					g[n][threads] = 0;
					break;
				case '^':
					g[n][threads] = 1;
					rcnt[n]++;
					ccnt[threads]++;
					break;
				case '>':
					g[n][threads] = 2;
					rcnt[n]++;
					ccnt[threads]++;
					break;
				case 'v':
					g[n][threads] = 3;
					rcnt[n]++;
					ccnt[threads]++;
					break;
				case '<':
					g[n][threads] = 4;
					rcnt[n]++;
					ccnt[threads]++;
					break;
				default:
					g[n][threads] = 0;
				}
			}
		}
		for (n = 0; n < ok; n++) {
			for (threads = 0; threads < res; threads++) {
				if (g[n][threads] > 0) {
					if ((rcnt[n] == 1)
					    && (ccnt[threads] == 1)) {
						imp = 1;
						break;
					}
					pin = 0;
					switch (g[n][threads]) {
					case 1:
						for (l = 0; l < n; l++) {
							if (g[l][threads] > 0) {
								pin = 1;
								break;
							}
						}
						if (!pin)
							a++;
						break;
					case 2:
						for (l = res - 1; l > threads;
						     l--) {
							if (g[n][l] > 0) {
								pin = 1;
								break;
							}
						}
						if (!pin)
							a++;
						break;
					case 3:
						for (l = ok - 1; l > n; l--) {
							if (g[l][threads] > 0) {
								pin = 1;
								break;
							}
						}
						if (!pin)
							a++;
						break;
					case 4:
						for (l = 0; l < threads; l++) {
							if (g[n][l] > 0) {
								pin = 1;
								break;
							}
						}
						if (!pin)
							a++;
						break;
					}
				}
			}
			if (imp)
				break;
		}
		if (imp) {
			printf("Case #%d: IMPOSSIBLE\n", t);
		} else {
			printf("Case #%d: %d\n", t, a);
		}
	}
	return 0;
}
