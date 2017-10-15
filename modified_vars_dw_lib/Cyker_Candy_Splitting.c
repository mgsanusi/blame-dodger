#include "stdio.h"
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int Main()
{
  int first_iteration;
  int t;
  int n;
  int base;
  int s = 0;
  int cont = 0;
  FILE *fp;
  fp = new_fopen("cs0.in", "r");
  fscanf(fp, "%d", &t);
  for (s = 1; s <= t; s++)
  {
    fscanf(fp, "%d", &n);
    int xor = 0;
    int sum = 0;
    int min = 10000000;
    for (cont = 0; cont < n; cont++)
    {
      fscanf(fp, "%d", &base);
      xor = xor ^ base;
      sum = sum + base;
      if (base < min)
        min = base;

    }

    if (xor == 0)
      printf("Case #%d: %d\n", s, sum - min);
    else
      printf("Case #%d: NO\n", s);

  }

  new_fclose(fp);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}