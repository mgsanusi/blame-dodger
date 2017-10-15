#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buf[8192];
int xor(int a, int b)
{
  int first_iteration;
  return (a | b) & (~(a & b));
}

int main()
{
  int first_iteration;
  int T;
  int caseNum;
  int N;
  int pow[20];
  int i;
  int mask;
  int total;
  int smallest;
  for (i = 0; i < 20; i++)
    pow[i] = 1 << i;

  scanf(" %d", &T);
  for (caseNum = 1; caseNum <= T; caseNum++)
  {
    scanf(" %d", &N);
    total = (mask = 0);
    smallest = 2 * pow[19];
    while ((N--) > 0)
    {
      scanf(" %d", &i);
      if (i < smallest)
        smallest = i;

      total += i;
      mask = xor(mask, i);
    }

    printf("Case #%d: ", caseNum);
    if (mask == 0)
      printf("%d", total - smallest);
    else
      printf("NO");

    printf("\n");
  }

}


