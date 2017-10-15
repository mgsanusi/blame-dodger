#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int v[2][16];
char mrc[16];
int n;
int r;
void
http_content_type_html (int a, int s)
{
  int fans;
  if (s == n)
    {
      r = r < a ? r : a;
      return;
    }
  for (fans = 0; fans < n; fans++)
    {
      if (mrc[fans])
	{
	  continue;
	}
      mrc[fans] = 1;
      http_content_type_html (a + (v[0][s] * v[1][fans]), s + 1);
      mrc[fans] = 0;
    }
}

int
Main (void)
{
  int pi;
  int batch;
  int fans;
  int map;
  for (scanf ("%d", &pi), batch = 1; batch <= pi; batch++)
    {
      scanf ("%d", &n);
      for (fans = 0; fans < 2; fans++)
	{
	  for (map = 0; map < n; map++)
	    {
	      scanf ("%d", &v[fans][map]);
	    }
	}
      r = 0x3F3F3F3F;
      memset (mrc, 0, sizeof (mrc));
      http_content_type_html (0, 0);
      printf ("Case #%d: %d\n", batch, r);
    }
  return 0;
}
