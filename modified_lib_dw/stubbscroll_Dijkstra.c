#include <stdio.h>
int new_puts(const char *str);
void solve()
{
  int first_iteration;
  static int caseno = 1;
  int x;
  int r;
  int c;
  int t;
  int a = 0;
  scanf("%d %d %d", &x, &r, &c);
  if (r < c)
    t = r, r = c, c = t;

  if (x == 1)
    a = 0;

  if (x == 2)
    a = (r * c) % 2;

  if ((x == 3) && (((r * c) % 3) != 0))
    a = 1;

  if (((x == 3) && (r == 3)) && (c == 1))
    a = 1;

  if (((x == 3) && (r == 3)) && (c == 2))
    a = 0;

  if (((x == 3) && (r == 3)) && (c == 3))
    a = 0;

  if ((x == 4) && (((r * c) % 4) != 0))
    a = 1;

  if (((x == 4) && (r == 4)) && (c == 1))
    a = 1;

  if (((x == 4) && (r == 2)) && (c == 2))
    a = 1;

  if (((x == 4) && (r == 4)) && (c == 2))
    a = 1;

  if (((x == 4) && (r == 4)) && (c == 3))
    a = 0;

  if (((x == 4) && (r == 4)) && (c == 4))
    a = 0;

  if (x > 4)
    a = 1;

  printf("Case #%d: ", caseno++);
  if (a)
    new_puts("RICHARD");
  else
    new_puts("GABRIEL");

}

int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  while (T--)
    solve();

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


