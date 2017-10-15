#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *file_name_in = "input.txt";
char *file_name_out = "output.txt";
FILE *in;
FILE *out;
char string[5000];
char array[5000];
int Main(void)
{
    int t;
    int k;
    int start;
    int end;
    int length;
    int cases;
    in = fopen(file_name_in, "r");
    out = fopen(file_name_out, "w");
    fscanf(in, "%d", &k);
    for (t = 1; t <= k; t++) {
	fscanf(in, "%s", string);
	length = strlen(string);
	fprintf(out, "Case #%d: ", t);
	start = (end = 2500);
	array[start] = string[0];
	for (cases = 1; cases < length; ++cases) {
	    if (string[cases] >= array[start]) {
		start--;
		array[start] = string[cases];
	    } else {
		end++;
		array[end] = string[cases];
	    }
	}
	array[end + 1] = 0;
	fprintf(out, "%s\n", array + start);
    }
    fclose(in);
    fclose(out);
}
