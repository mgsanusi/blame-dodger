#include <stdio.h>
#include <string.h>
typedef struct 
{
  int b;
  int a;
} Ans;
char res[35][35];
char s[150];
int acc[35][35];
int accv[35][35];
int b;
int e;
long long
toint (char s[])
{
  int value[256];
  int cl;
  long long answer = 0;
  for (cl = 0; cl < 10; cl++)
    {
      value['0' + cl] = cl;
      if (cl < 6)
	{
	  value['A' + cl] = 10 + cl;
	}
    }
  for (cl = 0; s[cl]; cl++)
    {
      answer = (answer * 16) + value[(int) s[cl]];
    }
  return answer;
}

void
torow (long long x, int a)
{
  int zBuf2;
  for (zBuf2 = 0; zBuf2 < e; zBuf2++)
    {
      res[a][zBuf2] = !(!(x & (1ll << ((e - zBuf2) - 1))));
    }
}

int
Main ()
{
  int l;
  int caso = 1;
  Ans list[35];
  int qtde;
  int cl;
  int zBuf2;
  int p1;
  int good;
  int count;
  int p;
  int f;
  scanf ("%d", &l);
  while (l--)
    {
      scanf ("%d %d\n", &b, &l);
      for (cl = 0; cl < b; cl++)
	{
	  gets (s);
	  torow (toint (s), cl);
	}
      qtde = 0;
      while (1)
	{
	  acc[0][0] = res[0][0] != (-1);
	  for (zBuf2 = 1; zBuf2 < l; zBuf2++)
	    {
	      if (res[0][zBuf2] == (-1))
		{
		  acc[0][zBuf2] = 0;
		}
	      else
		if ((res[0][zBuf2 - 1] == res[0][zBuf2])
		    || (res[0][zBuf2 - 1] == (-1)))
		{
		  acc[0][zBuf2] = 1;
		}
	      else
		{
		  acc[0][zBuf2] = acc[0][zBuf2 - 1] + 1;
		}
	    }
	  for (cl = 0; cl < b; cl++)
	    {
	      acc[cl][0] = res[cl][0] != (-1);
	      for (zBuf2 = 1; zBuf2 < l; zBuf2++)
		{
		  if (res[cl][zBuf2] == (-1))
		    {
		      acc[cl][zBuf2] = 0;
		    }
		  else
		    if ((res[cl][zBuf2 - 1] == res[cl][zBuf2])
			|| (res[cl][zBuf2 - 1] == (-1)))
		    {
		      acc[cl][zBuf2] = 1;
		    }
		  else
		    {
		      acc[cl][zBuf2] = acc[cl][zBuf2 - 1] + 1;
		    }
		}
	    }
	  for (zBuf2 = 0; zBuf2 < l; zBuf2++)
	    {
	      accv[0][zBuf2] = !(!acc[0][zBuf2]);
	    }
	  for (cl = 1; cl < b; cl++)
	    {
	      for (zBuf2 = 0; zBuf2 < l; zBuf2++)
		{
		  if (res[cl][zBuf2] == (-1))
		    {
		      accv[cl][zBuf2] = 0;
		    }
		  else if (res[cl][zBuf2] == res[cl - 1][zBuf2])
		    {
		      accv[cl][zBuf2] = 1;
		    }
		  else
		    {
		      good = acc[cl][zBuf2];
		      for (p1 = cl - 1;
			   (((p1 >= 0) && (acc[p1][zBuf2] > (cl - p1)))
			    && ((cl - p1) < good))
			   && ((cl - p1) <= accv[cl - 1][zBuf2]); p1--)
			{
			  if (acc[p1][zBuf2] < good)
			    {
			      good = acc[p1][zBuf2];
			    }
			}
		      accv[cl][zBuf2] = cl - p1;
		    }
		}
	    }
	  good = 1;
	  for (cl = 0; cl < b; cl++)
	    {
	      for (zBuf2 = 0; zBuf2 < l; zBuf2++)
		{
		  if (accv[cl][zBuf2] > good)
		    {
		      good = accv[cl][zBuf2];
		    }
		}
	    }
	  count = 0;
	  for (cl = 0; cl < b; cl++)
	    {
	      for (zBuf2 = 0; zBuf2 < l; zBuf2++)
		{
		  if ((((accv[cl][zBuf2] == good)
			&& (res[(cl - good) + 1][(zBuf2 - good) + 1] != (-1)))
		       && (res[(cl - good) + 1][zBuf2] != (-1)))
		      && (res[cl][(zBuf2 - good) + 1] != (-1)))
		    {
		      count++;
		      for (p = 0; p < good; p++)
			{
			  for (l = 0; l < good; l++)
			    {
			      res[cl - p][zBuf2 - l] = -1;
			    }
			}
		    }
		}
	    }
	  if (count > 0)
	    {
	      list[qtde].b = good;
	      list[qtde].a = count;
	      qtde++;
	    }
	  if (good == 1)
	    {
	      break;
	    }
	}
      printf ("Case #%d: %d\n", caso++, qtde);
      for (cl = 0; cl < qtde; cl++)
	{
	  printf ("%d %d\n", list[cl].b, list[cl].a);
	}
    }
  return 0;
}
