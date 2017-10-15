#include<stdio.h>
int n;
long long b;
long long y;
long long rp_dr;
long long rat;
long long minuts;
long long data[500000];
long long c[500000];
void process()
{
  int g;
  int j;
  for (g = 0; g < b; g++)
  {
    c[g] = 1;
  }

  for (g = 0; g < b; g++)
  {
    for (j = 0; j < g; j++)
    {
      if (data[g] > data[j])
      {
        c[g] = (c[g] + c[j]) % 1000000007;
      }

    }

  }

}

long long get_count()
{
  long long count = 0;
  int g;
  for (g = 0; g < b; g++)
    count = (count + c[g]) % 1000000007;

  return count;
}

void Main()
{
  FILE *b = fopen("input.txt", "r");
  FILE *out = fopen("output.txt", "w");
  long long t[500000];
  int g;
  int j;
  long long count;
  fscanf(b, "%d", &n);
  for (g = 0; g < n; g++)
  {
    fscanf(b, "%lld %lld %lld %lld %lld", &b, &y, &rp_dr, &rat, &minuts);
    for (j = 0; j < y; j++)
      fscanf(b, "%lld", &t[j]);

    for (j = 0; j < b; j++)
    {
      data[j] = t[j % y];
      t[j % y] = ((rp_dr * t[j % y]) + (rat * (j + 1))) % minuts;
    }

    process();
    count = get_count();
    fprintf(out, "Case #%d: %lld\n", g + 1, count);
  }

}


