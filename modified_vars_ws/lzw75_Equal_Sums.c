#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void
test_case (int k, double width, double len, double rad[])
{
  int cases;
  int j;
  int newline;
  double x[6000];
  double y[6000];
  double rrr;
  int blue_pos;
  int yt;
  int index[6000];
  for (cases = 0; cases < k; cases++)
    index[cases] = cases;
  for (cases = k - 2; cases >= 0; cases--)
    for (j = 0; j <= cases; j++)
      {
	if (rad[index[j]] < rad[index[j + 1]])
	  {
	    blue_pos = index[j];
	    index[j] = index[j + 1];
	    index[j + 1] = blue_pos;
	  }
      }
  x[index[0]] = (y[index[0]] = 0);
  for (cases = 1; cases < k; cases++)
    {
    again:
      blue_pos = random () % ((int) width);
      yt = random () % ((int) len);
      for (j = 0; j < cases; j++)
	{
	  if ((((x[index[j]] - blue_pos) * (x[index[j]] - blue_pos)) +
	       ((y[index[j]] - yt) * (y[index[j]] - yt))) <
	      (((rad[index[j]] + rad[index[cases]]) * (rad[index[j]] +
						       rad[index[cases]])) +
	       0.5))
	    goto again;
	}
      x[index[cases]] = blue_pos;
      y[index[cases]] = yt;
    }
  for (cases = 0; cases < k; cases++)
    {
      printf ("%lf %lf ", x[cases], y[cases]);
    }
  printf ("\n");
}

int
Main ()
{
  int num;
  int cases;
  int k;
  int j;
  double width;
  double len;
  double rad[6000];
  scanf ("%d", &num);
  for (cases = 0; cases < num; cases++)
    {
      scanf ("%d %lf %lf", &k, &width, &len);
      for (j = 0; j < k; j++)
	scanf ("%lf", &rad[j]);
      printf ("Case #%d: ", cases + 1);
      test_case (k, width, len, rad);
    }
  return 0;
}
