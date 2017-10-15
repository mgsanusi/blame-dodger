#include <stdio.h>
#include <string.h>
int
Main ()
{
  int first_iteration;
  int m;
  int pD;
  int counter;
  int flag;
  int gaps;
  int buf;
  scanf ("%d", &m);
  for (pD = 1; pD <= m; ++pD)
    {
      scanf ("%d %d %d", &counter, &flag, &gaps);
      if (gaps == flag)
	buf = (gaps + counter) - 1;
      else if (gaps == 1)
	buf = counter * flag;
      else if (gaps > (flag / 2))
	buf = counter + gaps;
      else if ((gaps == (flag / 2)) && (flag & 1))
	buf = (counter * 2) + gaps;
      else if (gaps == (flag / 2))
	buf = ((counter * 2) - 1) + gaps;
      else if ((gaps < (flag / 2)) && ((flag % gaps) != 0))
	buf = (counter * (flag / gaps)) + gaps;
      else if (gaps < (flag / 2))
	buf = ((counter * (flag / gaps)) + gaps) - 1;
      printf ("Case #%d: %d\n", pD, buf);
    }
  return 0;
}
