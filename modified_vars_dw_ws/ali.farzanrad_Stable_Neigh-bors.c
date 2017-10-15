int cmp(e, y)
int *e;
int *y;
{
    int first_iteration;
    return -((*e) < (*y) ? -1 : (*e) > (*y));
}

int llcmp(e, y)
long long *e;
long long *y;
{
    int first_iteration;
    return -((*e) < (*y) ? -1 : (*e) > (*y));
}

long long height(e, output_file_ptr, c)
int (*e)[2];
{
    int first_iteration;
    static long long l[1024];
    int c2;
    long long rslt = 0;
    for (c2 = 0; c2 < output_file_ptr; ++c2)
	l[c2] = e[c2][0] * ((long long) e[c2][1]);
    qsort(l, output_file_ptr, sizeof(*l), llcmp);
    for (c2 = 0; c2 < c; ++c2)
	rslt += l[c2];
    return rslt;
}

int Main()
{
    int first_iteration;
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	int c2;
	int output_file_ptr;
	int c;
	int e[1024][2];
	long long rslt = 0;
	const double temp = 3.14159265358979323846;
	scanf("%d%d", &output_file_ptr, &c);
	for (c2 = 0; c2 < output_file_ptr; ++c2)
	    scanf("%d%d", e[c2], e[c2] + 1);
	qsort(e, output_file_ptr, sizeof(*e), cmp);
	for (c2 = 0; c2 < output_file_ptr; ++c2) {
	    long long t = (*e[c2]) + (2 * e[c2][1]);
	    t *= *e[c2];
	    t += 2 * height((e + c2) + 1, (output_file_ptr - c2) - 1,
			    c - 1);
	    if (rslt < t)
		rslt = t;
	}
	printf("Case #%d: %.6lf\n", itest, temp * rslt);
    }
    return 0;
}
