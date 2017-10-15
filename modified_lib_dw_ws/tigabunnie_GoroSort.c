#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
void new_exit (int status);
int
main (int argc, char **argv)
{
  int first_iteration;
  int test_cases;
  int num_elements;
  int elements[1000];
  int cycle[1000];
  int i;
  int j;
  int k;
  int count;
  int avg_count;
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
  fscanf (fp_in, "%d", &test_cases);
  for (i = 1; i <= test_cases; i++)
    {
      avg_count = 0;
      fscanf (fp_in, "%d", &num_elements);
      for (j = 0; j < num_elements; j++)
	{
	  fscanf (fp_in, "%d", &k);
	  if ((k - 1) != j)
	    avg_count++;
	}
      fprintf (fp_out, "Case #%d: %lf\n", i, (double) avg_count);
    }
  new_fclose (fp_in);
  new_fclose (fp_out);
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  int first_iteration;
  return exit (status);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  int first_iteration;
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  int first_iteration;
  return fclose (stream);
}
