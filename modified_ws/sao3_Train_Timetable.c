#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 int ansa, ansb;
 typedef struct
{
  int dep;
   int arr;
   int sta;
 } time;
time train[201];
int u[201];
 void
readtime (int *a)
{
  char ch;
  *a = 0;
  scanf ("%c", &ch);
  *a += (ch - '0') * 600;
  scanf ("%c", &ch);
  *a += (ch - '0') * 60;
  scanf ("%c", &ch);
  scanf ("%c", &ch);
  *a += (ch - '0') * 10;
  scanf ("%c", &ch);
  *a += (ch - '0');
  scanf ("%c", &ch);
}  int

cmp (const void *a, const void *b)
{
  return ((const time *) a)->dep - ((const time *) b)->dep;
}  void

go ()
{
  int i, j;
  int t, na, nb;
  char ch;
  ansa = ansb = 0;
  scanf ("%d%d%d%c", &t, &na, &nb, &ch);
  for (i = 0; i < na + nb; i++)
    {
      readtime (&(train[i].dep));
      readtime (&(train[i].arr));
      train[i].arr += t;
      train[i].sta = i < na ? 0 : 1;
    }
  memset (u, 0, sizeof (u));
  qsort (train, na + nb, sizeof (time), cmp);
  for (i = 0; i < na + nb; i++)
    {
      if (u[i] == 0)
	{
	  if (train[i].sta == 0)
	    ansa++;
	  
	  else
	    ansb++;
	}
      for (j = 0; j < na + nb && 
	    (train[i].arr > train[j].dep || train[i].sta == train[j].sta
	     || u[j] == 1); j++);
      u[j] = 1;
    }
}

 int
main ()
{
  int i, cs;
  freopen ("B.in", "r", stdin);
  freopen ("B.out", "w", stdout);
  scanf ("%d", &cs);
  for (i = 1; i <= cs; i++)
    {
      go ();
      printf ("Case #%d: %d %d\n", i, ansa, ansb);
    }
  return 0;
}


