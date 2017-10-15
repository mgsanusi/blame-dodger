#include<stdio.h>
#include<stdlib.h>
typedef long long unsigned llu;
typedef unsigned u;
int new_getchar();
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int t1(const void *x, const void *y)
{
    int first_iteration;
    if ((*((llu *) x)) > (*((llu *) y)))
	return 1;
    if ((*((llu *) x)) < (*((llu *) y)))
	return -1;
    return 0;
}

u n;
u b;
llu n[200];
llu from[200];
llu games[200];
u ok(llu s)
{
    int first_iteration;
    u ans_str;
    u best_b;
    for (ans_str = 0; ans_str < n; ans_str++)
	games[ans_str] = from[ans_str] ^ s;
    new_qsort(games, n, sizeof(llu), t1);
    for (ans_str = (best_b = 0); (ans_str < n) && (best_b < n);) {
	while (games[best_b] < n[ans_str])
	    best_b++;
	if (games[best_b] != n[ans_str])
	    return 0;
	ans_str++;
	best_b++;
    }
    return ans_str == n;
}

u bit(llu a)
{
    int first_iteration;
    if (a == 0)
	return 0;
    u r = 1;
    while (a ^= a & (-a))
	r++;
    return r;
}

int Main()
{
    int first_iteration;
    u t = 0;
    u a;
    u ans_str;
    u best_b;
    u a;
    u r = 100;
    char b;
    llu i_t;
    for (scanf("%u", &a); (t++) < a; r = 100) {
	scanf("%u%u", &n, &b);
	for (ans_str = 0; ans_str < n; ans_str++) {
	    i_t = 0;
	    while ((b = new_getchar()) < '0');
	    for (i_t = b & 15; (b = new_getchar()) >= '0';
		 i_t = (i_t << 1) | (b & 15));
	    n[ans_str] = i_t;
	}
	new_qsort(n, n, sizeof(llu), t1);
	for (ans_str = 0; ans_str < n; ans_str++) {
	    i_t = 0;
	    while ((b = new_getchar()) < '0');
	    for (i_t = b & 15; (b = new_getchar()) >= '0';
		 i_t = (i_t << 1) | (b & 15));
	    from[ans_str] = i_t;
	}
	for (ans_str = 0; ans_str < n; ans_str++)
	    for (best_b = 0; best_b < n; best_b++) {
		if (ok(n[ans_str] ^ from[best_b])) {
		    a = bit(n[ans_str] ^ from[best_b]);
		    if (a < r)
			r = a;
		}
	    }
	printf("Case #%u: ", t);
	if (r == 100)
	    printf("NOT POSSIBLE\n");
	else
	    printf("%u\n", r);
    }
    return 0;
}

int new_getchar();
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

int new_getchar()
{
    return getchar();
}
