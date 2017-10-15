/*
 * Hirakendu Das, 20 May 2011, for Google Code Jam contest.
 * Problem 1: XXX.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define VERBOSE_LEVEL_DEFAULT 1
#define max(x,y) ((x) > (y) ? (x) : (y))
#define abs(x) ((x) > 0? (x) : (-(x)))
int main(int argc, char *argv[])
{
	int i, temp_i;
	FILE *input_file_ptr, *output_file_ptr;
	int verbose_level = VERBOSE_LEVEL_DEFAULT;
	char *input_file_name_default = "input.txt";
	char *input_file_name = NULL;
	char *output_file_name_default = "output.txt";
	char *output_file_name = NULL;
	int num_cases, case_id;

	long n, g, d, wg, wd, lg, ld, pg, pd, fac;
	int valid_flag;

	/* Parse commandline arguments. */
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
			input_file_name = argv[++i];
		} else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
			output_file_name = argv[++i];
		} else if (strcmp(argv[i], "-v") == 0) {
			verbose_level = atoi(argv[++i]);
		} else {
			printf("Error parsing arguments!\n");
			printf
			    ("Usage: template.bin -i <input_file_name> -o <output_file_name>");
			printf("  -v <verbose_level>\n");
			return 0;
		}
	}
	if (input_file_name == NULL) {
		input_file_name = input_file_name_default;
	}
	if (output_file_name == NULL) {
		output_file_name = output_file_name_default;
	}

	/* Parse input file and run the algorithm. */
	input_file_ptr = fopen(input_file_name, "r");
	if (input_file_ptr == NULL) {
		printf("Error opening input file.\n");
		return 0;
	}
	output_file_ptr = fopen(output_file_name, "w");
	if (input_file_ptr == NULL) {
		printf("Error opening output file.\n");
		return 0;
	}
	temp_i = fscanf(input_file_ptr, "%d", &num_cases);
	if (verbose_level >= 2) {
		printf("  Number of test cases: %d\n", num_cases);
	}
	for (case_id = 1; case_id <= num_cases; case_id++) {
		/* A particular test case. */
		/* Get the input. */
		temp_i = fscanf(input_file_ptr, "%ld %ld %ld", &n, &pd, &pg);
		if (verbose_level >= 3) {
			printf("    input: %ld %ld %ld", n, pd, pg);
		}
		/* 2. The algorithm and printing output. */
		valid_flag = 1;
		/* 2.1 corner cases. */
		if (((pd > 0) && (pg == 0)) || ((pd < 100) && (pg == 100))) {
			valid_flag = 0;
		}
		/* 2.2 factor that should divide d (pd * d is a multiple of 100). */
		fac = 100;
		if ((pd % 2) == 0) {
			fac /= 2;
			if ((pd % 4) == 0) {
				fac /= 2;
			}
		}
		if ((pd % 5) == 0) {
			fac /= 5;
			if ((pd % 25) == 0) {
				fac /= 5;
			}
		}
		if (fac > n) {
			valid_flag = 0;
		}
		if (verbose_level >= 1) {
			printf("  Case #%d: ", case_id);
			if (valid_flag == 0) {
				printf("Broken\n");
			} else {
				printf("Possible\n");
			}
		}
		if (valid_flag == 0) {
			fprintf(output_file_ptr, "Case #%d: Broken\n", case_id);
		} else {
			fprintf(output_file_ptr, "Case #%d: Possible\n",
				case_id);
		}
	}			/* End of case_id loop. */
	fclose(input_file_ptr);
	fclose(output_file_ptr);

	return 0;
}
