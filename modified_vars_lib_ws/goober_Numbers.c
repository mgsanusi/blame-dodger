#include <stdio.h>
#include <string.h>
#include <stddef.h>
char drink[2000][2000];
char mix[2000];
int deg[2000];
void *new_memset (void *ptr, int value, size_t num);
int
Main ()
{
  int file;
  scanf ("%d", &file);
  for (int cur = 1; cur <= file; cur++)
    {
      int m;
      int n;
      new_memset (drink, 0, sizeof (drink));
      new_memset (mix, 0, sizeof (mix));
      scanf ("%d %d", &n, &m);
      for (int i = 0; i < m; i++)
	{
	  scanf ("%d", &deg[i]);
	  for (int mpx = 0; mpx < deg[i]; mpx++)
	    {
	      int left;
	      int q;
	      scanf ("%d %d", &left, &q);
	      drink[i][left - 1] = q + 1;
	    }
	}
      printf ("Case #%d:", cur);
      while (1)
	{
	  int i;
	  for (i = 0; i < m; i++)
	    {
	      if (deg[i] == 0)
		goto impossible;
	      if (deg[i] == 1)
		{
		  int uh;
		  for (uh = 0; uh < n; uh++)
		    if (drink[i][uh] != 0)
		      break;
		  int file = drink[i][uh];
		  mix[uh] = file - 1;
		  deg[i] = -1;
		  for (int cas = 0; cas < m; cas++)
		    if (drink[cas][uh])
		      if (drink[cas][uh] == file)
			deg[cas] = -1;
		      else
			{
			  drink[cas][uh] = 0;
			  deg[cas]--;
			}
		  break;
		}
	    }
	  if (i >= m)
	    break;
	}
      for (int i = 0; i < n; i++)
	printf (" %d", mix[i]);
      printf ("\n");
      continue;
    impossible:
      printf (" IMPOSSIBLE\n");
    }
  return 0;
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
