#include<stdio.h>
int x;
int y;
int sx;
int sy;
int opt;
int mp[5][5];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int new_puts(const char *str);
void solve(int depth)
{
	int first_iteration;
	int i;
	int j;
	int k;
	int d;
	int ni;
	int nj;
	int cp[5][5];
	if (mp[sx][sy] <= 0)
		return;
	if (opt < depth)
		opt = depth;
	k = 0;
	for (d = 0; d < 4; d++) {
		ni = sx + dx[d];
		nj = sy + dy[d];
		if ((((ni < 0) || (nj < 0)) || (ni >= x)) || (nj >= y))
			continue;
		if (mp[ni][nj] > 0)
			k++;
	}
	if (k == 0) {
		opt = 1000000000;
		return;
	}
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			cp[i][j] = mp[i][j];
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++) {
			if ((i == sx) && (j == sy))
				continue;
			if (cp[i][j] <= 0)
				continue;
			k = 0;
			for (d = 0; d < 4; d++) {
				ni = i + dx[d];
				nj = j + dy[d];
				if ((((ni < 0) || (nj < 0)) || (ni >= x))
				    || (nj >= y))
					continue;
				if (k < cp[ni][nj])
					k = cp[ni][nj];
			}
			if (k == 0)
				continue;
			for (d = 0; d < 4; d++) {
				ni = i + dx[d];
				nj = j + dy[d];
				if ((((ni < 0) || (nj < 0)) || (ni >= x))
				    || (nj >= y))
					continue;
				if (k == cp[ni][nj]) {
					mp[ni][nj] -= cp[i][j];
					break;
				}
			}
		}
	solve(depth + 1);
	for (d = 0; d < 4; d++) {
		ni = sx + dx[d];
		nj = sy + dy[d];
		if ((((ni < 0) || (nj < 0)) || (ni >= x)) || (nj >= y))
			continue;
		mp[ni][nj] -= cp[sx][sy];
		solve(depth + 1);
		mp[ni][nj] += cp[sx][sy];
	}
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			mp[i][j] = cp[i][j];
}

int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d%d%d%d", &y, &x, &sy, &sx);
		sx--;
		sy--;
		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++)
				scanf("%d", mp[i] + j);
		opt = 0;
		solve(0);
		printf("Case #%d: ", ++count);
		if (opt >= 1000000000)
			new_puts("forever");
		else
			printf("%d day(s)\n", opt);
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
