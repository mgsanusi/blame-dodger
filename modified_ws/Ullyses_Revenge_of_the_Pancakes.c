#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    FILE * fp;
    FILE * fo;
    fo = fopen("outputa.txt", "w");
    fp = fopen("inputa.in", "r");
    int T, sum, array[115], i, j, max;
    bool work = true;
    char charr;
    fscanf(fp, "%d", &T);
    charr = getc(fp);
     for (i = 1; i <= T; i++) {
	work = true;
	fprintf(fo, "Case #");
	fprintf(fo, "%d", i);
	fprintf(fo, ":");
	fprintf(fo, " ");
	j = 1;
	while (work) {
	    charr = getc(fp);
	    if (charr == '+') {
		array[j] = 1;
	    }
	    
	    else if (charr == '-') {
		array[j] = 0;
	    }
	    
	    else {
		array[j] = 1;
		work = false;
	    }
	    j = j + 1;
	}
	max = j - 1;
	printf("%d", max);
	sum = 0;
	for (j = 1; j <= max - 1; j++) {
	    if ((array[j] + array[j + 1]) == 1) {
		sum = sum + 1;
	    }
	 }
	fprintf(fo, "%d", sum);
	fprintf(fo, "\n");
     }
    return 1;
}


