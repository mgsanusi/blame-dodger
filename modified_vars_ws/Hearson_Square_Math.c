#include <stdio.h>
#include <string.h>
int y[70];
int ptr;
int count;
void
read_data ()
{
  char s[100];
  int mm;
  int vis;
  scanf ("%d\n", &ptr);
  memset (y, 0, sizeof (y));
  for (vis = 0; vis < ptr; vis++)
    {
      gets (s);
      for (mm = ptr - 1; mm >= 0; mm--)
	{
	  if (s[mm] == '1')
	    {
	      break;
	    }
	}
      y[vis] = mm;
    }
  count = 0;
}

void
swap (int r0)
{
  y[r0] ^= y[r0 + 1];
  y[r0 + 1] ^= y[r0];
  y[r0] ^= y[r0 + 1];
  count++;
}

void
clear (int ans, int inc)
{
  int mm = 0;
  if (ans >= (ptr - 1))
    {
      return;
    }
  if (y[ans] > (ans - inc))
    {
      clear (ans + 1, inc + 1);
      swap (ans);
    }
  else
    {
      clear (ans + 1, 0);
    }
}

void
single_case ()
{
  int mm;
  int vis;
  read_data ();
  for (mm = 0; mm < ptr; mm++)
    {
      clear (mm, 0);
    }
  printf ("%d\n", count);
}

int
Main ()
{
  int mm;
  int t;
  scanf ("%d", &t);
  for (mm = 1; mm <= t; mm++)
    {
      printf ("Case #%d: ", mm);
      single_case ();
    }
  return 0;
}
