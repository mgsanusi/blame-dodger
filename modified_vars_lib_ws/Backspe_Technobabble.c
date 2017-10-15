#include <stdio.h>
#include <string.h>
typedef long long ll;
void
rps (int v, int a, int sym)
{
  if (a >= v)
    {
      if (sym == 0)
	printf ("P");
      if (sym == 1)
	printf ("R");
      if (sym == 2)
	printf ("S");
      return;
    }
  if (sym == 0)
    {
      rps (v, a + 2, 0);
      rps (v, a + 2, 1);
      rps (v, a + 2, 0);
      rps (v, a + 2, 2);
    }
  if (sym == 1)
    {
      rps (v, a + 2, 0);
      rps (v, a + 2, 1);
      rps (v, a + 2, 1);
      rps (v, a + 2, 2);
    }
  if (sym == 2)
    {
      rps (v, a + 2, 0);
      rps (v, a + 2, 2);
      rps (v, a + 2, 1);
      rps (v, a + 2, 2);
    }
}

int
Main ()
{
  int s1;
  int ione;
  int v;
  int r;
  int value;
  int s;
  int a;
  int pow;
  int c;
  int a;
  int s;
  int tmp;
  int now2;
  int flag;
  scanf ("%d", &ione);
  for (s1 = 1; s1 <= ione; s1++)
    {
      scanf ("%d %d %d %d", &v, &r, &value, &s);
      printf ("Case #%d: ", s1);
      a = v;
      c = r;
      a = value;
      s = s;
      flag = 0;
      pow = 1;
      for (now2 = 0; now2 < (v - 2); now2++)
	pow *= 2;
      while (a > 1)
	{
	  if (((c < pow) || (a < pow)) || (s < pow))
	    {
	      printf ("IMPOSSIBLE\n");
	      flag = 1;
	      break;
	    }
	  a = a - pow;
	  c = c - pow;
	  s = s - pow;
	  a -= 2;
	  pow /= 4;
	}
      if (flag == 1)
	continue;
      if (a == 1)
	{
	  if (((c == 2) || (s == 2)) || (a == 2))
	    {
	      printf ("IMPOSSIBLE\n");
	      continue;
	    }
	  if (a == 1)
	    rps (v - 1, 0, 0);
	  if (c == 1)
	    rps (v - 1, 0, 1);
	  if (s == 1)
	    rps (v - 1, 0, 2);
	}
      else
	{
	  if (a == 1)
	    rps (v, 0, 0);
	  if (c == 1)
	    rps (v, 0, 1);
	  if (s == 1)
	    rps (v, 0, 2);
	}
      printf ("\n");
    }
}
