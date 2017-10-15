#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char matrix[40][40];
int pos[40];
int s;
void swap(int *a, int *y)
{
  int first_iteration;
  int k = *a;
  *a = *y;
  *y = k;
  ++s;
}

int findone(char *string)
{
  int first_iteration;
  int count;
  int uglies;
  for (count = 0, uglies = 0; string[count] != '\0'; ++count)
  {
    if (string[count] == '1')
      uglies = count;

  }

  return uglies;
}

int Main()
{
  int first_iteration;
  int t;
  int n;
  int size;
  int n;
  int count;
  scanf("%d\n", &t);
  for (size = 1; size <= t; ++size)
  {
    scanf("%d\n", &n);
    for (n = 0; n < n; ++n)
    {
      scanf("%s\n", matrix[n]);
      pos[n] = findone(matrix[n]);
    }

    s = 0;
    for (n = 0; n < (n - 1); ++n)
    {
      if (pos[n] <= n)
        continue;

      for (count = n + 1; (count < n) && (pos[count] > n); ++count)
        ;

      for (; count > n; --count)
        swap(&pos[count], &pos[count - 1]);

    }

    printf("Case #%d: %d\n", size, s);
  }

  return 0;
}


