#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
  int count;
  int pos[500];
} posset_type;
int
showProgress (int length, int *progress)
{
  int first_iteration;
  int f;
  for (f = 0; f < length; f++)
    {
      printf (" %04d", progress[f]);
    }
  printf ("\n");
  return 0;
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  char buffer[4096];
  FILE *r = stdin;
  int k;
  int n;
  char tS[] = "welcome to code jam";
  int tSLength = strlen (tS);
  posset_type posSet[256];
  {
    int f;
    memset (posSet, 0, sizeof (posSet));
    for (f = 0; f < tSLength; f++)
      {
	int a = (int) tS[f];
	{
	  int posCount = posSet[a].count;
	  posSet[a].pos[posCount] = f;
	  posSet[a].count++;
	}
      }
  }
  if (0)
    {
      int f;
      int pi;
      for (f = 0; f < 256; f++)
	{
	  if (posSet[f].count > 0)
	    {
	      printf ("Used: %c at pos: ", f);
	      for (pi = 0; pi < posSet[f].count; pi++)
		{
		  printf (" %d", posSet[f].pos[pi]);
		}
	      printf ("\n");
	    }
	}
    }
  buffer[0] = 0;
  fgets (buffer, 4096, r);
  sscanf (buffer, "%d", &n);
  for (k = 0; k < n; k++)
    {
      char data[1024];
      int f;
      int pi;
      buffer[0] = 0;
      fgets (buffer, 4096, r);
      data[0] = 0;
      sscanf (buffer, "%[^\r\n]", data);
      printf ("Case #%d: ", k + 1);
      int progress[100];
      memset (progress, 0, sizeof (progress));
      for (f = 0; f < strlen (data); f++)
	{
	  if (posSet[(int) data[f]].count > 0)
	    {
	      for (pi = 0; pi < posSet[(int) data[f]].count; pi++)
		{
		  int n = posSet[(int) data[f]].pos[pi];
		  if (n == 0)
		    {
		      progress[n]++;
		    }
		  else
		    {
		      progress[n] += progress[n - 1];
		      if (progress[n] > 9999)
			{
			  progress[n] = progress[n] % 10000;
			}
		    }
		}
	    }
	}
      printf ("%04d\n", progress[tSLength - 1]);
    }
  return 0;
}
