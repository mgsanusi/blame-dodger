#include<stdio.h>
#include<string.h>
int uglies[300][100];
int num[100];
int target;
int len;
FILE *new_fopen (const char *filename, const char *mode);
int new_fscanf (FILE * stream, const char *format, ...);
int
getnum (int flag, int a)
{
  int cnt;
  int rem = 0;
  for (cnt = flag; cnt <= a; cnt++)
    {
      rem = (rem * 10) + num[cnt];
      rem %= 210;
    }
  return rem;
}

void
process ()
{
  int cnt;
  int cont;
  int v;
  int num;
  int add;
  int subtracted;
  int source;
  for (cnt = 1; cnt < len; cnt++)
    {
      for (cont = 0; cont < 210; cont++)
	uglies[cont][cnt] = 0;
      for (cont = 0; cont <= cnt; cont++)
	{
	  num = getnum (cont, cnt);
	  if (cont == 0)
	    {
	      uglies[num][cnt]++;
	    }
	  else
	    {
	      for (v = 0; v < 210; v++)
		{
		  add = (v + num) % 210;
		  subtracted = ((v - num) + 210) % 210;
		  uglies[add][cnt] += uglies[v][cont - 1];
		  uglies[subtracted][cnt] += uglies[v][cont - 1];
		}
	    }
	}
    }
  return;
}

int
getCnt ()
{
  int cnt;
  int t = 0;
  for (cnt = 0; cnt < 210; cnt++)
    {
      if (((((cnt % 2) == 0) || ((cnt % 3) == 0)) || ((cnt % 5) == 0))
	  || ((cnt % 7) == 0))
	t += uglies[cnt][len - 1];
    }
  return t;
}

void
Main ()
{
  FILE *in = new_fopen ("test.in", "r");
  FILE *out = new_fopen ("test.out", "w");
  int cnt;
  int cont;
  int cnt;
  char str[100];
  fscanf (in, "%d ", &target);
  for (cnt = 0; cnt < target; cnt++)
    {
      fscanf (in, "%s", str);
      len = strlen (str);
      for (cont = 0; cont < len; cont++)
	{
	  num[cont] = str[cont] - '0';
	}
      for (cont = 0; cont < 300; cont++)
	uglies[cont][0] = 0;
      uglies[num[0]][0] = 1;
      process ();
      cnt = getCnt ();
      fprintf (out, "Case #%d: %d\n", cnt + 1, cnt);
    }
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}
