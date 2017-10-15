/*
problem b, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com
insight: Patrick implements addition by instead doing XOR
there is a solution when Patrick XOR's all the values in each pile and the two results are the same, which is equivalent to XOR'ing every value and the result being 0
when there is a solution, Sean gains the most by giving Patrick 1 candy with the smallest value
compiled with: gcc c.c -o c -Wall -O3
*/
#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int main(int argc, char **argv)
{
    int test_cases, num_candies, min_candy, candy_sum, candy_mask, i, j, k;
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
	fscanf(fp_in, "%d", &num_candies);
	candy_mask = 0;
	candy_sum = 0;
	min_candy = 0x3fffffff;	//max 32 bit signed integer value
	for (j = 0; j < num_candies; j++) {
	    fscanf(fp_in, "%d", &k);
	    if (k < min_candy)
		min_candy = k;
	    candy_mask ^= k;
	    candy_sum += k;
	}
	fprintf(fp_out, "Case #%d: ", i);
	if (candy_mask)
	    fprintf(fp_out, "NO\n");
	else
	    fprintf(fp_out, "%d\n", candy_sum - min_candy);
    }

    new_fclose(fp_in);
    new_fclose(fp_out);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
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
