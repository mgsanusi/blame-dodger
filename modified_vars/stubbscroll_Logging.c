#include <stdio.h>
char buf[111][111];
int p;
int caso;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int be(int e, int ia)
{
  int refx;
  if (buf[e][ia] == '^')
    refx = 3;
  else
    if (buf[e][ia] == 'v')
    refx = 1;
  else
    if (buf[e][ia] == '<')
    refx = 2;
  else
    if (buf[e][ia] == '>')
    refx = 0;
  else
    printf("error"), refx = -1;




  while (1)
  {
    e += dx[refx];
    ia += dy[refx];
    if ((((e < 0) || (ia < 0)) || (e >= p)) || (ia >= caso))
      return 1;

    if (buf[e][ia] != '.')
      return 0;

  }

}

int solve2()
{
  int now2;
  int opp;
  int cnt = 0;
  for (now2 = 0; now2 < p; now2++)
    for (opp = 0; opp < caso; opp++)
    if ((buf[now2][opp] != '.') && be(now2, opp))
    cnt++;



  return cnt;
}

int impossible()
{
  int now2;
  int opp;
  int cnt;
  char z;
  for (now2 = 0; now2 < p; now2++)
    for (opp = 0; opp < caso; opp++)
    if (buf[now2][opp] != '.')
  {
    z = buf[now2][opp];
    cnt = 0;
    buf[now2][opp] = '^';
    cnt += be(now2, opp);
    buf[now2][opp] = 'v';
    cnt += be(now2, opp);
    buf[now2][opp] = '<';
    cnt += be(now2, opp);
    buf[now2][opp] = '>';
    cnt += be(now2, opp);
    buf[now2][opp] = z;
    if (cnt == 4)
      return 1;

  }



  return 0;
}

void clear()
{
  int now2;
  scanf("%d %d", &p, &caso);
  for (now2 = 0; now2 < p; now2++)
    scanf("%s", buf[now2]);

  if (impossible())
    puts("IMPOSSIBLE");
  else
    printf("%d\n", solve2());

}

int Main()
{
  int pb;
  int caseno = 1;
  scanf("%d", &pb);
  while (pb--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


