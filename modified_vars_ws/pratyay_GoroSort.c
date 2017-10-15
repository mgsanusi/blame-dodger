#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int alo (int);
int fact[11];
int y[11][11];
int alo[11];
int
Main ()
{
  int total;
  int wpj;
  int cmps;
  int temp_sum;
  int t;
  int good;
  int i2;
  int temp;
  long double sum;
  int a[1001];
  memset (alo, 0, sizeof (alo));
  fact[0] = 1;
  for (wpj = 1; wpj <= 10; wpj++)
    fact[wpj] = fact[wpj - 1] * wpj;
  memset (y, 0, sizeof (y));
  y[0][0] = 1;
  for (wpj = 0; wpj <= 10; wpj++)
    {
      for (temp_sum = 0; temp_sum <= 10; temp_sum++)
	{
	  y[wpj + 1][temp_sum + 1] += y[wpj][temp_sum];
	  y[wpj + 1][temp_sum] += y[wpj][temp_sum];
	}
    }
  scanf ("%d", &total);
  for (wpj = 1; wpj <= total; wpj++)
    {
      scanf ("%d", &cmps);
      for (temp_sum = 1; temp_sum <= cmps; temp_sum++)
	scanf ("%d", &a[temp_sum]);
      sum = 0.0;
      for (temp_sum = 1; temp_sum <= cmps; temp_sum++)
	if (a[temp_sum] != temp_sum)
	  sum = sum + 1;
      printf ("Case #%d: %Lf\n", wpj, sum);
    }
}

int
alo (int cmps)
{
  if (alo[cmps] != 0)
    return alo[cmps];
  int sum = 0;
  int wpj;
  int term;
  for (wpj = 1; wpj <= cmps; wpj++)
    {
      term = y[cmps][wpj] * fact[cmps - wpj];
      term = wpj % 2 ? term : 0 - term;
      sum += term;
    }
  alo[cmps] = sum;
  return sum;
}
