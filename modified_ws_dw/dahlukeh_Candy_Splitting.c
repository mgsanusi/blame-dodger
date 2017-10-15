#include <stdio.h>
#include <stdlib.h>
int sizes[1001];
void handleCase(void);
void sort(int start, int finish);
int main()
{
  int first_iteration;
  freopen("candy.in", "r", stdin);
  freopen("candy.out", "w", stdout);
  int numCases;
  scanf("%d ", &numCases);
  int i;
  for (i = 0; i < numCases; i++)
  {
    printf("Case #%d: ", i + 1);
    handleCase();
  }

  return 0;
}

void handleCase(void)
{
  int first_iteration;
  int num;
  scanf("%d ", &num);
  int i;
  int total = 0;
  int xored = 0;
  for (i = 0; i < num; i++)
  {
    scanf("%d ", &sizes[i]);
    xored ^= sizes[i];
    total += sizes[i];
  }

  if (xored != 0)
  {
    printf("NO\n");
    return;
  }

  sort(0, num - 1);
  total -= sizes[0];
  int otherXored = 0;
  otherXored ^= sizes[0];
  xored ^= sizes[0];
  for (i = 1; otherXored != xored; i++)
  {
    total -= sizes[i];
    otherXored ^= sizes[i];
    xored ^= sizes[i];
  }

  printf("%d\n", total);
}

void sort(int start, int finish)
{
  int first_iteration;
  if ((finish - start) <= 0)
  {
    return;
  }

  int midPoint = (start + finish) / 2;
  sort(start, midPoint);
  sort(midPoint + 1, finish);
  int i;
  int place1;
  int place2;
  int newSizes[(finish - start) + 1];
  place1 = start;
  place2 = midPoint + 1;
  for (i = 0; i < ((finish - start) + 1); i++)
  {
    if (place1 > midPoint)
    {
      newSizes[i] = sizes[place2];
      place2++;
    }
    else
      if (place2 > finish)
    {
      newSizes[i] = sizes[place1];
      place1++;
    }
    else
    {
      if (sizes[place1] < sizes[place2])
      {
        newSizes[i] = sizes[place1];
        place1++;
      }
      else
      {
        newSizes[i] = sizes[place2];
        place2++;
      }

    }


  }

  for (i = 0; i < ((finish - start) + 1); i++)
  {
    sizes[start + i] = newSizes[i];
  }

}


