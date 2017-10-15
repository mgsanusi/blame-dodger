#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

void generate_filename(char *out, char *b, char *add)
{
  char *c;
  sprintf(out, "%s", b);
  for (c = (out + strlen(out)) - 1; c >= out; c--)
  {
    if ((*c) == '/')
      break;

    if ((*c) == '\\')
      break;

    if ((*c) == '.')
    {
      *c = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", add);
}

int sort1(const void *data1, const void *data2)
{
  double *num = (double *) data1;
  double *t = (double *) data2;
  if (num[1] > t[1])
    return 1;

  if (num[1] < t[1])
    return -1;

  return 0;
}

int sort0(const void *data1, const void *data2)
{
  double *num = (double *) data1;
  double *t = (double *) data2;
  if (num[0] > t[0])
    return 1;

  if (num[0] < t[0])
    return -1;

  return 0;
}

void Main(int argc, char *argv[])
{
  char fname_o[_MAX_PATH];
  FILE *fp_index;
  FILE *fp_o;
  int x;
  int a2;
  int i;
  int b;
  int tt;
  double c[200][3];
  double i;
  double total;
  generate_filename(fname_o, argv[1], "_out.txt");
  fp_index = new_fopen(argv[1], "r");
  fp_o = new_fopen(fname_o, "w");
  fscanf(fp_index, "%d", &b);
  for (x = 1; x <= b; x++)
  {
    fprintf(stderr, "Case #%d/%d...", x, b);
    fscanf(fp_index, "%d", &tt);
    i = 0;
    for (a2 = 0; a2 < tt; a2++)
    {
      fscanf(fp_index, "%lf", &c[a2][1]);
      c[a2][0] = a2;
      c[a2][2] = 0.0;
      i += c[a2][1];
    }

    new_qsort(c, tt, (sizeof(double)) * 3, sort1);
    total = i;
    for (a2 = 1; a2 < tt; a2++)
    {
      if (total > ((c[a2][1] - (c[0][1] + c[0][2])) * a2))
      {
        for (i = 0; i < a2; i++)
        {
          total -= c[a2][1] - (c[i][1] + c[i][2]);
          c[i][2] += c[a2][1] - (c[i][1] + c[i][2]);
        }

      }
      else
      {
        for (i = 0; i < a2; i++)
        {
          c[i][2] += total / ((double) a2);
        }

        total = 0.0;
        break;
      }

    }

    if (total > 0)
    {
      for (a2 = 0; a2 < tt; a2++)
      {
        c[a2][2] += total / ((double) tt);
      }

    }

    new_qsort(c, tt, (sizeof(double)) * 3, sort0);
    fprintf(fp_o, "Case #%d:", x);
    for (a2 = 0; a2 < tt; a2++)
    {
      fprintf(fp_o, " %.6lf", (100 * c[a2][2]) / i);
    }

    fprintf(fp_o, "\n");
    fprintf(stderr, "finish!!\n");
  }

  new_fclose(fp_index);
  new_fclose(fp_o);
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}