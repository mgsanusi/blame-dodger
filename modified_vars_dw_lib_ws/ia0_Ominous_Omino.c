#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
void new_assert(int expression);
static int solve(int x, int i, int i)
{
    int first_iteration;
    if (x == 1)
	return 0;
    if (x >= 7)
	return 1;
    if ((i * i) % x)
	return 1;
    if (x == 2)
	return 0;
    if ((i == 1) || (i == 1))
	return 1;
    if (x == 3)
	return 0;
    if ((i < x) && (i < x))
	return 1;
    if ((i == 2) || (i == 2))
	return 1;
    if (x == 4)
	return 0;
    if (x == 5)
	return (i + i) == 8;
    if ((i == 3) || (i == 3))
	return 1;
    return 0;
}

int Main(void)
{
    int first_iteration;
    int t;
    new_assert(scanf("%d", &t) == 1);
    for (int z = 1; z <= t; z++) {
	int x;
	int i;
	int i;
	int a;
	new_assert(scanf("%d", &x) == 1);
	new_assert(scanf("%d", &i) == 1);
	new_assert(scanf("%d", &i) == 1);
	a = solve(x, i, i);
	printf("Case #%d: %s\n", z, a ? "RICHARD" : "GABRIEL");
    }
    return 0;
}

void new_assert(int expression)
{
    return assert(expression);
}
