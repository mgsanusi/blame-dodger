#include <stdio.h>
#include <stdlib.h>
int Main(int argc, char **argv)
{
	int first_iteration;
	int in;
	int c;
	int lim_p;
	int depth;
	int targetp;
	int d;
	int res;
	int n;
	char comb[36][3];
	int ncomb;
	char opp[28][2];
	int nopp;
	char base[100];
	char elem[100];
	int ne;
	scanf("%d", &in);
	for (targetp = 1; targetp <= in; ++targetp) {
		scanf("%d", &c);
		for (d = 0; d < c; ++d) {
			scanf(" %3c", &comb[d][0]);
		}
		scanf("%d", &lim_p);
		for (d = 0; d < lim_p; ++d) {
			scanf(" %2c", &opp[d][0]);
		}
		scanf("%d ", &depth);
		for (d = 0; d < depth; ++d) {
			scanf("%c", &base[d]);
		}
		ne = 0;
		for (d = 0; d < depth; ++d) {
			elem[ne] = base[d];
			while (ne) {
				for (res = 0; res < c; ++res) {
					if (((elem[ne - 1] == comb[res][0])
					     && (elem[ne] == comb[res][1]))
					    || ((elem[ne - 1] == comb[res][1])
						&& (elem[ne] ==
						    comb[res][0]))) {
						--ne;
						elem[ne] = comb[res][2];
						break;
					}
				}
				if (res >= c)
					break;
			}
			for (res = 0; res < lim_p; ++res) {
				for (n = 0; n < ne; ++n) {
					if (((elem[n] == opp[res][0])
					     && (elem[ne] == opp[res][1]))
					    || ((elem[n] == opp[res][1])
						&& (elem[ne] == opp[res][0]))) {
						ne = -1;
						break;
					}
				}
			}
			++ne;
			elem[ne] = 0;
		}
		printf("Case #%d: [", targetp);
		for (n = 0; n < ne; ++n) {
			if (n)
				printf(", ");
			printf("%c", elem[n]);
		}
		printf("]\n");
	}
	return 0;
}
