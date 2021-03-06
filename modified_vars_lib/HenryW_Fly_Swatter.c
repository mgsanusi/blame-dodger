#include<stdio.h>
long long n;
long long v;
long long rat;
long long l;
long long freq[2000];
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

void sort()
{
  long long make;
  long long xdrPtr;
  long long temp;
  for (make = 0; make < l; make++)
    for (xdrPtr = make + 1; xdrPtr < l; xdrPtr++)
    if (freq[make] < freq[xdrPtr])
  {
    temp = freq[make];
    freq[make] = freq[xdrPtr];
    freq[xdrPtr] = temp;
  }



  return;
}

long long getMin()
{
  long long sum = 0;
  long long make;
  for (make = 0; make < l; make++)
  {
    sum += ((make / rat) + 1) * freq[make];
  }

  return sum;
}

void Main()
{
  FILE *uart0InputHandler = new_fopen("input.txt", "r");
  FILE *out = new_fopen("output.txt", "w");
  long long make;
  long long xdrPtr;
  long long min;
  fscanf(uart0InputHandler, "%lld", &n);
  for (make = 0; make < n; make++)
  {
    fscanf(uart0InputHandler, "%lld %lld %lld", &v, &rat, &l);
    for (xdrPtr = 0; xdrPtr < l; xdrPtr++)
      fscanf(uart0InputHandler, "%lld", &freq[xdrPtr]);

    sort();
    min = getMin();
    fprintf(out, "Case #%lld: %lld\n", make + 1, min);
  }

}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}