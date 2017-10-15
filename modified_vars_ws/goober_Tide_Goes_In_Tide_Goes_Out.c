#include <stdio.h>
#include <string.h>
int pa[1000][1000];
int used[1000];
int flag;
int b;
int
dfs (int x)
{
  if (used[x])
    flag = 1;
  used[x] = 1;
  for (int changable = 0; changable < b; changable++)
    if (pa[x][changable])
      dfs (changable);
}

int
Main ()
{
  int t;
  scanf ("%d", &t);
  for (int p = 1; p <= t; p++)
    {
      printf ("Case #%d: ", p);
      scanf ("%d", &b);
      memset (pa, 0, sizeof (pa));
      for (int changable = 0; changable < b; changable++)
	{
	  int len;
	  scanf ("%d", &len);
	  for (int no = 0; no < len; no++)
	    {
	      int outs;
	      scanf ("%d", &outs);
	      pa[changable][outs - 1] = 1;
	    }
	}
      flag = 0;
      for (int changable = 0; changable < b; changable++)
	{
	  memset (used, 0, sizeof (used));
	  dfs (changable);
	}
      printf ("%s\n", flag ? "Yes" : "No");
    }
}
