#include <stdio.h>
unsigned int newSum(unsigned int x, unsigned int r)
{
  int first_iteration;
  return (x ^ r) & (x | r);
}

int Main(void)
{
  int first_iteration;
  int noTest;
  int noElement;
  unsigned int array[15];
  int i;
  int j;
  long currSum;
  unsigned int counter;
  unsigned int mask;
  int temp1;
  int temp2;
  int temp1I;
  int temp2I;
  int tempSum;
  int seanSum;
  unsigned int temp1Sum;
  unsigned int temp2Sum;
  scanf("%d", &noTest);
  for (i = 0; i < noTest; i++)
  {
    currSum = 0;
    scanf("%d", &noElement);
    for (j = 0; j < noElement; j++)
    {
      scanf(" %u", &array[j]);
      currSum += array[j];
    }

    counter = 1 << (noElement - 1);
    mask = counter - 1;
    mask = (mask << 1) | 1;
    seanSum = 0;
    for (j = 1; j <= counter; j++)
    {
      tempSum = 0;
      temp1Sum = 0;
      temp2Sum = 0;
      temp1 = j;
      temp1I = 0;
      do
      {
        if (temp1 & 1)
        {
          tempSum += array[temp1I];
          temp1Sum = newSum(temp1Sum, array[temp1I]);
        }

        temp1 = temp1 >> 1;
        temp1I++;
      }
      while (temp1 != 0);
      temp2 = (~j) & mask;
      temp2I = 0;
      do
      {
        if (temp2 & 1)
        {
          temp2Sum = newSum(temp2Sum, array[temp2I]);
        }

        temp2 = temp2 >> 1;
        temp2I++;
      }
      while (temp2 != 0);
      if (temp1Sum == temp2Sum)
      {
        if ((currSum - tempSum) > tempSum)
          tempSum = currSum - tempSum;

        if (tempSum > seanSum)
          seanSum = tempSum;

      }

    }

    if (seanSum == 0)
      printf("Case #%d: NO\n", i + 1);
    else
      printf("Case #%d: %d\n", i + 1, seanSum);

  }

  return 1;
}


