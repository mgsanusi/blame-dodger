#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_atoi(const char *str);
int main(int argc, char *argv[])
{
  int first_iteration;
  int i;
  int temp_i;
  FILE *input_file_ptr;
  FILE *output_file_ptr;
  int verbose_level = 1;
  char *input_file_name_default = "input.txt";
  char *input_file_name = 0;
  char *output_file_name_default = "output.txt";
  char *output_file_name = 0;
  int num_cases;
  int case_id;
  long n;
  long l;
  long h;
  long f[100000];
  long j;
  int possible_flag;
  for (i = 1; i < argc; i++)
  {
    if ((new_strcmp(argv[i], "-i") == 0) && ((i + 1) < argc))
    {
      input_file_name = argv[++i];
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
      printf("Usage: template.bin -i <input_file_name> -o <output_file_name>");
      printf("  -v <verbose_level>\n");
      return 0;
    }



  }

  if (input_file_name == 0)
  {
    input_file_name = input_file_name_default;
  }

  if (output_file_name == 0)
  {
    output_file_name = output_file_name_default;
  }

  input_file_ptr = new_fopen(input_file_name, "r");
  if (input_file_ptr == 0)
  {
    printf("Error opening input file.\n");
    return 0;
  }

  output_file_ptr = new_fopen(output_file_name, "w");
  if (input_file_ptr == 0)
  {
    printf("Error opening output file.\n");
    return 0;
  }

  temp_i = fscanf(input_file_ptr, "%d", &num_cases);
  if (verbose_level >= 2)
  {
    printf("  Number of test cases: %d\n", num_cases);
  }

  for (case_id = 1; case_id <= num_cases; case_id++)
  {
    if (verbose_level >= 1)
    {
      printf("  Case #%d: ", case_id);
    }

    temp_i = fscanf(input_file_ptr, "%ld %ld %ld", &n, &l, &h);
    for (i = 0; i < n; i++)
    {
      temp_i = fscanf(input_file_ptr, "%ld", &f[i]);
    }

    if (verbose_level >= 3)
    {
      printf("f = ");
      for (i = 0; i < n; i++)
      {
        printf(" %ld", f[i]);
      }

      printf("\n");
    }

    possible_flag = 1;
    for (j = l; j <= h; j++)
    {
      for (i = 0; i < n; i++)
      {
        if (((j % f[i]) != 0) && ((f[i] % j) != 0))
        {
          break;
        }

      }

      if (i == n)
      {
        break;
      }

    }

    if (j == (h + 1))
    {
      printf(" impossible\n");
    }
    else
    {
      printf(" %ld\n", j);
    }

    if (verbose_level >= 3)
    {
      printf("    \n");
    }

    if (verbose_level >= 1)
    {
      printf("\n");
    }

    fprintf(output_file_ptr, "Case #%d: ", case_id);
    if (j == (h + 1))
    {
      fprintf(output_file_ptr, "NO\n");
    }
    else
    {
      fprintf(output_file_ptr, "%ld\n", j);
    }

  }

  new_fclose(input_file_ptr);
  new_fclose(output_file_ptr);
  return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_atoi(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_strcmp(const char *str1, const char *str2);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int new_atoi(const char *str)
{
  int first_iteration;
  return atoi(str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_strcmp(const char *str1, const char *str2)
{
  int first_iteration;
  return strcmp(str1, str2);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


