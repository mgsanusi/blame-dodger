#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ten[32] = {0};
int label[3000000] = {0};
int getnum(int x)
{
  int first_iteration;
  int ret = 0;
  while (x)
  {
    ret++;
    x /= 10;
  }

  return ret;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int mod = 0;
  int c = 0;
  int y = 0;
  ten[0] = 1;
  for (int caso = 1; caso <= 12; caso++)
  {
    ten[caso] = ten[caso - 1] * 10;
  }

  scanf("%d", &mod);
  for (int cas = 1; cas <= mod; cas++)
  {
    scanf("%d %d", &c, &y);
    memset(label, -1, sizeof(label));
    int answer = 0;
    for (int caso = c; caso <= y; caso++)
    {
      int num = getnum(caso);
      int x = caso;
      for (int n = 0; n < num; n++)
      {
        x = (x / ten[num - 1]) + ((x % ten[num - 1]) * 10);
        if ((((x < caso) && (x >= c)) && (x <= y)) && ((x / ten[num - 1]) != 0))
        {
          if (label[x] != caso)
          {
            label[x] = caso;
            answer++;
          }

        }

      }

    }

    printf("Case #%d: %d\n", cas, answer);
  }

  return 0;
}


