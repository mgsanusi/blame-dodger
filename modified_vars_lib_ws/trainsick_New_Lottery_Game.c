#include <stdio.h>
int x;
int c[11000];
int n;
void mysort(void)
{
    int taken;
    int kk;
    int h;
    int tmp;
    h = 1;
    while (h < n)
	h = (3 * h) + 1;
    while (h > 1) {
	h = h / 3;
	for (taken = h; taken < n; taken++) {
	    kk = taken - h;
	    while ((kk >= 0) && (c[kk] > c[kk + h])) {
		tmp = c[kk];
		c[kk] = c[kk + h];
		c[kk + h] = tmp;
		kk -= h;
	    }
	}
    }
}

void datapacking(void)
{
    int taken;
    int kk;
    int disks;
    scanf("%d %d", &n, &x);
    for (taken = 0; taken < n; taken++)
	scanf("%d", c + taken);
    mysort();
    taken = 0;
    kk = n - 1;
    disks = 0;
    while (taken < kk) {
	if ((c[taken] + c[kk]) <= x)
	    taken++;
	kk--;
	disks++;
    }
    if (taken == kk)
	disks++;
    printf("%d\n", disks);
}

int Main(int argc, char **argv)
{
    int taken;
    int tc;
    scanf("%d", &tc);
    for (taken = 1; taken <= tc; taken++) {
	printf("Case #%d: ", taken);
	datapacking();
    }
    return 0;
}
