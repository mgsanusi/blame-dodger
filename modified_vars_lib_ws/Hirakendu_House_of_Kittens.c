#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_strcmp (const char *str1, const char *str2);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int new_atoi (const char *str);
int new_abs (int x);
int
Main (int argc, char *argv[])
{
  int index;
  int tempIndex;
  FILE *inputFilePtr;
  FILE *outputFilePointer;
  int verboseLevel = 1;
  char *inputFileNameDefault = "input.txt";
  char *inputFileName = 0;
  char *outputFileNameDefault = "output.txt";
  char *outputFileName = 0;
  int noCase;
  int caseId;
  long n;
  long l;
  long nc;
  long space[100000];
  long j;
  int possibleFlag;
  for (index = 1; index < argc; index++)
    {
      if ((new_strcmp (argv[index], "-i") == 0) && ((index + 1) < argc))
	{
	  inputFileName = argv[++index];
	}
      else if ((new_strcmp (argv[index], "-o") == 0) && ((index + 1) < argc))
	{
	  outputFileName = argv[++index];
	}
      else if (new_strcmp (argv[index], "-v") == 0)
	{
	  verboseLevel = new_atoi (argv[++index]);
	}
      else
	{
	  printf ("Error parsing arguments!\n");
	  printf
	    ("Usage: template.bin -i <input_file_name> -o <output_file_name>");
	  printf ("  -v <verbose_level>\n");
	  return 0;
	}
    }
  if (inputFileName == 0)
    {
      inputFileName = inputFileNameDefault;
    }
  if (outputFileName == 0)
    {
      outputFileName = outputFileNameDefault;
    }
  inputFilePtr = new_fopen (inputFileName, "r");
  if (inputFilePtr == 0)
    {
      printf ("Error opening input file.\n");
      return 0;
    }
  outputFilePointer = new_fopen (outputFileName, "w");
  if (inputFilePtr == 0)
    {
      printf ("Error opening output file.\n");
      return 0;
    }
  tempIndex = fscanf (inputFilePtr, "%d", &noCase);
  if (verboseLevel >= 2)
    {
      printf ("  Number of test cases: %d\n", noCase);
    }
  for (caseId = 1; caseId <= noCase; caseId++)
    {
      if (verboseLevel >= 1)
	{
	  printf ("  Case #%d: ", caseId);
	}
      tempIndex = fscanf (inputFilePtr, "%ld %ld %ld", &n, &l, &nc);
      for (index = 0; index < n; index++)
	{
	  tempIndex = fscanf (inputFilePtr, "%ld", &space[index]);
	}
      if (verboseLevel >= 3)
	{
	  printf ("f = ");
	  for (index = 0; index < n; index++)
	    {
	      printf (" %ld", space[index]);
	    }
	  printf ("\n");
	}
      possibleFlag = 1;
      for (j = l; j <= nc; j++)
	{
	  for (index = 0; index < n; index++)
	    {
	      if (((j % space[index]) != 0) && ((space[index] % j) != 0))
		{
		  break;
		}
	    }
	  if (index == n)
	    {
	      break;
	    }
	}
      if (j == (nc + 1))
	{
	  printf (" impossible\n");
	}
      else
	{
	  printf (" %ld\n", j);
	}
      if (verboseLevel >= 3)
	{
	  printf ("    \n");
	}
      if (verboseLevel >= 1)
	{
	  printf ("\n");
	}
      fprintf (outputFilePointer, "Case #%d: ", caseId);
      if (j == (nc + 1))
	{
	  fprintf (outputFilePointer, "NO\n");
	}
      else
	{
	  fprintf (outputFilePointer, "%ld\n", j);
	}
    }
  new_fclose (inputFilePtr);
  new_fclose (outputFilePointer);
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_strcmp (const char *str1, const char *str2);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int new_atoi (const char *str);
int
new_abs (int x)
{
  return abs (x);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_strcmp (const char *str1, const char *str2);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int
new_atoi (const char *str)
{
  return atoi (str);
}

FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int
new_strcmp (const char *str1, const char *str2)
{
  return strcmp (str1, str2);
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
