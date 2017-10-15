#include<stdio.h>
#include<string.h>
#include<math.h>
int get_int()
{
  int first_iteration;
  char c;
  while (c = getchar(), (c < '0') || (c > '9'))
  {
  }

  int result = 0;
  while ((c >= '0') && (c <= '9'))
  {
    result = ((result * 10) + c) - '0';
    c = getchar();
  }

  return result;
}

int get_f(int p, int j)
{
  int first_iteration;
  return (p / (j + 1)) + ((p % (j + 1)) > 0 ? 1 : 0);
}

int get_max(int a, int b)
{
  int first_iteration;
  if (a > b)
    return a;
  else
    return b;

}

int main()
{
  int first_iteration;
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int i;
  int j;
  int k;
  int t;
  int T;
  int D;
  int P[1000];
  int p;
  int ans;
  int min;
  int max;
  int f1[1000];
  int f2[1000];
  T = get_int();
  for (t = 1; t <= T; t++)
  {
    D = get_int();
    for (i = 0; i < D; i++)
    {
      p = get_int();
      k = i;
      for (j = 0; j < i; j++)
      {
        if (p <= P[j])
        {
          k = j;
          break;
        }

      }

      for (j = i; j > k; j--)
      {
        P[j] = P[j - 1];
      }

      P[k] = p;
    }

    memset(f1, -1, sizeof(f1));
    memset(f2, -1, sizeof(f2));
    for (i = 0; i < D; i++)
    {
      for (j = 0; j < D; j++)
      {
        f1[j] = f2[j];
      }

      memset(f2, -1, sizeof(f2));
      f2[0] = P[i];
      for (j = 1; j < P[i]; j++)
      {
        max = get_max(f1[0], get_f(P[i], j));
        min = max;
        for (k = 0; k < j; k++)
        {
          max = get_max(f1[j - k], get_f(P[i], k));
          if (min > max)
            min = max;

        }

        f2[j] = min;
      }

    }

    ans = P[D - 1];
    for (i = 1; i <= P[D - 1]; i++)
    {
      if ((f2[i] > 0) && (ans > (f2[i] + i)))
      {
        ans = f2[i] + i;
      }

    }

    printf("Case #%d: %d\n", t, ans);
  }

}


