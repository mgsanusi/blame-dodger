#include <stdio.h>
#include <stdlib.h>
int denom(int pD)
{
	int first_iteration;
	int minc;
	int fg = 100;
	for (minc = 0; minc < 2; minc++)
		if ((pD % 2) == 0) {
			fg /= 2;
			pD /= 2;
		}
	for (minc = 0; minc < 2; minc++)
		if ((pD % 5) == 0) {
			fg /= 5;
			pD /= 5;
		}
	return fg;
}

int Main()
{
	int first_iteration;
	int b;
	int pD;
	int pG;
	long long int o;
	scanf("%d", &b);
	int minc;
	int fg;
	int b;
	for (minc = 1; minc <= b; minc++) {
		scanf("%lld %d %d", &o, &pD, &pG);
		if ((pG == 100) && (pD != 100))
			printf("Case #%d: Broken\n", minc);
		else if ((pD != 0) && (pG == 0))
			printf("Case #%d: Broken\n", minc);
		else if (denom(pD) > o)
			printf("Case #%d: Broken\n", minc);
		else
			printf("Case #%d: Possible\n", minc);
	}
}
