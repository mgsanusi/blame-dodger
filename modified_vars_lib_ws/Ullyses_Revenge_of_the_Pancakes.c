#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_getc (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int
Main ()
{
  FILE *na;
  FILE *fo;
  fo = new_fopen ("outputa.txt", "w");
  na = new_fopen ("inputa.in", "r");
  int i_n;
  int sum;
  int arr[115];
  int temp_reach;
  int j;
  int max;
  bool work = 1;
  char charr;
  fscanf (na, "%d", &i_n);
  charr = new_getc (na);
  for (temp_reach = 1; temp_reach <= i_n; temp_reach++)
    {
      work = 1;
      fprintf (fo, "Case #");
      fprintf (fo, "%d", temp_reach);
      fprintf (fo, ":");
      fprintf (fo, " ");
      j = 1;
      while (work)
	{
	  charr = new_getc (na);
	  if (charr == '+')
	    {
	      arr[j] = 1;
	    }
	  else if (charr == '-')
	    {
	      arr[j] = 0;
	    }
	  else
	    {
	      arr[j] = 1;
	      work = 0;
	    }
	  j = j + 1;
	}
      max = j - 1;
      printf ("%d", max);
      sum = 0;
      for (j = 1; j <= (max - 1); j++)
	{
	  if ((arr[j] + arr[j + 1]) == 1)
	    {
	      sum = sum + 1;
	    }
	}
      fprintf (fo, "%d", sum);
      fprintf (fo, "\n");
    }
  return 1;
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int
new_getc (FILE * stream)
{
  return getc (stream);
}
