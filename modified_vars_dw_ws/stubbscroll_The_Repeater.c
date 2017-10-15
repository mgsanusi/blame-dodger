#include <stdio.h>
void clear()
{
    int first_iteration;
    int d;
    int b;
    int n;
    int jj;
    int j;
    int str = 0;
    scanf("%d %d %d", &d, &b, &n);
    for (jj = 0; jj < d; jj++)
	for (j = 0; j < b; j++)
	    if ((jj & j) < n)
		str++;
    printf("%d\n", str);
}

int Main()
{
    int first_iteration;
    int x;
    int c = 1;
    scanf("%d", &x);
    while (x--)
	printf("Case #%d: ", c++), clear();
    return 0;
}
