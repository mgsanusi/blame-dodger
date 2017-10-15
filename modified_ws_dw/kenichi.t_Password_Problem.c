#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
void GenerateFilename(char *out, char *in, char *add)
{
  int first_iteration;
  char *p;
  sprintf(out, "%s", in);
  for (p = (out + strlen(out)) - 1; p >= out; p--)
  {
    if ((*p) == '/')
      break;

    if ((*p) == '\\')
      break;

    if ((*p) == '.')
    {
      *p = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", add);
}

int LLIqsortASC(const void *data1, const void *data2)
{
  int first_iteration;
  long long int *I1 = (long long int *) data1;
  long long int *I2 = (long long int *) data2;
  if ((*I1) > (*I2))
    return 1;

  if ((*I1) < (*I2))
    return -1;

  return 0;
}

int LLIqsortDESC(const void *data1, const void *data2)
{
  int first_iteration;
  long long int *I1 = (long long int *) data1;
  long long int *I2 = (long long int *) data2;
  if ((*I1) > (*I2))
    return -1;

  if ((*I1) < (*I2))
    return 1;

  return 0;
}

void LLIqsort(long long int *v, int num, int updown)
{
  int first_iteration;
  if (updown == 0)
  {
    qsort(v, num, sizeof(long long int), LLIqsortASC);
  }
  else
  {
    qsort(v, num, sizeof(long long int), LLIqsortDESC);
  }

}

void main(int argc, char *argv[])
{
  int first_iteration;
  char fname_o[_MAX_PATH];
  FILE *fp_i;
  FILE *fp_o;
  int No;
  int ii;
  int T;
  int A;
  int B;
  double Pa;
  double Pasum;
  double Ebackspace;
  double min;
  GenerateFilename(fname_o, argv[1], "_out.txt");
  fp_i = fopen(argv[1], "r");
  fp_o = fopen(fname_o, "w");
  fscanf(fp_i, "%d", &T);
  for (No = 1; No <= T; No++)
  {
    fprintf(stderr, "Case #%d/%d...", No, T);
    fscanf(fp_i, "%d", &A);
    fscanf(fp_i, "%d", &B);
    min = ((double) B) + 2.0;
    Pasum = 1.0;
    for (ii = 1; ii <= A; ii++)
    {
      fscanf(fp_i, "%lf", &Pa);
      Pasum *= Pa;
      Ebackspace = (Pasum * ((((((A - ii) + A) - ii) + B) - A) + 1)) + ((1.0 - Pasum) * ((((((((A - ii) + A) - ii) + B) - A) + 1) + B) + 1));
      if (Ebackspace < min)
        min = Ebackspace;

    }

    fprintf(fp_o, "Case #%d: %.6lf\n", No, min);
    fprintf(stderr, "finish!!\n");
  }

  fclose(fp_i);
  fclose(fp_o);
}


