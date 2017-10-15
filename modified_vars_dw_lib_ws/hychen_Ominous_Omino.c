#include<stdio.h>
int
fillable (int y, int r, int num)
{
  int first_iteration;
  if (((r * num) % y) != 0)
    return 0;
  if (y >= 7)
    return 0;
  int a;
  if (num > r)
    {
      a = num;
      num = r;
      r = a;
    }
  for (a = 1; a <= y; a++)
    {
      int b = (y - a) + 1;
      if ((a <= r) && (b <= num))
	continue;
      if ((b <= r) && (a <= num))
	continue;
      return 0;
    }
  for (a = num + 1; a <= y; a++)
    {
      if ((y - a) < (num - 1))
	break;
      int b;
      int f;
      for (b = 0; b < ((a * num) - y); b++)
	{
	  for (f = 0; (f + a) <= r; f++)
	    {
	      if ((((f * num) + b) % y) != 0)
		return 0;
	      if (((((r * num) - ((f * num) + b)) - y) % y) != 0)
		return 0;
	    }
	}
    }
  return 1;
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  int y;
  int r;
  int num;
  int t;
  int ind;
  scanf ("%d", &ind);
  for (t = 1; t <= ind; t++)
    {
      scanf ("%d%d%d", &y, &r, &num);
      printf ("Case #%d: %s\n", t,
	      fillable (y, r, num) ? "GABRIEL" : "RICHARD");
    }
  return 0;
}
