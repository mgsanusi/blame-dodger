/*
 * Hirakendu Das, 07 May 2011, for Google Code Jam contest.
 * Problem 1: Bot Trust.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define VERBOSE_LEVEL_DEFAULT 1
#define max(x,y) ((x) > (y) ? (x) : (y))
#define new_abs(x) ((x) > 0? (x) : (-(x)))
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE * stream, const char *format, ...);
int new_atoi(const char *str);
void new_free(void *ptr);
int main(int argc, char *argv[])
{
    int i, temp_i;
    FILE *input_file_ptr, *output_file_ptr;
    int verbose_level = VERBOSE_LEVEL_DEFAULT;
    char *input_file_name_default = "input.txt";
    char *input_file_name = NULL;
    char *output_file_name_default = "output.txt";
    char *output_file_name = NULL;
    int case_id, num_cases, num_buttons, button_id;
    char button_color, *button_color_list;
    int button_pos, *button_pos_list;
    int blue_pos, orange_pos;
    int blue_time, orange_time, total_time;

    /* Parse commandline arguments. */
    for (i = 1; i < argc; i++) {
	if (new_strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
	    input_file_name = argv[++i];
	} else if (new_strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
	    output_file_name = argv[++i];
	} else if (new_strcmp(argv[i], "-v") == 0) {
	    verbose_level = new_atoi(argv[++i]);
	} else {
	    printf("Error parsing arguments!\n");
	    printf
		("Usage: bot_trust.bin -i <input_file_name> -o <output_file_name>");
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
    input_file_ptr = new_fopen(input_file_name, "r");
    if (input_file_ptr == NULL) {
	printf("Error opening input file.\n");
	return 0;
    }
    output_file_ptr = new_fopen(output_file_name, "w");
    if (input_file_ptr == NULL) {
	printf("Error opening output file.\n");
	return 0;
    }
    temp_i = fscanf(input_file_ptr, "%d", &num_cases);
    if (verbose_level >= 2) {
	printf("  Number of cases: %d\n", num_cases);
    }
    for (case_id = 1; case_id <= num_cases; case_id++) {
	/* A particular test case. */
	temp_i = fscanf(input_file_ptr, "%d", &num_buttons);
	button_color_list = new_malloc(num_buttons * sizeof(char));
	button_pos_list = new_malloc(num_buttons * sizeof(int));
	if (verbose_level >= 2) {
	    printf("  Case #%d: %d buttons\n", case_id, num_buttons);
	}
	/* 1. Get the button list. */
	for (button_id = 1; button_id <= num_buttons; button_id++) {
	    temp_i = fscanf(input_file_ptr, " %c %d",
			    &button_color_list[button_id - 1],
			    &button_pos_list[button_id - 1]);
	}
	if (verbose_level >= 3) {
	    printf("    Input button order:\n     ");
	    for (button_id = 1; button_id <= num_buttons; button_id++) {
		printf(" %c %d", button_color_list[button_id - 1],
		       button_pos_list[button_id - 1]);
	    }
	    printf("\n");
	}
	/* 2. An algorithm. */
	/*
	 * Each bot presses its button as soon as possible and moves to
	 * to its next button position and waits for the other bot to press its
	 * button if necessary. 
	 */
	blue_pos = 1;
	orange_pos = 1;
	blue_time = 0;
	orange_time = 0;
	for (button_id = 1; button_id <= num_buttons; button_id++) {
	    if (button_color_list[button_id - 1] == 'O') {
		orange_time +=
		    new_abs(button_pos_list[button_id - 1] - orange_pos);
		/* Time taken for orange to move from its last position. */
		orange_pos = button_pos_list[button_id - 1];
		if (blue_time >= orange_time) {
		    orange_time = blue_time;
		    /*
		     * If blue's time till pressing last button is more than
		     * orange's time when it reaches its button, it waits.
		     */
		}
		orange_time++;	/* 1 sec to press button. */
	    } else {
		blue_time +=
		    new_abs(button_pos_list[button_id - 1] - blue_pos);
		blue_pos = button_pos_list[button_id - 1];
		if (orange_time >= blue_time) {
		    blue_time = orange_time;
		}
		blue_time++;
	    }
	}
	total_time = max(orange_time, blue_time);
	if (verbose_level >= 2) {
	    printf("    Time: %d\n", total_time);
	}
	fprintf(output_file_ptr, "Case #%d: %d\n", case_id, total_time);
	new_free(button_color_list);
	new_free(button_pos_list);
    }				/* End of case_id loop. */
    new_fclose(input_file_ptr);
    new_fclose(output_file_ptr);

    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE * stream, const char *format, ...);
int new_atoi(const char *str);
void new_free(void *ptr);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE * stream, const char *format, ...);
int new_atoi(const char *str);
void new_free(void *ptr)
{
    return free(ptr);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE * stream, const char *format, ...);
int new_atoi(const char *str)
{
    return atoi(str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size);
int new_strcmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void *new_malloc(size_t size)
{
    return malloc(size);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
