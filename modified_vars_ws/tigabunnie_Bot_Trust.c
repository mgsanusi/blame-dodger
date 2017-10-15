#include <stdio.h>
#include <stdlib.h>
int
Main (int argc, char **argv)
{
  char input_char;
  char update_num_button_press;
  int test_case;
  int num_button;
  int i;
  int xpos;
  int s;
  int which_robot[100];
  int which_button[100];
  int next_button_blue;
  int next_button_orange;
  int pos_blue;
  int pos_orange;
  int no_button_press;
  int step;
  FILE *fp_in;
  FILE *fp_out;
  if (argc != 3)
    {
      printf
	("provide input and output file names as first 2 command line parameters\n");
      exit (1);
    }
  if ((fp_in = fopen (argv[1], "r")) == 0)
    {
      printf ("can't open file %s\n", argv[1]);
      exit (1);
    }
  if ((fp_out = fopen (argv[2], "w")) == 0)
    {
      printf ("can't open file %s\n", argv[2]);
      exit (1);
    }
  fscanf (fp_in, "%d\n", &test_case);
  for (i = 1; i <= test_case; i++)
    {
      fscanf (fp_in, "%d", &num_button);
      for (xpos = 0; xpos < num_button; xpos++)
	{
	  fscanf (fp_in, " %c %d", &input_char, &s);
	  which_robot[xpos] = input_char == 'B' ? 1 : 0;
	  which_button[xpos] = s;
	}
      pos_blue = 1;
      pos_orange = 1;
      no_button_press = 0;
      step = 0;
      for (xpos = 0; xpos < num_button; xpos++)
	if (which_robot[xpos] == 1)
	  break;
      next_button_blue = xpos < num_button ? which_button[xpos] : 1;
      for (xpos = 0; xpos < num_button; xpos++)
	if (which_robot[xpos] == 0)
	  break;
      next_button_orange = xpos < num_button ? which_button[xpos] : 1;
      while (no_button_press < num_button)
	{
	  update_num_button_press = 0;
	  if (pos_blue < next_button_blue)
	    pos_blue++;
	  else if (pos_blue > next_button_blue)
	    pos_blue--;
	  else if (which_robot[no_button_press] == 1)
	    {
	      update_num_button_press = 1;
	      for (xpos = no_button_press + 1; xpos < num_button; xpos++)
		if (which_robot[xpos] == 1)
		  break;
	      next_button_blue = xpos < num_button ? which_button[xpos] : 1;
	    }
	  if (pos_orange < next_button_orange)
	    pos_orange++;
	  else if (pos_orange > next_button_orange)
	    pos_orange--;
	  else if (which_robot[no_button_press] == 0)
	    {
	      update_num_button_press = 1;
	      for (xpos = no_button_press + 1; xpos < num_button; xpos++)
		if (which_robot[xpos] == 0)
		  break;
	      next_button_orange = xpos < num_button ? which_button[xpos] : 1;
	    }
	  if (update_num_button_press)
	    no_button_press++;
	  step++;
	}
      fprintf (fp_out, "Case #%d: %d\n", i, step);
    }
  fclose (fp_in);
  fclose (fp_out);
  return 0;
}
