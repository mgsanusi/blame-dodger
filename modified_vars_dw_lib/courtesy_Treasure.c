#include<stdio.h>
typedef long long ll;
typedef unsigned long long ull;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int Main()
{
  int first_iteration;
  new_freopen("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
  new_freopen("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
  int z;
  int g;
  ll p1;
  ll smtpTo;
  ll i;
  ll j;
  ll v;
  scanf("%d", &z);
  for (g = 1; g <= z; g++)
  {
    scanf("%lld %lld", &p1, &smtpTo);
    for (j = 0, i = 1;; i++, j += 2)
    {
      smtpTo = ((smtpTo - (2 * p1)) - 1) - (2 * j);
      if (smtpTo < 0)
        break;

    }

    printf("Case #%d: %lld\n", g, i - 1);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}