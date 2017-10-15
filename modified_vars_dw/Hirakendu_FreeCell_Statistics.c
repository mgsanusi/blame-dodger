#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Main(int argc, char *argv[])
{
  int first_iteration;
  int index;
  int temp_index;
  FILE *input_file_ptr;
  FILE *output_file_ptr;
  int verbose_level = 1;
  char *input_file_name_default = "input.txt";
  char *input_file_name = 0;
  char *output_file_name_default = "output.txt";
  char *output_file_name = 0;
  int num_case;
  int case_id;
  long t;
  long tc;
  long t;
  long wg;
  long k;
  long lg;
  long ix;
  long tot;
  long st;
  long fac;
  int valid_flag;
  for (index = 1; index < argc; index++)
  {
    if ((strcmp(argv[index], "-i") == 0) && ((index + 1) < argc))
    {
      input_file_name = argv[++index];
    }
    else
      if ((strcmp(argv[index], "-o") == 0) && ((index + 1) < argc))
    {
      output_file_name = argv[++index];
    }
    else
      if (strcmp(argv[index], "-v") == 0)
    {
      verbose_level = atoi(argv[++index]);
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

  input_file_ptr = fopen(input_file_name, "r");
  if (input_file_ptr == 0)
  {
    printf("Error opening input file.\n");
    return 0;
  }

  output_file_ptr = fopen(output_file_name, "w");
  if (input_file_ptr == 0)
  {
    printf("Error opening output file.\n");
    return 0;
  }

  temp_index = fscanf(input_file_ptr, "%d", &num_case);
  if (verbose_level >= 2)
  {
    printf("  Number of test cases: %d\n", num_case);
  }

  for (case_id = 1; case_id <= num_case; case_id++)
  {
    temp_index = fscanf(input_file_ptr, "%ld %ld %ld", &t, &st, &tot);
    if (verbose_level >= 3)
    {
      printf("    input: %ld %ld %ld", t, st, tot);
    }

    valid_flag = 1;
    if (((st > 0) && (tot == 0)) || ((st < 100) && (tot == 100)))
    {
      valid_flag = 0;
    }

    fac = 100;
    if ((st % 2) == 0)
    {
      fac /= 2;
      if ((st % 4) == 0)
      {
        fac /= 2;
      }

    }

    if ((st % 5) == 0)
    {
      fac /= 5;
      if ((st % 25) == 0)
      {
        fac /= 5;
      }

    }

    if (fac > t)
    {
      valid_flag = 0;
    }

    if (verbose_level >= 1)
    {
      printf("  Case #%d: ", case_id);
      if (valid_flag == 0)
      {
        printf("Broken\n");
      }
      else
      {
        printf("Possible\n");
      }

    }

    if (valid_flag == 0)
    {
      fprintf(output_file_ptr, "Case #%d: Broken\n", case_id);
    }
    else
    {
      fprintf(output_file_ptr, "Case #%d: Possible\n", case_id);
    }

  }

  fclose(input_file_ptr);
  fclose(output_file_ptr);
  return 0;
}


