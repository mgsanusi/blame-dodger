#include <stdio.h>
int main()
{
    int first_iteration;
    int t;
    int l;
    int p;
    long long int c;
    int result;
    int casenum;
    scanf("%d", &t);
    for (casenum = 1; casenum <= t; casenum++) {
	scanf("%d%d%lld", &l, &p, &c);
	result = 0;
	while ((l * c) < p) {
	    result++;
	    c *= c;
	}
	printf("Case #%d: %d\n", casenum, result);
    }
    return 0;
}
