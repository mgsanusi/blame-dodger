#include "stdio.h"
int main()
{
	int first_iteration;
	int tn;
	scanf("%d\n", &tn);
	char s[500 + 1][500 + 1];
	int tt;
	int m[500 + 1];
	int mx[500 + 1];
	int my[500 + 1];
	for (tt = 0; tt < tn; tt++) {
		int w;
		int h;
		int d;
		int n;
		scanf("%d%d%d", &w, &h, &d);
		int i;
		int j;
		for (i = 0; i < w; i++) {
			scanf("%s", s[i]);
		}
		int best = -1;
		for (n = 3; (n <= w) && (n <= h); n++) {
			for (j = 0; j < h; j++) {
				m[j] = 0;
				mx[j] = 0;
				my[j] = 0;
			}
			for (i = 0; i < (n - 1); i++)
				for (j = 0; j < h; j++) {
					m[j] += s[i][j] - '0';
					mx[j] += i * (s[i][j] - '0');
					my[j] += j * (s[i][j] - '0');
				}
			for (i = n - 1; (i < w) && (best < n); i++) {
				int cm = 0;
				int cmx = 0;
				int cmy = 0;
				for (j = 0; j < h; j++) {
					m[j] += s[i][j] - '0';
					mx[j] += i * (s[i][j] - '0');
					my[j] += j * (s[i][j] - '0');
					if (i >= n) {
						m[j] -= s[i - n][j] - '0';
						mx[j] -=
						    (i - n) * (s[i - n][j] -
							       '0');
						my[j] -=
						    j * (s[i - n][j] - '0');
					}
					cm += m[j];
					cmx += mx[j];
					cmy += my[j];
					if (j >= n) {
						cm -= m[j - n];
						cmx -= mx[j - n];
						cmy -= my[j - n];
					}
					if (j >= (n - 1)) {
						int curm = cm;
						int curmx = cmx;
						int curmy = cmy;
						int ii;
						int jj;
						for (ii = 0; ii < 2; ii++)
							for (jj = 0; jj < 2;
							     jj++) {
								curm -=
								    s[i -
								      ((n -
									1) *
								       ii)][j -
									    ((n
									      -
									      1)
									     *
									     jj)]
								    - '0';
								curmx -=
								    (i -
								     ((n -
								       1) *
								      ii)) *
								    (s
								     [i -
								      ((n -
									1) *
								       ii)][j -
									    ((n
									      -
									      1)
									     *
									     jj)]
								     - '0');
								curmy -=
								    (j -
								     ((n -
								       1) *
								      jj)) *
								    (s
								     [i -
								      ((n -
									1) *
								       ii)][j -
									    ((n
									      -
									      1)
									     *
									     jj)]
								     - '0');
							}
						if (((curmx * 2) ==
						     (curm *
						      ((2 * i) - (n - 1))))
						    && ((curmy * 2) ==
							(curm *
							 ((2 * j) -
							  (n - 1))))) {
							best = n;
							break;
						}
					}
				}
			}
		}
		printf("Case #%d: ", tt + 1);
		if (best >= 0)
			printf("%d\n", best);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
