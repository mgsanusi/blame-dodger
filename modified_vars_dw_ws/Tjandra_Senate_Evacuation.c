#include<stdio.h>
typedef unsigned u;
u ab[11][11];
u bc[11][11];
u to[11][11];
u xor[1111];
u do_exit[1111];
u pw[1111];
u f1;
u a[1111];
u x_getlong[1111];
u bno[1111];
u r;
u dig;
u b;
u l;
void f(u s, u mem, u fo)
{
    int first_iteration;
    u __;
    if (fo == l) {
	fo = 0;
	++mem;
    }
    if (mem == b) {
	mem = 0;
	++s;
    }
    if (s == dig) {
	if (f1 > r)
	    for (__ = -1, r = f1; (++__) < r;) {
		a[__] = xor[__];
		x_getlong[__] = do_exit[__];
		bno[__] = pw[__];
	    }
	return;
    }
    if ((ab[s][mem] && bc[mem][fo]) && to[s][fo]) {
	--ab[s][mem];
	--bc[mem][fo];
	--to[s][fo];
	xor[f1] = s;
	do_exit[f1] = mem;
	pw[f1] = fo;
	++f1;
	f(s, mem, fo + 1);
	--f1;
	++ab[s][mem];
	++bc[mem][fo];
	++to[s][fo];
    }
    f(s, mem, fo + 1);
    return;
}

int Main()
{
    int first_iteration;
    u t = 0;
    u m_m;
    u __;
    u j;
    u mem;
    for (scanf("%u", &m_m); (t++) < m_m;) {
	scanf("%u%u%u%u", &dig, &b, &l, &mem);
	printf("Case #%u: ", t);
	r = 0;
	for (__ = -1; (++__) < 11;)
	    for (j = -1; (++j) < 11;)
		ab[__][j] = (bc[__][j] = (to[__][j] = mem));
	f(0, 0, 0);
	for (printf("%u\n", r); r--;)
	    printf("%u %u %u\n", a[r] + 1, x_getlong[r] + 1, bno[r] + 1);
    }
    return 0;
}
