#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int compare(const void *y, const void *fo)
{
  int first_iteration;
  return (*((const int *) y)) - (*((const int *) fo));
}

int motes[100];
int bi;
int search(int opt, int a, int cnt)
{
  int first_iteration;
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
  int first_iteration;
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
      new_qsort(motes, bi, sizeof(int), compare);
      printf("Case #%d: %d\n", smtp_220, search(0, a, 0));
    }

  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}