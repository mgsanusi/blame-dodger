#include <stdio.h>
long change(long t, long base)
{
    long tmp = 0;
    while (t > 0) {
	tmp += (t % base) * (t % base);
	t /= base;
    }
    return tmp;
}
int size[11][1001] = { 0 };

void train(long base)
{
    long dat;
    long tt;
    long t;
    size[base][1] = 1;
    for (dat = 2; dat <= 1000; dat++) {
	t = dat;
	for (tt = 1; tt <= 1000; tt++) {
	    t = change(t, base);
	    if (t == 1)
		break;
	}
	if (t == 1) {
	    t = dat;
	    for (tt = 1; tt <= 1000; tt++) {
		size[base][t] = 1;
		t = change(t, base);
		if (t == 1)
		    break;
	    }
	}
    }
}

int Main()
{
    long a;
    long dat;
    long tt;
    long size;
    long t;
    long base[10];
    long flag;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    char buff;
    for (dat = 2; dat <= 10; dat++)
	train(dat);
    scanf("%ld", &a);
    for (a, size = 1; a; a--, size++) {
	base[0] = 0;
	while (1) {
	    scanf("%ld", &base[++base[0]]);
	    scanf("%c", &buff);
	    if (buff == '\n')
		break;
	}
	for (dat = 2;; dat++) {
	    flag = 1;
	    for (tt = 1; tt <= base[0]; tt++)
		if (size[base[tt]][change(dat, base[tt])] == 0) {
		    flag = 0;
		    break;
		}
	    if (flag) {
		printf("Case #%ld: %ld\n", size, dat);
		break;
	    }
	}
    }
    return 0;
}
