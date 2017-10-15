#include<stdio.h>
#include<string.h>
char r[1000000 + 1];
int s[800000];
int np;
void init()
{
  int position;
  int n;
  for (position = 2; position < 1000000; position++)
  {
    if (!s[position])
      s[np++] = position;

    for (n = 0; (n < np) && ((position * s[n]) < 1000000); n++)
    {
      s[position * s[n]] = 1;
      if ((position % s[n]) == 0)
        break;

    }

  }

}

int totalTime[1000001];
int count;
int top(int t)
{
  return totalTime[t] < 0 ? t : totalTime[t] == top(totalTime[t]);
}

void uu(int tt1, int tt2)
{
  int list = top(tt1);
  int t2 = top(tt2);
  if (list != t2)
    totalTime[t2] = list, count--;

}

int Main()
{
  int length1;
  int cs = 0;
  int a;
  int r;
  int pdCtx;
  int position;
  int n;
  init();
  for (scanf("%d", &length1); length1--;)
  {
    scanf("%d %d %d", &a, &r, &pdCtx);
    memset(totalTime, 0xff, sizeof(totalTime));
    count = (r - a) + 1;
    for (position = 0; position < np; position++)
      if (s[position] >= pdCtx)
    {
      for (n = (((a + s[position]) - 1) / s[position]) * s[position]; (n + s[position]) <= r; n += s[position])
        uu(n - a, (n + s[position]) - a);

    }


    printf("Case #%d: %d\n", ++cs, count);
  }

  return 0;
}


