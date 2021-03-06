#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int temp_i;
  char c;
  FILE *input_file_ptr;
  FILE *output_file_ptr;
  int verbose_level = 1;
  char *input_file_name_default = "input.txt";
  char *input_file_name = 0;
  char *output_file_name_default = "output.txt";
  char *output_file_name = 0;
  int num_cases;
  int case_id;
  int num_candies;
  long *candy_list;
  long xor_sum;
  long sum;
  long min;
  for (i = 1; i < argc; i++)
  {
    if ((strcmp(argv[i], "-i") == 0) && ((i + 1) < argc))
    {
      input_file_name = argv[++i];
    }
    else
      if ((strcmp(argv[i], "-o") == 0) && ((i + 1) < argc))
    {
      output_file_name = argv[++i];
    }
    else
      if (strcmp(argv[i], "-v") == 0)
    {
      verbose_level = atoi(argv[++i]);
    }
    else
    {
      printf("Error parsing arguments!\n");
      printf("Usage: bot_trust.bin -i <input_file_name> -o <output_file_name>");
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

  temp_i = fscanf(input_file_ptr, "%d", &num_cases);
  if (verbose_level >= 2)
  {
    printf("  Number of test cases: %d\n", num_cases);
  }

  for (case_id = 1; case_id <= num_cases; case_id++)
  {
    temp_i = fscanf(input_file_ptr, "%d", &num_candies);
    candy_list = malloc(num_candies * (sizeof(long)));
    for (i = 0; i < num_candies; i++)
    {
      temp_i = fscanf(input_file_ptr, "%ld", &candy_list[i]);
    }

    xor_sum = (sum = (min = candy_list[0]));
    for (i = 1; i < num_candies; i++)
    {
      xor_sum ^= candy_list[i];
      sum += candy_list[i];
      if (candy_list[i] < min)
      {
        min = candy_list[i];
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

    fprintf(output_file_ptr, "Case #%d: ", case_id);
    if (xor_sum == 0)
    {
      fprintf(output_file_ptr, "%ld\n", sum - min);
    }
    else
    {
      fprintf(output_file_ptr, "NO\n");
    }

    free(candy_list);
  }

  fclose(input_file_ptr);
  fclose(output_file_ptr);
  return 0;
}


