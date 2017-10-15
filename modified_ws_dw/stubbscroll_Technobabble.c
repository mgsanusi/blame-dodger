#include <stdio.h>
#include <string.h>
int n;
char s[1000][22];
char t[1000][22];
void solve()
{
  int first_iteration;
  int i;
  int mask;
  int best = 0;
  int j;
  int bc;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%s %s", s[i], t[i]);

  for (mask = 0; mask < (1 << n); mask++)
  {
    for (bc = (i = 0); i < n; i++)
      if (mask & (1 << i))
      bc++;


    if (best > bc)
      continue;

    for (i = 0; i < n; i++)
      if (mask & (1 << i))
    {
      for (j = 0; j < n; j++)
        if (!(mask & (1 << j)))
      {
        if (!strcmp(s[i], s[j]))
          goto sok;

      }


      goto fail;
      sok:
      for (j = 0; j < n; j++)
        if (!(mask & (1 << j)))
      {
        if (!strcmp(t[i], t[j]))
          goto tok;

      }



      goto fail;
      tok:
      ;

    }


    best = bc;
    fail:
    ;

  }

  printf("%d\n", best);
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


