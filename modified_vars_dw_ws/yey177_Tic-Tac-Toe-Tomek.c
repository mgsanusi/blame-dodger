#include <stdio.h>
char b[5][5];
int
Main ()
{
  int first_iteration;
  int p;
  int i;
  int j;
  int m2;
  int f;
  int rez;
  scanf ("%d", &p);
  for (m2 = 1; m2 <= p; m2++)
    {
      for (i = 0; i < 4; i++)
	scanf ("%s", b[i]);
      rez = 1;
      for (i = 0; i < 4; i++)
	{
	  f = 3;
	  for (j = 0; j < 4; j++)
	    {
	      if (b[i][j] == 'T')
		f &= 3;
	      else if (b[i][j] == 'O')
		f &= 2;
	      else if (b[i][j] == 'X')
		f &= 1;
	      else if (b[i][j] == '.')
		{
		  f = 0;
		  rez = 0;
		}
	    }
	  if (f)
	    goto END;
	}
      for (j = 0; j < 4; j++)
	{
	  f = 3;
	  for (i = 0; i < 4; i++)
	    {
	      if (b[i][j] == 'T')
		f &= 3;
	      else if (b[i][j] == 'O')
		f &= 2;
	      else if (b[i][j] == 'X')
		f &= 1;
	      else if (b[i][j] == '.')
		{
		  f = 0;
		  rez = 0;
		}
	    }
	  if (f)
	    goto END;
	}
      f = 3;
      for (i = 0; i < 4; i++)
	{
	  if (b[i][i] == 'T')
	    f &= 3;
	  else if (b[i][i] == 'O')
	    f &= 2;
	  else if (b[i][i] == 'X')
	    f &= 1;
	  else if (b[i][i] == '.')
	    {
	      f = 0;
	      rez = 0;
	    }
	}
      if (f)
	goto END;
      f = 3;
      for (i = 0; i < 4; i++)
	{
	  if (b[i][3 - i] == 'T')
	    f &= 3;
	  else if (b[i][3 - i] == 'O')
	    f &= 2;
	  else if (b[i][3 - i] == 'X')
	    f &= 1;
	  else if (b[i][3 - i] == '.')
	    {
	      f = 0;
	      rez = 0;
	    }
	}
    END:
      printf ("Case #%d: ", m2);
      if (f == 2)
	puts ("O won");
      else if (f == 1)
	puts ("X won");
      else if (rez == 1)
	puts ("Draw");
      else
	puts ("Game has not completed");
    }
  return 0;
}
