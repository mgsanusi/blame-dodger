#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int Main()
{
    FILE *t;
    FILE *b;
    b = fopen("outputa.txt", "w");
    t = fopen("inputa.in", "r");
    int c;
    int kl;
    int a1;
    int file;
    int t;
    int num;
    int array[300][300];
    int hei[2505];
    int ans[2505];
    fscanf(t, "%d", &c);
    for (kl = 1; kl <= c; kl++) {
	fscanf(t, "%d", &t);
	fprintf(b, "Case #");
	fprintf(b, "%d", kl);
	fprintf(b, ":");
	fprintf(b, " ");
	for (a1 = 1; a1 <= 2501; a1++) {
	    hei[a1] = 0;
	}
	for (a1 = 1; a1 <= ((2 * t) - 1); a1++) {
	    for (file = 1; file <= t; file++) {
		fscanf(t, "%d", &array[a1][file]);
		num = array[a1][file];
		if (hei[num] == 1) {
		    hei[num] = 0;
		} else
		    hei[num] = 1;
	    }
	}
	file = 1;
	for (a1 = 1; a1 <= 2501; a1++) {
	    if (hei[a1] == 1) {
		ans[file] = a1;
		file = file + 1;
	    }
	}
	for (a1 = 1; a1 < file; a1++) {
	    fprintf(b, "%d", ans[a1]);
	    fprintf(b, " ");
	}
	fprintf(b, "\n");
    }
    return 1;
}
