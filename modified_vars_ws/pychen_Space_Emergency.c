#include <stdio.h>
int l;
int l;
int p;
int d;
char a[505][505];
int Main()
{
	int t_cnt;
	scanf("%d", &t_cnt);
	for (l = 1; l <= t_cnt; l++) {
		scanf("%d %d %d", &l, &p, &d);
		int jj;
		int mn;
		for (jj = 0; jj < l; jj++)
			scanf("%s", a[jj]);
		int result = 0;
		for (jj = 0; jj < l; jj++)
			for (mn = 0; mn < p; mn++) {
				int rangex =
				    (l - jj) < (p - mn) ? l - jj : p - mn;
				int range;
				for (range = 1; range <= rangex; range++) {
					int r_sum = 0;
					int c_sum = 0;
					int tot;
					int kj;
					for (tot = jj; tot < (jj + range);
					     tot++)
						for (kj = mn; kj < (mn + range);
						     kj++) {
							if (((tot == jj)
							     || (tot ==
								 ((jj + range) -
								  1)))
							    && ((kj == mn)
								|| (kj ==
								    ((mn +
								      range) -
								     1)))) ;
							else {
								r_sum +=
								    (((2 *
								       tot) -
								      jj) -
								     ((jj +
								       range) -
								      1)) *
								    ((d +
								      a[tot]
								      [kj]) -
								     '0');
								c_sum +=
								    (((2 * kj) -
								      mn) -
								     ((mn +
								       range) -
								      1)) *
								    ((d +
								      a[tot]
								      [kj]) -
								     '0');
							}
						}
					if ((r_sum == 0) && (c_sum == 0))
						result =
						    result >
						    range ? result : range;
				}
			}
		printf("Case #%d: ", l);
		if (result >= 3)
			printf("%d\n", result);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
