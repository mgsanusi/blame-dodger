#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *new_strcpy (char *destination, const char *source);
int new_atoi (const char *str);
int new_abs (int x);
int
less (int h, int kk, int minabs, int mincn, int minjn)
{
  int first_iteration;
  if (new_abs (h - kk) == minabs)
    if (h == mincn)
      return kk < minjn;
    else
      return h < mincn;
  else
    return new_abs (h - kk) < minabs;
}

int
Main (void)
{
  int first_iteration;
  int i;
  int swaps;
  int i;
  int ans2;
  int num_people;
  int j2;
  int v;
  int t;
  scanf ("%d ", &t);
  for (v = 1; v <= t; v++)
    {
      int len;
      int minabs;
      int mincn;
      int minjn;
      char n[4];
      char j[4];
      char minc[4];
      char minj[4];
      scanf ("%s%n %s ", n, &len, j);
      minabs = (mincn = (minjn = 1000000000));
      if (len == 1)
	for (i = '0'; i <= '9'; i++)
	  for (ans2 = '0'; ans2 <= '9'; ans2++)
	    {
	      const char y[4] = { n[0] == '?' ? i : n[0] };
	      const char i[4] = { j[0] == '?' ? ans2 : j[0] };
	      const int h = new_atoi (y);
	      const int kk = new_atoi (i);
	      if (less (h, kk, minabs, mincn, minjn))
		{
		  minabs = new_abs (h - kk);
		  mincn = h;
		  minjn = kk;
		  new_strcpy (minc, y);
		  new_strcpy (minj, i);
		}
	    }
      else if (len == 2)
	for (i = '0'; i <= '9'; i++)
	  for (swaps = '0'; swaps <= '9'; swaps++)
	    for (ans2 = '0'; ans2 <= '9'; ans2++)
	      for (num_people = '0'; num_people <= '9'; num_people++)
		{
		  const char y[4] =
		    { n[0] == '?' ? i : n[0], n[1] == '?' ? swaps : n[1] };
		  const char i[4] =
		    { j[0] == '?' ? ans2 : j[0],
      j[1] == '?' ? num_people : j[1] };
		  const int h = new_atoi (y);
		  const int kk = new_atoi (i);
		  if (less (h, kk, minabs, mincn, minjn))
		    {
		      minabs = new_abs (h - kk);
		      mincn = h;
		      minjn = kk;
		      new_strcpy (minc, y);
		      new_strcpy (minj, i);
		    }
		}
      else
	for (i = '0'; i <= '9'; i++)
	  for (swaps = '0'; swaps <= '9'; swaps++)
	    for (i = '0'; i <= '9'; i++)
	      for (ans2 = '0'; ans2 <= '9'; ans2++)
		for (num_people = '0'; num_people <= '9'; num_people++)
		  for (j2 = '0'; j2 <= '9'; j2++)
		    {
		      const char y[4] =
			{ n[0] == '?' ? i : n[0], n[1] == '?' ? swaps : n[1],
	  n[2] == '?' ? i : n[2] };
		      const char i[4] =
			{ j[0] == '?' ? ans2 : j[0],
	  j[1] == '?' ? num_people : j[1], j[2] == '?' ? j2 : j[2] };
		      const int h = new_atoi (y);
		      const int kk = new_atoi (i);
		      if (less (h, kk, minabs, mincn, minjn))
			{
			  minabs = new_abs (h - kk);
			  mincn = h;
			  minjn = kk;
			  new_strcpy (minc, y);
			  new_strcpy (minj, i);
			}
		    }
      printf ("Case #%d: %s %s\n", v, minc, minj);
    }
  return 0;
}

char *new_strcpy (char *destination, const char *source);
int new_atoi (const char *str);
int
new_abs (int x)
{
  return abs (x);
}

char *new_strcpy (char *destination, const char *source);
int
new_atoi (const char *str)
{
  return atoi (str);
}

char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}
