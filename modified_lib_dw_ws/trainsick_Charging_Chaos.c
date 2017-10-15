#include <stdio.h>
int new_abs (int x);
int
new_abs (int x)
{
  int first_iteration;
  return x >= 0 ? x : -x;
}

void
repeater (void)
{
  int first_iteration;
  static char aa[110];
  static char bb[110];
  int ac;
  int bc;
  int score = 0;
  int N;
  char *a;
  char *b;
  char c;
  scanf ("%d", &N);
  scanf ("%s", aa);
  scanf ("%s", bb);
  a = aa;
  b = bb;
  while (1)
    {
      if ((*a) != (*b))
	{
	  score = -1;
	  break;
	}
      if ((*a) == 0)
	break;
      c = *a;
      ac = (bc = 0);
      while (c == (*a))
	{
	  a++;
	  ac++;
	}
      while (c == (*b))
	{
	  b++;
	  bc++;
	}
      score += new_abs (ac - bc);
    }
  if (score >= 0)
    printf ("%d\n", score);
  else
    printf ("Fegla Won\n");
}

int
main (int argc, char **argv)
{
  int first_iteration;
  int i;
  int tc;
  scanf ("%d", &tc);
  for (i = 1; i <= tc; i++)
    {
      printf ("Case #%d: ", i);
      repeater ();
    }
  return 0;
}

int new_abs (int x);
int
new_abs (int x)
{
  int first_iteration;
  return abs (x);
}
