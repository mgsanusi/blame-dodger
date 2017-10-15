#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
	int first_iteration;
	int tt;
	int lineb;
	scanf("%d", &tt);
	static int s2[105][256 + 5];
	static int atmp[256 + 5];
	for (lineb = 0; lineb < tt; lineb++) {
		int x;
		int smtp_from;
		int cnt;
		int state_table;
		scanf("%d %d %d %d", &x, &smtp_from, &cnt, &state_table);
		int ansb;
		int comb;
		int n;
		for (ansb = 0; ansb < 256; ansb++)
			s2[0][ansb] = 2000000000;
		s2[0][256] = 0;
		for (ansb = 1; ansb <= state_table; ansb++) {
			for (comb = 0; comb <= 256; comb++) {
				s2[ansb][comb] = 2000000000;
			}
			int no;
			int temp;
			scanf("%d", &no);
			for (comb = 0; comb <= 256; comb++) {
				if (s2[ansb - 1][comb] != 2000000000) {
					temp = s2[ansb - 1][comb] + x;
					if (temp < s2[ansb][comb])
						s2[ansb][comb] = temp;
					for (n = 0; n < 256; n++) {
						if ((comb == 256)
						    || (abs(n - comb) <= cnt)) {
							temp =
							    s2[ansb - 1][comb] +
							    abs(n - no);
							if (temp < s2[ansb][n])
								s2[ansb][n] =
								    temp;
						}
					}
					if ((comb == 256)
					    || (abs(no - comb) <= cnt)) {
						temp = s2[ansb - 1][comb];
						if (temp < s2[ansb][no])
							s2[ansb][no] = temp;
					}
				}
			}
			char flag = 1;
			while (flag) {
				flag = 0;
				atmp[256] = s2[ansb][256];
				for (n = 0; n < 256; n++) {
					atmp[n] = s2[ansb][n];
					for (comb = 0; comb <= 256; comb++) {
						if ((comb == 256)
						    || (abs(n - comb) <= cnt)) {
							temp =
							    s2[ansb][comb] +
							    smtp_from;
							if (temp < atmp[n]) {
								atmp[n] = temp;
								flag = 1;
							}
						}
					}
				}
				for (n = 0; n <= 256; n++)
					s2[ansb][n] = atmp[n];
			}
		}
		int res = 2000000000;
		for (comb = 0; comb <= 256; comb++) {
			if (s2[state_table][comb] < res)
				res = s2[state_table][comb];
		}
		printf("Case #%d: %d\n", lineb + 1, res);
	}
	return 0;
}
