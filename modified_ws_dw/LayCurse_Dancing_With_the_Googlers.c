#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int numdig(int n)
{
  int first_iteration;
  int res = 0;
  while (n)
    n /= 10, res++;

  return res;
}

int chk[2000010];
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
  int pw[20];
  int a;
  int b;
  int res;
  pw[0] = 1;
  for (i = 1; i < 20; i++)
    pw[i] = pw[i - 1] * 10;

  scanf("%d", &size);
  while (size--)
  {
    printf("Case #%d: ", ++count);
    fprintf(stderr, "rest %d\n", size);
    scanf("%d%d", &a, &b);
    for (i = a; i < (b + 1); i++)
      chk[i] = -1;

    res = 0;
    for (i = a; i < b; i++)
    {
      k = i;
      n = numdig(i);
      for (m = 0; m < n; m++)
      {
        k = (k / 10) + ((k % 10) * pw[n - 1]);
        if ((i < k) && (k <= b))
        {
          if (chk[k] != i)
            res++;

          chk[k] = i;
        }

      }

    }

    printf("%d\n", res);
  }

  return 0;
}


