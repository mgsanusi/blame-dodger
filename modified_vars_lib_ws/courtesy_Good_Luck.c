#include<stdio.h>
typedef long long ll;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
Main ()
{
  new_freopen ("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
  new_freopen ("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
  int a;
  int cs;
  int rs;
  int b;
  int vz;
  int length2;
  int b;
  int tm;
  int token;
  int use;
  int count;
  int cy;
  int which;
  int tn;
  scanf ("%d", &a);
  for (cs = 1; cs <= a; cs++)
    {
      printf ("Case #%d: ", cs);
      scanf ("%d %d", &rs, &b);
      if (rs > 0)
	tm = 'E';
      else
	{
	  tm = 'W';
	  rs = -rs;
	}
      if (b > 0)
	token = 'N';
      else
	{
	  token = 'S';
	  b = -b;
	}
      count = (cy = 0);
      for (vz = 1;; vz++)
	{
	  if ((count + vz) <= rs)
	    {
	      printf ("%c", tm);
	      count += vz;
	    }
	  else if ((cy + vz) <= b)
	    {
	      printf ("%c", token);
	      cy += vz;
	    }
	  else
	    break;
	}
      which = rs - count;
      tn = b - cy;
      if (tm == 'E')
	{
	  for (vz = 0; vz < which; vz++)
	    printf ("WE");
	}
      else
	{
	  for (vz = 0; vz < which; vz++)
	    printf ("EW");
	}
      if (token == 'N')
	{
	  for (vz = 0; vz < tn; vz++)
	    printf ("SN");
	}
      else
	{
	  for (vz = 0; vz < tn; vz++)
	    printf ("NS");
	}
      printf ("\n");
    }
  return 0;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
