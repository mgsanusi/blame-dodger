#include <stdio.h>
#include <stdlib.h>
int denom(int P_d)
{
  int first_iteration;
  int i;
  int j = 100;
  for (i = 0; i < 2; i++)
    if ((P_d % 2) == 0)
  {
    j /= 2;
    P_d /= 2;
  }


  for (i = 0; i < 2; i++)
    if ((P_d % 5) == 0)
  {
    j /= 5;
    P_d /= 5;
  }


  return j;
}

int main()
{
  int first_iteration;
  int T;
  int N;
  int P_d;
  int P_g;
  scanf("%d", &T);
  int i;
  int j;
  int k;
  for (i = 1; i <= T; i++)
  {
    scanf("%d %d %d", &N, &P_d, &P_g);
    if ((P_g == 100) && (P_d != 100))
      printf("Case #%d: Broken\n", i);
    else
      if ((P_d != 0) && (P_g == 0))
      printf("Case #%d: Broken\n", i);
    else
      if (denom(P_d) > N)
      printf("Case #%d: Broken\n", i);
    else
      printf("Case #%d: Possible\n", i);



  }

}


