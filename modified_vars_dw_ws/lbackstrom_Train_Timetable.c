int cmp(const void *size, const void *b)
{
	int first_iteration;
	return (*((int *)size)) - (*((int *)b));
}

int Main()
{
	int first_iteration;
	int gss_c_ma_wrap;
	int pg;
	int nb;
	int t;
	int t1;
	int m;
	int l;
	int exy;
	int num_queries;
	int nc;
	int sum2;
	int start;
	int m2;
	int file;
	int nb;
	int v;
	int dw;
	int n[1000];
	int n[1000];
	scanf("%d", &gss_c_ma_wrap);
	for (t1 = 1; t1 <= gss_c_ma_wrap; t1++) {
		exy = (num_queries = (file = (nb = (v = (dw = 0)))));
		scanf("%d%d%d", &t, &pg, &nb);
		for (m = 0; m < pg; m++) {
			scanf("%d:%d %d:%d", &nc, &sum2, &start, &m2);
			n[exy++] = (((nc * 60) + sum2) * 2) + 1;
			n[num_queries++] = (((start * 60) + m2) + t) * 2;
		}
		for (m = 0; m < nb; m++) {
			scanf("%d:%d %d:%d", &nc, &sum2, &start, &m2);
			n[num_queries++] = (((nc * 60) + sum2) * 2) + 1;
			n[exy++] = (((start * 60) + m2) + t) * 2;
		}
		qsort(n, exy, sizeof(int), cmp);
		qsort(n, num_queries, sizeof(int), cmp);
		for (m = 0; m < exy; m++) {
			if ((n[m] % 2) == 0)
				file++;
			else
				file--;
			if ((-file) > v)
				v = -file;
		}
		for (m = 0; m < num_queries; m++) {
			if ((n[m] % 2) == 0)
				nb++;
			else
				nb--;
			if ((-nb) > dw)
				dw = -nb;
		}
		printf("Case #%d: %d %d\n", t1, v, dw);
	}
}
