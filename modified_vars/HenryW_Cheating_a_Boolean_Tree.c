#include<stdio.h>
#include<math.h>
int counter;
int n;
int m;
int r;
int l[3];
int p2[3];
int divisor[100][2][10001];
int nfactors[10001];
int rprime(int l, int p2)
{
  if (p2 == 0)
    return l;

  return rprime(p2, l % p2);
}

void getfactors()
{
  int exists;
  int cs;
  int s;
  int walk;
  int t1;
  for (exists = 0; exists <= 10000; exists++)
    nfactors[exists] = 0;

  for (exists = 1; exists <= 10000; exists++)
    for (cs = 1; cs <= 100; cs++)
  {
    if ((cs * cs) > exists)
      break;

    walk = cs;
    t1 = sqrt((exists * exists) - (walk * walk));
    if (((walk * walk) + (t1 * t1)) != exists)
      continue;

    divisor[nfactors[s]++][0][s] = walk;
    divisor[nfactors[s]++][1][s] = t1;
  }


  return;
}

int get_min(int a, int k, int arr)
{
  int min = a < k ? a : k;
  if (min < arr)
    return min;
  else
    return arr;

}

int proc()
{
  int n;
  int count;
  int max_a = sqrt(r);
  int x1;
  int envp;
  int n;
  int y2;
  int dx;
  int i2;
  int gcd;
  int ulen;
  int f;
  int exists;
  int cs;
  int mx = 0;
  int my = 0;
  for (n = 1; n <= sqrt(r); n++)
  {
    if (r % n)
      continue;

    count = r / n;
    for (exists = 0; l < nfactors[n]; exists++)
    {
      x1 = divisor[exists][0][n];
      n = divisor[exists][1][n];
      gcd = rprime(x1, n);
      dx = (-1) * (n / gcd);
      i2 = x1 / gcd;
      ulen = (dx * dx) + (i2 * i2);
      if (count % ulen)
        continue;

      f = count / ulen;
      envp = dx * f;
      y2 = i2 * f;
    }

  }

  return -1;
}

void Main()
{
  FILE *t = fopen("input.txt", "r");
  FILE *out = fopen("output.txt", "w");
  long exists;
  long cs;
  long min;
  getfactors();
  fscanf(t, "%d", &counter);
  for (exists = 0; exists < counter; exists++)
  {
    fscanf(t, "%d %d %d", &n, &m, &r);
    min = proc();
    if (min == (-1))
      fprintf(stdout, "Case #%ld: IMPOSSIBLE\n", exists + 1);
    else
      fprintf(stdout, "Case #%ld: %d %d %d %d %d %d\n", exists + 1, l[0], p2[0], l[1], p2[1], l[2], p2[2]);

  }

}


