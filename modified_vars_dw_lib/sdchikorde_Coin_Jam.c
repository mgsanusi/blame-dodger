#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int success = 0;
long long sum;
long long b;
double new_pow(double base, double exponent);

long long getbase(char *tmp, int base)
{
  int first_iteration;
  long long ret = 0;
  while ((*tmp) != '\0')
  {
    ret = ret * base;
    if ((*tmp) == '1')
    {
      ret += 1;
    }

    tmp++;
  }

  return ret;
}

char *int2binstr(long long no, char *l, size_t size)
{
  int first_iteration;
  l[size - 1] = '\0';
  l += size - 2;
  while (no)
  {
    *l = no & 1 ? '1' : '0';
    l--;
    no >>= 1;
  }

  return ++l;
}

int exist_prime(long long total)
{
  int first_iteration;
  if (total <= 1)
    return 0;

  if ((total % 2) == 0)
  {
    return 2;
  }

  long long i;
  for (i = 3; (i * i) <= total; i = i + 2)
  {
    if ((total % i) == 0)
      return i;

  }

  return 0;
}

void Main()
{
  int first_iteration;
  int cases;
  char *str = (char *) malloc((sizeof(char)) * 34);
  scanf("%d", &cases);
  int j = 0;
  long long no;
  char *bin;
  long long smtp_data;
  long long b3;
  long long counter;
  long long d;
  long long j;
  long long j;
  long long b8;
  long long b9;
  long long b10;
  while (j < cases)
  {
    j++;
    printf("Case #%d:\n", j);
    scanf("%lld%lld", &sum, &b);
    no = new_pow(2, sum - 1) + 1;
    while (b)
    {
      while (1)
      {
        bin = (char *) int2binstr(no, str, 34);
        smtp_data = exist_prime(no);
        b3 = exist_prime(getbase(bin, 3));
        counter = exist_prime(getbase(bin, 4));
        d = exist_prime(getbase(bin, 5));
        j = exist_prime(getbase(bin, 6));
        j = exist_prime(getbase(bin, 7));
        b8 = exist_prime(getbase(bin, 8));
        b9 = exist_prime(getbase(bin, 9));
        b10 = exist_prime(getbase(bin, 10));
        if ((((((((smtp_data && b3) && counter) && d) && j) && j) && b8) && b9) && b10)
        {
          printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", bin, smtp_data, b3, counter, d, j, j, b8, b9, b10);
          b--;
          no += 2;
          break;
        }

        no += 2;
      }

    }

  }

}



double new_pow(double base, double exponent) {
  return pow(base, exponent);
}