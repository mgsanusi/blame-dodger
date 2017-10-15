#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
  int main()
{
    FILE * fp;
    FILE * fo;
    fo = fopen("outputa.txt", "w");
    fp = fopen("inputa.in", "r");
    int T, kl, i, j, n, lo, array[300][300], hei[2505], result[2505];
    fscanf(fp, "%d", &T);
    
//scanf("%d",&T);
	for (kl = 1; kl <= T; kl++) {
	fscanf(fp, "%d", &n);
	fprintf(fo, "Case #");
	fprintf(fo, "%d", kl);
	fprintf(fo, ":");
	fprintf(fo, " ");
	
	    //scanf("%d",&n);
	    for (i = 1; i <= 2501; i++) {
	    hei[i] = 0;
	}
	for (i = 1; i <= 2 * n - 1; i++) {
	    for (j = 1; j <= n; j++) {
		fscanf(fp, "%d", &array[i][j]);
		
		    // scanf("%d",&array[i][j]);
		    lo = array[i][j];
		if (hei[lo] == 1) {
		    hei[lo] = 0;
		}
		
		else
		    hei[lo] = 1;
	    }
	}
	j = 1;
	 for (i = 1; i <= 2501; i++) {
	    if (hei[i] == 1) {
		result[j] = i;
		j = j + 1;
	    }
	}
	for (i = 1; i < j; i++) {
	    fprintf(fo, "%d", result[i]);
	    fprintf(fo, " ");
	    
//printf("%d",result[i]);
	}
	fprintf(fo, "\n");
    }
    return 1;
}


