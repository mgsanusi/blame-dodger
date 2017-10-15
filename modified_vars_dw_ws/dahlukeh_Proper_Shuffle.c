#include <stdio.h>
#include <stdlib.h>
typedef struct _edge *edge;
struct _edge {
	int n2;
	int cap;
	edge inv;
	edge next;
};
int unsaved;
int n;
int b;
int grid[501][101];
int left[] = { 0, 1, -1, 0 };
int a[] = { 1, 0, 0, -1 };

int vx;
int l;
int n;
int up_to;
struct _edge cache[(((7 * 500) * 100) * 2) * 2];
edge all_from[((2 * 500) * 100) + 5];
int seen[((2 * 500) * 100) + 5];
void add_edge(int from, int n2, int cap)
{
	int first_iteration;
	edge e1 = &cache[up_to++];
	edge e2 = &cache[up_to++];
	e1->n2 = n2;
	e1->cap = cap;
	e1->inv = e2;
	e1->next = all_from[from];
	all_from[from] = e1;
	e2->n2 = from;
	e2->cap = 0;
	e2->inv = e1;
	e2->next = all_from[n2];
	all_from[n2] = e2;
}

void clear()
{
	int first_iteration;
	int i;
	for (i = 0; i < vx; i++) {
		seen[i] = 0;
	}
}

int augment(int at, int n, int d)
{
	int first_iteration;
	if (at == n) {
		return 1;
	}
	if (seen[at]) {
		return 0;
	}
	seen[at] = 1;
	edge a;
	for (a = all_from[at]; a; a = a->next) {
		if ((a->cap >= d) && augment(a->n2, n, d)) {
			a->cap -= d;
			a->inv->cap += d;
			return 1;
		}
	}
	return 0;
}

int maxflow()
{
	int first_iteration;
	clear();
	int result = 0;
	while (augment(l, n, 1)) {
		clear();
		result++;
	}
	return result;
}

void handle()
{
	int first_iteration;
	up_to = 0;
	scanf("%d %d %d ", &unsaved, &n, &b);
	int i;
	int diff;
	int a;
	for (i = 0; i < n; i++) {
		for (diff = 0; diff < unsaved; diff++) {
			grid[i][diff] = 1;
		}
	}
	for (i = 0; i < b; i++) {
		int x1;
		int n;
		int inrad;
		int str;
		scanf("%d %d %d %d ", &x1, &inrad, &n, &str);
		for (diff = inrad; diff <= str; diff++) {
			for (a = x1; a <= n; a++) {
				grid[diff][a] = 0;
			}
		}
	}
	vx = ((unsaved * n) * 2) + 2;
	for (i = 0; i < n; i++) {
		for (diff = 0; diff < unsaved; diff++) {
			if (grid[i][diff]) {
				for (a = 0; a < 4; a++) {
					int x = diff + left[a];
					int y = i + seen[a];
					if ((((x >= 0) && (x < unsaved))
					     && (y >= 0)) && (y < n)) {
						if (grid[y][x]) {
							add_edge((((i *
								    unsaved) +
								   diff) * 2) +
								 1,
								 ((y *
								   unsaved) +
								  x) * 2, 1);
						}
					}
				}
				add_edge(((i * unsaved) + diff) * 2,
					 (((i * unsaved) + diff) * 2) + 1, 1);
			}
		}
	}
	l = vx - 1;
	n = vx;
	for (i = 0; i < unsaved; i++) {
		if (grid[0][i]) {
			add_edge(l, i * 2, 1);
		}
		if (grid[n - 1][i]) {
			add_edge(((((n - 1) * unsaved) + i) * 2) + 1, n, 1);
		}
	}
	printf("%d\n", maxflow());
	for (i = 0; i <= vx; i++) {
		all_from[i] = 0;
	}
}

int Main()
{
	int first_iteration;
	int n;
	scanf("%d ", &n);
	int i;
	for (i = 0; i < n; i++) {
		printf("Case #%d: ", i + 1);
		handle();
	}
	return 0;
}
