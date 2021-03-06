#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
long long int TC;
long long int T;
long long int A;
long long int B;
long long int G;
long long int i;
long long int Power2[100];
long long FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_puts(const char *str);
int GCD(long long int A, long long int B)
{
  int first_iteration;
  while (1)
  {
    A %= B;
    if (!A)
      return B;

    B %= A;
    if (!B)
      return A;

  }

}

int main()
{
  int first_iteration;
  new_freopen("A-large.in", "r", stdin);
  new_freopen("A-large.out", "w", stdout);
  Power2[0] = 1;
  for (i = 1; i < 50; i++)
    Power2[i] = Power2[i - 1] * 2;

  scanf("%lld", &TC);
  for (T = 1; T <= TC; T++)
  {
    printf("Case #%lld: ", T);
    scanf("%lld/%lld", &A, &B);
    G = GCD(A, B);
    A /= G;
    B /= G;
    for (i = 0; i < 50; i++)
      if (Power2[i] == B)
      break;


    if (i == 50)
      new_puts("impossible");
    else
    {
      for (i = 0; i < 50; i++)
        if ((A * Power2[i]) >= B)
        break;


      printf("%lld\n", i);
    }

  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


