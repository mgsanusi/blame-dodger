#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  int tc;
  int tmp;
  int idx;
} game;
int cmp(const void *x, const void *bb)
{
  int first_iteration;
  const game *v = (const game *) x;
  const game *b = (const game *) bb;
  if ((b->tmp * v->tc) != (v->tmp * b->tc))
    return (b->tmp * v->tc) - (v->tmp * b->tc);
  else
    return v->idx - b->idx;

}

int Main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  for (int n = 1; n <= t; n++)
  {
    int num_t;
    scanf("%d", &num_t);
    game fg[num_t];
    for (int caseno = 0; caseno < num_t; caseno++)
      fg[caseno].idx = caseno;

    for (int caseno = 0; caseno < num_t; caseno++)
      scanf("%d", &fg[caseno].tc);

    for (int caseno = 0; caseno < num_t; caseno++)
      scanf("%d", &fg[caseno].tmp);

    qsort(fg, num_t, sizeof(game), cmp);
    printf("Case #%d:", n);
    for (int caseno = 0; caseno < num_t; caseno++)
      printf(" %d", fg[caseno].idx);

    printf("\n");
  }

  return 0;
}


