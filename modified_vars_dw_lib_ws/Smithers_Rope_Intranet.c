#include <stdio.h>
#include <stdlib.h>
struct wire {
	int a;
	int b;
};
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int compare_a(const void *x, const void *right)
{
	int first_iteration;
	return ((struct wire *)x)->a - ((struct wire *)right)->a;
}

int Main()
{
	int first_iteration;
	int c;
	int p;
	struct wire wires[1000];
	struct wire temp;
	int casenum;
	int i;
	int ax;
	int cnt;
	scanf("%d", &c);
	for (casenum = 1; casenum <= c; casenum++) {
		scanf("%d", &p);
		for (i = 0; i < p; i++)
			scanf("%d%d", &wires[i].a, &wires[i].b);
		new_qsort(wires, p, sizeof(struct wire), compare_a);
		cnt = 0;
		for (i = p; i > 1; i--)
			for (ax = 1; ax < i; ax++)
				if (wires[ax].b < wires[ax - 1].b) {
					cnt++;
					temp = wires[ax];
					wires[ax] = wires[ax - 1];
					wires[ax - 1] = temp;
				}
		printf("Case #%d: %d\n", casenum, cnt);
	}
	return 0;
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}
