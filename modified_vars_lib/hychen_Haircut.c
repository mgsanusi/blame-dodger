#include<stdio.h>
typedef long long LL;
LL barber[1000];
LL finishcount(int x, LL mid)
{
  int r;
  LL finishcnt = 0;
  for (r = 0; r < x; r++)
  {
    finishcnt += mid / barber[r];
  }

  return finishcnt;
}

int Main(int argc, char *argv[])
{
  int r;
  int m;
  int p;
  int t;
  int x;
  scanf("%d", &p);
  for (m = 1; m <= p; m++)
  {
    scanf("%d%d", &x, &t);
    for (r = 0; r < x; r++)
      scanf("%I64d", barber + r);

    t--;
    int rslt;
    if (t < x)
    {
      rslt = t;
      goto answer;
    }

    LL i = 0;
    LL gssCNtExportName = 100001 * ((LL) 1000000001);
    while ((i + 1) != gssCNtExportName)
    {
      LL mid = (i + gssCNtExportName) / 2;
      LL finishcnt = finishcount(x, mid);
      if ((finishcnt + x) <= t)
        i = mid;
      else
        gssCNtExportName = mid;

    }

    LL fincnt = finishcount(x, i);
    LL enqcnt = fincnt + x;
    if (enqcnt > t)
      puts("error1");

    rslt = -1;
    for (r = 0; r < x; r++)
    {
      if ((gssCNtExportName % barber[r]) == 0)
      {
        enqcnt++;
        if (enqcnt == (t + 1))
        {
          rslt = r;
          break;
        }

      }

    }

    if (rslt < 0)
      puts("error2");

    answer:
    printf("Case #%d: %d\n", m, rslt + 1);

  }

  return 0;
}


