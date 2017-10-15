#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);

int new_abs(int x);

int Main(int argc, char *argv[])
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
    if ((new_strcmp(argv[index], "-i") == 0) && ((index + 1) < argc))
    {
      inputFileName = argv[++index];
    }
    else
      if ((new_strcmp(argv[index], "-o") == 0) && ((index + 1) < argc))
    {
      outputFileName = argv[++index];
    }
    else
      if (new_strcmp(argv[index], "-v") == 0)
    {
      verboseLevel = new_atoi(argv[++index]);
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

  inputFilePtr = new_fopen(inputFileName, "r");
  if (inputFilePtr == 0)
  {
    printf("Error opening input file.\n");
    return 0;
  }

  outputFilePointer = new_fopen(outputFileName, "w");
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

  new_fclose(inputFilePtr);
  new_fclose(outputFilePointer);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);

int new_abs(int x) {
  return abs(x);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_strcmp(const char *str1, const char *str2);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str) {
  return atoi(str);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}