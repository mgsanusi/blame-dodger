#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[1000000];
int n;
int len;
int main(void)
{
  int first_iteration;
  int num;
  int N;
  int i;
  int j;
  int k;
  scanf("%d", &num);
  for (i = 1; i <= num; ++i)
  {
    char t;
    len = 0;
    gets(name);
    while ((t = new_getchar()) != ' ')
    {
      switch (t)
      {
        case 'a':

        case 'i':

        case 'u':

        case 'e':

        case 'o':
          name[len] = 0;
          break;

        default:
          name[len] = 1;

      }

      ++len;
    }

    scanf("%d", &n);
    for (j = 0; j <= (len - n); ++j)
    {
      for (k = 0; k < n; ++k)
      {
        if (!name[j + k])
          break;

      }

      if (k < n)
        name[j] = 0;

    }

    N = 0;
    j = 0;
    while (j <= (len - n))
    {
      for (k = j; k <= (len - n); ++k)
      {
        if (name[k] == 1)
          break;

      }

      if (k > (len - n))
        break;

      N += (((len - n) - k) + 1) * ((k - j) + 1);
      j = k + 1;
    }

    printf("Case #%d: %d\n", i, N);
  }

  return 0;
}

int new_getchar()
{
  int first_iteration;
  return getchar();
}


