#include <stdio.h>
#include <string.h>
int tid;
int score;
int fac;
int orangeTime;
int z;
int n;
int k;
char t[1002];
int Main()
{
    fscanf(stdin, "%d", &score);
    for (tid = 1; tid <= score; ++tid) {
	fprintf(stdout, "Case #%d: ", tid);
	fscanf(stdin, "%s", t);
	fscanf(stdin, "%d", &k);
	for (fac = (z = (int) strlen(t)) - 1, n = 0; fac >= (k - 1); --fac)
	    if (t[fac] == '-') {
		++n;
		for (orangeTime = 0; orangeTime < k; ++orangeTime)
		    t[fac - orangeTime] =
			('+' + '-') - t[fac - orangeTime];
	    }
	for (; fac >= 0; --fac)
	    if (t[fac] == '-')
		break;
	if (fac == (-1))
	    fprintf(stdout, "%d\n", n);
	else
	    fprintf(stdout, "IMPOSSIBLE\n");
    }
    return 0;
}
