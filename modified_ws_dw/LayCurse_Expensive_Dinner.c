#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int getPrime(int n, int p[])
{
  int first_iteration;
  int i;
  int j;
  int n2 = n / 2;
  for (i = 0; i < n2; i++)
    p[i] = 1;

  for (i = 3; (i * i) < n; i += 2)
    if (p[i >> 1])
    for (j = (i * i) >> 1; j < n2; j += i)
    p[j] = 0;



  j = 1;
  p[0] = 2;
  for (i = 1; i < n2; i++)
    if (p[i])
    p[j++] = (i * 2) + 1;


  return j;
}

int ps;
int p[1000000];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  long long n;
  long long np;
  long long mul;
  int size;
  int count = 0;
  int res;
  ps = getPrime(1000000, p);
  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "size %d\n", size);
    scanf("%lld", &n);
    res = 0;
    for (i = 0; i < ps; i++)
    {
      np = p[i];
      if ((np * np) > n)
        break;

      mul = np;
      for (;;)
      {
        mul *= np;
        if (mul > n)
          break;

        res++;
      }

    }

    if (n > 1)
      res++;

    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


