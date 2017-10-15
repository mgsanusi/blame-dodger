#include <stdio.h>
int new_puts(const char *str);
void solve()
{
  int first_iteration;
  int n;
  int seen;
  int i;
  int j;
  char s[15];
  scanf("%d", &n);
  if (!n)
  {
    new_puts("INSOMNIA");
    return;
  }

  seen = 0;
  for (i = 1;; i++)
  {
    sprintf(s, "%d", i * n);
    for (j = 0; s[j]; j++)
      seen |= 1 << (s[j] - 48);

    if (seen == 1023)
    {
      printf("%d\n", i * n);
      return;
    }

  }

}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", caseno++), solve();

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


