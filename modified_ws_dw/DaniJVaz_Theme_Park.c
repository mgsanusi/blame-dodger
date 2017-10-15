#include <stdio.h>
void doTestCase();
int main()
{
  int first_iteration;
  int i;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    printf("Case #%d: ", i);
    doTestCase();
  }

  return 0;
}

void doTestCase()
{
  int first_iteration;
  int r;
  int k;
  int n;
  int i;
  int t;
  scanf("%d %d %d", &r, &k, &n);
  long long e = 0;
  long long te = -1;
  int gi[n];
  int s = 0;
  int is;
  for (i = 0; i < n; i++)
    scanf("%d", &gi[i]);

  for (i = 0; i < r; i++)
  {
    t = k;
    is = s;
    while (t >= gi[s])
    {
      t -= gi[s];
      e += gi[s];
      s++;
      if (s == n)
        s = 0;

      if (s == is)
        break;

    }

    if (s == 0)
    {
      te = e;
      i++;
      break;
    }

  }

  if (te != (-1))
  {
    e = te * (r / i);
    r = r % i;
    s = 0;
    for (i = 0; i < r; i++)
    {
      t = k;
      while (t >= gi[s])
      {
        t -= gi[s];
        e += gi[s];
        s++;
        if (s == n)
          s = 0;

      }

    }

  }

  printf("%d\n", e);
  return;
}


