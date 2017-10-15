#include <stdio.h>
#include <string.h>
char ti[1048576];
int tmp;
int a;
int lineno[201];
int num[20];
int type[20];
int gssrpc_svc_maxfd[20][201];
int
can (int h, int b8)
{
  int flag;
  int key;
  key = lineno[type[b8]];
  for (flag = 0; flag < a; flag++)
    if (h & (1 << flag))
      {
	key += gssrpc_svc_maxfd[flag][type[b8]];
	if (type[b8] == type[flag])
	  key--;
      }
  return key > 0;
}

int
Main ()
{
  int t;
  int cnt = 1;
  int h;
  int b8;
  int d;
  int mask;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d %d", &tmp, &a);
      memset (lineno, 0, sizeof (lineno));
      for (h = 0; h < tmp; h++)
	{
	  scanf ("%d", &d);
	  lineno[d]++;
	}
      memset (gssrpc_svc_maxfd, 0, sizeof (gssrpc_svc_maxfd));
      for (h = 0; h < a; h++)
	{
	  scanf ("%d %d", &type[h], &num[h]);
	  for (b8 = 0; b8 < num[h]; b8++)
	    {
	      scanf ("%d", &d);
	      gssrpc_svc_maxfd[h][d]++;
	    }
	}
      memset (ti, 0, sizeof (ti));
      ti[0] = 1;
      for (h = 0; h < (1 << a); h++)
	if (ti[h])
	  {
	    for (b8 = 0; b8 < a; b8++)
	      if (!(h & (1 << b8)))
		{
		  if (can (h, b8))
		    ti[h + (1 << b8)] = 1;
		}
	  }
      if (ti[(1 << a) - 1])
	ti[(1 << a) - 1] = 2;
      for (h = (1 << a) - 1; h; h--)
	if (ti[h] > 1)
	  {
	    for (b8 = 0; b8 < a; b8++)
	      if ((h & (1 << b8)) && ti[h - (1 << b8)])
		{
		  if (can (h - (1 << b8), b8))
		    ti[h - (1 << b8)] = 2;
		}
	  }
      printf ("Case #%d:", cnt++);
      if (ti[0] < 2)
	puts (" IMPOSSIBLE");
      else
	{
	  for (mask = (h = 0); h < a; h++)
	    {
	      for (b8 = 0; b8 < a; b8++)
		if (((!(mask & (1 << b8))) && (ti[mask + (1 << b8)] > 1))
		    && can (mask, b8))
		  {
		    mask |= 1 << b8;
		    printf (" %d", b8 + 1);
		    break;
		  }
	    }
	  putchar ('\n');
	}
    }
  return 0;
}
