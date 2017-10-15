#include<stdio.h>
int Main()
{
  int first_iteration;
  int y;
  scanf("%d", &y);
  int t;
  for (t = 1; t <= y; t++)
  {
    printf("Case #%d: ", t);
    int dig;
    int cs;
    int b1;
    int first;
    scanf("%d%d%d%d", &dig, &cs, &b1, &first);
    unsigned long long rslt = 0;
    int i;
    for (i = dig; i <= cs; i++)
    {
      int m = ((int) ((i + 0.0) * 1.6180339887)) + 1;
      m = b1 > m ? b1 : m;
      if (m > first)
        break;

      rslt += (first - m) + 1;
    }

    for (i = b1; i <= first; i++)
    {
      int m = ((int) ((i + 0.0) * 1.6180339887)) + 1;
      m = dig > m ? dig : m;
      if (m > cs)
        break;

      rslt += (cs - m) + 1;
    }

    printf("%llu\n", rslt);
  }

  return 0;
}


