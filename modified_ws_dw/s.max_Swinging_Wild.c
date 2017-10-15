#include <stdio.h>
int y[2000];
int rez[2000];
int daj(int l, int r, int h)
{
  int first_iteration;
  int i;
  int k;
  if ((l + 1) >= r)
    return 1;

  if (y[r - 1] > r)
    return 0;

  k = r - 1;
  rez[k] = h;
  for (i = r - 2; i >= l; i--)
  {
    if ((i > l) && (y[i] > r))
    {
      return 0;
    }

    if ((y[i] == r) || ((i == l) && (y[i] > r)))
    {
      if (i > l)
      {
        rez[i] = h;
      }

      if (!daj(i, k, (((((long long) rez[k]) * (r - k)) - (((long long) (k - i)) * (rez[r] - rez[k]))) / (r - k)) - 1))
        return 0;

      k = i;
    }

  }

  return 1;
}

int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  int tt;
  int moze = 1;
  for (tt = 1; tt <= T; tt++)
  {
    int n;
    scanf("%d", &n);
    int i;
    printf("Case #%d: ", tt);
    for (i = 0; i < (n - 1); i++)
    {
      scanf("%d", y + i);
      y[i]--;
      if (y[i] <= i)
      {
        moze = 0;
      }

    }

    if (!moze)
    {
      printf("Impossible\n");
      continue;
    }

    for (i = 0; i < n;)
    {
      rez[i] = 1000000000;
      int l;
      if (i == (n - 1))
        break;

      rez[y[i]] = 1000000000;
      if (!daj(i, y[i], 1000000000 - 1))
      {
        printf("Impossible\n");
        break;
      }

      i = y[i];
    }

    if (i < (n - 1))
      continue;

    for (i = 0; i < n; i++)
      printf("%d ", rez[i]);

    printf("\n");
  }

  return 0;
}


