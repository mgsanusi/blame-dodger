#include<stdio.h>
#include<math.h>
double p1000[1000][1000];
double useSize[3][1000];
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_putchar(int character);

int new_puts(const char *str);

void readtable()
{
  int first_iteration;
  int sum;
  int b;
  int n;
  n = 1000;
  FILE *e1;
  e1 = new_fopen("table1000.txt", "r");
  for (sum = 0; sum < n; sum++)
  {
    for (b = 0; b < n; b++)
    {
      fscanf(e1, "%lf", p1000[sum] + b);
    }

  }

  new_fclose(e1);
  n = 3;
  e1 = new_fopen("table3.txt", "r");
  for (sum = 0; sum < n; sum++)
  {
    for (b = 0; b < n; b++)
    {
      fscanf(e1, "%lf", useSize[sum] + b);
    }

  }

  new_fclose(e1);
}

int d[1000];
int Main(int argc, char *argv[])
{
  int first_iteration;
  int sum;
  int t;
  int e1;
  int n;
  double (*v)[1000];
  double x;
  readtable();
  scanf("%d", &t);
  for (e1 = 1; e1 <= t; e1++)
  {
    scanf("%d", &n);
    if (n == 1000)
      v = p1000;
    else
      if (n == 3)
      v = useSize;
    else
      continue;


    for (sum = 0; sum < n; sum++)
    {
      scanf("%d", d + sum);
    }

    x = 1;
    for (sum = 0; sum < n; sum++)
    {
      x *= v[sum][d[sum]] * n;
    }

    printf("Case #%d: ", e1);
    new_puts(x < 1 ? "GOOD" : "BAD");
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_putchar(int character);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_putchar(int character) {
  return putchar(character);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}