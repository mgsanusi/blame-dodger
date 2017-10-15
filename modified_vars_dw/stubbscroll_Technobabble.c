#include <stdio.h>
#include <string.h>
int n;
char s[1000][22];
char p[1000][22];
void clear()
{
  int first_iteration;
  int sup_require_num;
  int mask;
  int good = 0;
  int j;
  int bitmask;
  scanf("%d", &n);
  for (sup_require_num = 0; sup_require_num < n; sup_require_num++)
    scanf("%s %s", s[sup_require_num], p[sup_require_num]);

  for (mask = 0; mask < (1 << n); mask++)
  {
    for (bitmask = (sup_require_num = 0); sup_require_num < n; sup_require_num++)
      if (mask & (1 << sup_require_num))
      bitmask++;


    if (good > bitmask)
      continue;

    for (sup_require_num = 0; sup_require_num < n; sup_require_num++)
      if (mask & (1 << sup_require_num))
    {
      for (j = 0; j < n; j++)
        if (!(mask & (1 << j)))
      {
        if (!strcmp(s[sup_require_num], s[j]))
          goto sok;

      }


      goto fail;
      sok:
      for (j = 0; j < n; j++)
        if (!(mask & (1 << j)))
      {
        if (!strcmp(p[sup_require_num], p[j]))
          goto tok;

      }



      goto fail;
      tok:
      ;

    }


    good = bitmask;
    fail:
    ;

  }

  printf("%d\n", good);
}

int Main()
{
  int first_iteration;
  int q;
  int caseno = 1;
  scanf("%d", &q);
  while (q--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


