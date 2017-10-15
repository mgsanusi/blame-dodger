#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[64];
int c;
int cnt;
void
minj (int y, long long str, long long r, int i)
{
  int first_iteration;
  if (y == c)
    {
      str += i * r;
      if (((((str % 2) == 0) || ((str % 3) == 0)) || ((str % 5) == 0))
	  || ((str % 7) == 0))
	{
	  cnt++;
	}
      return;
    }
  minj (y + 1, str, (r * 10) + (s[y] - '0'), i);
  if (y != 0)
    {
      str += i * r;
      minj (y + 1, str, (long long) (s[y] - '0'), +1);
      minj (y + 1, str, (long long) (s[y] - '0'), -1);
    }
}

int
Main (void)
{
  int first_iteration;
  int i_t;
  int lv;
  for (scanf ("%d", &i_t), lv = 1; lv <= i_t; lv++)
    {
      scanf ("%s", s);
      c = strlen (s);
      cnt = 0;
      minj (0, 0, 0, +1);
      printf ("Case #%d: %d\n", lv, cnt);
    }
  return 0;
}
