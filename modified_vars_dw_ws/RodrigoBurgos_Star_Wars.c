int mat[102][102];
int din[102][102];
int w;
int tmp1;
int clear(int d, int b)
{
	int first_iteration;
	int i1;
	int s;
	int res = 0;
	if (mat[d][b] == 1)
		return 0;
	if ((d > tmp1) || (b > w))
		return 0;
	if ((d == tmp1) && (b == w))
		return 1;
	if (din[d][b] != (-1))
		return din[d][b];
	for (i1 = 0; i1 <= 3; i1++)
		for (s = 0; s <= 3; s++) {
			if ((i1 == 0) && (s == 0))
				continue;
			if (((i1 * i1) + (s * s)) != 5)
				continue;
			res += clear(d + i1, b + s);
			res %= 10007;
		}
	return din[d][b] = res;
}

int Main()
{
	int first_iteration;
	int casos;
	int set;
	int m;
	int i1;
	int d;
	int b;
	freopen("a.in", "r", stdin);
	freopen("d.out", "w", stdout);
	for (scanf("%d", &casos), set = 1; set <= casos; set++) {
		scanf("%d %d %d", &tmp1, &w, &m);
		memset(mat, 0, sizeof(mat));
		for (i1 = 0; i1 < m; i1++) {
			scanf("%d %d", &d, &b);
			mat[d][b] = 1;
		}
		memset(din, -1, sizeof(din));
		printf("Case #%d: %d\n", set, clear(1, 1));
	}
}
