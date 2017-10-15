#include<stdio.h>
int sum[10001][10001];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int a;
  int b;
  int c;
  int size;
  int count = 0;
  int res;
  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "rest input = %d\n", size);
    for (i = 0; i < 10001; i++)
      for (j = 0; j < 10001; j++)
      sum[i][j] = 0;


    scanf("%d", &n);
    while (n--)
    {
      scanf("%d%d%d", &a, &b, &c);
      for (i = a; i < 10001; i++)
        for (j = b; j < 10001; j++)
      {
        if (((10000 - i) - j) < c)
          break;

        sum[i][j]++;
      }


    }

    res = 0;
    for (i = 0; i < 10001; i++)
      for (j = 0; j < 10001; j++)
      if (res < sum[i][j])
      res = sum[i][j];



    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


