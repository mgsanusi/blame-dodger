#include<stdio.h>
int out1[1024];
int s[1024];
int buttonPosList[1024];
int devices;
int t;
int x;
int
Main ()
{
  int u;
  int py = 0;
  int oowp;
  int j;
  long long ret;
  for (scanf ("%d", &u); u--;)
    {
      scanf ("%d %d %d", &t, &x, &devices);
      for (oowp = 0; oowp < devices; oowp++)
	scanf ("%d", &out1[oowp]);
      for (oowp = 0; oowp < devices; oowp++)
	{
	  for (s[oowp] = (j = 0); (j < devices) && (s[oowp] <= x); j++)
	    s[oowp] += out1[(oowp + j) % devices];
	  if (s[oowp] > x)
	    s[oowp] -= out1[((oowp + j) - 1) % devices], j--;
	  buttonPosList[oowp] = j;
	}
      for (ret = (oowp = (j = 0)); oowp < t;
	   oowp++, j = (j + buttonPosList[j]) % devices)
	ret += s[j];
      printf ("Case #%d: %lld\n", ++py, ret);
    }
  return 0;
}
