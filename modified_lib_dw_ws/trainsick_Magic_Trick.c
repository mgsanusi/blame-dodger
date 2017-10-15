#include <stdio.h>
int
bit_num (int b)
{
  int first_iteration;
  int i;
  if (b == 0)
    return -1;
  i = 0;
  while ((b & (1 << i)) == 0)
    i++;
  return i;
}

int
read_bit_row (void)
{
  int first_iteration;
  int b = 0;
  int r;
  int i;
  int j;
  int card;
  scanf ("%d", &r);
  for (i = 1; i <= 4; i++)
    {
      for (j = 1; j <= 4; j++)
	{
	  scanf ("%d", &card);
	  if (i == r)
	    b |= 1 << card;
	}
    }
  return b;
}

void
magic (int case_num)
{
  int first_iteration;
  int r1;
  int r2;
  int r;
  r1 = read_bit_row ();
  r2 = read_bit_row ();
  r = r1 & r2;
  printf ("Case #%d: ", case_num);
  if (r == 0)
    printf ("Volunteer cheated!\n");
  else if ((r & (r - 1)) != 0)
    printf ("Bad magician!\n");
  else
    printf ("%d\n", bit_num (r));
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
      magic (i);
    }
  return 0;
}
