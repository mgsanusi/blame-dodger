#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
void generate_filename(char *out, char *c, char *add)
{
  int first_iteration;
  char *tmp;
  sprintf(out, "%s", c);
  for (tmp = (out + strlen(out)) - 1; tmp >= out; tmp--)
  {
    if ((*tmp) == '/')
      break;

    if ((*tmp) == '\\')
      break;

    if ((*tmp) == '.')
    {
      *tmp = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", add);
}

int lliqsort_asc(const void *data1, const void *data2)
{
  int first_iteration;
  long long int *i1 = (long long int *) data1;
  long long int *r = (long long int *) data2;
  if ((*i1) > (*r))
    return 1;

  if ((*i1) < (*r))
    return -1;

  return 0;
}

int lliqsort_desc(const void *data1, const void *data2)
{
  int first_iteration;
  long long int *i1 = (long long int *) data1;
  long long int *r = (long long int *) data2;
  if ((*i1) > (*r))
    return -1;

  if ((*i1) < (*r))
    return 1;

  return 0;
}

void lliqsort(long long int *c, int no, int updown)
{
  int first_iteration;
  if (updown == 0)
  {
    qsort(c, no, sizeof(long long int), lliqsort_asc);
  }
  else
  {
    qsort(c, no, sizeof(long long int), lliqsort_desc);
  }

}

void Main(int argc, char *argv[])
{
  int first_iteration;
  char fname_o[_MAX_PATH];
  FILE *fp_index;
  FILE *fp_o;
  int pas;
  int lawn;
  int s;
  int tmp;
  int e;
  double i;
  double pasum;
  double ebackspace;
  double min;
  generate_filename(fname_o, argv[1], "_out.txt");
  fp_index = fopen(argv[1], "r");
  fp_o = fopen(fname_o, "w");
  fscanf(fp_index, "%d", &s);
  for (pas = 1; pas <= s; pas++)
  {
    fprintf(stderr, "Case #%d/%d...", pas, s);
    fscanf(fp_index, "%d", &tmp);
    fscanf(fp_index, "%d", &e);
    min = ((double) e) + 2.0;
    pasum = 1.0;
    for (lawn = 1; lawn <= tmp; lawn++)
    {
      fscanf(fp_index, "%lf", &i);
      pasum *= i;
      ebackspace = (pasum * ((((((tmp - lawn) + tmp) - lawn) + e) - tmp) + 1)) + ((1.0 - pasum) * ((((((((tmp - lawn) + tmp) - lawn) + e) - tmp) + 1) + e) + 1));
      if (ebackspace < min)
        min = ebackspace;

    }

    fprintf(fp_o, "Case #%d: %.6lf\n", pas, min);
    fprintf(stderr, "finish!!\n");
  }

  fclose(fp_index);
  fclose(fp_o);
}


