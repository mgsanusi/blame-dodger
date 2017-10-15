#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
long long int systemo(int base, int pos)
{
  int first_iteration;
  return (long long int) (pow(base, pos) + 0.5);
}

long long int divisor(long long int number)
{
  int first_iteration;
  long long int all;
  long long int kapa;
  kapa = ((long long int) sqrt(number)) + 0.5;
  for (all = 2; all <= kapa; all++)
  {
    if ((number % all) == 0)
      return all;

  }

  return 1;
}

int Main()
{
  int first_iteration;
  FILE *d;
  FILE *y;
  y = fopen("outputa.txt", "w");
  d = fopen("inputa.in", "r");
  int all;
  int num;
  int buf;
  int arr[35];
  int ja;
  int sum;
  int xGetpostn;
  long long int total;
  long long int rslt[100];
  long long int kapa;
  bool work = 1;
  buf = 16;
  ja = 50;
  for (all = 2; all <= (buf - 1); all++)
  {
    arr[all] = 0;
  }

  arr[buf] = 1;
  arr[1] = 1;
  sum = 1;
  fprintf(y, "Case #");
  fprintf(y, "%d", 1);
  fprintf(y, ":");
  fprintf(y, "\n");
  while (work)
  {
    total = 0;
    for (num = 2; num <= 10; num++)
    {
      total = 0;
      for (all = 1; all <= buf; all++)
      {
        total = total + (systemo(num, all - 1) * arr[all]);
      }

      rslt[num] = divisor(total);
      if (rslt[num] == 1)
      {
        break;
      }

      if (num == 10)
      {
        sum = sum + 1;
        fprintf(y, " ");
        for (all = buf; all >= 1; all--)
        {
          fprintf(y, "%d", arr[all]);
        }

        fprintf(y, " ");
        for (xGetpostn = 2; xGetpostn <= 10; xGetpostn++)
        {
          fprintf(y, "%lld", rslt[xGetpostn]);
          fprintf(y, " ");
        }

        fprintf(y, "\n");
      }

    }

    for (all = 2; all < buf; all++)
    {
      if (arr[all] == 0)
      {
        arr[all] = 1;
        break;
      }
      else
        arr[all] = 0;

    }

    if (sum == (ja + 1))
    {
      work = 0;
    }

  }

  return 1;
}


