#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *y, const void *fo)
{
  return (*((const int *) y)) - (*((const int *) fo));
}

int motes[100];
int bi;
int search(int opt, int a, int cnt)
{
  int from;
  int ans1;
  while ((opt < bi) && (motes[opt] < a))
  {
    a += motes[opt++];
  }

  if (opt >= bi)
    return cnt;

  from = search(opt, (a + a) - 1, cnt + 1);
  ans1 = (bi - opt) + cnt;
  return from < ans1 ? from : ans1;
}

int Main(void)
{
  int no;
  int smtp_220;
  int opt;
  int a;
  scanf("%d", &no);
  for (smtp_220 = 1; smtp_220 <= no; ++smtp_220)
  {
    scanf("%d", &a);
    scanf("%d", &bi);
    for (opt = 0; opt < bi; ++opt)
    {
      scanf("%d", motes + opt);
    }

    if (a == 1)
    {
      printf("Case #%d: %d\n", smtp_220, bi);
    }
    else
    {
      qsort(motes, bi, sizeof(int), compare);
      printf("Case #%d: %d\n", smtp_220, search(0, a, 0));
    }

  }

  return 0;
}


