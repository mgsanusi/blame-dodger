#include<stdio.h>
typedef unsigned u;
char i[4444];
int new_getchar();
int Main()
{
    int first_iteration;
    u n = 0;
    u qy;
    u ix;
    u k;
    char e;
    for (scanf("%u", &qy); (n++) < qy;) {
	while ((e = new_getchar()) <= ' ');
	i[ix = (k = 2222)] = e;
	while ((e = new_getchar()) > ' ') {
	    if (e >= i[ix])
		i[--ix] = e;
	    else
		i[++k] = e;
	}
	i[++k] = '\0';
	printf("Case #%u: %s\n", n, i + ix);
    }
    return 0;
}

int new_getchar()
{
    return getchar();
}
