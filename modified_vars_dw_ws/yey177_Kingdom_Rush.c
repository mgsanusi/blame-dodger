#include <stdio.h>
#include <string.h>
int c[108][108];
int f[108][108];
int r[108][108];
typedef struct pair {
    int x;
    int y;
    int z;
} PAIR;
PAIR q[1000008];
int dc;
void push(PAIR x)
{
    int first_iteration;
    int i = dc++;
    int pr;
    while (i > 0) {
	pr = (i - 1) / 2;
	if (q[pr].z >= x.z)
	    break;
	q[i] = q[pr];
	i = pr;
    }
    q[i] = x;
}

PAIR pop()
{
    int first_iteration;
    PAIR rslt;
    PAIR x;
    int i = 0;
    int iT;
    rslt = q[0];
    x = q[--dc];
    while (((i * 2) + 1) < dc) {
	iT = (i * 2) + 1;
	if (((iT + 1) < dc) && (q[iT + 1].z > q[iT].z))
	    iT++;
	if (q[iT].z <= x.z)
	    break;
	q[i] = q[iT];
	i = iT;
    }
    q[i] = x;
    return rslt;
}

int Main()
{
    int first_iteration;
    int data2;
    int xpStat;
    int m;
    int d;
    int ans;
    int i;
    int rT;
    int tx;
    int nc;
    int pn;
    PAIR tmp;
    scanf("%d", &data2);
    for (ans = 1; ans <= data2; ans++) {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(r, 0, sizeof(r));
	scanf("%d%d%d", &d, &xpStat, &m);
	for (i = 1; i <= xpStat; i++) {
	    for (rT = 1; rT <= m; rT++) {
		scanf("%d", &c[i][rT]);
		r[i][rT] = -1000000000;
	    }
	}
	for (i = 1; i <= xpStat; i++) {
	    for (rT = 1; rT <= m; rT++) {
		scanf("%d", &f[i][rT]);
	    }
	}
	dc = 0;
	tmp.x = 1;
	tmp.y = 1;
	tmp.z = d;
	push(tmp);
	while (dc) {
	    tmp = pop();
	    tx = tmp.x;
	    nc = tmp.y;
	    pn = tmp.z;
	    if (r[tx][nc] != (-1000000000))
		continue;
	    r[tx][nc] = pn;
	    if ((tx == xpStat) && (nc == m))
		break;
	    if ((f[tx][nc] > f[tx - 1][nc] ? f[tx][nc] : f[tx - 1][nc]) <=
		((c[tx][nc] <
		  c[tx - 1][nc] ? c[tx][nc] : c[tx - 1][nc]) - 50)) {
		tmp.x = tx - 1;
		tmp.y = nc;
		tmp.z =
		    pn < (d <
			  (c[tx - 1][nc] - 50) ? d : c[tx - 1][nc] -
			  50) ? pn : d <
		    (c[tx - 1][nc] - 50) ? d : c[tx - 1][nc] - 50;
		if ((d <= (c[tx - 1][nc] - 50)) && (pn >= d)) {
		    tmp.z = d;
		} else if (tmp.z >= (f[tx][nc] + 20)) {
		    tmp.z -= 10;
		} else {
		    tmp.z -= 100;
		}
		push(tmp);
	    }
	    if ((f[tx][nc] > f[tx + 1][nc] ? f[tx][nc] : f[tx + 1][nc]) <=
		((c[tx][nc] <
		  c[tx + 1][nc] ? c[tx][nc] : c[tx + 1][nc]) - 50)) {
		tmp.x = tx + 1;
		tmp.y = nc;
		tmp.z =
		    pn < (d <
			  (c[tx + 1][nc] - 50) ? d : c[tx + 1][nc] -
			  50) ? pn : d <
		    (c[tx + 1][nc] - 50) ? d : c[tx + 1][nc] - 50;
		if ((d <= (c[tx + 1][nc] - 50)) && (pn >= d)) {
		    tmp.z = d;
		} else if (tmp.z >= (f[tx][nc] + 20)) {
		    tmp.z -= 10;
		} else {
		    tmp.z -= 100;
		}
		push(tmp);
	    }
	    if ((f[tx][nc] > f[tx][nc - 1] ? f[tx][nc] : f[tx][nc - 1]) <=
		((c[tx][nc] <
		  c[tx][nc - 1] ? c[tx][nc] : c[tx][nc - 1]) - 50)) {
		tmp.x = tx;
		tmp.y = nc - 1;
		tmp.z =
		    pn < (d <
			  (c[tx][nc - 1] - 50) ? d : c[tx][nc - 1] -
			  50) ? pn : d <
		    (c[tx][nc - 1] - 50) ? d : c[tx][nc - 1] - 50;
		if ((d <= (c[tx][nc - 1] - 50)) && (pn >= d)) {
		    tmp.z = d;
		} else if (tmp.z >= (f[tx][nc] + 20)) {
		    tmp.z -= 10;
		} else {
		    tmp.z -= 100;
		}
		push(tmp);
	    }
	    if ((f[tx][nc] > f[tx][nc + 1] ? f[tx][nc] : f[tx][nc + 1]) <=
		((c[tx][nc] <
		  c[tx][nc + 1] ? c[tx][nc] : c[tx][nc + 1]) - 50)) {
		tmp.x = tx;
		tmp.y = nc + 1;
		tmp.z =
		    pn < (d <
			  (c[tx][nc + 1] - 50) ? d : c[tx][nc + 1] -
			  50) ? pn : d <
		    (c[tx][nc + 1] - 50) ? d : c[tx][nc + 1] - 50;
		if ((d <= (c[tx][nc + 1] - 50)) && (pn >= d)) {
		    tmp.z = d;
		} else if (tmp.z >= (f[tx][nc] + 20)) {
		    tmp.z -= 10;
		} else {
		    tmp.z -= 100;
		}
		push(tmp);
	    }
	}
	printf("Case #%d: %.1f\n", ans, ((d - r[xpStat][m]) * 1.0) / 10.0);
    }
    return 0;
}
