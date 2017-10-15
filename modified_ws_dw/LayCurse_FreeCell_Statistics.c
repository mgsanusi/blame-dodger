#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  long long n;
  int x;
  int y;
  int size;
  int count = 0;
  int is_can[101][101] = {};
  for (i = 1; i < 101; i++)
    for (j = 0; j < (i + 1); j++)
  {
    k = j * 100;
    if (k % i)
      continue;

    k /= i;
    for (m = i; m < 101; m++)
      is_can[m][k] = 1;

  }


  scanf("%d", &size);
  while (size--)
  {
    scanf("%lld%d%d", &n, &x, &y);
    printf("Case #%d: ", ++count);
    if ((x < 100) && (y == 100))
    {
      puts("Broken");
      continue;
    }

    if ((x > 0) && (y == 0))
    {
      puts("Broken");
      continue;
    }

    if (n > 100)
      n = 100;

    if (is_can[n][x])
      puts("Possible");
    else
      puts("Broken");

  }

  return 0;
}


