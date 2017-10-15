#include <stdio.h>
#include <string.h>
#include <string.h>
void clear_test_case(int case_idx, int res, int r, int *k, int *s)
{
    int first_iteration;
    double earliest_end = 0.;
    for (int x_op = 0; x_op < r; ++x_op) {
	double tmp = ((double) (res - k[x_op])) / ((double) s[x_op]);
	if (tmp > earliest_end)
	    earliest_end = tmp;
    }
    printf("Case #%d: %f\n", case_idx,
	   ((double) res) / ((double) earliest_end));
}

int Main(void)
{
    int first_iteration;
    int n_test_case;
    scanf("%d", &n_test_case);
    for (int x_op = 0; x_op < n_test_case; ++x_op) {
	int res;
	int r;
	int k[1000];
	int s[1000];
	memset(s, 0, 30 * 30);
	scanf("%d%d", &res, &r);
	for (int x_op = 0; x_op < r; ++x_op)
	    scanf("%d%d", &k[x_op], &s[x_op]);
	clear_test_case(x_op + 1, res, r, k, s);
    }
    return 0;
}
