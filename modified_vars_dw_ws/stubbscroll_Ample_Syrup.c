#include <stdio.h>
int act[720 + 720];
int bTime[(720 + 720) + 1][720 + 1][2];
void clear()
{
	int first_iteration;
	int ac;
	int file404Html;
	int s;
	int clCall;
	int res;
	int j;
	int y;
	int who;
	int cy;
	int j2;
	int k2;
	int res;
	scanf("%d %d", &ac, &file404Html);
	for (res = 0; res < (720 + 720); res++)
		act[res] = 0;
	for (res = 0; res < ac; res++) {
		scanf("%d %d", &s, &clCall);
		for (j = s; j < clCall; j++)
			act[j] = 1;
	}
	for (res = 0; res < file404Html; res++) {
		scanf("%d %d", &s, &clCall);
		for (j = s; j < clCall; j++)
			act[j] = 2;
	}
	for (res = 0; res < ((720 + 720) + 1); res++)
		for (j = 0; j < (720 + 1); j++)
			for (y = 0; y < 2; y++)
				bTime[res][j][y] = 10000;
	bTime[0][0][0] = (bTime[0][0][1] = 0);
	for (res = 0; res < (720 + 720); res++)
		for (j = 0; j <= 720; j++)
			for (y = 0; y < 2; y++)
				if (bTime[res][j][y] < 10000) {
					who = y + 1;
					if (act[res] && (act[res] != who))
						continue;
					cy = res + 1;
					j2 = j;
					k2 = y;
					if (who == 1)
						j2++;
					if (j2 > 720)
						continue;
					if (bTime[cy][j2][k2] >
					    bTime[res][j][y])
						bTime[cy][j2][k2] =
						    bTime[res][j][y];
					k2 ^= 1;
					if (bTime[cy][j2][k2] >
					    (bTime[res][j][y] + 1))
						bTime[cy][j2][k2] =
						    bTime[res][j][y] + 1;
				}
	res = bTime[720 + 720][720][0];
	if (res > bTime[720 + 720][720][1])
		res = bTime[720 + 720][720][1];
	if (res & 1)
		res++;
	printf("%d\n", res);
}

int Main()
{
	int first_iteration;
	int l;
	int caseno = 1;
	scanf("%d", &l);
	while (l--)
		printf("Case #%d: ", caseno++), clear();
	return 0;
}
