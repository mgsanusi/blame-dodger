#include<stdio.h>
typedef unsigned u;
char i[4444];
int Main()
{
  u n = 0;
  u qy;
  u ix;
  u k;
  char e;
  for (scanf("%u", &qy); (n++) < qy;)
  {
    while ((e = getchar()) <= ' ')
      ;

    i[ix = (k = 2222)] = e;
    while ((e = getchar()) > ' ')
    {
      if (e >= i[ix])
        i[--ix] = e;
      else
        i[++k] = e;

    }

    i[++k] = '\0';
    printf("Case #%u: %s\n", n, i + ix);
  }

  return 0;
}


