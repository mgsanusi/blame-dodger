#include<stdio.h>
typedef long long ll;
typedef unsigned long long ull;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int main()
{
  int first_iteration;
  new_freopen("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
  new_freopen("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
  int t;
  int cs;
  ll r;
  ll t1;
  ll t2;
  ll t3;
  ll t4;
  scanf("%d", &t);
  for (cs = 1; cs <= t; cs++)
  {
    scanf("%lld %lld", &r, &t1);
    for (t3 = 0, t2 = 1;; t2++, t3 += 2)
    {
      t1 = ((t1 - (2 * r)) - 1) - (2 * t3);
      if (t1 < 0)
        break;

    }

    printf("Case #%d: %lld\n", cs, t2 - 1);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


