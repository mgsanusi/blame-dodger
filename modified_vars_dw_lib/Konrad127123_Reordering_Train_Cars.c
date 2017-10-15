#include<stdio.h>
#include<stdlib.h>
int i;
int x;
int y;
int i;
int ansc1;
int foo[1024];
int oldMin;
int min;
int position;
int leftFree;
int rightFree;
int result;
int xdrs;
int b;
int new_abs(int x);

int Main()
{
  int first_iteration;
  scanf("%d", &i);
  for (y = 1; y <= i; y++)
  {
    scanf("%d", &i);
    for (x = 0; x < i; x++)
    {
      scanf("%d", &foo[x]);
    }

    result = 0;
    oldMin = -1;
    leftFree = 0;
    rightFree = i - 1;
    for (xdrs = 0; xdrs < i; xdrs++)
    {
      min = 1000000001;
      for (x = leftFree; x <= rightFree; x++)
      {
        if (foo[x] > oldMin)
          if (foo[x] < min)
        {
          min = foo[x];
          position = x;
        }


      }

      if (new_abs(position - leftFree) < new_abs(rightFree - position))
      {
        for (b = position; b > leftFree; b--)
        {
          foo[b] = foo[b - 1];
        }

        foo[leftFree] = min;
        result += position - leftFree;
        leftFree++;
      }
      else
      {
        for (b = position; b < rightFree; b++)
        {
          foo[b] = foo[b + 1];
        }

        foo[rightFree] = min;
        result += rightFree - position;
        rightFree--;
      }

      oldMin = min;
    }

    printf("Case #%d: %d\n", y, result);
  }

  return 0;
}



int new_abs(int x) {
  return abs(x);
}