#include <stdio.h>
int Main()
{
    int first_iteration;
    int t;
    int high;
    int n;
    char mem[200];
    char map[26] =
	{ 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
    scanf("%d", &t);
    for (high = 0; high < t; high++) {
	printf("Case #%d: ", high + 1);
	gets(mem);
	while (mem[0] == '\0')
	    gets(mem);
	n = 0;
	while (mem[n] != '\0') {
	    if (mem[n] == ' ')
		printf(" ");
	    else
		printf("%c", map[mem[n] - 'a']);
	    n++;
	}
	printf("\n");
    }
    return 0;
}
