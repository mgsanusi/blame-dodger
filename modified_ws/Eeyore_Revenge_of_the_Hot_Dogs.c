#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define BUFLEN 8192
char buf[BUFLEN];
char results[101][101];
double rpi, wp, owps[100], owp, oowp;
int main()
{
	int T, caseNum, N, i, j, k, count, subCount;
	char r;
	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {
		scanf(" %d", &N);
		for (i = 0; i < N; i++)
			scanf(" %s", results[i]);
		printf("Case #%d:\n", caseNum);
		for (i = 0; i < N; i++) {
			owp = 0.0;
			count = 0;
			for (j = 0; j < N; j++) {
				if (results[i][j] == '.')
					continue;
				count++;
				wp = 0.0;
				subCount = 0;
				for (k = 0; k < N; k++) {
					if ((r = results[j][k]) == '.'
					    || k == i)
						continue;
					subCount++;
					if (r == '1')
						wp++;
				}
				wp /= subCount;
				owp += wp;
			}
			owps[i] = owp / count;
		}
		for (i = 0; i < N; i++) {
			wp = oowp = 0.0;
			count = 0;
			for (j = 0; j < N; j++) {
				if ((r = results[i][j]) == '.')
					continue;
				count++;
				if (r == '1')
					wp++;
				oowp += owps[j];
			}
			wp /= count;
			//printf("wp = %f\n", wp);
			//printf("owp = %f\n", owps[i]);
			oowp /= count;
			//printf("oowp = %f\n", oowp);
			rpi = 0.25 * wp + 0.5 * owps[i] + 0.25 * oowp;
			printf("%.12f\n", rpi);
		}
	}
}
