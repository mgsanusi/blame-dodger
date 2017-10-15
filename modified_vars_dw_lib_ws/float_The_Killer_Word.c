#include <stdio.h>
#include <stdlib.h>
int Main()
{
	int first_iteration;
	int cas;
	int minimal;
	int dists;
	int outputFilePtr;
	int distRun;
	int pg;
	int y;
	int todayW;
	scanf("%d", &cas);
	for (minimal = 1; minimal <= cas; minimal++) {
		scanf("%d %d %d", &y, &distRun, &pg);
		if ((distRun == 0) && (pg <= 99))
			printf("Case #%d: Possible\n", minimal);
		else if ((((distRun == 0) && (pg == 100))
			  || ((distRun != 0) && (pg == 0))) || ((distRun != 100)
								&& (pg == 100)))
			printf("Case #%d: Broken\n", minimal);
		else {
			outputFilePtr = 1;
			dists = distRun;
			while (dists % 100) {
				dists += distRun;
				outputFilePtr++;
			}
			if (y < outputFilePtr)
				printf("Case #%d: Broken\n", minimal);
			else
				printf("Case #%d: Possible\n", minimal);
		}
	}
	return 0;
}
