#include<stdio.h>
typedef unsigned u;
int Main()
{
  u t = 0;
  u s;
  u n;
  u ok;
  u cfStat;
  u k;
  u c[11];
  u r;
  for (scanf("%u", &s); (t++) < s;)
  {
    scanf("%u", &n);
    r = 0;
    printf("Case #%u: ", t);
    for (ok = -1; (++ok) < 11;)
      c[ok] = 0;

    for (ok = (cfStat = 0); (++ok) < 111;)
    {
      for (k = (cfStat += n); k; k /= 10)
        if ((++c[k % 10]) == 1)
        ++r;


      if (r == 10)
        break;

    }

    printf(r == 10 ? "%u\n" : "INSOMNIA\n", cfStat);
  }

  return 0;
}


