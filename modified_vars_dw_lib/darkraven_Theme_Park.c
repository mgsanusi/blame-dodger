#include<stdio.h>
#include<memory.h>

#include <stddef.h>
unsigned long long nj[2001];
int time[1001];
int mark[1001];
int a;
int r;
int src;
inline 
void * new_memset(void *ptr, int value, int num);
static void find(int *start, int *end)
{
  int first_iteration;
  int th1 = 1;
  int count = 1;
  while (!mark[th1])
  {
    mark[th1] = count;
    unsigned long long sum = 0;
    for (; sum <= ((unsigned long long) a);)
    {
      sum += (unsigned long long) time[th1];
      if (sum <= ((unsigned long long) a))
        th1 = (th1 % src) + 1;

    }

    nj[count] = (nj[count - 1] + sum) - ((unsigned long long) time[th1]);
    count++;
  }

  *start = mark[th1];
  *end = count - 1;
  return;
}

int Main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  int l;
  for (l = 1; l <= t; l++)
  {
    scanf("%d%d%d", &r, &a, &src);
    new_memset(time, 0, sizeof(time));
    new_memset(mark, 0, sizeof(mark));
    int cnt_switch;
    unsigned long long tmp = 0;
    for (cnt_switch = 1; cnt_switch <= src; cnt_switch++)
    {
      scanf("%d", time + cnt_switch);
      tmp += time[cnt_switch];
    }

    unsigned long long answer = 0;
    if (tmp > a)
    {
      int d;
      int e;
      find(&d, &e);
      answer = nj[d - 1];
      answer += (nj[e] - nj[d - 1]) * (((r - d) + 1) / ((e - d) + 1));
      answer += nj[((((r - d) + 1) % ((e - d) + 1)) + d) - 1] - nj[d - 1];
    }
    else
    {
      answer = tmp * r;
    }

    printf("Case #%d: %llu\n", l, answer);
  }

  return 0;
}



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}