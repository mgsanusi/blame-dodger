#include <stdio.h>
#include <stdlib.h>
int Main()
{
    int first_iteration;
    int cas;
    int b;
    int team;
    int highest_number;
    int j;
    int tmp;
    int b1[110][2];
    double fonts[110];
    double owp[110];
    double oowp[110];
    char adj[110][110];
    scanf("%d", &cas);
    for (b = 1; b <= cas; b++) {
	scanf("%d", &team);
	for (highest_number = 0; highest_number < team; highest_number++)
	    scanf("%s", adj[highest_number]);
	for (highest_number = 0; highest_number < team; highest_number++) {
	    fonts[highest_number] = 0;
	    b1[highest_number][0] = 0;
	    b1[highest_number][1] = 0;
	    for (j = 0; j < team; j++) {
		if (adj[highest_number][j] == '1') {
		    b1[highest_number][0]++;
		    fonts[highest_number] += 1;
		}
		if (adj[highest_number][j] == '0')
		    b1[highest_number][1]++;
	    }
	    fonts[highest_number] =
		((double) fonts[highest_number]) / (b1[highest_number][0] +
						    b1[highest_number][1]);
	}
	for (highest_number = 0; highest_number < team; highest_number++) {
	    owp[highest_number] = 0;
	    for (j = 0; j < team; j++) {
		if (adj[highest_number][j] == '1')
		    owp[highest_number] +=
			((double) b1[j][0]) / ((b1[j][0] + b1[j][1]) - 1);
		if (adj[highest_number][j] == '0')
		    owp[highest_number] +=
			((double) (b1[j][0] - 1)) /
			((b1[j][0] + b1[j][1]) - 1);
	    }
	    owp[highest_number] =
		owp[highest_number] / (b1[highest_number][0] +
				       b1[highest_number][1]);
	}
	for (highest_number = 0; highest_number < team; highest_number++) {
	    oowp[highest_number] = 0;
	    tmp = 0;
	    for (j = 0; j < team; j++) {
		if ((adj[highest_number][j] == '1')
		    || (adj[highest_number][j] == '0')) {
		    tmp++;
		    oowp[highest_number] += owp[j];
		}
	    }
	    oowp[highest_number] = oowp[highest_number] / tmp;
	}
	printf("Case #%d:\n", b);
	for (highest_number = 0; highest_number < team; highest_number++)
	    printf("%.6lf\n",
		   ((0.25 * fonts[highest_number]) +
		    (0.5 * owp[highest_number])) +
		   (0.25 * oowp[highest_number]));
    }
    return 0;
}
