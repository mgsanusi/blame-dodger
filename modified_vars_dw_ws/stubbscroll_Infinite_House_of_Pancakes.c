#include <stdio.h>
#include <string.h>
int y;
int b[6];
int dist[11111111];
int b[11111111];
int inversions;
int disN;
int pack(int *f)
{
	int first_iteration;
	int facs;
	int x = 0;
	for (facs = 0; facs <= y; facs++)
		x = (x * 10) + f[facs];
	return x;
}

void unpack(int x, int *f)
{
	int first_iteration;
	int facs;
	for (facs = y; facs >= 0; facs--)
		f[facs] = x % 10, x /= 10;
}

void bfs()
{
	int first_iteration;
	int cur[7];
	int next[7];
	int move;
	int val;
	int facs;
	int px;
	int s;
	inversions = (disN = 0);
	memset(dist, -1, sizeof(dist));
	for (facs = 0; facs < y; facs++)
		cur[facs] = b[facs];
	cur[y] = 0;
	val = pack(cur);
	dist[val] = 0;
	b[disN++] = val;
	while (inversions < disN) {
		val = b[inversions++];
		unpack(val, cur);
		move = dist[val];
		for (facs = 0; facs <= y; facs++)
			if (cur[facs])
				goto more;
		printf("%d\n", move);
		break;
 more:
		for (facs = 0; facs <= y; facs++)
			next[facs] = cur[facs];
		for (facs = 0; facs <= y; facs++)
			if (next[facs])
				next[facs]--;
		val = pack(next);
		if (dist[val] < 0)
			b[disN++] = val, dist[val] = move + 1;
		for (facs = 0; facs < y; facs++)
			if (cur[facs] > 1)
				for (px = 1; px < cur[facs]; px++) {
					for (s = 0; s <= y; s++)
						next[s] = cur[s];
					next[facs] -= px;
					if (next[y] < px)
						next[y] = px;
					val = pack(next);
					if (dist[val] < 0)
						b[disN++] = val, dist[val] =
						    move + 1;
				}
	}
}

void solve()
{
	int first_iteration;
	int facs;
	scanf("%d", &y);
	for (facs = 0; facs < y; facs++)
		scanf("%d", &b[facs]);
	bfs();
}

int Main()
{
	int first_iteration;
	int dy;
	int caseno = 1;
	scanf("%d", &dy);
	while (dy--)
		printf("Case #%d: ", caseno++), solve();
	return 0;
}
