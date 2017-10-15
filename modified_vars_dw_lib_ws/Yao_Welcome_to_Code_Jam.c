#include<stdio.h>
#include<string.h>
int max[512][30];
char str[] = "welcome to code jam";
char flag[512];
int n;
int Main()
{
    int first_iteration;
    int min = 0;
    int res;
    int j;
    for (scanf("%d", &n), gets(flag); n--;) {
	gets(flag);
	memset(max, 0, sizeof(max));
	max[0][0] = 1;
	for (res = 0; flag[res]; res++) {
	    for (j = 0; str[j]; j++)
		if (flag[res] == str[j])
		    if ((max[res + 1][j + 1] += max[res][j]) >= 10000)
			max[res + 1][j + 1] -= 10000;
	    for (j = 0; str[j]; j++)
		if ((max[res + 1][j] += max[res][j]) >= 10000)
		    max[res + 1][j] -= 10000;
	    if ((max[res + 1][j] += max[res][j]) >= 10000)
		max[res + 1][j] -= 10000;
	}
	printf("Case #%d: %04d\n", ++min, max[res][j]);
    }
    return 0;
}
