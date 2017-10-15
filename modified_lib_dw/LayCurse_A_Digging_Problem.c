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
  int in[1000];
  int res;
  char tmp[1000];
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    res = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%s", tmp);
      for (k = n - 1; k >= 0; k--)
        if (tmp[k] == '1')
        break;


      in[i] = k;
    }

    for (i = 0; i < n; i++)
    {
      for (j = i; j < n; j++)
        if (in[j] <= i)
        break;


      while (j > i)
      {
        res++;
        k = in[j], in[j] = in[j - 1], in[j - 1] = k;
        j--;
      }

    }

    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


