/*
problem b, google code jam 2011
coded by Jason Thong
jason.thong.86@gmail.com
insight: array-based implementation is used for simplicity (could use a link-list-based stack too...)
combining involves modifying the most recently added elements, this can't propagate backwards since only base elements can combine and the result is a non-base element
if not combining, deletion involves sweeping through array and checking the destory_table to find a match
deletion could be sped up by using flags to indicate this array has element X, so if we pick up anything opposed to X, set the array size to 0 (not implemented...)
could use less memory by using triangular shaped combine and destroy tables (not implemented...)
compiled with: gcc b.c -o b -Wall -O3
*/
#include <stdio.h>
#include <stdlib.h>
#define STR_SIZE 100
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int
main (int argc, char **argv)
{
  char str[STR_SIZE], combine_table[26][26], destroy_table[26][26],
    output_str[STR_SIZE];
  int test_cases, num_combine, num_destroy, num_invoke, i, j, k, n,
    output_str_size;
  FILE *fp_in, *fp_out;

  if (argc != 3)
    {
      printf
	("provide input and output file names as first 2 command line parameters\n");
      new_exit (1);
    }
  if ((fp_in = new_fopen (argv[1], "r")) == NULL)
    {
      printf ("can't open file %s\n", argv[1]);
      new_exit (1);
    }
  if ((fp_out = new_fopen (argv[2], "w")) == NULL)
    {
      printf ("can't open file %s\n", argv[2]);
      new_exit (1);
    }
  fscanf (fp_in, "%d\n", &test_cases);

  for (i = 1; i <= test_cases; i++)
    {
      //clean up the tables
      for (j = 0; j < 26; j++)
	for (k = 0; k < 26; k++)
	  {
	    combine_table[j][k] = 0;
	    destroy_table[j][k] = 0;
	  }
      //read input
      fscanf (fp_in, "%d", &num_combine);
      for (j = 0; j < num_combine; j++)
	{
	  fscanf (fp_in, " %s", str);
	  j = str[0] - 'A';	//source, translate 'A' to 'Z' into 0 to 25
	  k = str[1] - 'A';	//source
	  n = str[2] - 'A' + 1;	//result after combining, translate 'A' to 'Z' into 1 to 26, 0 means no combine is defined
	  combine_table[j][k] = n;
	  combine_table[k][j] = n;
	}
      fscanf (fp_in, "%d", &num_destroy);
      for (j = 0; j < num_destroy; j++)
	{
	  fscanf (fp_in, " %s", str);
	  j = str[0] - 'A';	//source, translate 'A' to 'Z' into 0 to 25
	  k = str[1] - 'A';	//source
	  destroy_table[j][k] = 1;	//0 means no destroy for this pair, 1 means destroy
	  destroy_table[k][j] = 1;
	}
      fscanf (fp_in, "%d", &num_invoke);
      fscanf (fp_in, " %s\n", str);

      //generate output string
      output_str_size = 0;
      for (j = 0; j < num_invoke; j++)
	{
	  if (output_str_size == 0)
	    output_str[output_str_size++] = str[j];	//nothing in list, just add element
	  else
	    {
	      //first check for combine
	      k = str[j] - 'A';	//translate to indexing for table
	      n = output_str[output_str_size - 1] - 'A';
	      if (combine_table[k][n])
		{		//can be combined, overwrite last item in output_str
		  output_str[output_str_size - 1] =
		    combine_table[k][n] - 1 + 'A';
		}
	      else
		{		//now check for destory
		  for (n = 0; n < output_str_size; n++)
		    if (destroy_table[k][output_str[n] - 'A'])
		      {
			output_str_size = 0;	//delete list
			break;
		      }
		  if (output_str_size)
		    {		//no combine, no destroy, just add it
		      output_str[output_str_size++] = str[j];
		    }
		}
	    }
	}
      //output to file
      fprintf (fp_out, "Case #%d: [", i);
      for (j = 0; j < output_str_size - 1; j++)
	fprintf (fp_out, "%c, ", output_str[j]);
      for (; j < output_str_size; j++)
	fprintf (fp_out, "%c", output_str[j]);
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
