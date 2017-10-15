#include<stdio.h>
typedef unsigned u;
char newmask[11][11] = {"EORZ", "ENO", "OTW", "EHRT", "FORU", "EFIV", "ISX", "ENSV", "EGHIT", "EIN"};
char size[11] = "ZXWUGHSOFI";
char dy;
u canuse[11] = {0, 6, 2, 4, 8, 3, 7, 1, 5, 9};
u a[128];
u b[11];
int Main()
{
  u t = 0;
  u s;
  u i;
  u len;
  u data1;
  u n;
  for (scanf("%u", &s); (t++) < s; putchar('\n'))
  {
    while ((dy = getchar()) < 'A')
      ;

    do
      ++a[(u) dy];
    while ((dy = getchar()) >= 'A');
    for (i = -1; (++i) < 10;)
    {
      b[len = canuse[i]] += (data1 = a[(u) size[i]]);
      for (n = -1; dy = newmask[len][++n];)
        a[(u) dy] -= data1;

    }

    printf("Case #%u: ", t);
    for (i = -1; (++i) < 10;)
      while (b[i])
    {
      --b[i];
      putchar(i | '0');
    }


  }

  return 0;
}


