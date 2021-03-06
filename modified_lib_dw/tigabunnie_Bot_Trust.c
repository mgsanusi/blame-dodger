#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
void new_exit(int status);
int main(int argc, char **argv)
{
  int first_iteration;
  char input_char;
  char update_num_buttons_pressed;
  int test_cases;
  int num_buttons;
  int i;
  int j;
  int k;
  int which_robot[100];
  int which_button[100];
  int next_button_blue;
  int next_button_orange;
  int pos_blue;
  int pos_orange;
  int num_buttons_pressed;
  int steps;
  FILE *fp_in;
  FILE *fp_out;
  if (argc != 3)
  {
    printf("provide input and output file names as first 2 command line parameters\n");
    new_exit(1);
  }

  if ((fp_in = new_fopen(argv[1], "r")) == 0)
  {
    printf("can't open file %s\n", argv[1]);
    new_exit(1);
  }

  if ((fp_out = new_fopen(argv[2], "w")) == 0)
  {
    printf("can't open file %s\n", argv[2]);
    new_exit(1);
  }

  fscanf(fp_in, "%d\n", &test_cases);
  for (i = 1; i <= test_cases; i++)
  {
    fscanf(fp_in, "%d", &num_buttons);
    for (j = 0; j < num_buttons; j++)
    {
      fscanf(fp_in, " %c %d", &input_char, &k);
      which_robot[j] = input_char == 'B' ? 1 : 0;
      which_button[j] = k;
    }

    pos_blue = 1;
    pos_orange = 1;
    num_buttons_pressed = 0;
    steps = 0;
    for (j = 0; j < num_buttons; j++)
      if (which_robot[j] == 1)
      break;


    next_button_blue = j < num_buttons ? which_button[j] : 1;
    for (j = 0; j < num_buttons; j++)
      if (which_robot[j] == 0)
      break;


    next_button_orange = j < num_buttons ? which_button[j] : 1;
    while (num_buttons_pressed < num_buttons)
    {
      update_num_buttons_pressed = 0;
      if (pos_blue < next_button_blue)
        pos_blue++;
      else
        if (pos_blue > next_button_blue)
        pos_blue--;
      else
        if (which_robot[num_buttons_pressed] == 1)
      {
        update_num_buttons_pressed = 1;
        for (j = num_buttons_pressed + 1; j < num_buttons; j++)
          if (which_robot[j] == 1)
          break;


        next_button_blue = j < num_buttons ? which_button[j] : 1;
      }



      if (pos_orange < next_button_orange)
        pos_orange++;
      else
        if (pos_orange > next_button_orange)
        pos_orange--;
      else
        if (which_robot[num_buttons_pressed] == 0)
      {
        update_num_buttons_pressed = 1;
        for (j = num_buttons_pressed + 1; j < num_buttons; j++)
          if (which_robot[j] == 0)
          break;


        next_button_orange = j < num_buttons ? which_button[j] : 1;
      }



      if (update_num_buttons_pressed)
        num_buttons_pressed++;

      steps++;
    }

    fprintf(fp_out, "Case #%d: %d\n", i, steps);
  }

  new_fclose(fp_in);
  new_fclose(fp_out);
  return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
void new_exit(int status)
{
  int first_iteration;
  return exit(status);
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


