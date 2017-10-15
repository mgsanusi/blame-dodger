#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
char buf[8192];
void *new_malloc(size_t size);
void randomPermutation(int *arr, int len)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int t;
  for (i = 0; i < len; i++)
    arr[i] = i;

  for (k = 0; k < 1; k++)
  {
    for (i = 0; i < len; i++)
    {
      j = random() % len;
      t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }

  }

}

double monteCarlo(int n, int trialNum)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int *arr = new_malloc(n * (sizeof(int)));
  int len;
  int count;
  double total = 0.0;
  for (i = 0; i < trialNum; i++)
  {
    for (count = 0, len = n; len > 1; count++)
    {
      randomPermutation(arr, len);
      for (j = 0; j < len; j++)
      {
        if (arr[j] == j)
          len--;

        if (arr[arr[j]] = j)
        {
          len -= 2;
          count += 2;
        }

      }

    }

    total += count;
  }

  return total / trialNum;
}

int main()
{
  int first_iteration;
  int T;
  int caseNum;
  int i;
  int N;
  int len;
  int x;
  scanf(" %d", &T);
  for (caseNum = 1; caseNum <= T; caseNum++)
  {
    scanf(" %d", &N);
    len = N;
    for (i = 0; i < N; i++)
    {
      scanf(" %d", &x);
      if (x == (i + 1))
        len--;

    }

    printf("Case #%d: ", caseNum);
    printf("%.6f", (double) len);
    printf("\n");
  }

}

void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}


