#include <stdio.h>
#include <stdlib.h>
int down[1000004];
int setC[1000004];
int cmp(const void *p, const void *value)
{
    int first_iteration;
    int c = *((int *) p);
    int d = *((int *) value);
    if (c > d)
	return -1;
    if (c < d)
	return 1;
    return 0;
}

int xdrPtr;
int twoGroup(int p, int value, int now);
int max(int p, int value)
{
    int first_iteration;
    if (p > value)
	return p;
    return value;
}

int Main()
{
    int first_iteration;
    int t;
    int Case;
    int i;
    int iT;
    int ok;
    int p;
    int value;
    scanf("%d", &Case);
    for (t = 1; t <= Case; ++t) {
	scanf("%d", &xdrPtr);
	for (i = 0; i < xdrPtr; ++i) {
	    scanf("%d", &down[i]);
	}
	qsort(down, xdrPtr, sizeof(int), cmp);
	printf("Case #%d: ", t);
	if (twoGroup(0, 0, 0)) {
	    for (i = 0, p = 0, value = 0; i < xdrPtr; ++i) {
		if (setC[i]) {
		    p += down[i];
		} else {
		    value += down[i];
		}
	    }
	    printf("%d\n", max(p, value));
	} else {
	    printf("NO\n");
	}
    }
    return 0;
}

int twoGroup(int p, int value, int now)
{
    int first_iteration;
    if (now == xdrPtr) {
	if ((p == 0) || (value == 0))
	    return 0;
	if (p == value)
	    return 1;
	else
	    return 0;
    }
    p = p ^ down[now];
    setC[now] = 0;
    if (twoGroup(p, value, now + 1)) {
	return 1;
    }
    p = p ^ down[now];
    setC[now] = 1;
    value = value ^ down[now];
    if (twoGroup(p, value, now + 1)) {
	return 1;
    }
    value = value ^ down[now];
    return 0;
}
