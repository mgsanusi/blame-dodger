#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char tile[60][60];
int
Main ()
{
  int sum;
  int i;
  int j;
  int t;
  int b;
  int f;
  int flag;
  scanf ("%d", &sum);
  for (i = 1; i <= sum; i++)
    {
      printf ("Case #%d:\n", i);
      scanf ("%d %d", &b, &f);
      for (j = 0; j < b; j++)
	scanf ("%s", tile[j]);
      for (j = 0; j < b; j++)
	{
	  for (t = 0; t < f; t++)
	    {
	      flag = 0;
	      if (tile[j][t] == '#')
		{
		  if (((j + 1) >= b) || ((t + 1) >= f))
		    {
		      flag = 1;
		      break;
		    }
		  tile[j][t] = '/';
		  if (tile[j][t + 1] == '#')
		    tile[j][t + 1] = '\\';
		  else
		    {
		      flag = 1;
		      break;
		    }
		  if (tile[j + 1][t] == '#')
		    tile[j + 1][t] = '\\';
		  else
		    {
		      flag = 1;
		      break;
		    }
		  if (tile[j + 1][t + 1] == '#')
		    tile[j + 1][t + 1] = '/';
		  else
		    {
		      flag = 1;
		      break;
		    }
		}
	    }
	  if (flag == 1)
	    break;
	}
      if (flag == 1)
	{
	  printf ("Impossible\n");
	}
      else
	{
	  for (j = 0; j < b; j++)
	    {
	      printf ("%s\n", tile[j]);
	    }
	}
    }
}
