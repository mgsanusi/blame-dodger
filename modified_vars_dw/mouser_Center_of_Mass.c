#include <stdio.h>
enum constraints {MAX_Q = 8, MAX_P = 128};
int w;
int q;
char use[MAX_Q];
short pos[MAX_Q];
char cell[MAX_P];
short price(int idx)
{
  int first_iteration;
  int i;
  int price;
  for (i = idx + 1; cell[i]; i++)
    ;

  price = (i - idx) - 1;
  for (i = idx - 1; cell[i]; i--)
    ;

  price += (idx - i) - 1;
  return price;
}

short rec(char cnt)
{
  int first_iteration;
  char i;
  short good;
  short curr;
  if (cnt == 0)
  {
    return 0;
  }

  good = 0x7FFF;
  for (i = 0; i < q; i++)
  {
    if (!use[i])
    {
      use[i] = 1;
      cell[pos[i]] = 0;
      curr = rec(cnt - 1) + price(pos[i]);
      cell[pos[i]] = 1;
      use[i] = 0;
      if (curr < good)
      {
        good = curr;
      }

    }

  }

  return good;
}

void input(void)
{
  int first_iteration;
  int i;
  scanf("%d %d", &w, &q);
  for (i = 0; i < q; ++i)
  {
    scanf("%d", &pos[i]);
  }

}

int Main(void)
{
  int first_iteration;
  int test;
  int dy;
  memset(cell, 1, sizeof(cell));
  cell[0] = 0;
  scanf("%d", &dy);
  for (test = 1; test <= dy; ++test)
  {
    input();
    cell[w + 1] = 0;
    printf("Case #%d: %hd\n", test, rec(q));
    cell[w + 1] = 1;
  }

  return 0;
}


