char mapa[101][101];
int n;
int k;
char queue[2][((((15 * 15) * 16) * 16) * 16) * 16][7];
int vis[16][16][16][16][15][15];
int set;
int value[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int position[15][15][4][2];
void find(char c, int *k, int *p)
{
    int di;
    int y;
    for (di = 0; di < n; di++)
	for (y = 0; y < k; y++)
	    if (mapa[di][y] == c) {
		*k = di;
		*p = y;
		return;
	    }
}

int sale(int di, int y)
{
    if (((((di < 0) || (di >= n)) || (y < 0)) || (y >= k))
	|| (mapa[di][y] == '#'))
	return 1;
    return 0;
}

void accept(int di, int y, int dir, int *k, int *p)
{
    if ((((di < 0) || (y < 0)) || (di >= n)) || (y >= k))
	return;
    if (sale(di + value[dir], y + dy[dir])) {
	*k = (position[di][y][dir][0] = di);
	*p = (position[di][y][dir][1] = y);
	return;
    }
    if (position[di][y][dir][0] != (-1)) {
	*k = position[di][y][dir][0];
	*p = position[di][y][dir][1];
	return;
    }
    accept(di + value[dir], y + dy[dir], dir, k, p);
    position[di][y][dir][0] = *k;
    position[di][y][dir][1] = *p;
}

void insert(int pos, int *nq, int ep, int caso, int flag, int amo, int di,
	    int y, int length)
{
    if ((((di < 0) || (y < 0)) || (di >= n)) || (y >= k))
	return;
    if (mapa[di][y] == '#')
	return;
    if ((ep == (-1)) || (flag == (-1)))
	return;
    if (vis[ep][caso][flag][amo][di][y] == set)
	return;
    vis[ep][caso][flag][amo][di][y] = set;
    queue[pos][*nq][0] = ep;
    queue[pos][*nq][1] = caso;
    queue[pos][*nq][2] = flag;
    queue[pos][*nq][3] = amo;
    queue[pos][*nq][4] = di;
    queue[pos][*nq][5] = y;
    queue[pos][*nq][6] = length;
    (*nq)++;
}

int Main()
{
    int casos;
    int di;
    int k;
    int p;
    int y;
    int dir;
    int nq[2];
    int len;
    int ep;
    int caso;
    int flag;
    int amo;
    int pos;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    for (scanf("%d", &casos), set = 1; set <= casos; set++) {
	scanf("%d %d", &n, &k);
	for (di = 0; di < n; di++)
	    scanf("%s", mapa[di]);
	memset(position, -1, sizeof(position));
	for (di = 0; di < n; di++)
	    for (y = 0; y < k; y++) {
		if (mapa[di][y] == '#')
		    continue;
		for (dir = 0; dir < 4; dir++) {
		    accept(di, y, dir, &k, &p);
		}
	    }
	find('O', &k, &p);
	printf("Case #%d: ", set);
	memset(nq, 0, sizeof(nq));
	insert(0, &nq[0], 16, 16, 16, 16, k, p, 0);
	for (len = 0;; len++) {
	    if (nq[len % 2] == 0) {
		printf("THE CAKE IS A LIE\n");
		break;
	    }
	    for (pos = 0; pos < nq[len % 2]; pos++) {
		ep = (int) queue[len % 2][pos][0];
		caso = (int) queue[len % 2][pos][1];
		flag = (int) queue[len % 2][pos][2];
		amo = (int) queue[len % 2][pos][3];
		di = (int) queue[len % 2][pos][4];
		y = (int) queue[len % 2][pos][5];
		if (mapa[di][y] == 'X') {
		    printf("%d\n", len);
		    break;
		}
		for (dir = 0; dir < 4; dir++) {
		    insert(len % 2, &nq[len % 2], position[di][y][dir][0],
			   position[di][y][dir][1], flag, amo, di, y, len);
		    insert(len % 2, &nq[len % 2], ep, caso,
			   position[di][y][dir][0],
			   position[di][y][dir][1], di, y, len);
		}
		if (((di == ep) && (y == caso)) && (flag != 16)) {
		    insert((len + 1) % 2, &nq[(len + 1) % 2], ep, caso,
			   flag, amo, flag, amo, len + 1);
		}
		if (((di == flag) && (y == amo)) && (ep != 16)) {
		    insert((len + 1) % 2, &nq[(len + 1) % 2], ep, caso,
			   flag, amo, ep, caso, len + 1);
		}
		for (dir = 0; dir < 4; dir++)
		    insert((len + 1) % 2, &nq[(len + 1) % 2], ep, caso,
			   flag, amo, di + value[dir], y + dy[dir],
			   len + 1);
	    }
	    if (pos < nq[len % 2])
		break;
	    nq[len % 2] = 0;
	}
    }
    return 0;
}
