#include <stdio.h>
int rjWhy;
int l;
int pp;
int base;
int powN(int n, int i1)
{
  int r = 0;
  while ((n % i1) == 0)
  {
    r++;
    n = n / i1;
  }

  return r;
}

int max(int m, int b)
{
  return m > b ? m : b;
}

void goody(void)
{
  int max3 = 0;
  int max5 = 0;
  int oddpow2 = 0;
  int max2 = 0;
  int n2;
  int v;
  int p2;
  int left;
  for (n2 = 0; n2 < base; n2++)
  {
    scanf("%d", &v);
    max3 = max(max3, powN(v, 3));
    max5 = max(max5, powN(v, 5));
    p2 = powN(v, 2);
    max2 = max(max2, p2);
    oddpow2 |= p2 & 1;
  }

  left = l;
  while (max3)
  {
    printf("3");
    max3--;
    left--;
  }

  while (max5)
  {
    printf("5");
    max5--;
    left--;
  }

  if (oddpow2)
  {
    printf("2");
    max2--;
    left--;
  }

  while (max2 && ((2 * left) > max2))
  {
    printf("2");
    max2--;
    left--;
  }

  while (left > 0)
  {
    printf("4");
    max2 -= 2;
    left--;
  }

  printf("\n");
}

void lucky(void)
{
  int n2;
  scanf("%d %d %d %d", &rjWhy, &l, &pp, &base);
  for (n2 = 1; n2 <= rjWhy; n2++)
  {
    goody();
  }

}

int Main(int argc, char **argv)
{
  int t;
  scanf("%d", &t);
  printf("Case #1:\n");
  lucky();
  return 0;
}


