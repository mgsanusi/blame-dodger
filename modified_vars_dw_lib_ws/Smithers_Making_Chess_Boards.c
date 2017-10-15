#include <stdio.h>
#include <stdlib.h>
int Main()
{
	int first_iteration;
	int t;
	int b;
	int n;
	int grid[512][512 / (4 * 8)];
	int good_board[512][512];
	int cnt[512 + 1];
	int tot;
	int skipper;
	int k;
	int a;
	int mode;
	int good_best;
	int size_cnt;
	int temp;
	char st;
	int casenum;
	scanf("%d", &t);
	for (casenum = 1; casenum <= t; casenum++) {
		scanf("%d%d", &b, &n);
		for (tot = 0; tot < b; tot++) {
			for (skipper = 0; (skipper * (4 * 8)) < n; skipper++) {
				grid[tot][skipper] = 0;
				for (k = 0;
				     (k < 8)
				     && (((skipper * (4 * 8)) + (k * 4)) < n);
				     k++) {
					scanf(" %c", &st);
					grid[tot][skipper] |=
					    ((st <
					      'A' ? st - '0' : (st - 'A') +
					      10) ^ (tot % 2 ? 5 : 10)) << (4 *
									    ((8
									      -
									      k)
									     -
									     1));
				}
			}
		}
		for (tot = b; tot > 0; tot--)
			cnt[tot] = 0;
		for (mode = 0; mode < 2; mode++) {
			good_best = 0;
			for (tot = b - 1; tot >= 0; tot--)
				for (skipper = n - 1; skipper >= 0; skipper--) {
					if (((grid[tot][skipper / (4 * 8)] >>
					      (((4 * 8) - (skipper % (4 * 8))) -
					       1)) & 1) != mode)
						good_board[tot][skipper] = 0;
					else if ((tot == (b - 1))
						 || (skipper == (n - 1)))
						good_board[tot][skipper] = 1;
					else {
						good_board[tot][skipper] =
						    good_board[tot +
							       1][skipper + 1] +
						    1;
						if (good_board[tot + 1][skipper]
						    < good_board[tot][skipper])
							good_board[tot][skipper]
							    =
							    good_board[tot +
								       1]
							    [skipper] + 1;
						if (good_board[tot][skipper + 1]
						    < good_board[tot][skipper])
							good_board[tot][skipper]
							    =
							    good_board[tot]
							    [skipper + 1] + 1;
					}
					if (good_board[tot][skipper] >
					    good_best)
						good_best =
						    good_board[tot][skipper];
				}
			while (good_best > 0) {
				for (tot = 0; tot < b; tot++)
					for (skipper = 0; skipper < n;
					     skipper++)
						if (good_board[tot][skipper] ==
						    good_best) {
							cnt[good_best]++;
							for (k = 1 - good_best;
							     k < good_best; k++)
								for (a =
								     1 -
								     good_best;
								     a <
								     good_best;
								     a++) {
									temp =
									    k <
									    a ?
									    -k :
									    -a;
									if ((((tot + k) >= 0) && ((skipper + a) >= 0)) && (good_board[tot + k][skipper + a] > temp))
										good_board
										    [tot
										     +
										     k]
										    [skipper
										     +
										     a]
										    =
										    temp;
								}
						}
				good_best--;
			}
		}
		size_cnt = 0;
		for (tot = b; tot > 0; tot--)
			if (cnt[tot])
				size_cnt++;
		printf("Case #%d: %d\n", casenum, size_cnt);
		for (tot = b; tot > 0; tot--)
			if (cnt[tot])
				printf("%d %d\n", tot, cnt[tot]);
	}
	return 0;
}
