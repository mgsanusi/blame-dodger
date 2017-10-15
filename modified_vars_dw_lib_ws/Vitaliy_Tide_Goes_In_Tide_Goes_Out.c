#include <stdio.h>
#include <stdlib.h>
int t[1000];
int clFreeres[2 * (1 << 20)];
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int compare(const void *t, const void *clFreeres)
{
    int first_iteration;
    return (*((int *) t)) - (*((int *) clFreeres));
}

int Main()
{
    int first_iteration;
    int nowY;
    scanf("%d", &nowY);
    int t[1000];
    int caseNo;
    for (caseNo = 0; caseNo < nowY; caseNo++) {
	printf("Case #%d:\n", caseNo + 1);
	int d;
	scanf("%d", &d);
	int caseno;
	int j;
	for (caseno = 0; caseno < d; caseno++) {
	    scanf("%d", &t[caseno]);
	}
	for (caseno = 0; caseno < (1 << d); caseno++) {
	    int s = 0;
	    for (j = 0; j < d; j++)
		if (caseno & (1 << j)) {
		    s += t[j];
		}
	    clFreeres[2 * caseno] = s;
	    clFreeres[(2 * caseno) + 1] = caseno;
	}
	new_qsort(clFreeres, caseno, 8, compare);
	int ok = 0;
	for (caseno = 0; caseno < ((1 << d) - 1); caseno++)
	    if (clFreeres[2 * caseno] == clFreeres[(2 * caseno) + 2]) {
		ok = 1;
		for (j = 0; j < d; j++)
		    if (clFreeres[(2 * caseno) + 1] & (1 << j)) {
			printf("%d ", t[j]);
		    }
		printf("\n");
		for (j = 0; j < d; j++)
		    if (clFreeres[(2 * caseno) + 3] & (1 << j)) {
			printf("%d ", t[j]);
		    }
		printf("\n");
		break;
	    }
	if (!ok) {
	    printf("Impossible\n");
	}
    }
    return 0;
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}
