#include <stdio.h>
int
bit_no (int w)
{
  int first_iteration;
  int ans;
  if (w == 0)
    return -1;
  ans = 0;
  while ((w & (1 << ans)) == 0)
    ans++;
  return ans;
}

int
read_bit_row (void)
{
  int first_iteration;
  int w = 0;
  int r;
  int ans;
  int ctail;
  int card;
  scanf ("%d", &r);
  for (ans = 1; ans <= 4; ans++)
    {
      for (ctail = 1; ctail <= 4; ctail++)
	{
	  scanf ("%d", &card);
	  if (ans == r)
	    w |= 1 << card;
	}
    }
  return w;
}

void
magic (int case_num)
{
  int first_iteration;
  int count;
  int itest;
  int r;
  count = read_bit_row ();
  itest = read_bit_row ();
  r = count & itest;
  printf ("Case #%d: ", case_num);
  if (r == 0)
    printf ("Volunteer cheated!\n");
  else if ((r & (r - 1)) != 0)
    printf ("Bad magician!\n");
  else
    printf ("%d\n", bit_no (r));
}

int
Main (int argc, char **argv)
{
  int first_iteration;
  int ans;
  int tc;
  scanf ("%d", &tc);
  for (ans = 1; ans <= tc; ans++)
    {
      magic (ans);
    }
  return 0;
}
