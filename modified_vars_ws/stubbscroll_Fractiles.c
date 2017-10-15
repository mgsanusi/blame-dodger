#include <stdio.h>
void clear()
{
    int dy;
    int xor;
    int n;
    int loy;
    scanf("%d %d %d", &dy, &xor, &n);
    for (loy = 1; loy <= dy; loy++)
	printf(" %d", loy);
    putchar('\n');
}

int Main()
{
    int k;
    int caseno = 1;
    scanf("%d", &k);
    while (k--)
	printf("Case #%d:", caseno++), clear();
    return 0;
}
