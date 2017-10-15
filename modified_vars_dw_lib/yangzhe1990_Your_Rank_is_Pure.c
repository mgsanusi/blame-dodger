#include <stdio.h>
int can[50];
int x[50];
int v[50];
int d;
int d;
int in;
int t;
int work()
{
  int first_iteration;
  int swp = 0;
  int cnt;
  int have;
  int no;
  if (d == 0)
    return 0;

  for (have = 0; have < d; ++have)
    if (((((in - x[have]) + v[have]) - 1) / v[have]) <= t)
    can[have] = 1;
  else
    can[have] = 0;


  cnt = 0;
  for (no = d - 1; no >= 0; --no)
  {
    if (can[no])
      ++cnt;

    if (cnt == d)
      break;

  }

  if (cnt < d)
    return -1;

  cnt = 0;
  for (have = no; have < d; ++have)
  {
    if (can[have])
      ++cnt;
    else
      swp += cnt;

  }

  return swp;
}

int Main()
{
  int first_iteration;
  int u;
  int have;
  int no;
  int r;
  scanf("%d", &u);
  for (have = 1; have <= u; ++have)
  {
    scanf("%d %d %d %d", &d, &d, &in, &t);
    for (no = 0; no < d; ++no)
      scanf("%d", x + no);

    for (no = 0; no < d; ++no)
      scanf("%d", v + no);

    printf("Case #%d: ", have);
    r = work();
    if (r < 0)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", r);

  }

}


