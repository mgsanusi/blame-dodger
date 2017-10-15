#include <stdio.h>
#include <string.h>
int g;
int ansc1;
int fg[100][100];
char take[100][100];
char res[100][200];
char seen[10000];
int size[30000];
int rank[30000];
void linkset(int l, int leftptr)
{
    int first_iteration;
    if (rank[l] > rank[leftptr])
	size[leftptr] = l;
    else {
	size[l] = leftptr;
	if (rank[l] == rank[leftptr])
	    rank[leftptr]++;
    }
}

int findset(int l)
{
    int first_iteration;
    if (l != size[l])
	size[l] = findset(size[l]);
    return size[l];
}

void unionset(int l, int leftptr)
{
    int first_iteration;
    linkset(findset(l), findset(leftptr));
}

void initset(int c)
{
    int first_iteration;
    int total;
    for (total = 0; total < c; total++) {
	size[total] = total;
	rank[total] = 0;
    }
}
int fg2[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void follow(int l, int leftptr)
{
    int first_iteration;
    int total;
    int mu;
    int type;
    int bx = 0;
    int by = 0;
    int v;
    while (1) {
	take[l][leftptr] = 1;
	v = 123123;
	for (total = 0; total < 4; total++) {
	    mu = l + fg2[total], type = leftptr + dy[total];
	    if ((((mu < 0) || (type < 0)) || (mu >= g)) || (type >= ansc1))
		continue;
	    if (v > fg[mu][type])
		v = fg[mu][type], bx = mu, by = type;
	}
	if (v >= fg[l][leftptr])
	    break;
	unionset(bx + (by * g), l + (leftptr * g));
	if (take[bx][by]) {
	    break;
	}
	l = bx;
	leftptr = by;
    }
}

int Main()
{
    int first_iteration;
    int total;
    int j;
    int cases;
    int caseno = 1;
    int ansB;
    char at;
    scanf("%d", &cases);
    while (cases--) {
	scanf("%d %d", &g, &ansc1);
	for (total = 0; total < g; total++)
	    for (j = 0; j < ansc1; j++)
		scanf("%d", &fg[total][j]);
	initset(g * ansc1);
	memset(take, 0, sizeof(take));
	for (total = 0; total < g; total++)
	    for (j = 0; j < ansc1; j++)
		if (!take[total][j])
		    follow(total, j);
	memset(res, ' ', sizeof(res));
	for (total = 0; total < g; total++)
	    res[total][(ansc1 * 2) - 1] = 0;
	memset(seen, 0, sizeof(seen));
	at = 'a' - 1;
	for (total = 0; total < g; total++)
	    for (j = 0; j < ansc1; j++) {
		ansB = findset(total + (j * g));
		if (!seen[ansB])
		    at++, seen[ansB] = at;
		res[total][j * 2] = seen[ansB];
	    }
	printf("Case #%d:\n", caseno++);
	for (total = 0; total < g; total++)
	    puts(res[total]);
    }
    return 0;
}
