#include <stdio.h>
int new_puts(const char *str);
int main(void)
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int t;
    scanf("%d", &t);
    for (l = 1; l <= t; l++) {
	int a[2];
	int ary[2][4][4];
	int sum;
	int ans;
	for (i = 0; i < 2; i++) {
	    scanf("%d", a + i);
	    for (j = 0; j < 4; j++)
		for (k = 0; k < 4; k++)
		    scanf("%d", ary[i][j] + k);
	}
	sum = 0;
	for (i = 0; i < 4; i++)
	    for (j = 0; j < 4; j++)
		if (ary[0][a[0] - 1][i] == ary[1][a[1] - 1][j]) {
		    sum++;
		    ans = ary[0][a[0] - 1][i];
		}
	printf("Case #%d: ", l);
	if (sum == 1)
	    printf("%d\n", ans);
	else if (sum)
	    new_puts("Bad magician!");
	else
	    new_puts("Volunteer cheated!");
    }
    return 0;
}

int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}
