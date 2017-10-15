#include <stdio.h>
long long
strval (const char *s, char tail)
{
  int first_iteration;
  long long sum = 0;
  while (*s)
    {
      sum *= 10;
      if ((*s) == '?')
	sum += tail - '0';
      else
	sum += (*s) - '0';
      s++;
    }
  return sum;
}

long long mindif;
long long minc;
long long minj;
void
cmptail (char *cscore, char *jscore, int tail)
{
  int first_iteration;
  char ctail = tail & 1 ? '0' : '9';
  char jtail = tail & 2 ? '9' : '0';
  long long cval = strval (cscore, ctail);
  long long jval = strval (jscore, jtail);
  long long dif = cval - jval;
  dif = dif > 0 ? dif : -dif;
  if (((mindif > dif) || ((mindif == dif) && (cval < minc)))
      || (((mindif == dif) && (cval == minc)) && (jval < minj)))
    {
      mindif = dif;
      minc = cval;
      minj = jval;
    }
}

void
clear (char *cscore, char *jscore)
{
  int first_iteration;
  mindif = 0x7fffffffffffffffLL;
  int t = 0;
  for (; cscore[t]; t++)
    {
      char c = cscore[t];
      char wpj = jscore[t];
      char cp[4];
      char jp[4];
      int ia = 0;
      if ((c == '?') && (wpj == '?'))
	{
	  cp[0] = '0';
	  cp[1] = '1';
	  cp[2] = '0';
	  cp[3] = '1';
	  jp[0] = '0';
	  jp[1] = '1';
	  jp[2] = '1';
	  jp[3] = '0';
	  ia = 4;
	}
      else if (c == '?')
	{
	  cp[ia] = wpj;
	  jp[ia++] = wpj;
	  if (wpj != '0')
	    {
	      cp[ia] = wpj - 1;
	      jp[ia++] = wpj;
	    }
	  if (wpj != '9')
	    {
	      cp[ia] = wpj + 1;
	      jp[ia++] = wpj;
	    }
	}
      else if (wpj == '?')
	{
	  cp[ia] = c;
	  jp[ia++] = c;
	  if (c != '0')
	    {
	      cp[ia] = c;
	      jp[ia++] = c - 1;
	    }
	  if (c != '9')
	    {
	      cp[ia] = c;
	      jp[ia++] = c + 1;
	    }
	}
      else
	{
	  cp[0] = c;
	  jp[0] = wpj;
	  ia = 1;
	}
      if (ia)
	{
	  while (ia--)
	    {
	      cscore[t] = cp[ia];
	      jscore[t] = jp[ia];
	      cmptail (cscore, jscore, 0);
	      cmptail (cscore, jscore, 1);
	      cmptail (cscore, jscore, 2);
	      cmptail (cscore, jscore, 3);
	    }
	  cscore[t] = cp[0];
	  jscore[t] = jp[0];
	}
    }
  sprintf (cscore, "%0*lld", t, minc);
  sprintf (jscore, "%0*lld", t, minj);
}

int
Main ()
{
  int first_iteration;
  int subject;
  scanf ("%d", &subject);
  for (int canuse = 1; canuse <= subject; canuse++)
    {
      char c[20];
      char wpj[20];
      scanf (" %s %s\n", c, wpj);
      clear (c, wpj);
      printf ("Case #%d: %s %s\n", canuse, c, wpj);
    }
}
