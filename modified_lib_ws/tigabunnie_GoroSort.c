/*
problem d, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com
insight:
find closed groups of where the indexes define the loop (pick up the value at index i, go to index[value], stop when we return to i)
on average, to sort a group of N numbers, we need N hits
take advantage of the fact that only the smallest N integers are used, so that number tells us the index of where it is supposed to go
compiled with: gcc d.c -o d -Wall -O3
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 1000
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
void new_exit(int status);
int main(int argc, char **argv)
{
    int test_cases, num_elements, elements[MAX_ELEMENTS],
	cycle[MAX_ELEMENTS], i, j, k, count, avg_count;
    FILE *fp_in, *fp_out;

    if (argc != 3) {
	printf
	    ("provide input and output file names as first 2 command line parameters\n");
	new_exit(1);
    }
    if ((fp_in = new_fopen(argv[1], "r")) == NULL) {
	printf("can't open file %s\n", argv[1]);
	new_exit(1);
    }
    if ((fp_out = new_fopen(argv[2], "w")) == NULL) {
	printf("can't open file %s\n", argv[2]);
	new_exit(1);
    }
    fscanf(fp_in, "%d", &test_cases);

    for (i = 1; i <= test_cases; i++) {
	avg_count = 0;
	fscanf(fp_in, "%d", &num_elements);
	for (j = 0; j < num_elements; j++) {
	    fscanf(fp_in, "%d", &k);
	    if (k - 1 != j)
		avg_count++;
	}
	/*
	   for (j=0; j<num_elements; j++) {
	   fscanf(fp_in, "%d", &k);
	   elements[j] = k-1;   //translate from 1 to N into 0 to N-1 to be compatible with c indexing
	   }
	   for (j=0; j<num_elements; j++) {
	   for (k=0; k<num_elements; k++) cycle[k] = 0;
	   count = 0;
	   k = j;
	   while (elements[k]!=j) {
	   cycle[k] = 1;
	   k = elements[k];
	   count++;
	   }
	   }
	 */
	fprintf(fp_out, "Case #%d: %lf\n", i, (double) avg_count);
    }

    new_fclose(fp_in);
    new_fclose(fp_out);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
    return exit(status);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
