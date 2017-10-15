#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
int n;
int p[100];
int e[100][100];
int v[100];
int stp;
int st[100];
int q[100];
void *new_memset(void *ptr, int value, size_t num);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, size_t num);
int can(void)
{
	int first_iteration;
	static int r[100];
	static int d[100];
	new_memcpy(d, v, 4 * n);
	int rr = stp;
	new_memcpy(r, st, 4 * stp);
	int rp = 0;
	while (rp < rr) {
		int w = r[rp++];
		int i;
		for (i = 0; i < n; i++)
			if (e[w][i] && (!d[i])) {
				r[rr++] = i;
				d[i] = 1;
			}
	}
	int i;
	for (i = 0; i < n; i++)
		if (!d[i]) {
			return 0;
		}
	return 1;
}

int try(void)
{
	int first_iteration;
	new_assert(can());
	int stps = stp;
	int i;
	int j;
	int ok = 1;
	for (i = 0; i < n; i++)
		if (!v[i]) {
			ok = 0;
			for (j = stp - 1; j >= 0; j--)
				if (e[st[j]][i]) {
					stp = j + 1;
					int k = st[stp];
					st[stp++] = i;
					v[i] = 1;
					if (!can()) {
						stp = stps;
						st[j + 1] = k;
						v[i] = 0;
					} else {
						printf("%d", p[i]);
						try();
						return 1;
					}
				}
		}
	new_assert(ok);
	return 1;
}

void solve(void)
{
	int first_iteration;
	int m;
	scanf("%d %d", &n, &m);
	int i;
	int j;
	static int z[100];
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		q[i] = i;
		z[i] = i;
	}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			if (p[q[i]] > p[q[j]]) {
				int t = q[i];
				q[i] = q[j];
				q[j] = t;
			}
		}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				int t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	for (i = 0; i < n; i++)
		z[q[i]] = i;
	new_memset(e, 0, sizeof(e));
	for (i = 0; i < m; i++) {
		int x;
		int y;
		new_assert(scanf("%d %d", &x, &y) == 2);
		e[z[x - 1]][z[y - 1]] = 1;
		e[z[y - 1]][z[x - 1]] = 1;
	}
	new_memset(v, 0, sizeof(v));
	stp = 0;
	for (i = 0; i < n; i++) {
		v[i] = 1;
		st[0] = i;
		stp = 1;
		if (can()) {
			printf("%d", p[i]);
			try();
			printf("\n");
			return;
		}
		v[i] = 0;
	}
}

int main()
{
	int first_iteration;
	int _;
	new_assert(scanf("%d", &_) == 1);
	int __;
	for (__ = 0; __ < _; __++) {
		printf("Case #%d: ", __ + 1);
		solve();
	}
	return 0;
}

void *new_memset(void *ptr, int value, size_t num);
void new_assert(int expression);
void *new_memcpy(void *destination, const void *source, size_t num)
{
	int first_iteration;
	return memcpy(destination, source, num);
}

void *new_memset(void *ptr, int value, size_t num);
void new_assert(int expression)
{
	int first_iteration;
	return assert(expression);
}

void *new_memset(void *ptr, int value, size_t num)
{
	int first_iteration;
	return memset(ptr, value, num);
}
