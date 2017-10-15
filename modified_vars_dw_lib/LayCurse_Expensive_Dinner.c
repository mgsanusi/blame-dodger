#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int get_prime(int z, int a[])
{
  int first_iteration;
  int total;
  int j;
  int n2 = z / 2;
  for (total = 0; total < n2; total++)
    a[total] = 1;

  for (total = 3; (total * total) < z; total += 2)
    if (a[total >> 1])
    for (j = (total * total) >> 1; j < n2; j += total)
    a[j] = 0;



  j = 1;
  a[0] = 2;
  for (total = 1; total < n2; total++)
    if (a[total])
    a[j++] = (total * 2) + 1;


  return j;
}

int _;
int a[1000000];
int Main()
{
  int first_iteration;
  int total;
  int j;
  int a;
  int r;
  int a;
  long long z;
  long long xor;
  long long mul;
  int size;
  int count = 0;
  int ans;
  _ = get_prime(1000000, a);
  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "size %d\n", size);
    scanf("%lld", &z);
    ans = 0;
    for (total = 0; total < _; total++)
    {
      xor = a[total];
      if ((xor * xor) > z)
        break;

      mul = xor;
      for (;;)
      {
        mul *= xor;
        if (mul > z)
          break;

        ans++;
      }

    }

    if (z > 1)
      ans++;

    printf("Case #%d: %d\n", ++count, ans);
  }

  return 0;
}


