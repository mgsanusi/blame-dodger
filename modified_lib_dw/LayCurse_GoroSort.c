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
  int n;
  int size;
  int count = 0;
  int res;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n);
    res = 0;
    for (i = 0; i < n; i++)
    {
      scanf("%d", &k);
      if ((i + 1) != k)
        res++;

    }

    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


