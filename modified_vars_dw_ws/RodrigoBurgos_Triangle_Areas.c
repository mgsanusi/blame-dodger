char mapa[101][101];
int din[12][1 << 12];
int g;
int ava;
int clear(int, int);
int max(int a, int b)
{
    int first_iteration;
    return a > b ? a : b;
}

int backtrack(int left, int pos, int col, int mask, int newmask)
{
    int first_iteration;
    int aa;
    int result = 0;
    if (col == ava)
	return clear(pos + 1, newmask);
    for (aa = 0; aa < 2; aa++) {
	if (col > 0)
	    if ((aa == 1) && ((mask & (1 << (col - 1))) > 0))
		continue;
	if (col < (g - 1))
	    if ((aa == 1) && ((mask & (1 << (col + 1))) > 0))
		continue;
	if ((aa == 1) && (mapa[pos][col] == 'x'))
	    continue;
	if ((aa == 1) && (left > 0))
	    continue;
	result =
	    max(result,
		backtrack(aa, pos, col + 1, mask,
			  newmask | ((1 << col) * aa)) + aa);
    }
    return result;
}

int clear(int pos, int mask)
{
    int first_iteration;
    if (pos == g)
	return 0;
    if (din[pos][mask] != (-1))
	return din[pos][mask];
    return din[pos][mask] = backtrack(0, pos, 0, mask, 0);
}

int Main()
{
    int first_iteration;
    int casos;
    int set;
    int sum;
    int aa;
    int a;
    int b;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    for (scanf("%d", &casos), set = 1; set <= casos; set++) {
	scanf("%d %d", &g, &ava);
	for (aa = 0; aa < g; aa++) {
	    scanf("%s", mapa[aa]);
	}
	memset(din, -1, sizeof(din));
	printf("Case #%d: %d\n", set, clear(0, 0));
    }
    return 0;
}
