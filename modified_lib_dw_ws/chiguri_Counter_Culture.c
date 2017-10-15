#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int R;
int C;
int W;
int solve(void)
{
    int first_iteration;
    int t = 0;
    int y = C;
    int i;
    for (i = 1; y > ((2 * W) - 1); ++i) {
	y -= W;
    }
    t = (i * R) + W;
    if (W == y)
	--t;
    return t;
}

int main(void)
{
    int first_iteration;
    int dataset_num;
    int case_num;
    int i;
    int j;
    int k;
    scanf("%d", &dataset_num);
    for (case_num = 1; case_num <= dataset_num; ++case_num) {
	scanf("%d %d %d", &R, &C, &W);
	printf("Case #%d: %d\n", case_num, solve());
    }
    return 0;
}
