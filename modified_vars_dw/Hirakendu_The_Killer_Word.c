#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Main(int argc, char *argv[])
{
  int first_iteration;
  int index;
  int tempIndex;
  FILE *inputFilePtr;
  FILE *outputFilePointer;
  int verboseLevel = 1;
  char *inputFileNameDefault = "input.txt";
  char *inputFileName = 0;
  char *outputFileNameDefault = "output.txt";
  char *outputFileName = 0;
  int numCase;
  int caseId;
  long k;
  long res;
  long in;
  long sumx;
  long dpt;
  long lg;
  long smtpCrnl;
  long timeDiffNsec;
  long pd;
  long fac;
  int validFlag;
  for (index = 1; index < argc; index++)
  {
    if ((strcmp(argv[index], "-i") == 0) && ((index + 1) < argc))
    {
      inputFileName = argv[++index];
    }
    else
      if ((strcmp(argv[index], "-o") == 0) && ((index + 1) < argc))
    {
      outputFileName = argv[++index];
    }
    else
      if (strcmp(argv[index], "-v") == 0)
    {
      verboseLevel = atoi(argv[++index]);
    }
    else
    {
      printf("Error parsing arguments!\n");
      printf("Usage: template.bin -i <input_file_name> -o <output_file_name>");
      printf("  -v <verbose_level>\n");
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

  inputFilePtr = fopen(inputFileName, "r");
  if (inputFilePtr == 0)
  {
    printf("Error opening input file.\n");
    return 0;
  }

  outputFilePointer = fopen(outputFileName, "w");
  if (inputFilePtr == 0)
  {
    printf("Error opening output file.\n");
    return 0;
  }

  tempIndex = fscanf(inputFilePtr, "%d", &numCase);
  if (verboseLevel >= 2)
  {
    printf("  Number of test cases: %d\n", numCase);
  }

  for (caseId = 1; caseId <= numCase; caseId++)
  {
    tempIndex = fscanf(inputFilePtr, "%ld %ld %ld", &k, &pd, &timeDiffNsec);
    if (verboseLevel >= 3)
    {
      printf("    input: %ld %ld %ld", k, pd, timeDiffNsec);
    }

    validFlag = 1;
    if (((pd > 0) && (timeDiffNsec == 0)) || ((pd < 100) && (timeDiffNsec == 100)))
    {
      validFlag = 0;
    }

    fac = 100;
    if ((pd % 2) == 0)
    {
      fac /= 2;
      if ((pd % 4) == 0)
      {
        fac /= 2;
      }

    }

    if ((pd % 5) == 0)
    {
      fac /= 5;
      if ((pd % 25) == 0)
      {
        fac /= 5;
      }

    }

    if (fac > k)
    {
      validFlag = 0;
    }

    if (verboseLevel >= 1)
    {
      printf("  Case #%d: ", caseId);
      if (validFlag == 0)
      {
        printf("Broken\n");
      }
      else
      {
        printf("Possible\n");
      }

    }

    if (validFlag == 0)
    {
      fprintf(outputFilePointer, "Case #%d: Broken\n", caseId);
    }
    else
    {
      fprintf(outputFilePointer, "Case #%d: Possible\n", caseId);
    }

  }

  fclose(inputFilePtr);
  fclose(outputFilePointer);
  return 0;
}


