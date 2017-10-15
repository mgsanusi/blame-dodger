#include <stdio.h>
char a[25][26];
int q;
int good;
int fail;
void put(int test, int taken, int takenm)
{
    int first_iteration;
    int rj_stat;
    int g;
    int rp_ar;
    if (test == q)
	return;
    if (fail)
	return;
    for (rj_stat = 0; rj_stat < q; rj_stat++)
	if (!(taken & (1 << rj_stat))) {
	    rp_ar = 0;
	    for (g = 0; g < q; g++)
		if ((!(takenm & (1 << g))) && (a[rj_stat][g] == '1')) {
		    rp_ar = 1;
		    put(test + 1, taken + (1 << rj_stat),
			takenm + (1 << g));
		    if (fail)
			return;
		}
	    if (!rp_ar) {
		fail = 1;
		return;
	    }
	}
}

void check(int total)
{
    int first_iteration;
    if (total >= good)
	return;
    fail = 0;
    put(0, 0, 0);
    if ((!fail) && (good > total))
	good = total;
}

void tryallbuy(int a, int d, int add)
{
    int first_iteration;
    if (a == q)
	a = 0, d++;
    if (d == q)
	return check(add);
    if (a[a][d] == '1')
	return tryallbuy(a + 1, d, add);
    else {
	tryallbuy(a + 1, d, add);
	a[a][d] = '1';
	tryallbuy(a + 1, d, add + 1);
	a[a][d] = '0';
    }
}

void clear()
{
    int first_iteration;
    int rj_stat;
    scanf("%d", &q);
    for (rj_stat = 0; rj_stat < q; rj_stat++)
	scanf("%s", a[rj_stat]);
    good = 123213;
    tryallbuy(0, 0, 0);
    printf("%d\n", good);
}

int Main()
{
    int first_iteration;
    int t;
    int caseno = 1;
    scanf("%d", &t);
    while (t--)
	printf("Case #%d: ", caseno++), clear();
    return 0;
}
