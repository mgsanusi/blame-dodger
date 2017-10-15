#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int
Main (int argc, char **argv)
{
  int first_iteration;
  char str[100];
  char combine_board[26][26];
  char destroy_table[26][26];
  char output_str[100];
  int test_case;
  int num_combine;
  int no_destroy;
  int num_invoke;
  int read;
  int len;
  int e;
  int b;
  int output_str_size;
  FILE *fp_in;
  FILE *fp_out;
  if (argc != 3)
    {
      printf
	("provide input and output file names as first 2 command line parameters\n");
      new_exit (1);
    }
  if ((fp_in = new_fopen (argv[1], "r")) == 0)
    {
      printf ("can't open file %s\n", argv[1]);
      new_exit (1);
    }
  if ((fp_out = new_fopen (argv[2], "w")) == 0)
    {
      printf ("can't open file %s\n", argv[2]);
      new_exit (1);
    }
  fscanf (fp_in, "%d\n", &test_case);
  for (read = 1; read <= test_case; read++)
    {
      for (len = 0; len < 26; len++)
	for (e = 0; e < 26; e++)
	  {
	    combine_board[len][e] = 0;
	    destroy_table[len][e] = 0;
	  }
      fscanf (fp_in, "%d", &num_combine);
      for (len = 0; len < num_combine; len++)
	{
	  fscanf (fp_in, " %s", str);
	  len = str[0] - 'A';
	  e = str[1] - 'A';
	  b = (str[2] - 'A') + 1;
	  combine_board[len][e] = b;
	  combine_board[e][len] = b;
	}
      fscanf (fp_in, "%d", &no_destroy);
      for (len = 0; len < no_destroy; len++)
	{
	  fscanf (fp_in, " %s", str);
	  len = str[0] - 'A';
	  e = str[1] - 'A';
	  destroy_table[len][e] = 1;
	  destroy_table[e][len] = 1;
	}
      fscanf (fp_in, "%d", &num_invoke);
      fscanf (fp_in, " %s\n", str);
      output_str_size = 0;
      for (len = 0; len < num_invoke; len++)
	{
	  if (output_str_size == 0)
	    output_str[output_str_size++] = str[len];
	  else
	    {
	      e = str[len] - 'A';
	      b = output_str[output_str_size - 1] - 'A';
	      if (combine_board[e][b])
		{
		  output_str[output_str_size - 1] =
		    (combine_board[e][b] - 1) + 'A';
		}
	      else
		{
		  for (b = 0; b < output_str_size; b++)
		    if (destroy_table[e][output_str[b] - 'A'])
		      {
			output_str_size = 0;
			break;
		      }
		  if (output_str_size)
		    {
		      output_str[output_str_size++] = str[len];
		    }
		}
	    }
	}
      fprintf (fp_out, "Case #%d: [", read);
      for (len = 0; len < (output_str_size - 1); len++)
	fprintf (fp_out, "%c, ", output_str[len]);
      for (; len < output_str_size; len++)
	fprintf (fp_out, "%c", output_str[len]);
      fprintf (fp_out, "]\n");
    }
  new_fclose (fp_in);
  new_fclose (fp_out);
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  return exit (status);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
