#include "stdio.h"
#include "string.h"
int Main()
{
    int t;
    int j;
    int pos[2];
    int final[2];
    int count[102];
    int s[102];
    int time[102];
    int t;
    int m;
    FILE *fp;
    fp = fopen("as1.in", "r");
    fscanf(fp, "%d", &t);
    for (t = 1; t <= t; t++) {
	memset(pos, 0, sizeof(pos));
	memset(final, 0, sizeof(final));
	memset(count, 0, sizeof(count));
	memset(s, 0, sizeof(s));
	memset(time, 0, sizeof(time));
	pos[0] = 1;
	pos[1] = 1;
	fscanf(fp, "%d ", &j);
	char color = 0;
	for (m = 1; m <= j; m++) {
	    fscanf(fp, "%c", &color);
	    if (color == 'O')
		count[m] = 0;
	    else
		count[m] = 1;
	    fscanf(fp, "%d ", &s[m]);
	}
	for (m = 1; m <= j; m++) {
	    int time1 = time[m - 1] + 1;
	    int dist = s[m] - pos[count[m]];
	    if (dist < 0)
		dist = -dist;
	    int time2 = (dist + 1) + final[count[m]];
	    if (time1 < 0)
		printf("error, %d, 1!\n", m);
	    if (time2 < 0)
		printf("error, %d, 2!\n", m);
	    if (time1 > time2)
		time[m] = time1;
	    else
		time[m] = time2;
	    pos[count[m]] = s[m];
	    final[count[m]] = time[m];
	}
	printf("Case #%d: %d\n", t, time[j]);
    }
    fclose(fp);
    return 0;
}
