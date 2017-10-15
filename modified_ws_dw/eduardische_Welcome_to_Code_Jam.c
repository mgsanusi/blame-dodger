#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int T;
  scanf("%d\n", &T);
  static char data[510];
  static char symb[25];
  static int a[25];
  strcpy(symb, "welcome to code jam");
  int iT;
  int i;
  int j;
  int N;
  for (iT = 0; iT < T; iT++)
  {
    gets(data);
    N = strlen(data);
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for (i = 0; i < N; i++)
    {
      for (j = 19; j >= 1; j--)
      {
        if (data[i] == symb[j - 1])
          a[j] = (a[j] + a[j - 1]) % 10000;

      }

    }

    printf("Case #%d: ", iT + 1);
    if (a[19] < 1000)
      printf("0");

    if (a[19] < 100)
      printf("0");

    if (a[19] < 10)
      printf("0");

    printf("%d\n", a[19]);
  }

  return 0;
}


