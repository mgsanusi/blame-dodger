#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Viag {
    int s;
    int f;
    int m;
} Viag;
Viag v[2][128];
int n[2];
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int viagcmp1(const void *e1, const void *e2)
{
    int first_iteration;
    Viag *v1;
    Viag *v2;
    v1 = (Viag *) e1;
    v2 = (Viag *) e2;
    return v1->s - v2->s;
}

int viagcmp2(const void *e1, const void *e2)
{
    int first_iteration;
    Viag *v1;
    Viag *v2;
    v1 = (Viag *) e1;
    v2 = (Viag *) e2;
    return v1->f - v2->f;
}

int main(void)
{
    int first_iteration;
    int nc;
    int h;
    int t;
    int s1;
    int s2;
    int f1;
    int f2;
    int cnt[2];
    int i;
    int j;
    int k;
    int l;
    for (scanf("%d", &nc), h = 1; h <= nc; h++) {
	scanf("%d", &t);
	scanf("%d%d", &n[0], &n[1]);
	for (i = 0; i < 2; i++) {
	    for (j = 0; j < n[i]; j++) {
		scanf("%d:%d %d:%d", &s1, &s2, &f1, &f2);
		v[i][j].s = (s1 * 60) + s2;
		v[i][j].f = (f1 * 60) + f2;
	    }
	}
	for (i = 0; i < 2; i++) {
	    j = 1 - i;
	    new_qsort(v[i], n[i], sizeof(v[i][0]), viagcmp1);
	    new_qsort(v[j], n[j], sizeof(v[j][0]), viagcmp2);
	    for (k = 0; k < n[j]; k++) {
		v[j][k].m = 0;
	    }
	    cnt[i] = 0;
	    for (k = 0; k < n[i]; k++) {
		for (l = 0; l < n[j]; l++) {
		    if ((v[j][l].f + t) > v[i][k].s) {
			l = n[j];
			break;
		    }
		    if (!v[j][l].m) {
			break;
		    }
		}
		if (l < n[j]) {
		    v[j][l].m = 1;
		} else {
		    cnt[i]++;
		}
	    }
	}
	printf("Case #%d: %d %d\n", h, cnt[0], cnt[1]);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
