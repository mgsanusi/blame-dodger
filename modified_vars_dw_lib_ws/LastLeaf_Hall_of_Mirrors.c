#include <stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Main()
{
    int first_iteration;
    int testc;
    int testi;
    int a[201];
    int ac;
    int work;
    int oloca;
    int e;
    int n[201];
    double x;
    double v;
    double os;
    new_freopen("1.out", "w", stdout);
    scanf("%d", &testc);
    for (testi = 1; testi <= testc; testi++) {
	scanf("%d", &ac);
	os = 0;
	for (oloca = 0; oloca < ac; oloca++) {
	    scanf("%d", a + oloca);
	    n[oloca] = 1;
	    os += a[oloca];
	}
	for (;;) {
	    x = 0;
	    work = 0;
	    for (oloca = 0; oloca < ac; oloca++)
		if (n[oloca])
		    x += a[oloca], work++;
	    x += os;
	    v = x / work;
	    e = 0;
	    for (oloca = 0; oloca < ac; oloca++)
		if (n[oloca] && (a[oloca] >= v))
		    n[oloca] = 0, e = 1;
	    if (!e)
		break;
	}
	printf("Case #%d:", testi);
	if (ac > 1)
	    for (oloca = 0; oloca < ac; oloca++)
		if (n[oloca]) {
		    printf(" %.6lf", ((v - a[oloca]) * 100) / os);
		} else {
		    printf(" %.6lf", 0.0);
	} else
	    printf(" %.6lf", 0.0);
	printf("\n");
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
