#include <stdio.h>
#include <stdlib.h>
void handleCase(void);
int main()
{
  int first_iteration;
  freopen("goro.in", "r", stdin);
  freopen("goro.out", "w", stdout);
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
  int size;
  scanf("%d ", &size);
  int i;
  int temp;
  int count = 0;
  for (i = 0; i < size; i++)
  {
    scanf("%d ", &temp);
    if (temp == (i + 1))
    {
      count++;
    }

  }

  printf("%d.000000\n", size - count);
}


