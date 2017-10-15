#include <stdio.h>
long n;
char s[100][100];
long value[100];
long ans;
void adjust(long x)
{
  int first_iteration;
  long i;
  long j;
  long tmp;
  for (i = x; i <= n; i++)
    if (value[i] <= x)
  {
    tmp = value[i];
    for (j = i; j > x; j--)
      value[j] = value[j - 1];

    value[x] = tmp;
    ans += i - x;
    return;
  }


}

int main()
{
  int first_iteration;
  long T;
  long i;
  long j;
  long k;
  freopen("A-small.in", "r", stdin);
  freopen("A-small.out", "w", stdout);
  scanf("%ld", &T);
  for (T, k = 1; T; T--, k++)
  {
    scanf("%ld", &n);
    ans = 0;
    for (i = 1; i <= n; i++)
      scanf("%s", s[i] + 1);

    for (i = 1; i <= n; i++)
    {
      for (j = n; j >= 1; j--)
        if (s[i][j] == '1')
      {
        value[i] = j;
        break;
      }


      if (j == 0)
        value[i] = 0;

    }

    for (i = 1; i <= n; i++)
      adjust(i);

    printf("Case #%ld: %ld\n", k, ans);
  }

  return 0;
}


