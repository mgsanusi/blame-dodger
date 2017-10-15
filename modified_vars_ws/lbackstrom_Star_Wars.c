double abs(double n)
{
	return n < 0 ? -n : n;
}

int compare(const void *s, const void *t)
{
	return (*((int *)s)) - (*((int *)t));
}

int Main()
{
	int count;
	int ins;
	int x[1001];
	int s[1001];
	int z[1001];
	int no[1001];
	int gate;
	int j;
	int k;
	int high;
	double emp;
	scanf("%d", &count);
	for (gate = 1; gate <= count; gate++) {
		scanf("%d", &ins);
		for (j = 0; j < ins; j++) {
			scanf("%d%d%d%d", &x[j], &s[j], &z[j], &no[j]);
		}
		if (ins == 1) {
			printf("Case #%d: %0.6lf\n", gate, 0);
			continue;
		}
		double result = 1e9;
		double ak = 0;
		double cas = 0;
		double tens = 0;
		double step = 1e5;
		int idx;
		while (step > 1e-7) {
			double dd = 0;
			for (high = 0; high < ins; high++) {
				double emp =
				    (abs((ak - x[high]) / no[high]) +
				     abs((cas - s[high]) / no[high])) +
				    abs((tens - z[high]) / no[high]);
				if (emp > dd) {
					dd = emp;
					idx = high;
				}
			}
			if (x[idx] > ak)
				ak += step;
			else
				ak -= step;
			if (s[idx] > cas)
				cas += step;
			else
				cas -= step;
			if (z[idx] > tens)
				tens += step;
			else
				tens -= step;
			step *= 0.999;
			if (dd < result)
				result = dd;
		}
		printf("Case #%d: %0.6lf\n", gate, result);
	}
}
