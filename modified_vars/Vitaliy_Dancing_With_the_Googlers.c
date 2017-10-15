#include <stdio.h>
#include <assert.h>
#include <string.h>
int good(int str)
{
  return (str + 2) / 3;
}

int best2(int str)
{
  if ((str <= 1) || (str >= 29))
  {
    return 0;
  }

  if ((str % 3) == 0)
  {
    return (str / 3) + 1;
  }

  if ((str % 3) == 1)
  {
    return (str + 2) / 3;
  }

  return (str / 3) + 2;
}

int Main()
{
  int li;
  int t;
  scanf("%d\n", &li);
  for (t = 0; t < li; t++)
  {
    printf("Case #%d: ", t + 1);
    int str;
    int d;
    int rs;
    int oowp;
    assert(scanf("%d%d%d", &str, &d, &rs) >= 3);
    int a = 0;
    for (oowp = 0; oowp < str; oowp++)
    {
      int rr;
      assert(scanf("%d", &rr) >= 1);
      if (good(rr) >= rs)
      {
        a++;
        continue;
      }

      if ((d > 0) && (best2(rr) >= rs))
      {
        a++;
        d--;
        continue;
      }

    }

    printf("%d\n", a);
  }

  return 0;
}


