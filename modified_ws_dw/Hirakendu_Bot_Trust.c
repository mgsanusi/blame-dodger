#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  int case_id;
  int num_cases;
  int num_buttons;
  int button_id;
  char button_color;
  char *button_color_list;
  int button_pos;
  int *button_pos_list;
  int blue_pos;
  int orange_pos;
  int blue_time;
  int orange_time;
  int total_time;
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
    printf("  Number of cases: %d\n", num_cases);
  }

  for (case_id = 1; case_id <= num_cases; case_id++)
  {
    temp_i = fscanf(input_file_ptr, "%d", &num_buttons);
    button_color_list = malloc(num_buttons * (sizeof(char)));
    button_pos_list = malloc(num_buttons * (sizeof(int)));
    if (verbose_level >= 2)
    {
      printf("  Case #%d: %d buttons\n", case_id, num_buttons);
    }

    for (button_id = 1; button_id <= num_buttons; button_id++)
    {
      temp_i = fscanf(input_file_ptr, " %c %d", &button_color_list[button_id - 1], &button_pos_list[button_id - 1]);
    }

    if (verbose_level >= 3)
    {
      printf("    Input button order:\n     ");
      for (button_id = 1; button_id <= num_buttons; button_id++)
      {
        printf(" %c %d", button_color_list[button_id - 1], button_pos_list[button_id - 1]);
      }

      printf("\n");
    }

    blue_pos = 1;
    orange_pos = 1;
    blue_time = 0;
    orange_time = 0;
    for (button_id = 1; button_id <= num_buttons; button_id++)
    {
      if (button_color_list[button_id - 1] == 'O')
      {
        orange_time += (button_pos_list[button_id - 1] - orange_pos) > 0 ? button_pos_list[button_id - 1] - orange_pos : -(button_pos_list[button_id - 1] - orange_pos);
        orange_pos = button_pos_list[button_id - 1];
        if (blue_time >= orange_time)
        {
          orange_time = blue_time;
        }

        orange_time++;
      }
      else
      {
        blue_time += (button_pos_list[button_id - 1] - blue_pos) > 0 ? button_pos_list[button_id - 1] - blue_pos : -(button_pos_list[button_id - 1] - blue_pos);
        blue_pos = button_pos_list[button_id - 1];
        if (orange_time >= blue_time)
        {
          blue_time = orange_time;
        }

        blue_time++;
      }

    }

    total_time = orange_time > blue_time ? orange_time : blue_time;
    if (verbose_level >= 2)
    {
      printf("    Time: %d\n", total_time);
    }

    fprintf(output_file_ptr, "Case #%d: %d\n", case_id, total_time);
    free(button_color_list);
    free(button_pos_list);
  }

  fclose(input_file_ptr);
  fclose(output_file_ptr);
  return 0;
}


