#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(int size);

int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);

int new_abs(int x);

int Main(int argc, char *argv[])
{
  int first_iteration;
  int i;
  int j;
  int a;
  int z;
  int temp_i;
  char r;
  FILE *input_file_ptr;
  FILE *output_file_pointer;
  int verbose_level = 1;
  char *input_file_name_default = "input.txt";
  char *input_file_list = 0;
  char *output_file_name_default = "output.txt";
  char *output_file_name = 0;
  int num_case;
  int case_id;
  int num_candy;
  long *candy_lst;
  long xor_sum;
  long sum;
  long min;
  for (i = 1; i < argc; i++)
  {
    if ((new_strcmp(argv[i], "-i") == 0) && ((i + 1) < argc))
    {
      input_file_list = argv[++i];
    }
    else
      if ((new_strcmp(argv[i], "-o") == 0) && ((i + 1) < argc))
    {
      output_file_name = argv[++i];
    }
    else
      if (new_strcmp(argv[i], "-v") == 0)
    {
      verbose_level = new_atoi(argv[++i]);
    }
    else
    {
      printf("Error parsing arguments!\n");
      printf("Usage: bot_trust.bin -i <input_file_name> -o <output_file_name>");
      printf("  -v <verbose_level>\n");
      return 0;
    }



  }

  if (input_file_list == 0)
  {
    input_file_list = input_file_name_default;
  }

  if (output_file_name == 0)
  {
    output_file_name = output_file_name_default;
  }

  input_file_ptr = new_fopen(input_file_list, "r");
  if (input_file_ptr == 0)
  {
    printf("Error opening input file.\n");
    return 0;
  }

  output_file_pointer = new_fopen(output_file_name, "w");
  if (input_file_ptr == 0)
  {
    printf("Error opening output file.\n");
    return 0;
  }

  temp_i = fscanf(input_file_ptr, "%d", &num_case);
  if (verbose_level >= 2)
  {
    printf("  Number of test cases: %d\n", num_case);
  }

  for (case_id = 1; case_id <= num_case; case_id++)
  {
    temp_i = fscanf(input_file_ptr, "%d", &num_candy);
    candy_lst = new_malloc(num_candy * (sizeof(long)));
    for (i = 0; i < num_candy; i++)
    {
      temp_i = fscanf(input_file_ptr, "%ld", &candy_lst[i]);
    }

    xor_sum = (sum = (min = candy_lst[0]));
    for (i = 1; i < num_candy; i++)
    {
      xor_sum ^= candy_lst[i];
      sum += candy_lst[i];
      if (candy_lst[i] < min)
      {
        min = candy_lst[i];
      }

    }

    if (verbose_level >= 1)
    {
      printf("  Case #%d: ", case_id);
      if (xor_sum == 0)
      {
        printf("%ld\n", sum - min);
      }
      else
      {
        printf("NO\n");
      }

    }

    fprintf(output_file_pointer, "Case #%d: ", case_id);
    if (xor_sum == 0)
    {
      fprintf(output_file_pointer, "%ld\n", sum - min);
    }
    else
    {
      fprintf(output_file_pointer, "NO\n");
    }

    free(candy_lst);
  }

  new_fclose(input_file_ptr);
  new_fclose(output_file_pointer);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(int size);

int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);

int new_abs(int x) {
  return abs(x);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(int size);

int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str) {
  return atoi(str);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(int size);

int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void* new_malloc(int size) {
  return malloc(size);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}