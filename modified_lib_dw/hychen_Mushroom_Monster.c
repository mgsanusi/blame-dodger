#include<stdio.h>
int m[10000];
int main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int b;
  int c;
  int d;
  int e;
  int n;
  scanf("%d", &e);
  for (d = 1; d <= e; d++)
  {
    scanf("%d", &n);
    for (a = 0; a < n; a++)
      scanf("%d", m + a);

    int ans1 = 0;
    int ans2 = 0;
    for (a = 1; a < n; a++)
    {
      if (m[a] < m[a - 1])
        ans1 += m[a - 1] - m[a];

    }

    int rate = 0;
    for (a = 1; a < n; a++)
    {
      if (m[a] < m[a - 1])
      {
        if ((m[a - 1] - m[a]) > rate)
          rate = m[a - 1] - m[a];

      }

    }

    b = m[0];
    for (a = 1; a < n; a++)
    {
      if (b < rate)
      {
        ans2 += b;
        b = 0;
      }
      else
      {
        b -= rate;
        ans2 += rate;
      }

      b = m[a];
    }

    printf("Case #%d: %d %d\n", d, ans1, ans2);
  }

  return 0;
}


