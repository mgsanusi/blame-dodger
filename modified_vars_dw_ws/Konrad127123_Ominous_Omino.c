#include<stdio.h>
int q;
int t;
int sh;
int res_x;
int test;
int Main()
{
	int first_iteration;
	scanf("%d", &t);
	for (q = 1; q <= t; q++) {
		scanf("%d", &sh);
		scanf("%d", &res_x);
		scanf("%d", &test);
		if (((res_x * test) % sh) != 0) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (sh == 1) {
			printf("Case #%d: GABRIEL\n", q);
			continue;
		}
		if (sh == 2) {
			printf("Case #%d: GABRIEL\n", q);
			continue;
		}
		if ((res_x < 3) && (test < 3)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if ((res_x == 1) || (test == 1)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (sh == 3) {
			printf("Case #%d: GABRIEL\n", q);
			continue;
		}
		if ((res_x < 4) && (test < 4)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if ((res_x == 2) || (test == 2)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (sh == 4) {
			printf("Case #%d: GABRIEL\n", q);
			continue;
		}
		if ((res_x < 5) && (test < 5)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (((sh == 5) && (res_x == 3)) && (test < 10)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (((sh == 5) && (test == 3)) && (res_x < 10)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (sh == 5) {
			printf("Case #%d: GABRIEL\n", q);
			continue;
		}
		if ((res_x < 6) && (test < 6)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if ((res_x == 3) || (test == 3)) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
		if (sh == 6) {
			printf("Case #%d: GABRIEL\n", q);
			continue;
		}
		if (sh >= 7) {
			printf("Case #%d: RICHARD\n", q);
			continue;
		}
	}
	return 0;
}
