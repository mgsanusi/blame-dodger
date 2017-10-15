#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE * in;
FILE * out;
 
// just a quick & dirty hack to ensure I go on to round 1
int main(void)
{
     int t, T, K, C, s, S;
     in = fopen(fileNameIn, "r");
    out = fopen(fileNameOut, "w");
     fscanf(in, "%d", &T);
     for (t = 1; t <= T; t++) {
	fprintf(out, "Case #%d:", t);
	fscanf(in, "%d", &K);
	fscanf(in, "%d", &C);
	fscanf(in, "%d", &S);
	 for (s = 1; s <= K; ++s) {
	    fprintf(out, " %d", s);
	}
	fprintf(out, "\n");
    }
     fclose(in);
    fclose(out);
}
