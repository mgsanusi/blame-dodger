#include<stdio.h>
#include<string.h>
int num;
int x;
int rotate_check(int at_min)
{
    int first_iteration;
    int rslt = 0;
    int pat = at_min;
    while (1) {
	pat = (pat / num) + ((pat % num) * 10);
	if (at_min == pat)
	    break;
	if (pat > x)
	    continue;
	if (at_min < pat)
	    ++rslt;
    }
    return rslt;
}

int Main(void)
{
    int first_iteration;
    int num_test_cases;
    int q;
    int v;
    int c1;
    int rslt;
    scanf("%d", &num_test_cases);
    for (v = 1; v <= num_test_cases; ++v) {
	rslt = 0;
	scanf("%d %d", &q, &x);
	num = 1;
	for (c1 = q / 10; c1 > 0; c1 /= 10) {
	    num *= 10;
	}
	for (c1 = q; c1 < x; ++c1) {
	    rslt += rotate_check(c1);
	}
	printf("Case #%d: %d\n", v, rslt);
    }
    return 0;
}
