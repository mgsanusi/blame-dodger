#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#include <stddef.h>
int new_strlen(const char *str);

void* new_malloc(int size);

double new_sqrt(double x);

double new_pow(double base, double exponent);

long isprime(long test)
{
  int first_iteration;
  long s = new_sqrt(test) + 1;
  long count;
  for (count = 2; count <= s; count++)
  {
    if ((test % count) == 0)
    {
      return count;
    }

  }

  return 0;
}

long baseconvert(char *r, int base)
{
  int first_iteration;
  int count;
  size_t length = new_strlen(r);
  long result = 0;
  for (count = 0; count < length; count++)
  {
    result += r[count] - 48 ? new_pow(base, (length - count) - 1) : 0;
  }

  return result;
}

void nextpotentialjamcoin(char *r)
{
  int first_iteration;
  size_t length = new_strlen(r);
  if ((r[0] != '1') || (r[length - 1] != '1'))
  {
    printf("Error: argument not valid jam coin.\n");
  }

  size_t count;
  for (count = length - 2; count > 0; count--)
  {
    if (r[count] == '1')
    {
      r[count] = '0';
    }
    else
    {
      r[count] = '1';
      break;
    }

  }

}

void nextjamcoin(char *r, long *divisor)
{
  int first_iteration;
  nextpotentialjamcoin(r);
  int ibase;
  for (ibase = 2; ibase <= 10; ibase++)
  {
    if ((divisor[ibase - 2] = isprime(baseconvert(r, ibase))) == 0)
    {
      nextpotentialjamcoin(r);
      ibase = 1;
    }

  }

}

int Main()
{
  int first_iteration;
  int num;
  int tmp;
  scanf(" %d", &num);
  for (tmp = 0; tmp < num; tmp++)
  {
    int dh;
    int r;
    scanf(" %d %d", &dh, &r);
    long divisor[9];
    char *r = new_malloc(dh + 1);
    r[dh] = '\0';
    int count;
    for (count = 0; count < dh; count++)
    {
      r[count] = (count == 0) || (count == (dh - 1)) ? '1' : '0';
    }

    printf("Case #%d: \n", tmp + 1);
    for (count = 0; count < r; count++)
    {
      nextjamcoin(r, divisor);
      printf("%s ", r);
      int count;
      for (count = 0; count < 9; count++)
      {
        printf("%ld ", divisor[count]);
      }

      printf("\n");
    }

  }

  return 0;
}



int new_strlen(const char *str);

void* new_malloc(int size);

double new_sqrt(double x);

double new_pow(double base, double exponent) {
  return pow(base, exponent);
}
int new_strlen(const char *str);

void* new_malloc(int size);

double new_sqrt(double x) {
  return sqrt(x);
}
int new_strlen(const char *str);

void* new_malloc(int size) {
  return malloc(size);
}
int new_strlen(const char *str) {
  return strlen(str);
}