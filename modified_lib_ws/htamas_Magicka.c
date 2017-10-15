#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int T, C, D, N, tc, i, j, k;
    char comb[36][3];
    int ncomb;
    char opp[28][2];
    int nopp;
    char base[100];
    char elem[100];
    int ne;
    scanf("%d", &T);
    for (tc = 1; tc <= T; ++tc) {
	scanf("%d", &C);
	for (i = 0; i < C; ++i) {
	    scanf(" %3c", &comb[i][0]);
	}
	scanf("%d", &D);
	for (i = 0; i < D; ++i) {
	    scanf(" %2c", &opp[i][0]);
	}
	scanf("%d ", &N);
	for (i = 0; i < N; ++i) {
	    scanf("%c", &base[i]);
	}
	ne = 0;
	/*for(i=0;i<C;++i) { printf("%c%c%c ", comb[i][0], comb[i][1], comb[i][2]); } printf("/ "); fflush(stdout);
	   for(i=0;i<D;++i) { printf("%c%c ", opp[i][0], opp[i][1]); } printf("/ "); fflush(stdout);
	   for(i=0;i<N;++i) { printf("%c", base[i]); } printf("\n"); fflush(stdout); */
	for (i = 0; i < N; ++i) {
	    elem[ne] = base[i];
	    while (ne) {
		for (j = 0; j < C; ++j) {
		    if (((elem[ne - 1] == comb[j][0])
			 && (elem[ne] == comb[j][1]))
			|| ((elem[ne - 1] == comb[j][1])
			    && (elem[ne] == comb[j][0]))) {
			--ne;
			elem[ne] = comb[j][2];
			break;
		    }
		}
		if (j >= C)
		    break;
	    }
	    for (j = 0; j < D; ++j) {
		for (k = 0; k < ne; ++k) {
		    if (((elem[k] == opp[j][0]) && (elem[ne] == opp[j][1]))
			|| ((elem[k] == opp[j][1])
			    && (elem[ne] == opp[j][0]))) {
			ne = -1;
			break;
		    }
		}
	    }
	    ++ne;
	    elem[ne] = 0;
	}
	printf("Case #%d: [", tc);
	for (k = 0; k < ne; ++k) {
	    if (k)
		printf(", ");
	    printf("%c", elem[k]);
	}
	printf("]\n");
    }
    return 0;
}
