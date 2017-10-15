#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nowX[108][108];
int s[108];
void new_qsort (void *base, size_t num, size_t size,
		int (*compar) (const void *, const void *));
int
comp (const void *b, const void *c)
{
  return (*((int *) b)) - (*((int *) c));
}

int
Main ()
{
  int c;
  int m;
  int t;
  int key;
  int cur;
  int k;
  int x1;
  int m;
  scanf ("%d", &t);
  for (k = 1; k <= t; k++)
    {
      m = 0;
      scanf ("%d%d", &c, &m);
      for (key = 1; key <= m; key++)
	scanf ("%d", &s[key]);
      new_qsort (s + 1, m, 4, comp);
      memset (nowX, -1, sizeof (nowX));
      nowX[0][0] = c;
      for (key = 1; key <= m; key++)
	nowX[0][key] = (nowX[0][key - 1] * 2) - 1;
      for (key = 1; key <= m; key++)
	for (cur = 0; cur <= m; cur++)
	  {
	    if (nowX[key - 1][cur] > s[key])
	      nowX[key][cur] =
		nowX[key][cur] >
		(nowX[key - 1][cur] + s[key]) ? nowX[key][cur] : nowX[key -
								      1][cur]
		+ s[key];
	    if (cur > 0)
	      nowX[key][cur] =
		nowX[key][cur] >
		((nowX[key][cur - 1] * 2) -
		 1) ? nowX[key][cur] : (nowX[key][cur - 1] * 2) - 1;
	    for (x1 = 1; ((key - x1) >= 0) && ((cur - x1) >= 0); x1++)
	      {
		nowX[key][cur] =
		  nowX[key][cur] >
		  nowX[key - x1][cur - x1] ? nowX[key][cur] : nowX[key -
								   x1][cur -
								       x1];
	      }
	  }
      for (key = 0; key <= m; key++)
	{
	  if (nowX[m][key] > 0)
	    {
	      m = key;
	      break;
	    }
	}
      printf ("Case #%d: %d\n", k, m);
    }
  return 0;
}

void
new_qsort (void *base, size_t num, size_t size,
	   int (*compar) (const void *, const void *))
{
  return qsort (base, num, size, compar);
}
