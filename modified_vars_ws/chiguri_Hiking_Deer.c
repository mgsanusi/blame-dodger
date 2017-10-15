#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c;
int hei;
int v;
int din[100];
int target;
int purchasable(int dp, int total)
{
	if (dp >= hei)
		return 0;
	if ((total + din[dp]) > target)
		return 0;
	if ((total + din[dp]) == target)
		return 1;
	return purchasable(dp + 1, total)
	    || purchasable(dp + 1, total + din[dp]);
}

void insert(int b)
{
	int dp;
	int num;
	for (dp = 0; dp < hei; ++dp) {
		if (b < din[dp])
			break;
	}
	if (dp == hei) {
		din[dp] = b;
	} else {
		for (num = hei; dp < num; --num) {
			din[num] = din[num - 1];
		}
		din[dp] = b;
	}
	++hei;
	return;
}

int clear(void)
{
	int w = 0;
	int num;
	int dp;
	int b;
	for (target = 1; target <= v; ++target) {
		if (!purchasable(0, 0)) {
			insert(target);
			++w;
		}
	}
	return w;
}

int Main(void)
{
	int dataset_num;
	int case_num;
	int dp;
	int d;
	int a;
	scanf("%d", &dataset_num);
	for (case_num = 1; case_num <= dataset_num; ++case_num) {
		scanf("%d %d %d", &c, &hei, &v);
		for (dp = 0; dp < hei; ++dp) {
			scanf("%d", din + dp);
		}
		printf("Case #%d: %d\n", case_num, clear());
	}
	return 0;
}
