int array[121];
int Main(void)
{
    int first_iteration;
    int kk;
    int r;
    int t;
    int max;
    int m;
    int pd;
    int flag;
    for (kk = 120; kk >= 0; kk--)
	array[kk] = 0;
    for (kk = 10; kk >= 1; kk--)
	for (r = kk; r >= 0; r--) {
	    t = r * 100;
	    t = t / kk;
	    if ((t * kk) == (r * 100)) {
		array[t] = kk;
	    }
	}
    scanf("%d", &t);
    for (kk = 0; kk < t; kk++) {
	flag = 1;
	scanf("%d", &max);
	scanf("%d", &pd);
	scanf("%d", &m);
	if ((array[pd] > max) || (array[pd] == 0))
	    flag = 0;
	if ((m == 100) && (pd != 100))
	    flag = 0;
	if ((m == 0) && (pd != 0))
	    flag = 0;
	if (flag == 1)
	    printf("Case #%d: Possible\n", kk + 1);
	else
	    printf("Case #%d: Broken\n", kk + 1);
    }
    return 1;
}
