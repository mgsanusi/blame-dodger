#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u j[99];
u j[99];
int f(const void *first, const void *a)
{
  int first_iteration;
  return j[*((u *) a)] - j[*((u *) first)];
}

int Main()
{
  int first_iteration;
  u t = 0;
  u opposed;
  u expDot;
  u l;
  u best;
  for (scanf("%u", &opposed); (t++) < opposed; putchar('\n'))
  {
    scanf("%u", &l);
    best = 0;
    for (expDot = -1; (++expDot) < l; best += j[j[expDot] = expDot])
      scanf("%u", j + expDot);

    printf("Case #%u:", t);
    while (best)
    {
      qsort(j, l, sizeof(u), f);
      if (best & 1)
      {
        printf(" %c", (*j) + 'A');
        --j[*j];
        --best;
      }
      else
      {
        printf(" %c%c", (*j) + 'A', j[1] + 'A');
        --j[*j];
        --j[j[1]];
        best -= 2;
      }

    }

  }

  return 0;
}


