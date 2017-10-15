/*
 * Hirakendu Das, 07 May 2011, for Google Code Jam contest.
 * Problem 3: Candy splitting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

#define VERBOSE_LEVEL_DEFAULT 1

#define max(x,y) ((x) > (y) ? (x) : (y))
#define new_abs(x) ((x) > 0? (x) : (-(x)))
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);



int main(int argc, char *argv[])
{
  int i, j, k, l, temp_i;
  char c;
  FILE *input_file_ptr, *output_file_ptr;
  int verbose_level = VERBOSE_LEVEL_DEFAULT;
  char *input_file_name_default = "input.txt";
  char *input_file_name = NULL;
  char *output_file_name_default = "output.txt";
  char *output_file_name = NULL;
  int num_cases, case_id, num_candies;
  long *candy_list, xor_sum, sum, min;
  
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
      printf("Usage: bot_trust.bin -i <input_file_name> -o <output_file_name>");
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
    printf("  Number of test cases: %d\n", num_cases);
  }
  for (case_id = 1; case_id <= num_cases; case_id++) {
    /* A particular test case. */
    /* Get the input. */
    temp_i = fscanf(input_file_ptr, "%d", &num_candies);
    candy_list = new_malloc(num_candies * sizeof(long));
    for (i = 0; i < num_candies; i++) {
      temp_i = fscanf(input_file_ptr, "%ld", &candy_list[i]);
    }
    /* 2. An algorithm. */
    /*
     * Suppose the candie values are expressed in binary
     * and arranged in an array , with each row containing a candie value
     * and least significant bits aligned.
     * Then it is easy to observe that in each column, if the number of 1's
     * is even, then no matter which way the column is split into 2 parts,
     * Patrick sees the value total value of the two parts as equal (for
     * that column). Conversely, if the number of 1's is odd, no matter
     * which way we split, Patrick sees them as unequal.
     * Hence, if the xor sum of the numbers is 0, (i.e., all columns have
     * equal number of 1's), we can split it equally, and otherwise not.
     * 
     * Also, if all columns have equal number of 1's, no matter which way
     * we split, Patrick sees it as equal. Hence, in this case, Sean
     * can give patrick the candy with smallest value and keep the rest to him.
     */
    xor_sum = sum = min = candy_list[0];
    for (i = 1; i < num_candies; i++) {
      xor_sum ^= candy_list[i];
      sum += candy_list[i];
      if (candy_list[i] < min) {
	min = candy_list[i];
      }
    }
    if (verbose_level >= 1) {
      printf("  Case #%d: ", case_id);
      if (xor_sum == 0) {
	printf("%ld\n", sum - min);
      } else {
	printf("NO\n");
      }
    }
    fprintf(output_file_ptr, "Case #%d: ", case_id);
    if (xor_sum == 0) {
      fprintf(output_file_ptr, "%ld\n", sum - min);
    } else {
      fprintf(output_file_ptr, "NO\n");
    }
    free(candy_list);
  }  /* End of case_id loop. */
  new_fclose(input_file_ptr);
  new_fclose(output_file_ptr);
  
  return 0;
}


FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);

FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str) {
  return atoi(str);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size);

int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(size_t size) {
  return malloc(size);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}
