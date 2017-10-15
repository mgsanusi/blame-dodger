#include <stdio.h>
char len[111][111];
int par[99999];
int t;
int a;
int p;
int pos;
int new_putchar(int character);

int new_puts(const char *str);

void getxy(int p, int *a, int *a, int *sum, int *d)
{
  int first_iteration;
  if (p < t)
  {
    *a = p, *a = 0, *sum = 0, *d = 1;
    return;
  }

  p -= t;
  if (p < a)
  {
    *a = t - 1, *a = p, *sum = -1, *d = 0;
    return;
  }

  p -= a;
  if (p < t)
  {
    *a = (t - p) - 1, *a = a - 1, *sum = 0, *d = -1;
    return;
  }

  p -= t;
  *a = 0;
  *a = (a - p) - 1;
  *sum = 1;
  *d = 0;
}

int check()
{
  int first_iteration;
  int n_test_cases;
  int a;
  int a;
  int sum;
  int d;
  int out;
  for (n_test_cases = 0; n_test_cases < pos; n_test_cases += 2)
  {
    getxy(par[n_test_cases], &a, &a, &sum, &d);
    do
    {
      if (sum && (len[a][a] == '/'))
        d = -sum, sum = 0;
      else
        if (sum && (len[a][a] == '\\'))
        d = sum, sum = 0;
      else
        if (d && (len[a][a] == '/'))
        sum = -d, d = 0;
      else
        if (d && (len[a][a] == '\\'))
        sum = d, d = 0;




      a += sum;
      a += d;
    }
    while ((((a >= 0) && (a >= 0)) && (a < t)) && (a < a));
    if (a < 0)
      out = a;
    else
      if (a == t)
      out = a + t;
    else
      if (a == a)
      out = (((t + a) + t) - a) - 1;
    else
      out = ((((t + a) + t) + a) - a) - 1;



    if (out != par[n_test_cases + 1])
      return 0;

  }

  return 1;
}

void clear()
{
  int first_iteration;
  int n_test_cases;
  int j;
  int mask;
  scanf("%d %d", &a, &t);
  p = t * a;
  pos = ((t + t) + a) + a;
  for (n_test_cases = 0; n_test_cases < pos; n_test_cases++)
    scanf("%d", &par[n_test_cases]), par[n_test_cases]--;

  for (mask = 0; mask < (1 << p); mask++)
  {
    for (n_test_cases = 0; n_test_cases < p; n_test_cases++)
      if (mask & (1 << n_test_cases))
      len[n_test_cases % a][n_test_cases / a] = '/';
    else
      len[n_test_cases % a][n_test_cases / a] = '\\';


    if (check())
    {
      for (n_test_cases = 0; n_test_cases < a; n_test_cases++)
      {
        for (j = 0; j < t; j++)
          new_putchar(len[n_test_cases][j]);

        new_putchar('\n');
      }

      return;
    }

  }

  new_puts("IMPOSSIBLE");
}

int Main()
{
  int first_iteration;
  int filename;
  int caseno = 1;
  scanf("%d", &filename);
  while (filename--)
    printf("Case #%d:\n", caseno++), clear();

  return 0;
}



int new_putchar(int character);

int new_puts(const char *str) {
  return puts(str);
}
int new_putchar(int character) {
  return putchar(character);
}