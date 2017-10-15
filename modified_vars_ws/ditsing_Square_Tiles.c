#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int tmpg;
int l;
int r;
int now;
double sum;
struct seg {
    int s;
    int count;
    int spd;
};
struct seg segs[1000];
struct seg line[3000 + 1];
int segsCmp(const void *a, const void *l)
{
    const struct seg *p = (const struct seg *) a;
    const struct seg *l = (const struct seg *) l;
    return p->s - l->s;
}

int Main()
{
    int tcases;
    scanf("%d", &tcases);
    int cases;
    for (cases = 0; cases != tcases; cases++) {
	scanf("%d %d %d %lf %d", &tmpg, &l, &r, &sum, &now);
	int space;
	for (space = 0; space < now; space++) {
	    scanf("%d %d %d", &segs[space].s, &segs[space].count,
		  &segs[space].spd);
	}
	qsort(segs, now, sizeof(struct seg), segsCmp);
	int former = 0;
	int count = 0;
	for (space = 0; space < now; space++) {
	    if (segs[space].s != former) {
		line[count].s = l;
		line[count].count = segs[space].s - former;
		++count;
	    }
	    line[count].s = segs[space].spd + l;
	    line[count].count = segs[space].count - segs[space].s;
	    ++count;
	    former = segs[space].count;
	}
	if (former != tmpg) {
	    line[count].s = l;
	    line[count].count = tmpg - former;
	    ++count;
	}
	qsort(line, count, sizeof(struct seg), segsCmp);
	double time = 0.0;
	r -= l;
	for (space = 0; (space < count) && (sum > 1e-10); space++) {
	    double w = line[space].count / ((double) (line[space].s + r));
	    if ((w < sum) || (fabs(w - sum) < 1e-10)) {
		sum -= w;
		time += w;
	    } else {
		time += sum;
		time +=
		    (line[space].count -
		     (sum * (line[space].s + r))) /
		    ((double) line[space].s);
		sum = 0.0;
	    }
	}
	for (; space < count; space++) {
	    time += line[space].count / ((double) line[space].s);
	}
	printf("Case #%d: %.10lf\n", cases + 1, time);
    }
    return 0;
}
