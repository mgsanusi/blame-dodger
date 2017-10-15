#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length;
int c;
int w;
int clear(void)
{
	int first_iteration;
	int n = 0;
	int b = c;
	int tt;
	for (tt = 1; b > ((2 * w) - 1); ++tt) {
		b -= w;
	}
	n = (tt * length) + w;
	if (w == b)
		--n;
	return n;
}

int Main(void)
{
	int first_iteration;
	int dataset_no;
	int case_no;
	int tt;
	int yc;
	int a;
	scanf("%d", &dataset_no);
	for (case_no = 1; case_no <= dataset_no; ++case_no) {
		scanf("%d %d %d", &length, &c, &w);
		printf("Case #%d: %d\n", case_no, clear());
	}
	return 0;
}
