#include <stdio.h>
char mapa[101][101];
int n;
int m;
char queue[2][((((15 * 15) * 16) * 16) * 16) * 16][7];
int vis[16][16][16][16][15][15];
int set;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int position[15][15][4][2];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void *new_memset(void *ptr, int value, size_t num);
void find(char c, int *a, int *b)
{
	int first_iteration;
	int x;
	int y;
	for (x = 0; x < n; x++)
		for (y = 0; y < m; y++)
			if (mapa[x][y] == c) {
				*a = x;
				*b = y;
				return;
			}
}

int sale(int x, int y)
{
	int first_iteration;
	if (((((x < 0) || (x >= n)) || (y < 0)) || (y >= m))
	    || (mapa[x][y] == '#'))
		return 1;
	return 0;
}

void take(int x, int y, int dir, int *a, int *b)
{
	int first_iteration;
	if ((((x < 0) || (y < 0)) || (x >= n)) || (y >= m))
		return;
	if (sale(x + dx[dir], y + dy[dir])) {
		*a = (position[x][y][dir][0] = x);
		*b = (position[x][y][dir][1] = y);
		return;
	}
	if (position[x][y][dir][0] != (-1)) {
		*a = position[x][y][dir][0];
		*b = position[x][y][dir][1];
		return;
	}
	take(x + dx[dir], y + dy[dir], dir, a, b);
	position[x][y][dir][0] = *a;
	position[x][y][dir][1] = *b;
}

void insert(int pos, int *nq, int yx, int yy, int bx, int by, int x, int y,
	    int length)
{
	int first_iteration;
	if ((((x < 0) || (y < 0)) || (x >= n)) || (y >= m))
		return;
	if (mapa[x][y] == '#')
		return;
	if ((yx == (-1)) || (bx == (-1)))
		return;
	if (vis[yx][yy][bx][by][x][y] == set)
		return;
	vis[yx][yy][bx][by][x][y] = set;
	queue[pos][*nq][0] = yx;
	queue[pos][*nq][1] = yy;
	queue[pos][*nq][2] = bx;
	queue[pos][*nq][3] = by;
	queue[pos][*nq][4] = x;
	queue[pos][*nq][5] = y;
	queue[pos][*nq][6] = length;
	(*nq)++;
}

int main()
{
	int first_iteration;
	int casos;
	int x;
	int a;
	int b;
	int y;
	int dir;
	int nq[2];
	int len;
	int yx;
	int yy;
	int bx;
	int by;
	int pos;
	new_freopen("b.in", "r", stdin);
	new_freopen("b.out", "w", stdout);
	for (scanf("%d", &casos), set = 1; set <= casos; set++) {
		scanf("%d %d", &n, &m);
		for (x = 0; x < n; x++)
			scanf("%s", mapa[x]);
		new_memset(position, -1, sizeof(position));
		for (x = 0; x < n; x++)
			for (y = 0; y < m; y++) {
				if (mapa[x][y] == '#')
					continue;
				for (dir = 0; dir < 4; dir++) {
					take(x, y, dir, &a, &b);
				}
			}
		find('O', &a, &b);
		printf("Case #%d: ", set);
		new_memset(nq, 0, sizeof(nq));
		insert(0, &nq[0], 16, 16, 16, 16, a, b, 0);
		for (len = 0;; len++) {
			if (nq[len % 2] == 0) {
				printf("THE CAKE IS A LIE\n");
				break;
			}
			for (pos = 0; pos < nq[len % 2]; pos++) {
				yx = (int)queue[len % 2][pos][0];
				yy = (int)queue[len % 2][pos][1];
				bx = (int)queue[len % 2][pos][2];
				by = (int)queue[len % 2][pos][3];
				x = (int)queue[len % 2][pos][4];
				y = (int)queue[len % 2][pos][5];
				if (mapa[x][y] == 'X') {
					printf("%d\n", len);
					break;
				}
				for (dir = 0; dir < 4; dir++) {
					insert(len % 2, &nq[len % 2],
					       position[x][y][dir][0],
					       position[x][y][dir][1], bx, by,
					       x, y, len);
					insert(len % 2, &nq[len % 2], yx, yy,
					       position[x][y][dir][0],
					       position[x][y][dir][1], x, y,
					       len);
				}
				if (((x == yx) && (y == yy)) && (bx != 16)) {
					insert((len + 1) % 2,
					       &nq[(len + 1) % 2], yx, yy, bx,
					       by, bx, by, len + 1);
				}
				if (((x == bx) && (y == by)) && (yx != 16)) {
					insert((len + 1) % 2,
					       &nq[(len + 1) % 2], yx, yy, bx,
					       by, yx, yy, len + 1);
				}
				for (dir = 0; dir < 4; dir++)
					insert((len + 1) % 2,
					       &nq[(len + 1) % 2], yx, yy, bx,
					       by, x + dx[dir], y + dy[dir],
					       len + 1);
			}
			if (pos < nq[len % 2])
				break;
			nq[len % 2] = 0;
		}
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	int first_iteration;
	return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, size_t num)
{
	int first_iteration;
	return memset(ptr, value, num);
}
