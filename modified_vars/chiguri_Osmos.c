#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Main(void)
{
  int no;
  int n;
  int i;
  int score;
  int x;
  int cs;
  int y;
  int s;
  int st;
  scanf("%d", &no);
  for (i = 1; i <= no; ++i)
  {
    scanf("%d %d", &y, &cs);
    s = 0;
    st = 0;
    printf("Case #%d: ", i);
    score = 1;
    if (cs > 0)
    {
      for (; s < cs; ++score)
      {
        s += score;
        putchar('N');
      }

    }
    else
      if (cs < 0)
    {
      for (; s > cs; ++score)
      {
        s -= score;
        putchar('S');
      }

    }


    if (y > 0)
    {
      for (; st < y; ++score)
      {
        st += score;
        putchar('E');
      }

    }
    else
      if (y < 0)
    {
      for (; st > y; ++score)
      {
        st -= score;
        putchar('W');
      }

    }


    if (cs > 0)
    {
      while (s != cs)
      {
        s--;
        printf("NS");
      }

    }
    else
    {
      while (s != cs)
      {
        s++;
        printf("SN");
      }

    }

    if (y > 0)
    {
      while (st != y)
      {
        st--;
        printf("EW");
      }

    }
    else
    {
      while (st != y)
      {
        st++;
        printf("WE");
      }

    }

    puts("");
  }

  return 0;
}


