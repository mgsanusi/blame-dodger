#include <stdio.h>
void clear()
{
  int first_iteration;
  char t[1001];
  int p;
  int i;
  int ar;
  int b = 0;
  scanf("%1000s %d", t, &p);
  for (i = 0; t[i]; i++)
    if (t[i] == '-')
  {
    for (ar = 0; ar < p; ar++)
    {
      if (!t[i + ar])
      {
        puts("IMPOSSIBLE");
        return;
      }

      t[i + ar] ^= '-' ^ '+';
    }

    b++;
  }


  printf("%d\n", b);
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


