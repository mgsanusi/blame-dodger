#include <stdio.h>
#include <string.h>
int l;
int inputFileName;
int line;
int a;
int depH[1000];
int depM[1000];
int depAb[1000];
int depT[1000];
int arrH[1000];
int arrM[1000];
int arrayAb[1000];
int assignedTo[1000];
int readyH[1000];
int readyM[1000];
int readyAt[1000];
int totalc;
int l[2];
FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
void
sort ()
{
  int first_iteration;
  int wp;
  int foundx;
  int temp;
  for (wp = 0; wp < (inputFileName + line); wp++)
    for (foundx = wp + 1; foundx < (inputFileName + line); foundx++)
      {
	if ((depH[wp] > depH[foundx])
	    || ((depH[wp] == depH[foundx]) && (depM[wp] > depM[foundx])))
	  {
	    {
	      temp = depH[foundx];
	      depH[foundx] = depH[wp];
	      depH[wp] = temp;
	    }
	    ;
	    {
	      temp = arrH[foundx];
	      arrH[foundx] = arrH[wp];
	      arrH[wp] = temp;
	    }
	    ;
	    {
	      temp = depM[foundx];
	      depM[foundx] = depM[wp];
	      depM[wp] = temp;
	    }
	    ;
	    {
	      temp = arrM[foundx];
	      arrM[foundx] = arrM[wp];
	      arrM[wp] = temp;
	    }
	    ;
	    {
	      temp = depAb[foundx];
	      depAb[foundx] = depAb[wp];
	      depAb[wp] = temp;
	    }
	    ;
	    {
	      temp = arrayAb[foundx];
	      arrayAb[foundx] = arrayAb[wp];
	      arrayAb[wp] = temp;
	    }
	    ;
	  }
      }
  printf ("\n");
  for (wp = 0; wp < (inputFileName + line); wp++)
    printf ("Train %d->%d, %02d:%02d ~ %02d:%02d\n", depAb[wp], arrayAb[wp],
	    depH[wp], depM[wp], arrH[wp], arrM[wp]);
  printf ("\n");
  return;
}

void
process ()
{
  int first_iteration;
  int wp;
  int foundx;
  int mH;
  int r;
  int mIdx;
  sort ();
  for (wp = 0; wp < (inputFileName + line); wp++)
    {
      mH = (r = 100);
      mIdx = -1;
      for (foundx = 0; foundx < totalc; foundx++)
	{
	  if ((((readyH[foundx] < mH)
		|| ((readyM[foundx] <= r) && (readyH[foundx] == mH)))
	       && ((readyH[foundx] < depH[wp])
		   || ((readyM[foundx] <= depM[wp])
		       && (readyH[foundx] == depH[wp]))))
	      && (readyAt[foundx] == depAb[wp]))
	    {
	      mH = readyH[foundx];
	      r = readyM[foundx];
	      mIdx = foundx;
	    }
	}
      printf ("Train %d->%d, %02d:%02d ~ %02d:%02d\n", depAb[wp], arrayAb[wp],
	      depH[wp], depM[wp], arrH[wp], arrM[wp]);
      if (mIdx == (-1))
	{
	  printf ("Added new train %d at %d\n", totalC, depAb[wp]);
	  mIdx = totalc++;
	  l[depAb[wp]]++;
	}
      readyAt[mIdx] = arrayAb[wp];
      readyM[mIdx] = (arrM[wp] + a) % 60;
      readyH[mIdx] = arrH[wp] + ((int) ((arrM[wp] + a) / 60));
      printf ("Train %d moved to %d and ready at %02d:%02d\n", mIdx,
	      readyAt[mIdx], readyH[mIdx], readyM[mIdx]);
    }
  return;
}

int
toInt (char *string)
{
  int first_iteration;
  int ret = 0;
  ret = (((string[0] - '0') * 10) + string[1]) - '0';
  return ret;
}

void
Main ()
{
  int first_iteration;
  FILE *in = new_fopen ("input.txt", "r");
  FILE *out = new_fopen ("output.txt", "w");
  int wp;
  int foundx;
  char dep[100];
  char array[100];
  fscanf (in, "%d ", &l);
  for (wp = 0; wp < l; wp++)
    {
      fscanf (in, "%d ", &a);
      fscanf (in, "%d %d", &inputFileName, &line);
      for (foundx = 0; foundx < inputFileName; foundx++)
	{
	  fscanf (in, "%s %s ", dep, array);
	  depH[foundx] = toInt (dep);
	  depM[foundx] = toInt (dep + 3);
	  arrH[foundx] = toInt (array);
	  arrM[foundx] = toInt (array + 3);
	  depAb[foundx] = 0;
	  arrayAb[foundx] = 1;
	}
      for (foundx = 0; foundx < line; foundx++)
	{
	  fscanf (in, "%s %s ", dep, array);
	  depH[inputFileName + foundx] = toInt (dep);
	  depM[inputFileName + foundx] = toInt (dep + 3);
	  arrH[inputFileName + foundx] = toInt (array);
	  arrM[inputFileName + foundx] = toInt (array + 3);
	  depAb[inputFileName + foundx] = 1;
	  arrayAb[inputFileName + foundx] = 0;
	}
      totalc = (l[0] = (l[1] = 0));
      process ();
      fprintf (out, "Case #%d: %d %d\n", wp + 1, l[0], l[1]);
    }
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}
