#include<stdio.h>
int val;
int res;
int check;
int target;
int type[20000];
int change[20000];
int value[20000];
int opt0[20000];
int opt1[20000];
void clear(int node)
{
  int ok;
  int fdy;
  int d;
  int tmp0;
  int tmp1;
  if (opt0[node] >= 0)
    return;

  if (node >= res)
  {
    if (value[node] == 0)
    {
      opt0[node] = 0;
      opt1[node] = 1000000;
    }
    else
    {
      opt0[node] = 1000000;
      opt1[node] = 0;
    }

    return;
  }

  opt0[node] = (opt1[node] = 1000000);
  clear((node * 2) + 1);
  clear((node * 2) + 2);
  tmp0 = opt0[(node * 2) + 1] + opt0[(node * 2) + 2];
  if (opt0[node] > tmp0)
    opt0[node] = tmp0;

  tmp1 = opt1[(node * 2) + 1] + opt1[(node * 2) + 2];
  if (opt1[node] > tmp1)
    opt1[node] = tmp1;

  tmp0 = opt0[(node * 2) + 1] + opt1[(node * 2) + 2];
  tmp1 = opt1[(node * 2) + 1] + opt0[(node * 2) + 2];
  if (tmp0 > tmp1)
    tmp0 = tmp1;

  tmp1 = tmp0;
  if (type[node] == 0)
    if (opt1[node] > tmp0)
    opt1[node] = tmp0;


  if (type[node] == 1)
    if (opt0[node] > tmp0)
    opt0[node] = tmp0;


  if (change[node])
  {
    if (opt0[node] > (tmp0 + 1))
      opt0[node] = tmp0 + 1;

    if (opt1[node] > (tmp0 + 1))
      opt1[node] = tmp0 + 1;

  }

}

int Main()
{
  int ok;
  int fdy;
  int d;
  int l;
  int m;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &val, &target);
    res = (val - 1) / 2;
    check = (val + 1) / 2;
    for (ok = 0; ok < res; ok++)
    {
      scanf("%d%d", &fdy, &d);
      type[ok] = fdy;
      change[ok] = d;
    }

    for (ok = res; ok < val; ok++)
    {
      scanf("%d", &fdy);
      value[ok] = fdy;
    }

    for (ok = 0; ok < val; ok++)
      opt0[ok] = (opt1[ok] = -1);

    clear(0);
    printf("Case #%d: ", ++count);
    if (target == 0)
      m = opt0[0];
    else
      m = opt1[0];

    if (m >= 1000000)
      puts("IMPOSSIBLE");
    else
      printf("%d\n", m);

  }

  return 0;
}


