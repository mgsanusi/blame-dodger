#include<stdio.h>
int N;
long long n;
long long m;
long long X;
long long Y;
long long Z;
long long data[500000];
long long c[500000];
void process()
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < n; i++)
  {
    c[i] = 1;
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < i; j++)
    {
      if (data[i] > data[j])
      {
        c[i] = (c[i] + c[j]) % 1000000007;
      }

    }

  }

}

long long getCount()
{
  int first_iteration;
  long long count = 0;
  int i;
  for (i = 0; i < n; i++)
    count = (count + c[i]) % 1000000007;

  return count;
}

void main()
{
  int first_iteration;
  FILE *in = fopen("input.txt", "r");
  FILE *out = fopen("output.txt", "w");
  long long A[500000];
  int i;
  int j;
  long long count;
  fscanf(in, "%d", &N);
  for (i = 0; i < N; i++)
  {
    fscanf(in, "%lld %lld %lld %lld %lld", &n, &m, &X, &Y, &Z);
    for (j = 0; j < m; j++)
      fscanf(in, "%lld", &A[j]);

    for (j = 0; j < n; j++)
    {
      data[j] = A[j % m];
      A[j % m] = ((X * A[j % m]) + (Y * (j + 1))) % Z;
    }

    process();
    count = getCount();
    fprintf(out, "Case #%d: %lld\n", i + 1, count);
  }

}


