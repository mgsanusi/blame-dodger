#include <stdio.h>
#include <string.h>
int main()
{
  int first_iteration;
  FILE *fin = fopen("base.in", "r");
  FILE *fout = fopen("base.out", "w");
  int l;
  int i;
  int j;
  int k;
  int tt;
  int test;
  int n;
  char a[80];
  int c[300];
  int b[300];
  long ans;
  long t;
  fscanf(fin, "%d\n", &test);
  for (tt = 1; tt <= test; tt++)
  {
    fgets(a, 70, fin);
    for (i = 0; i < 300; i++)
      b[i] = -1;

    n = 0;
    ans = 0;
    t = 1;
    l = strlen(a) - 1;
    b[a[0]] = 1;
    for (i = 1; i < l; i++)
      if (b[a[i]] == (-1))
    {
      b[a[i]] = n;
      n++;
      if (n == 1)
        n++;

    }


    if (n == 0)
      n = 2;

    for (i = l - 1; i >= 0; i--)
    {
      ans += t * b[a[i]];
      if (i > 0)
        t *= n;

    }

    fprintf(fout, "Case #%d: %d\n", tt, ans);
  }

  return 0;
}


