#include <stdio.h>
int Main(int argc, char **argv)
{
  int first_iteration;
  unsigned int num_case;
  unsigned int case_num;
  scanf("%u", &num_case);
  for (case_num = 0; case_num != num_case; case_num++)
  {
    unsigned int d;
    unsigned int c;
    unsigned int i;
    unsigned int o;
    unsigned int k;
    unsigned int p;
    unsigned int mincn;
    unsigned int num = 0;
    unsigned int m;
    unsigned int x;
    char cake[1024];
    scanf("%u%u", &c, &d);
    for (i = 0; i != c; i++)
    {
      getchar();
      mincn = 0;
      for (o = 0; o != d; o++)
      {
        mincn |= (cake[(i << 5) | o] = getchar()) != '?';
      }

      if (mincn)
      {
        m = 0;
        for (o = 0; o != d; o++)
        {
          for (k = num; k <= i; k++)
          {
            if (cake[(k << 5) | o] != '?')
            {
              break;
            }

          }

          if (k <= i)
          {
            x = cake[(k << 5) | o];
            for (k = num; k <= i; k++)
            {
              for (p = m; p <= o; p++)
              {
                cake[(k << 5) | p] = x;
              }

            }

            m = o + 1;
          }

        }

        for (k = num; k <= i; k++)
        {
          for (p = m; p <= o; p++)
          {
            cake[(k << 5) | p] = x;
          }

        }

        num = i + 1;
      }

    }

    printf("Case #%u: \n", case_num + 1);
    num = 65536;
    for (i = 0; i != c; i++)
    {
      cake[(i << 5) | d] = 0;
      if ((cake[i << 5] == '?') && (num == 65536))
      {
        num = (i - 1) << 5;
      }

      puts(cake + (num == 65536 ? i << 5 : num));
    }

  }

  return 0;
}


