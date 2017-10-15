#include <stdio.h>
#include <string.h>
int
Main ()
{
  int in;
  scanf ("%d", &in);
  for (int tt = 1; tt <= in; tt++)
    {
      char curlist[100];
      int cnt = 0;
      char combine[256][256] = { 0 };
      char explode[256][256] = { 0 };
      int c;
      scanf ("%d ", &c);
      for (int i = 0; i < c; i++)
	{
	  char s[4];
	  scanf ("%s", &s);
	  combine[s[0]][s[1]] = s[2];
	  combine[s[1]][s[0]] = s[2];
	}
      int p;
      scanf ("%d", &p);
      for (int i = 0; i < p; i++)
	{
	  char s[3];
	  scanf ("%s", &s);
	  explode[s[0]][s[1]] = 1;
	  explode[s[1]][s[0]] = 1;
	}
      int x;
      char s[101];
      scanf ("%d %s", &x, &s);
      for (int i = 0; i < x; i++)
	{
	  curlist[cnt++] = s[i];
	  if (cnt < 2)
	    continue;
	  char a = combine[curlist[cnt - 1]][curlist[cnt - 2]];
	  if (a != 0)
	    {
	      cnt -= 2;
	      curlist[cnt++] = a;
	    }
	  else
	    {
	      for (int j = 0; j < (cnt - 1); j++)
		if (explode[curlist[j]][s[i]])
		  {
		    cnt = 0;
		    break;
		  }
	    }
	}
      printf ("Case #%d: [", tt);
      for (int i = 0; i < cnt; i++)
	{
	  if (i > 0)
	    printf (", ");
	  printf ("%c", curlist[i]);
	}
      printf ("]\n");
    }
  return 0;
}
