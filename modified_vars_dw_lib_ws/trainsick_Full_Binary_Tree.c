#include <stdio.h>
int r;
int t;
int pos;
int kpicked[1100];
void
lottery (void)
{
  int first_iteration;
  scanf ("%d %d %d", &r, &t, &pos);
  int p;
  int fp;
  int c;
  int size = 0;
  for (c = 0; c < pos; c++)
    kpicked[c] = 0;
  for (p = 0; p < r; p++)
    {
      for (fp = 0; fp < t; fp++)
	{
	  if ((p & fp) < pos)
	    size++;
	}
    }
  printf ("%d\n", size);
}

int
Main (int argc, char **argv)
{
  int first_iteration;
  int hnamebuf;
  int t2;
  scanf ("%d", &t2);
  for (hnamebuf = 1; hnamebuf <= t2; hnamebuf++)
    {
      printf ("Case #%d: ", hnamebuf);
      lottery ();
    }
  return 0;
}
