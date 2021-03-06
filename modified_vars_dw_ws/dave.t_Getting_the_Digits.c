#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
int count[256];
int digit[10];
char j[3000];
int Main(void)
{
    int first_iteration;
    int mx;
    int z;
    int length;
    int b;
    int orgb;
    in = fopen(fileNameIn, "r");
    out = fopen(fileNameOut, "w");
    fscanf(in, "%d", &orgb);
    for (b = 1; b <= orgb; b++) {
	for (mx = 0; mx < 26; ++mx) {
	    count['A' + mx] = 0;
	}
	for (mx = 0; mx < 10; ++mx) {
	    digit[mx] = 0;
	}
	fprintf(out, "Case #%d: ", b);
	fscanf(in, "%s", j);
	length = strlen(j);
	for (mx = 0; mx < length; ++mx) {
	    count[j[mx]]++;
	}
	digit[0] = count['Z'];
	digit[2] = count['W'];
	digit[6] = count['X'];
	digit[7] = count['S'] - digit[6];
	digit[5] = count['V'] - digit[7];
	digit[8] = count['G'];
	digit[3] = count['H'] - digit[8];
	digit[4] = count['F'] - digit[5];
	digit[9] = ((count['I'] - digit[5]) - digit[6]) - digit[8];
	digit[1] = ((count['O'] - digit[0]) - digit[2]) - digit[4];
	for (mx = 0; mx < 10; ++mx) {
	    for (z = 0; z < digit[mx]; ++z) {
		fprintf(out, "%d", mx);
	    }
	}
	fprintf(out, "\n");
    }
    fclose(in);
    fclose(out);
}
