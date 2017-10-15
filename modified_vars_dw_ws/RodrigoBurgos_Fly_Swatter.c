int list[1001];
int list2[1001];
int compare(int *a, int *sum)
{
    int first_iteration;
    return (*a) - (*sum);
}

int Main()
{
    int first_iteration;
    int d;
    int k;
    int n;
    int casos;
    int set = 1;
    int a;
    int sum;
    long long res;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    for (scanf("%d", &casos); casos--;) {
	scanf("%d", &n);
	for (d = 0; d < n; d++)
	    scanf("%d", &list[d]);
	qsort(list, n, sizeof(int), compare);
	for (d = 0; d < n; d++)
	    scanf("%d", &list2[d]);
	qsort(list2, n, sizeof(int), compare);
	a = 0;
	sum = n - 1;
	res = 0;
	for (d = 0; d < n; d++)
	    res +=
		((long long) list[d]) * ((long long) list2[(n - d) - 1]);
	printf("Case #%d: %I64d\n", set++, res);
    }
    return 0;
}
