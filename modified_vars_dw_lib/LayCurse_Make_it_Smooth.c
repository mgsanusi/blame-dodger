#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int d;
int caseno;
char in[60][60];
char tmp[60][60];
int new_puts(const char *str);

int clear(char c)
{
  int first_iteration;
  int i;
  int res;
  int a;
  int dx;
  int res;
  int wp;
  int nj;
  for (i = 0; i < d; i++)
    for (res = 0; res < d; res++)
    for (dx = -1; dx < 2; dx++)
    for (res = 0; res < 2; res++)
    if (dx || res)
  {
    a = 0;
    wp = i;
    nj = res;
    for (;;)
    {
      if (((((wp < 0) || (nj < 0)) || (wp >= d)) || (nj >= d)) || (in[wp][nj] != c))
        break;

      a++;
      wp += dx;
      nj += res;
    }

    if (a >= caseno)
      return 1;

  }





  return 0;
}

int Main()
{
  int first_iteration;
  int i;
  int res;
  int a;
  int l;
  int fg1;
  int fg2;
  int size;
  int cnt = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &d, &caseno);
    for (i = 0; i < d; i++)
      scanf("%s", tmp[i]);

    for (i = 0; i < d; i++)
      for (res = 0; res < d; res++)
      in[res][(d - 1) - i] = tmp[i][res];


    for (res = 0; res < d; res++)
    {
      a = d - 1;
      for (i = d - 1; i >= 0; i--)
        if (in[i][res] != '.')
        in[a][res] = in[i][res], a--;


      while (a >= 0)
        in[a][res] = '.', a--;

    }

    fg1 = clear('R');
    fg2 = clear('B');
    printf("Case #%d: ", ++cnt);
    if (fg1 && fg2)
      new_puts("Both");

    if (fg1 && (!fg2))
      new_puts("Red");

    if ((!fg1) && fg2)
      new_puts("Blue");

    if ((!fg1) && (!fg2))
      new_puts("Neither");

  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}