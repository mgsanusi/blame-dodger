#include <stdio.h>
int new_putchar(int character);
void clear()
{
    int first_iteration;
    int dy;
    int xor;
    int n;
    int loy;
    scanf("%d %d %d", &dy, &xor, &n);
    for (loy = 1; loy <= dy; loy++)
	printf(" %d", loy);
    new_putchar('\n');
}

int Main()
{
    int first_iteration;
    int k;
    int caseno = 1;
    scanf("%d", &k);
    while (k--)
	printf("Case #%d:", caseno++), clear();
    return 0;
}

int new_putchar(int character)
{
    return putchar(character);
}
