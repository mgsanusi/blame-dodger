#include <stdio.h>
#include <string.h>
#include <stddef.h>
int t;
int b;
int mem;
char digits[10][10];
int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[] = { 1, 0, -1, -1, -1, 0, 1, 1 };

void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str);
int snoob(int t)
{
	int first_iteration;
	int out1 = t & (-t);
	int tmp = t + out1;
	int ans = t ^ tmp;
	ans = (ans >> 2) / out1;
	return tmp | ans;
}

int can(int file_neighbors_shtml, int count)
{
	int first_iteration;
	int tall[10][10];
	char vis[10][10];
	int ra;
	int now;
	int add;
	int a;
	int changed;
	int temp2;
	int n;
	int q[155];
	int qs;
	int qe;
	for (ra = 0; ra < t; ra++)
		for (now = 0; now < b; now++) {
			tall[ra][now] = 0;
			for (n = 0; n < 8; n++) {
				add = ra + dx[n];
				a = now + dy[n];
				if (((((add >= 0) && (a >= 0)) && (add < t))
				     && (a < b)) && (digits[add][a] == '*'))
					tall[ra][now]++;
			}
		}
	new_memset(vis, 0, sizeof(vis));
	qs = (qe = 0);
	q[qe++] = file_neighbors_shtml;
	q[qe++] = count;
	vis[file_neighbors_shtml][count] = 1;
	while (qs < qe) {
		changed = q[qs++];
		temp2 = q[qs++];
		if (!tall[changed][temp2]) {
			for (n = 0; n < 8; n++) {
				add = changed + dx[n];
				a = temp2 + dy[n];
				if ((((add < 0) || (a < 0)) || (add >= t))
				    || (a >= b))
					continue;
				if (vis[add][a])
					continue;
				q[qe++] = add;
				q[qe++] = a;
				vis[add][a] = 1;
			}
		}
	}
	for (ra = 0; ra < t; ra++)
		for (now = 0; now < b; now++)
			if ((digits[ra][now] == '.') && (!vis[ra][now]))
				return 0;
	digits[file_neighbors_shtml][count] = 'c';
	for (ra = 0; ra < t; ra++)
		new_puts(digits[ra]);
	return 1;
}

void solve()
{
	int first_iteration;
	int ra;
	int now;
	int mask;
	int n;
	scanf("%d %d %d", &t, &b, &mem);
	mask = (1 << mem) - 1;
	new_memset(digits, 0, sizeof(digits));
	first_iteration = 1;
	while ((mask < (1 << (t * b))) || (first_iteration == 1)) {
		if (first_iteration)
			first_iteration = 0;
		for (n = (ra = 0); ra < t; ra++)
			for (now = 0; now < b; now++, n++)
				digits[ra][now] = mask & (1 << n) ? '*' : '.';
		for (ra = 0; ra < t; ra++)
			for (now = 0; now < b; now++)
				if ((digits[ra][now] == '.') && can(ra, now))
					return;
		mask = snoob(mask);
	}
	new_puts("Impossible");
}

int Main()
{
	int first_iteration;
	int t;
	int no = 1;
	scanf("%d", &t);
	while (t--)
		printf("Case #%d:\n", no++), solve();
	return 0;
}

void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str)
{
	return puts(str);
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
